using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;

namespace FinanceTerminal.Expressions
{
    public class Expression
    {
        //������ʼ��Ƿ�
        const char VA_BEGIN = '{';
        const char VA_END = '}';
        private log4net.ILog log = log4net.LogManager.GetLogger(typeof(Expression));

        string strExpression;
        public Expression(string exp)
        {
            if (exp == null)
                throw new ArgumentNullException();
            strExpression = exp;
        }

        private object CalcInner()
        {
            int index = 0;
            //��ų�����
            List<decimal?> digit = new List<decimal?>();
            //���ݱ��ʽ
            List<ExpressionToken> polandCalc = new List<ExpressionToken>(rePoland.Count);
            for (int i = 0; i < rePoland.Count; i++)
            {
                polandCalc.Add(rePoland[i]);
            }
            while (index < polandCalc.Count)
            {
                if (polandCalc.Count == 1 && polandCalc[0].Type == TokenType.Numeric)
                    break;
                ExpressionToken token = polandCalc[index];
                switch (token.Type)
                {
                    case TokenType.Numeric:
                        if (polandCalc[index].Data==DBNull.Value)
                            digit.Add(null);
                        else
                            digit.Add(Convert.ToDecimal(polandCalc[index].Data));
                        index++;
                        break;
                    //case TokenType.Variant:
                    //    //�������滻Ϊ����
                    //    polandCalc[index].Data = GetVariantValue(token);
                    //    polandCalc[index].Type = TokenType.Numeric;
                    //    break;
                    case TokenType.Operator:
                        int paramCount = 2; //һ���Ƕ�Ԫʽ����Ҫ��������
                        //����
                        if (IsFunc((OperatorType)token.Data))
                        {
                            FunctionBase func = FuncFactory.GetFunc((int)(OperatorType)token.Data);
                            if (func == null)
                                throw new ExpressionException("����ʶ��ĺ�����.");
                            paramCount = func.ParamCount;
                        }
                        //����ǰ����������ֵ
                        if (digit.Count < paramCount)
                        {
                            throw new ExpressionException("ȱ�ٲ�����", 1002);
                        }
                        //�������
                        decimal?[] data = new decimal?[paramCount];
                        for (int i = 0; i < paramCount; i++)
                        {
                            data[i] = digit[index - paramCount + i];
                        }
                        polandCalc[index - paramCount].Data = CalcOperator((OperatorType)token.Data, data);
                        //�������� repoland ���Ƴ�
                        for (int i = 0; i < paramCount; i++)
                        {
                            polandCalc.RemoveAt(index - i);
                            digit.RemoveAt(index - i - 1);
                        }
                        index -= paramCount;
                        break;
                    default:
                        break;
                }
            }
            if (polandCalc.Count == 1)
            {
                switch (polandCalc[0].Type)
                {
                    case TokenType.Numeric:
                        return polandCalc[0].Data;
                    default:
                        throw new ExpressionException("ȱ�ٲ�����", 1002);
                }
            }
            else
            {
                throw new ExpressionException("ȱ�ٲ������������", 1002);
            }
        }

        object GetVariantValue(ExpressionToken token)
        {
            if (lstVariant.Contains(token.Data))
            {
                if (lstVariant[token.Data] == DBNull.Value || lstVariant[token.Data] == null)
                    return DBNull.Value;
                else
                {
                    try
                    {
                        decimal data;
                        if (decimal.TryParse(lstVariant[token.Data].ToString(), out data))
                        {
                            return data;
                        }
                        else
                        {
                            return DBNull.Value;
                        }
                    }
                    catch (Exception)
                    {
                        return DBNull.Value;
                    }
                }
            }
            else
                throw new ExpressionException("����δ����ֵ:" + Convert.ToString(token.Data));
        }

        public object Calc()
        {
            return CalcInner();
        }

        /// <summary>
        /// �����Ԫ���ʽ��ֵ
        /// </summary>
        public object CalcOperator(OperatorType op, decimal?[] data)
        {
            if (IsBaseOperator(op))
            {
                decimal? d1 = data[0];
                decimal? d2 = data[1];
                if (d1 == null || d2 == null)
                    return DBNull.Value;
                switch (op)
                {
                    case OperatorType.Plus:
                        return d1 + d2;
                    case OperatorType.Subtract:
                        return d1 - d2;
                    case OperatorType.MultiPly:
                        return d1 * d2;
                    case OperatorType.Divide:
                        if (d2 == 0)
                            throw new DivideByZeroException();
                        return d1 / d2;
                    case OperatorType.Power://������
                        return Math.Pow((double)d1,(double)d2);
                }
            }
            else if (IsFunc(op))
            {
                FunctionBase func = FuncFactory.GetFunc((int)op);
                if (func == null)
                    throw new ExpressionException("����ʶ��ĺ�����.");
                else
                {
                    func.Data = data;
                    try
                    {
                        return func.Calc();
                    }
                    catch (Exception ex)
                    {
                        throw new ExpressionException("�����������:" + ex.Message, 9000);
                    }
                }
            }
            return 0;
        }

        bool needOp = false;
        bool needParentheses = false;//ǰһ���������Ǻ�����������һ��������������������
        bool needDigit = false; //ǰһ���������� -�����ţ���������һ������������������
        OperatorType curOp = OperatorType.Plus;
        List<ExpressionToken> rePoland = new List<ExpressionToken>();
        //���������
        Stack<OperatorType> stackOp = new Stack<OperatorType>();

        /// <summary>
        /// ���������ʽת��Ϊ�沨�����ʽ
        /// </summary>
        public void ConvertExpression()
        {
            #region for

                for (int i = 0; i < strExpression.Length; i++)
                {
                    char c = strExpression[i];
                    if (needDigit && !char.IsDigit(c))
                        throw new ExpressionException("һԪ������(+,-)��������������");
                    if (char.IsWhiteSpace(c))
                        continue;
                    //���ǰһ���������Ǻ�������˴�����Ϊ����
                    if (needParentheses && c != '(')
                        throw new ExpressionException("ȱ�ٺ�����������", 1003);
                    switch (c)
                    {
                        //+-����Ϊ��Ԫ��������Ҳ��ΪһԪ������
                        case '+':
                            curOp = OperatorType.Plus;
                            if (!needOp)
                            {
                                needDigit = true;
                                stackOp.Push(curOp);
                                continue;
                            }
                            ProcOperator(i, curOp);
                            break;
                        case '-':
                            curOp = OperatorType.Subtract;
                            if (!needOp)
                            {
                                needDigit = true;
                                stackOp.Push(curOp);
                                continue;
                            }
                            ProcOperator(i, curOp);
                            break;
                        case '*':
                            curOp = OperatorType.MultiPly;
                            ProcOperator(i, curOp);
                            break;
                        case '/':
                            curOp = OperatorType.Divide;
                            ProcOperator(i, curOp);
                            break;
                        case '^':
                            curOp = OperatorType.Power;
                            ProcOperator(i, curOp);
                            break;
                        case '(':
                            curOp = OperatorType.L_Parentheses;
                            ProcParentheses(i, curOp);
                            break;
                        case ')':
                            curOp = OperatorType.R_Parentheses;
                            ProcParentheses(i, curOp);
                            break;
                        case ',':
                            ProcComma(i);
                            break;
                        case VA_BEGIN:
                            curOp = OperatorType.VARIANT;
                            i++;
                            ProcVariant(ref i, ref strExpression);
                            break;
                        default:
                            //����
                            if (char.IsDigit(c))
                            {
                                ProcDigit(ref i, ref strExpression);
                            }
                            else //�������ַ�ȫ���ɺ���
                            {
                                ProcFunc(ref i, ref strExpression);
                            }
                            break;
                    }
                }
                #endregion
            if (!needOp)
            {
                //���һ�����������������ֻ����
                throw new ExpressionException("ȱ�ٲ�����", 1002);
            }
            while (stackOp.Count > 0)
            {
                if (stackOp.Peek() == OperatorType.L_Parentheses)
                    throw new ExpressionException("���Ų�ƥ��(ȱ��������)", 1004);
                rePoland.Add(new ExpressionToken(TokenType.Operator, stackOp.Pop()));
            }
        }


        /// <summary>
        /// ������
        /// </summary>
        /// <param name="i"></param>
        /// <param name="curOp"></param>
        private void ProcComma(int index)
        {
            //���ű����ں�������
            //��ǰ���ݵ������ŵĵط������ж��Ƿ��Ǻ���
            Stack<OperatorType> stackBk = new Stack<OperatorType>();
            bool find = false;
            bool valid = false; //�Ƿ�Ϸ�
            OperatorType opBk;
            while (stackOp.Count > 0)
            {
                opBk = stackOp.Pop();
                stackBk.Push(opBk);
                if (opBk == OperatorType.L_Parentheses)
                {
                    find = true;
                    break;
                }
            }
            if (find)
            {
                if (stackOp.Count > 0)
                {
                    //ǰһ���Ƿ�Ϊ����
                    opBk = stackOp.Pop();
                    stackBk.Push(opBk);
                    if (IsFunc(opBk))
                    {
                        valid = true;
                    }
                }
            }
            //��ջ��ԭ
            while (stackBk.Count > 0)
            {
                stackOp.Push(stackBk.Pop());
            }

            if (!valid)
                throw new ExpressionException("���Ų���������ں�������.", 2001);
            else
            {
                needOp = false;
                stackOp.Push(OperatorType.Comma);
            }
        }

        /// <summary>
        /// �Ƚ����������������ȼ�
        /// </summary>
        public int PRI(OperatorType op1, OperatorType op2)
        {
            return (int)op1 - (int)op2;
        }

        public void ProcOperator(int index, OperatorType op)
        {
            if (!needOp)
                throw new ExpressionException("ȱ�ٲ�����", 1002);
            if (stackOp.Count > 0)
            {
                while (stackOp.Count > 0)
                {
                    OperatorType opPrev = stackOp.Peek();
                    if (!IsBaseOperator(opPrev) || PRI(opPrev, op) < 0)
                        break;
                    //����ǰһ�����ʽ
                    rePoland.Add(new ExpressionToken(TokenType.Operator, opPrev));
                    stackOp.Pop();
                }
                stackOp.Push(op);
            }
            else
            {
                stackOp.Push(op);
            }
            needOp = false;
        }

        private bool IsBaseOperator(OperatorType op)
        {
            return (int)op < 5;
        }

        private bool IsFunc(OperatorType op)
        {
            return (int)op > (int)OperatorType.VARIANT;
        }

        public void ProcParentheses(int index, OperatorType op)
        {
            if (op == OperatorType.L_Parentheses) //������
            {
                needOp = false;
                needParentheses = false;
                stackOp.Push(op);
            }
            else if (op == OperatorType.R_Parentheses) //������
            {
                bool find = false;
                //����Ǻ�������˴�Ϊ�����Ĳ�������
                //ͨ��ͳ�ƶ��ŵĸ����ó������ĸ���
                int funcParam = 1;  
                while (stackOp.Count > 0)
                {
                    if (stackOp.Peek() != OperatorType.L_Parentheses)
                    {
                        OperatorType opPop = stackOp.Pop();
                        if (opPop == OperatorType.Comma)
                        {
                            funcParam++;
                        }
                        else
                            rePoland.Add(new ExpressionToken(TokenType.Operator, opPop));
                    }
                    else
                    {
                        stackOp.Pop();
                        find = true;
                        break;
                    }
                }
                if (!find)
                    throw new ExpressionException("���Ų�ƥ��.(ȱ��������)", 1003);
                //�����ǰһ���Ǻ�����ҲҪ�ӵ� rePoland ��
                if (stackOp.Count > 0)
                {
                    OperatorType opPrev = stackOp.Peek();
                    if (IsFunc(opPrev))
                    {
                        //���жϺ����Ĳ��������Ƿ���ȷ
                        FunctionBase func = FuncFactory.GetFunc((int)opPrev);
                        if (func.ParamCount != funcParam)
                            throw new ExpressionException("����(" + func.Name + ")������������ȷ\n"
                                + "ӦΪ" + func.ParamCount + "��,"
                                + "ʵΪ" + funcParam + "��");
                        rePoland.Add(new ExpressionToken(TokenType.Operator, stackOp.Pop()));
                    }
                }
            }
        }

        public void ProcDigit(ref int index, ref string expression)
        {
            if (needOp)
                throw new ExpressionException("ȱ�ٲ�����", 1001);

            StringBuilder str = new StringBuilder();
            for (int i = index; i < expression.Length; i++)
            {
                char c = expression[i];
                if (char.IsDigit(c) || c == '.')
                    str.Append(c);
                else
                {
                    break;
                }
                index = i;
            }
            needOp = true;
            decimal data = Convert.ToDecimal(str.ToString());
            //���ǰһ����һԪ������(-) ���ţ��������ֵ���д���
            if (needDigit)
            {
                if (stackOp.Pop() == OperatorType.Subtract)
                    data = -data;
                needDigit = false;
            }
            rePoland.Add(new ExpressionToken(TokenType.Numeric
                , data));
        }

        private void ProcFunc(ref int index, ref string expression)
        {
            if (needOp)
                throw new ExpressionException("ȱ�ٲ�����", 1001);

            StringBuilder str = new StringBuilder();
            for (int i = index; i < expression.Length; i++)
            {
                char c = expression[i];
                if (char.IsWhiteSpace(c) || c == '(')
                {
                    this.needParentheses = true;
                    break;
                }
                else
                {
                    str.Append(c);
                }
                index = i;
            }
            string strFunc = str.ToString();
            //�����Ƿ���ȷ
            if (!FuncFactory.IsValidFunc(strFunc))
                throw new ExpressionException("��������Ч:" + strFunc, 2001);
            else
                stackOp.Push((OperatorType)FuncFactory.GetFuncIndex(strFunc));
        }

        private void ProcVariant(ref int index, ref string expression)
        {
            if (needOp)
                throw new ExpressionException("ȱ�ٲ�����", 1001);

            StringBuilder str = new StringBuilder();
            bool match = false; //�����Ƿ�ƥ��
            for (int i = index; i < expression.Length; i++)
            {
                char c = expression[i];
                if (c != VA_END)   //������ֻ�� } Ϊ������
                    str.Append(c);
                else
                {
                    match = true;
                    break;
                }
                index = i;
            }
            if (!match)
                throw new ExpressionException("�������Ų�ƥ��(ȱ����ֹ��'}')", 2001);
            index++;
            needOp = true;
            //rePoland.Add(new ExpressionToken(TokenType.Variant
            //    , str.ToString()));
        }

        private Hashtable lstVariant = new Hashtable();

        /// <summary>
        /// ���ò�����ֵ
        /// </summary>
        public void SetVariantValue(string key, object data)
        {
            lstVariant[key] = data;
        }
    }
}

using System;
using System.Collections.Generic;
using System.Text;

/*
 * ��Ӻ�����Ҫע�⣺
 * 1. ����̳��� FunctionBase
 * 2. ����������������ȷ
 * 2. �������� FuncFactory ���޸� GetFunc������ aryFunc ����
 * 3. �޸Ĳ�����ö��ֵ OperatorType
 * */

namespace FinanceTerminal.Expressions
{
    /// <summary>
    /// ����ֵ
    /// </summary>
    public class FuncABS : FunctionBase
    {
        public FuncABS()
        {
            paramCount = 1;
            name = "ABS";
        }

        public override object Calc()
        {
            if (data[0] == null)
                return DBNull.Value;
            return Math.Abs((decimal)data[0]);
        }
    }

    /// <summary>
    /// ƽ��
    /// </summary>
    public class FuncSQR : FunctionBase
    {
        public FuncSQR()
        {
            paramCount = 1;
            name = "SQR";
        }

        public override object Calc()
        {
            if (data[0] == null)
                return DBNull.Value;
            return data[0] * data[0];
        }
    }

    /// <summary>
    /// ��ƽ��
    /// </summary>
    public class FuncSQRT : FunctionBase
    {
        public FuncSQRT()
        {
            //�������ƺͲ�������һ��Ҫ������ȷ
            //�����ڽ�����ʱ������
            paramCount = 1;
            name = "SQRT";
        }
        /// <summary>
        /// ����
        /// ������ʵ����һ�������ˣ� �򵥰�
        /// </summary>
        /// <returns></returns>
        public override object Calc()
        {
            if (data[0] == null)
                return DBNull.Value;
            return Math.Sqrt((double)data[0]);
        }
    }

    /// <summary>
    /// С��ȡ��
    /// </summary>
    public class FuncRound : FunctionBase
    {
        public FuncRound()
        {
            paramCount = 2;
            name = "ROUND";
        }

        public override object Calc()
        {
            if (data[0] == null || data[1] == null)
                return DBNull.Value;
            return Math.Round((double)data[0], (int)data[1]);
        }
    }

    /// <summary>
    /// ����
    /// </summary>
    public class FuncLog : FunctionBase
    {
        public FuncLog()
        {
            paramCount = 2;
            name = "LOG";
        }

        public override object Calc()
        {
            if (data[0] == null || data[1] == null)
                return DBNull.Value;
            return (decimal)Math.Log((double)data[0], (double)data[1]);
        }
    }

    /// <summary>
    /// 10Ϊ�׵Ķ���
    /// </summary>
    public class FuncLn : FunctionBase
    {
        public FuncLn()
        {
            paramCount = 1;
            name = "LN";
        }

        public override object Calc()
        {
            if (data[0] == null)
                return DBNull.Value;
            return (decimal)Math.Log((double)data[0]);
        }
    }

    /// <summary>
    /// ָ������
    /// </summary>
    public class FuncExp : FunctionBase
    {
        public FuncExp()
        {
            paramCount = 1;
            name = "EXP";
        }

        public override object Calc()
        {
            if (data[0] == null)
                return DBNull.Value;
            return (decimal)Math.Exp((double)data[0]);
        }
    }

    /// <summary>
    /// ����
    /// </summary>
    public class FuncSin : FunctionBase
    {
        public FuncSin()
        {
            paramCount = 1;
            name = "EXP";
        }

        public override object Calc()
        {
            if (data[0] == null)
                return DBNull.Value;
            return (decimal)Math.Sin(ConvertAngleToRad((double)data[0]));
        }
    }

    /// <summary>
    /// ����
    /// </summary>
    public class FuncCos : FunctionBase
    {
        public FuncCos()
        {
            paramCount = 1;
            name = "COS";
        }

        public override object Calc()
        {
            if (data[0] == null)
                return DBNull.Value;
            return (decimal)Math.Cos(ConvertAngleToRad((double)data[0]));
        }
    }

    /// <summary>
    /// ����
    /// </summary>
    public class FuncTan : FunctionBase
    {
        public FuncTan()
        {
            paramCount = 1;
            name = "TAN";
        }

        public override object Calc()
        {
            if (data[0] == null)
                return DBNull.Value;
            return (decimal)Math.Tan(ConvertAngleToRad((double)data[0]));
        }
    }

    /// <summary>
    /// ����
    /// </summary>
    public class FuncCot : FunctionBase
    {
        public FuncCot()
        {
            paramCount = 1;
            name = "COT";
        }

        public override object Calc()
        {
            if (data[0] == null)
                return DBNull.Value;
            return 1m / (decimal)Math.Tan(ConvertAngleToRad((double)data[0]));
        }
    }

    /// <summary>
    /// IsNull
    /// </summary>
    public class FuncIsNull : FunctionBase
    {
        public FuncIsNull()
        {
            paramCount = 2;
            name = "ISNULL";
        }

        public override object Calc()
        {
            if (data[1] == null)
                return DBNull.Value;
            if (data[0] == null)
                return data[1];
            else
                return data[0];
        }
    }
}

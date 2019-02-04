using System;
using System.Collections.Generic;
using System.Text;

namespace FinanceTerminal.Expressions
{
    /// <summary>
    /// �ڵ���
    /// </summary>
    public class ExpressionToken
    {
        private TokenType type;

        /// <summary>
        /// �ڵ�����
        /// </summary>
        public TokenType Type
        {
            get { return type; }
            set { type = value; }
        }
        private object data;

        /// <summary>
        /// �ڵ�����
        /// </summary>
        public object Data
        {
            get { return data; }
            set { data = value; }
        }

        /// <summary>
        /// ���캯��
        /// </summary>
        /// <param name="type">�ڵ�����</param>
        /// <param name="data">�ڵ�����</param>
        public ExpressionToken(TokenType type, object data)
        {
            this.type = type;
            this.data = data;
        }
    }

    /// <summary>
    /// �ڵ�����
    /// </summary>
    public enum TokenType
    {
        /// <summary>
        /// ������
        /// </summary>
        Numeric,
        /// <summary>
        /// ������
        /// </summary>
        Operator
    }
}

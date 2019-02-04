using System;
using System.Collections.Generic;
using System.Text;

namespace FinanceTerminal.Expressions
{
    /// <summary>
    /// ��������
    /// </summary>
    public abstract class FunctionBase
    {
        protected string name;
        /// <summary>
        /// ��������
        /// </summary>
        public string Name
        {
            get { return name; }
            set { name = value; }
        }
        protected decimal?[] data;
        /// <summary>
        /// ��������(���洫��Ĳ���)
        /// </summary>
        public decimal?[] Data
        {
            get { return data; }
            set { data = value; }
        }
        protected int paramCount;
        /// <summary>
        /// ָ�������ĸ���
        /// </summary>
        public int ParamCount
        {
            get { return paramCount; }
        }

        protected FunctionBase()
        {
        }

        /// <summary>
        /// ���㣨����Ϊ�麯����
        /// </summary>
        /// <returns></returns>
        public abstract object Calc();

        /// <summary>
        /// �Ƕ�ת����
        /// </summary>
        /// <param name="angle">�Ƕ�</param>
        /// <returns></returns>
        protected double ConvertAngleToRad(double angle)
        {
            return Math.PI * angle / 180d;
        }
    }
}

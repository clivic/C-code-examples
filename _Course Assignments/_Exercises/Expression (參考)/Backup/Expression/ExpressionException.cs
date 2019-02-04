using System;
using System.Collections.Generic;
using System.Text;

namespace FinanceTerminal.Expressions
{
    /*
     * ErrCode
     * 1001 : ȱ�ٲ�����
     * 1002 : ȱ�ٲ�����
     * 1003 : ȱ��������
     * 1004 : ȱ��������
     * 1999 : ȱ�ٲ����������������������沨�����ʽ��Tokenʣ�²�ֹ1��)
     * 2001 : ��������Ч
     * 2002 : �����ں�������
     */
    public class ExpressionException : Exception
    {
        private int errCode;

        public int ErrCode
        {
            get { return errCode; }
            set { errCode = value; }
        }

        public ExpressionException(string message, int errCode)
            :base(message)
        {
            this.errCode = errCode;
        }

        public ExpressionException(string message)
            :base(message)
        {
        }

        public ExpressionException()
            :base()
        {
            
        }
    }
}

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using FinanceTerminal.Expressions;
namespace Expression
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            try
            {
                FinanceTerminal.Expressions.Expression r = new FinanceTerminal.Expressions.Expression(textBox1.Text);
                //r.SetVariantValue("x", Convert.ToDecimal(textBox3.Text));
                r.ConvertExpression();
                textBox2.Text = r.Calc().ToString();
            }
            catch (ExpressionException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int b = 0;
            int i = 10 / b;
        }
    }
}
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Welcome
{
    public partial class Form1 : Form
    {
        bool clicked = false;   // 是否按過"顯示"按鈕
        public Form1()
        {
            InitializeComponent();
            for (long i = 1; i <= 100000; i++) 
            {
                this.Opacity += 0.00001;
            }
        }

        private void btnQuit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void btnShow_Click(object sender, EventArgs e)
        {
            if (clicked) lblShow.Text = "你已經按過了喲,再按一下來再顯示一下~ :)";
            else lblShow.Text = "歡迎學習C#! :)";
            clicked = !clicked;
        }
    }
}

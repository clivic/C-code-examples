using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Hold_And_Attack_2._0
{
    public partial class FormResult : Form
    {
        FormPlay formPlay;              // 存儲遊戲窗體的內容以調用顯示結果

        public FormResult(FormPlay fP)
        {
            this.formPlay = fP;
            InitializeComponent();
            DisplayResult();
        }

        private void FormResult_Load(object sender, EventArgs e)
        {

        }

        public void DisplayResult()
        {
            richTbResult.Text = formPlay.PrintRev();
        }
    }
}

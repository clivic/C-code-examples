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
    public partial class AboutForm : Form
    {
        public FormPlay.Language lang = FormPlay.Language.ENG;

        public AboutForm(FormPlay.Language lang)
        {
            InitializeComponent();
            this.lang = lang;
        }

        private void AboutForm_Load(object sender, EventArgs e)
        {
            switch (lang)
            {
                case FormPlay.Language.ENG: this.Text = "About us"; lblVersion.Text = "Hold And Attack Version 2.0"; lblCom.Text = "H&A Corporation 2015"; break;
                case FormPlay.Language.CNT: this.Text = "關於我們"; lblVersion.Text = "屏鏜轟 Ver 2.0"; lblCom.Text = "H&A 集團 2015"; break;
                case FormPlay.Language.CNS: this.Text = "关于我们"; lblVersion.Text = "屏镗波 Ver 2.0"; lblCom.Text = "H&A 集团 2015"; break;
                default: break;
            }
        }
    }
}

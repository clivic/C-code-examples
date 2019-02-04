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
    public partial class OptionForm : Form
    {
        public FormPlay.Language lang = FormPlay.Language.CNS;

        public Personality diff = Personality.NORMAL;

        public OptionForm(FormPlay.Language lang,Personality diff)
        {
            InitializeComponent();
            this.lang = lang;
            this.diff = diff;
        }

        private void OptionForm_Load(object sender, EventArgs e)
        {
            switch (lang)
            {
                case FormPlay.Language.ENG: lblDiff.Text = "Diffculty"; lblLang.Text = "Language"; rBEasy.Text = "Easy"; rBNormal.Text = "Normal"; rBHard.Text = "Hard"; btnOK.Text = "Accept"; btnCancel.Text = "Cancel"; rBENG.Checked = true; break;
                case FormPlay.Language.CNT: lblDiff.Text = "難度"; lblLang.Text = "語言"; rBEasy.Text = "簡單"; rBNormal.Text = "中等"; rBHard.Text = "困難"; btnOK.Text = "確定"; btnCancel.Text = "取消"; rBCNT.Checked = true; break;
                case FormPlay.Language.CNS: lblDiff.Text = "难度"; lblLang.Text = "语言"; rBEasy.Text = "简单"; rBNormal.Text = "正常"; rBHard.Text = "困难"; btnOK.Text = "确定"; btnCancel.Text = "取消"; rBCNS.Checked = true; break;
                default: break;
            }
            switch (diff)
            {
                case Personality.EASY: rBEasy.Checked = true; break;
                case Personality.NORMAL:rBNormal.Checked = true; break;
                case Personality.DEFAULT: rBHard.Checked = true; break;
                default: break;
            }
        }

        protected void BtnKeyUpOpF(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Escape)
                btnCancel.PerformClick();
            else if (e.KeyCode == Keys.Enter)
                btnOK.PerformClick();

            e.Handled = true;
        }

        protected void BtnKeyDownOpF(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.F1)
                btnCancel.PerformClick();
            e.Handled = true;
        }

        //*********************************************************************

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            if (rBENG.Checked) 
                lang = FormPlay.Language.ENG;
            else if (rBCNT.Checked) 
                lang = FormPlay.Language.CNT;
            else 
                lang = FormPlay.Language.CNS;
            if (rBEasy.Checked)
                diff = Personality.NORMAL;
            else if (rBNormal.Checked)
                diff = Personality.NORMAL;
            else
                diff = Personality.DEFAULT;
            this.Close();
        }

        private void btnOK_KeyUp(object sender, KeyEventArgs e)
        {
            BtnKeyUpOpF(sender, e);
        }

        private void btnOK_KeyDown(object sender, KeyEventArgs e)
        {
            BtnKeyDownOpF(sender, e);
        }

        private void btnCancel_KeyUp(object sender, KeyEventArgs e)
        {
            BtnKeyUpOpF(sender, e);
        }

        private void btnCancel_KeyDown(object sender, KeyEventArgs e)
        {
            BtnKeyDownOpF(sender, e);
        }

        private void OptionForm_KeyUp(object sender, KeyEventArgs e)
        {
            BtnKeyUpOpF(sender, e);
        }

        private void OptionForm_KeyDown(object sender, KeyEventArgs e)
        {
            BtnKeyDownOpF(sender, e);
        }
    }
}

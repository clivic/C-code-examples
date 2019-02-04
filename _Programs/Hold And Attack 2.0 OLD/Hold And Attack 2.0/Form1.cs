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
    public partial class FormUI : Form
    {
        public FormPlay.Language lang = FormPlay.Language.CNS;
        public Personality diff = Personality.NORMAL;
        public FormUI()
        {
            InitializeComponent();
        }

        private void btnPlay_Click(object sender, EventArgs e)
        {
            FormPlay formPlay = new FormPlay(FormPlay.Mode.PVE, diff, lang);
            //FormPlay formPlay = new FormPlay();
            formPlay.ShowDialog();
            //formPlay.SetLang(lang);
            //formPlay.SetPntyAI(diff);
        }

        private void btnOption_Click(object sender, EventArgs e)
        {
            OptionForm of = new OptionForm(lang,diff);
            of.ShowDialog();
            lang = of.lang;
            diff = of.diff;
            FormUI_Load(sender, e);
        }

        private void FormUI_Load(object sender, EventArgs e)
        {
            switch (lang)
            {
                case FormPlay.Language.ENG: btnPlay.Text = "Begin"; btnOption.Text = "Setting"; btnAbout.Text = "About us"; btnExit.Text = "Exit"; this.Text = lblTitle.Text = "Hold And Attack"; lblTitle.Left = 17; break;
                case FormPlay.Language.CNT: btnPlay.Text = "開始遊戲"; btnOption.Text = "調控選項"; btnAbout.Text = "關於我們"; btnExit.Text = "退出遊戲"; this.Text = lblTitle.Text = "屏鏜轟"; lblTitle.Left = 90; break;
                case FormPlay.Language.CNS: btnPlay.Text = "开始游戏"; btnOption.Text = "设置选项"; btnAbout.Text = "关于我们"; btnExit.Text = "退出游戏"; this.Text = lblTitle.Text = "屏镗波"; lblTitle.Left = 90; break;
                default: break;
            }
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void btnAbout_Click(object sender, EventArgs e)
        {
            AboutForm aboutform = new AboutForm(lang);
            aboutform.ShowDialog();
        }
    }
}

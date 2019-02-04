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


    public partial class HelpForm : Form
    {
        private string helpTxtENG = "";
        private string helpTxtCNT = "簡介：\n這是一款音樂類互動益智遊戲，玩家根據音樂的節奏（也即滑條的位置）來出招，達到益智益腦同時又享受音樂的雙重體驗。至於怎麼出招就是屏鏜轟的規則了。請看之下的介紹:\n\n規則：\n每位玩家有三個招數，屏、鏜、轟。\n“波”是攻擊，“波”一下對方如果對方是“屏”則對方減一點血。\n但是要轟，要有屏，且一一對應，屏一個能轟一個，屏兩個能轟兩個，以此類推。\n雙方是同時出招的。\n然而當一方“轟”一方“鏜”時，轟就被擋住了，不減血。對轟也是不減血的。\n鏜是能夠阻擋進攻,但是最多連鏜五下。";
        private string helpTxtCNS = "简介：\n这是一款音乐类互动益智游戏，玩家根据音乐的节奏（也即滑条的位置）来出招，达到益智益脑同时又享受音乐的双重体验。至于怎么出招就是屏镗波的规则了。请看之下的介绍:\n\n规则：\n每位玩家有三个招数，屏、镗、波。\n“波”是攻击，“波”一下对方如果对方是“屏”则对方扣一点血。\n但是要波，要有屏，且一一对应，屏一个能波一个，屏两个能波两个，以此类推。\n双方是同时出招的。\n然而当一方“波”一方“镗”时，波就被挡住了，不扣血。对波也是不扣血的。\n镗是能够阻挡进攻,但是最多连镗五下。";        

        public FormPlay.Language lang = FormPlay.Language.CNS;
        public HelpForm(FormPlay.Language lang)
        {
            InitializeComponent();
            this.lang = lang;
        }

        private void HelpForm_Load(object sender, EventArgs e)
        {
            switch (lang)
            {
                case FormPlay.Language.ENG: this.Text = "Help"; rtBoxHelp.Text = helpTxtENG; break;
                case FormPlay.Language.CNT: this.Text = "幫助"; rtBoxHelp.Text = helpTxtCNT; break;
                case FormPlay.Language.CNS: this.Text = "帮助"; rtBoxHelp.Text = helpTxtCNS; break;
                default: break;
            }
        }

        private void HelpForm_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void rtBoxHelp_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Escape || e.KeyCode == Keys.Enter) 
                this.Close();
            e.Handled = true;            
        }

        private void rtBoxHelp_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.H)
                this.Close();
            e.Handled = true;
        }
    }
}

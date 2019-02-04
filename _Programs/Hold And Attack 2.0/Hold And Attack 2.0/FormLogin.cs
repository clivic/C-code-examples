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
    public partial class FormLogin : Form
    {
        public static FormPlay.Language lang = FormPlay.Language.ENG;		// default language
        public string username = "";
        public string password = "";
        public long userID = int.MinValue;
        public bool hasLoggedInSuccessfully = false;

        FormLoginOK formLoginOK;

        public FormLogin()
        {
            InitializeComponent();
        }

        public FormLogin(FormPlay.Language l)
        {
            InitializeComponent();
            lang = l;
        }

        private void lblRes_MouseHover(object sender, EventArgs e)
        {
            lblRes.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
        }

        private void lblRes_MouseLeave(object sender, EventArgs e)
        {
            lblRes.ForeColor = System.Drawing.SystemColors.ActiveCaption;
        }

        private void lblForgetPw_MouseHover(object sender, EventArgs e)
        {
            lblForgetPw.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
        }

        private void lblForgetPw_MouseLeave(object sender, EventArgs e)
        {
            lblForgetPw.ForeColor = System.Drawing.SystemColors.ButtonShadow;
        }

        private void btnLogin_Click(object sender, EventArgs e)
        {
            // stub
            username = tbUser.Text;
            password = tbPassword.Text;
            //userID = 
            hasLoggedInSuccessfully = true;

            // dummy
            // 聯網登錄代碼寫於此

            if (hasLoggedInSuccessfully)
            {
                timerRedirect.Enabled = true;
                formLoginOK = new FormLoginOK();
                formLoginOK.ShowDialog();

                // dummy
                // 記錄好用戶輸入的賬號名與密鑰,記在那兩個成員變量上
            }
        }

        private void timerRedirect_Tick(object sender, EventArgs e)
        {
            if (formLoginOK != null)
            {
                formLoginOK.Close();
                timerRedirect.Enabled = false;
                this.Close();
            }
            else
                MessageBox.Show("ERROR: timer is enabled at wrong time!", "Error");
        }
    }
}

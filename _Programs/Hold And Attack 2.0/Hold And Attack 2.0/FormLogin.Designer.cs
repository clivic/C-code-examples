namespace Hold_And_Attack_2._0
{
    partial class FormLogin
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormLogin));
            this.lblWelcome = new System.Windows.Forms.Label();
            this.lblWelcome2 = new System.Windows.Forms.Label();
            this.tbUser = new System.Windows.Forms.TextBox();
            this.lblUser = new System.Windows.Forms.Label();
            this.tbPassword = new System.Windows.Forms.TextBox();
            this.lblPassword = new System.Windows.Forms.Label();
            this.lblResTip = new System.Windows.Forms.Label();
            this.lblRes = new System.Windows.Forms.Label();
            this.btnLogin = new System.Windows.Forms.Button();
            this.lblForgetPw = new System.Windows.Forms.Label();
            this.lblAbout = new System.Windows.Forms.Label();
            this.timerRedirect = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // lblWelcome
            // 
            this.lblWelcome.AutoSize = true;
            this.lblWelcome.Font = new System.Drawing.Font("微软雅黑", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lblWelcome.ForeColor = System.Drawing.Color.RoyalBlue;
            this.lblWelcome.Location = new System.Drawing.Point(12, 9);
            this.lblWelcome.Name = "lblWelcome";
            this.lblWelcome.Size = new System.Drawing.Size(293, 31);
            this.lblWelcome.TabIndex = 0;
            this.lblWelcome.Text = "歡迎遊玩屏鏜轟聯機對戰! ";
            // 
            // lblWelcome2
            // 
            this.lblWelcome2.AutoSize = true;
            this.lblWelcome2.Font = new System.Drawing.Font("微软雅黑", 13F);
            this.lblWelcome2.ForeColor = System.Drawing.Color.DodgerBlue;
            this.lblWelcome2.Location = new System.Drawing.Point(43, 53);
            this.lblWelcome2.Name = "lblWelcome2";
            this.lblWelcome2.Size = new System.Drawing.Size(226, 24);
            this.lblWelcome2.TabIndex = 1;
            this.lblWelcome2.Text = "現在請先登錄您的聯機賬戶";
            // 
            // tbUser
            // 
            this.tbUser.Location = new System.Drawing.Point(106, 91);
            this.tbUser.Name = "tbUser";
            this.tbUser.Size = new System.Drawing.Size(100, 21);
            this.tbUser.TabIndex = 2;
            // 
            // lblUser
            // 
            this.lblUser.AutoSize = true;
            this.lblUser.Location = new System.Drawing.Point(52, 94);
            this.lblUser.Name = "lblUser";
            this.lblUser.Size = new System.Drawing.Size(53, 12);
            this.lblUser.TabIndex = 3;
            this.lblUser.Text = "賬戶名稱";
            // 
            // tbPassword
            // 
            this.tbPassword.Location = new System.Drawing.Point(106, 120);
            this.tbPassword.Name = "tbPassword";
            this.tbPassword.PasswordChar = '*';
            this.tbPassword.Size = new System.Drawing.Size(100, 21);
            this.tbPassword.TabIndex = 4;
            // 
            // lblPassword
            // 
            this.lblPassword.AutoSize = true;
            this.lblPassword.Location = new System.Drawing.Point(52, 123);
            this.lblPassword.Name = "lblPassword";
            this.lblPassword.Size = new System.Drawing.Size(53, 12);
            this.lblPassword.TabIndex = 3;
            this.lblPassword.Text = "登錄密鑰";
            // 
            // lblResTip
            // 
            this.lblResTip.AutoSize = true;
            this.lblResTip.Font = new System.Drawing.Font("微软雅黑", 9F);
            this.lblResTip.ForeColor = System.Drawing.Color.CornflowerBlue;
            this.lblResTip.Location = new System.Drawing.Point(161, 153);
            this.lblResTip.Name = "lblResTip";
            this.lblResTip.Size = new System.Drawing.Size(62, 17);
            this.lblResTip.TabIndex = 5;
            this.lblResTip.Text = "沒有賬號?";
            // 
            // lblRes
            // 
            this.lblRes.AutoSize = true;
            this.lblRes.Font = new System.Drawing.Font("微软雅黑", 9F, System.Drawing.FontStyle.Underline);
            this.lblRes.ForeColor = System.Drawing.SystemColors.ActiveCaption;
            this.lblRes.Location = new System.Drawing.Point(225, 153);
            this.lblRes.Name = "lblRes";
            this.lblRes.Size = new System.Drawing.Size(80, 17);
            this.lblRes.TabIndex = 6;
            this.lblRes.Text = "前往激活產品";
            this.lblRes.MouseLeave += new System.EventHandler(this.lblRes_MouseLeave);
            this.lblRes.MouseHover += new System.EventHandler(this.lblRes_MouseHover);
            // 
            // btnLogin
            // 
            this.btnLogin.Location = new System.Drawing.Point(213, 91);
            this.btnLogin.Name = "btnLogin";
            this.btnLogin.Size = new System.Drawing.Size(53, 21);
            this.btnLogin.TabIndex = 7;
            this.btnLogin.Text = "登錄";
            this.btnLogin.UseVisualStyleBackColor = true;
            this.btnLogin.Click += new System.EventHandler(this.btnLogin_Click);
            // 
            // lblForgetPw
            // 
            this.lblForgetPw.AutoSize = true;
            this.lblForgetPw.Font = new System.Drawing.Font("微软雅黑", 9F, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lblForgetPw.ForeColor = System.Drawing.SystemColors.ButtonShadow;
            this.lblForgetPw.Location = new System.Drawing.Point(212, 124);
            this.lblForgetPw.Name = "lblForgetPw";
            this.lblForgetPw.Size = new System.Drawing.Size(62, 17);
            this.lblForgetPw.TabIndex = 8;
            this.lblForgetPw.Text = "忘記密鑰?";
            this.lblForgetPw.MouseLeave += new System.EventHandler(this.lblForgetPw_MouseLeave);
            this.lblForgetPw.MouseHover += new System.EventHandler(this.lblForgetPw_MouseHover);
            // 
            // lblAbout
            // 
            this.lblAbout.AutoSize = true;
            this.lblAbout.Font = new System.Drawing.Font("微软雅黑", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lblAbout.ForeColor = System.Drawing.Color.LightSteelBlue;
            this.lblAbout.Location = new System.Drawing.Point(173, 170);
            this.lblAbout.Name = "lblAbout";
            this.lblAbout.Size = new System.Drawing.Size(132, 17);
            this.lblAbout.TabIndex = 9;
            this.lblAbout.Text = "HA Corporation 2015";
            // 
            // timerRedirect
            // 
            this.timerRedirect.Interval = 1000;
            this.timerRedirect.Tick += new System.EventHandler(this.timerRedirect_Tick);
            // 
            // FormLogin
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(317, 202);
            this.Controls.Add(this.lblAbout);
            this.Controls.Add(this.lblForgetPw);
            this.Controls.Add(this.btnLogin);
            this.Controls.Add(this.lblRes);
            this.Controls.Add(this.lblResTip);
            this.Controls.Add(this.tbPassword);
            this.Controls.Add(this.lblPassword);
            this.Controls.Add(this.lblUser);
            this.Controls.Add(this.tbUser);
            this.Controls.Add(this.lblWelcome2);
            this.Controls.Add(this.lblWelcome);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "FormLogin";
            this.Text = "登錄HA賬戶";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblWelcome;
        private System.Windows.Forms.Label lblWelcome2;
        private System.Windows.Forms.TextBox tbUser;
        private System.Windows.Forms.Label lblUser;
        private System.Windows.Forms.TextBox tbPassword;
        private System.Windows.Forms.Label lblPassword;
        private System.Windows.Forms.Label lblResTip;
        private System.Windows.Forms.Label lblRes;
        private System.Windows.Forms.Button btnLogin;
        private System.Windows.Forms.Label lblForgetPw;
        private System.Windows.Forms.Label lblAbout;
        public System.Windows.Forms.Timer timerRedirect;
    }
}
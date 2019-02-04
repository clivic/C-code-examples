namespace Hold_And_Attack_2._0
{
    partial class FormPlay
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormPlay));
            this.timerSlider = new System.Windows.Forms.Timer(this.components);
            this.panelBar = new System.Windows.Forms.Panel();
            this.picBoxPosition = new System.Windows.Forms.PictureBox();
            this.picBoxSlider = new System.Windows.Forms.PictureBox();
            this.btnStart = new System.Windows.Forms.Button();
            this.lblHP1Name = new System.Windows.Forms.Label();
            this.lblHP1 = new System.Windows.Forms.Label();
            this.lblHP2Name = new System.Windows.Forms.Label();
            this.lblHP2 = new System.Windows.Forms.Label();
            this.timerDispResult = new System.Windows.Forms.Timer(this.components);
            this.lblText = new System.Windows.Forms.Label();
            this.timerText = new System.Windows.Forms.Timer(this.components);
            this.picBoxResultPlayer1 = new System.Windows.Forms.PictureBox();
            this.picBoxResultPlayer2 = new System.Windows.Forms.PictureBox();
            this.btnAttack = new System.Windows.Forms.Button();
            this.btnDefend = new System.Windows.Forms.Button();
            this.btnHold = new System.Windows.Forms.Button();
            this.panelHolds = new System.Windows.Forms.Panel();
            this.picBoxHold8 = new System.Windows.Forms.PictureBox();
            this.picBoxHold7 = new System.Windows.Forms.PictureBox();
            this.picBoxHold6 = new System.Windows.Forms.PictureBox();
            this.picBoxHold5 = new System.Windows.Forms.PictureBox();
            this.picBoxHold4 = new System.Windows.Forms.PictureBox();
            this.picBoxHold3 = new System.Windows.Forms.PictureBox();
            this.picBoxHold2 = new System.Windows.Forms.PictureBox();
            this.picBoxHold1 = new System.Windows.Forms.PictureBox();
            this.lblMoreHolds = new System.Windows.Forms.Label();
            this.imageListDisp = new System.Windows.Forms.ImageList(this.components);
            this.btnStop = new System.Windows.Forms.Button();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.MenuGame = new System.Windows.Forms.ToolStripMenuItem();
            this.TMenuRestart = new System.Windows.Forms.ToolStripMenuItem();
            this.TMenuSet = new System.Windows.Forms.ToolStripMenuItem();
            this.TMenuHelp = new System.Windows.Forms.ToolStripMenuItem();
            this.TMenuAbout = new System.Windows.Forms.ToolStripMenuItem();
            this.TMemuExit = new System.Windows.Forms.ToolStripMenuItem();
            this.panelBar.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxPosition)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxSlider)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxResultPlayer1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxResultPlayer2)).BeginInit();
            this.panelHolds.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxHold8)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxHold7)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxHold6)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxHold5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxHold4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxHold3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxHold2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxHold1)).BeginInit();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // timerSlider
            // 
            this.timerSlider.Enabled = true;
            this.timerSlider.Interval = 1;
            this.timerSlider.Tick += new System.EventHandler(this.timerSlider_Tick);
            // 
            // panelBar
            // 
            this.panelBar.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panelBar.Controls.Add(this.picBoxPosition);
            this.panelBar.Controls.Add(this.picBoxSlider);
            this.panelBar.Location = new System.Drawing.Point(119, 178);
            this.panelBar.Name = "panelBar";
            this.panelBar.Size = new System.Drawing.Size(325, 48);
            this.panelBar.TabIndex = 4;
            // 
            // picBoxPosition
            // 
            this.picBoxPosition.Image = ((System.Drawing.Image)(resources.GetObject("picBoxPosition.Image")));
            this.picBoxPosition.Location = new System.Drawing.Point(56, 0);
            this.picBoxPosition.Name = "picBoxPosition";
            this.picBoxPosition.Size = new System.Drawing.Size(40, 46);
            this.picBoxPosition.TabIndex = 4;
            this.picBoxPosition.TabStop = false;
            // 
            // picBoxSlider
            // 
            this.picBoxSlider.Image = global::Hold_And_Attack_2._0.Properties.Resources.Slider;
            this.picBoxSlider.Location = new System.Drawing.Point(281, 0);
            this.picBoxSlider.Name = "picBoxSlider";
            this.picBoxSlider.Size = new System.Drawing.Size(43, 48);
            this.picBoxSlider.TabIndex = 3;
            this.picBoxSlider.TabStop = false;
            // 
            // btnStart
            // 
            this.btnStart.Location = new System.Drawing.Point(335, 282);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(75, 23);
            this.btnStart.TabIndex = 1;
            this.btnStart.Text = "Start";
            this.btnStart.UseVisualStyleBackColor = true;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // lblHP1Name
            // 
            this.lblHP1Name.AutoSize = true;
            this.lblHP1Name.Location = new System.Drawing.Point(43, 433);
            this.lblHP1Name.Name = "lblHP1Name";
            this.lblHP1Name.Size = new System.Drawing.Size(29, 12);
            this.lblHP1Name.TabIndex = 7;
            this.lblHP1Name.Text = "HP: ";
            // 
            // lblHP1
            // 
            this.lblHP1.AutoSize = true;
            this.lblHP1.Location = new System.Drawing.Point(78, 432);
            this.lblHP1.Name = "lblHP1";
            this.lblHP1.Size = new System.Drawing.Size(0, 12);
            this.lblHP1.TabIndex = 8;
            // 
            // lblHP2Name
            // 
            this.lblHP2Name.AutoSize = true;
            this.lblHP2Name.Location = new System.Drawing.Point(440, 432);
            this.lblHP2Name.Name = "lblHP2Name";
            this.lblHP2Name.Size = new System.Drawing.Size(29, 12);
            this.lblHP2Name.TabIndex = 7;
            this.lblHP2Name.Text = "HP: ";
            // 
            // lblHP2
            // 
            this.lblHP2.AutoSize = true;
            this.lblHP2.Location = new System.Drawing.Point(462, 431);
            this.lblHP2.Name = "lblHP2";
            this.lblHP2.Size = new System.Drawing.Size(0, 12);
            this.lblHP2.TabIndex = 9;
            // 
            // timerDispResult
            // 
            this.timerDispResult.Interval = 1000;
            this.timerDispResult.Tick += new System.EventHandler(this.timerDispResult_Tick);
            // 
            // lblText
            // 
            this.lblText.AutoSize = true;
            this.lblText.Font = new System.Drawing.Font("微软雅黑", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lblText.Location = new System.Drawing.Point(138, 35);
            this.lblText.Name = "lblText";
            this.lblText.Size = new System.Drawing.Size(0, 31);
            this.lblText.TabIndex = 10;
            this.lblText.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // timerText
            // 
            this.timerText.Tick += new System.EventHandler(this.timerText_Tick);
            // 
            // picBoxResultPlayer1
            // 
            this.picBoxResultPlayer1.BackgroundImage = global::Hold_And_Attack_2._0.Properties.Resources.Default;
            this.picBoxResultPlayer1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.picBoxResultPlayer1.Location = new System.Drawing.Point(36, 81);
            this.picBoxResultPlayer1.Name = "picBoxResultPlayer1";
            this.picBoxResultPlayer1.Size = new System.Drawing.Size(90, 90);
            this.picBoxResultPlayer1.TabIndex = 12;
            this.picBoxResultPlayer1.TabStop = false;
            // 
            // picBoxResultPlayer2
            // 
            this.picBoxResultPlayer2.BackgroundImage = global::Hold_And_Attack_2._0.Properties.Resources.Default;
            this.picBoxResultPlayer2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.picBoxResultPlayer2.Location = new System.Drawing.Point(449, 81);
            this.picBoxResultPlayer2.Name = "picBoxResultPlayer2";
            this.picBoxResultPlayer2.Size = new System.Drawing.Size(90, 90);
            this.picBoxResultPlayer2.TabIndex = 11;
            this.picBoxResultPlayer2.TabStop = false;
            // 
            // btnAttack
            // 
            this.btnAttack.BackgroundImage = global::Hold_And_Attack_2._0.Properties.Resources.Attack;
            this.btnAttack.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btnAttack.Enabled = false;
            this.btnAttack.FlatAppearance.BorderSize = 0;
            this.btnAttack.Location = new System.Drawing.Point(41, 345);
            this.btnAttack.Name = "btnAttack";
            this.btnAttack.Size = new System.Drawing.Size(72, 72);
            this.btnAttack.TabIndex = 4;
            this.btnAttack.UseVisualStyleBackColor = true;
            this.btnAttack.Click += new System.EventHandler(this.btnAttack_Click);
            // 
            // btnDefend
            // 
            this.btnDefend.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btnDefend.BackgroundImage")));
            this.btnDefend.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btnDefend.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.btnDefend.FlatAppearance.BorderSize = 0;
            this.btnDefend.Location = new System.Drawing.Point(41, 267);
            this.btnDefend.Name = "btnDefend";
            this.btnDefend.Size = new System.Drawing.Size(72, 72);
            this.btnDefend.TabIndex = 3;
            this.btnDefend.UseVisualStyleBackColor = true;
            this.btnDefend.Click += new System.EventHandler(this.btnDefend_Click);
            // 
            // btnHold
            // 
            this.btnHold.BackgroundImage = global::Hold_And_Attack_2._0.Properties.Resources.Hold;
            this.btnHold.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btnHold.FlatAppearance.BorderSize = 0;
            this.btnHold.Location = new System.Drawing.Point(41, 189);
            this.btnHold.Name = "btnHold";
            this.btnHold.Size = new System.Drawing.Size(72, 72);
            this.btnHold.TabIndex = 2;
            this.btnHold.UseVisualStyleBackColor = true;
            this.btnHold.Click += new System.EventHandler(this.btnHold_Click);
            // 
            // panelHolds
            // 
            this.panelHolds.Controls.Add(this.picBoxHold8);
            this.panelHolds.Controls.Add(this.picBoxHold7);
            this.panelHolds.Controls.Add(this.picBoxHold6);
            this.panelHolds.Controls.Add(this.picBoxHold5);
            this.panelHolds.Controls.Add(this.picBoxHold4);
            this.panelHolds.Controls.Add(this.picBoxHold3);
            this.panelHolds.Controls.Add(this.picBoxHold2);
            this.panelHolds.Controls.Add(this.picBoxHold1);
            this.panelHolds.Location = new System.Drawing.Point(144, 383);
            this.panelHolds.Name = "panelHolds";
            this.panelHolds.Size = new System.Drawing.Size(300, 34);
            this.panelHolds.TabIndex = 13;
            // 
            // picBoxHold8
            // 
            this.picBoxHold8.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.picBoxHold8.Location = new System.Drawing.Point(267, 1);
            this.picBoxHold8.Name = "picBoxHold8";
            this.picBoxHold8.Size = new System.Drawing.Size(32, 32);
            this.picBoxHold8.TabIndex = 0;
            this.picBoxHold8.TabStop = false;
            // 
            // picBoxHold7
            // 
            this.picBoxHold7.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.picBoxHold7.Location = new System.Drawing.Point(229, 1);
            this.picBoxHold7.Name = "picBoxHold7";
            this.picBoxHold7.Size = new System.Drawing.Size(32, 32);
            this.picBoxHold7.TabIndex = 0;
            this.picBoxHold7.TabStop = false;
            // 
            // picBoxHold6
            // 
            this.picBoxHold6.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.picBoxHold6.Location = new System.Drawing.Point(190, 1);
            this.picBoxHold6.Name = "picBoxHold6";
            this.picBoxHold6.Size = new System.Drawing.Size(32, 32);
            this.picBoxHold6.TabIndex = 0;
            this.picBoxHold6.TabStop = false;
            // 
            // picBoxHold5
            // 
            this.picBoxHold5.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.picBoxHold5.Location = new System.Drawing.Point(152, 1);
            this.picBoxHold5.Name = "picBoxHold5";
            this.picBoxHold5.Size = new System.Drawing.Size(32, 32);
            this.picBoxHold5.TabIndex = 0;
            this.picBoxHold5.TabStop = false;
            // 
            // picBoxHold4
            // 
            this.picBoxHold4.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.picBoxHold4.Location = new System.Drawing.Point(114, 1);
            this.picBoxHold4.Name = "picBoxHold4";
            this.picBoxHold4.Size = new System.Drawing.Size(32, 32);
            this.picBoxHold4.TabIndex = 0;
            this.picBoxHold4.TabStop = false;
            // 
            // picBoxHold3
            // 
            this.picBoxHold3.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.picBoxHold3.Location = new System.Drawing.Point(76, 1);
            this.picBoxHold3.Name = "picBoxHold3";
            this.picBoxHold3.Size = new System.Drawing.Size(32, 32);
            this.picBoxHold3.TabIndex = 0;
            this.picBoxHold3.TabStop = false;
            // 
            // picBoxHold2
            // 
            this.picBoxHold2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.picBoxHold2.Location = new System.Drawing.Point(38, 1);
            this.picBoxHold2.Name = "picBoxHold2";
            this.picBoxHold2.Size = new System.Drawing.Size(32, 32);
            this.picBoxHold2.TabIndex = 0;
            this.picBoxHold2.TabStop = false;
            // 
            // picBoxHold1
            // 
            this.picBoxHold1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.picBoxHold1.Location = new System.Drawing.Point(0, 1);
            this.picBoxHold1.Name = "picBoxHold1";
            this.picBoxHold1.Size = new System.Drawing.Size(32, 32);
            this.picBoxHold1.TabIndex = 0;
            this.picBoxHold1.TabStop = false;
            // 
            // lblMoreHolds
            // 
            this.lblMoreHolds.AutoSize = true;
            this.lblMoreHolds.Font = new System.Drawing.Font("微软雅黑", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lblMoreHolds.Location = new System.Drawing.Point(450, 384);
            this.lblMoreHolds.Name = "lblMoreHolds";
            this.lblMoreHolds.Size = new System.Drawing.Size(0, 27);
            this.lblMoreHolds.TabIndex = 14;
            // 
            // imageListDisp
            // 
            this.imageListDisp.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageListDisp.ImageStream")));
            this.imageListDisp.TransparentColor = System.Drawing.Color.Transparent;
            this.imageListDisp.Images.SetKeyName(0, "Hold.bmp");
            this.imageListDisp.Images.SetKeyName(1, "Defend.bmp");
            this.imageListDisp.Images.SetKeyName(2, "Attack.bmp");
            this.imageListDisp.Images.SetKeyName(3, "Default.bmp");
            // 
            // btnStop
            // 
            this.btnStop.Enabled = false;
            this.btnStop.Location = new System.Drawing.Point(422, 282);
            this.btnStop.Name = "btnStop";
            this.btnStop.Size = new System.Drawing.Size(75, 23);
            this.btnStop.TabIndex = 15;
            this.btnStop.Text = "Give up";
            this.btnStop.UseVisualStyleBackColor = true;
            this.btnStop.Visible = false;
            this.btnStop.Click += new System.EventHandler(this.btnStop_Click);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.MenuGame});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(584, 25);
            this.menuStrip1.TabIndex = 17;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // MenuGame
            // 
            this.MenuGame.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.TMenuRestart,
            this.TMenuSet,
            this.TMenuHelp,
            this.TMenuAbout,
            this.TMemuExit});
            this.MenuGame.Name = "MenuGame";
            this.MenuGame.Size = new System.Drawing.Size(61, 21);
            this.MenuGame.Text = "游戏(&G)";
            // 
            // TMenuRestart
            // 
            this.TMenuRestart.Enabled = false;
            this.TMenuRestart.Name = "TMenuRestart";
            this.TMenuRestart.ShortcutKeys = System.Windows.Forms.Keys.F2;
            this.TMenuRestart.Size = new System.Drawing.Size(163, 22);
            this.TMenuRestart.Text = "重新开始(&R)";
            this.TMenuRestart.Click += new System.EventHandler(this.TMenuRestart_Click);
            // 
            // TMenuSet
            // 
            this.TMenuSet.Name = "TMenuSet";
            this.TMenuSet.ShortcutKeys = System.Windows.Forms.Keys.F1;
            this.TMenuSet.Size = new System.Drawing.Size(163, 22);
            this.TMenuSet.Text = "设置(&O)";
            this.TMenuSet.Click += new System.EventHandler(this.TMenuSet_Click);
            // 
            // TMenuHelp
            // 
            this.TMenuHelp.Name = "TMenuHelp";
            this.TMenuHelp.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.H)));
            this.TMenuHelp.Size = new System.Drawing.Size(163, 22);
            this.TMenuHelp.Text = "帮助(&H)";
            this.TMenuHelp.Click += new System.EventHandler(this.TMenuHelp_Click);
            // 
            // TMenuAbout
            // 
            this.TMenuAbout.Name = "TMenuAbout";
            this.TMenuAbout.Size = new System.Drawing.Size(163, 22);
            this.TMenuAbout.Text = "关于我们(&A)";
            this.TMenuAbout.Click += new System.EventHandler(this.TMenuAbout_Click);
            // 
            // TMemuExit
            // 
            this.TMemuExit.Name = "TMemuExit";
            this.TMemuExit.Size = new System.Drawing.Size(163, 22);
            this.TMemuExit.Text = "退出";
            this.TMemuExit.Click += new System.EventHandler(this.TMemuExit_Click);
            // 
            // FormPlay
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(584, 489);
            this.Controls.Add(this.menuStrip1);
            this.Controls.Add(this.btnStop);
            this.Controls.Add(this.lblMoreHolds);
            this.Controls.Add(this.panelHolds);
            this.Controls.Add(this.picBoxResultPlayer1);
            this.Controls.Add(this.picBoxResultPlayer2);
            this.Controls.Add(this.lblText);
            this.Controls.Add(this.lblHP2);
            this.Controls.Add(this.lblHP1);
            this.Controls.Add(this.lblHP2Name);
            this.Controls.Add(this.lblHP1Name);
            this.Controls.Add(this.btnStart);
            this.Controls.Add(this.panelBar);
            this.Controls.Add(this.btnAttack);
            this.Controls.Add(this.btnDefend);
            this.Controls.Add(this.btnHold);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "FormPlay";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "屏鏜轟";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.FormPlay_FormClosing);
            this.Load += new System.EventHandler(this.FormPlay_Load);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.FormPlay_KeyUp);
            this.panelBar.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.picBoxPosition)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxSlider)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxResultPlayer1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxResultPlayer2)).EndInit();
            this.panelHolds.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.picBoxHold8)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxHold7)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxHold6)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxHold5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxHold4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxHold3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxHold2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxHold1)).EndInit();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnHold;
        private System.Windows.Forms.Button btnDefend;
        private System.Windows.Forms.Button btnAttack;
        private System.Windows.Forms.PictureBox picBoxSlider;
        private System.Windows.Forms.Timer timerSlider;
        private System.Windows.Forms.Panel panelBar;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Label lblHP1Name;
        private System.Windows.Forms.Label lblHP1;
        private System.Windows.Forms.Label lblHP2Name;
        private System.Windows.Forms.Label lblHP2;
        private System.Windows.Forms.PictureBox picBoxPosition;
        private System.Windows.Forms.Timer timerDispResult;
        private System.Windows.Forms.Label lblText;
        private System.Windows.Forms.Timer timerText;
        private System.Windows.Forms.PictureBox picBoxResultPlayer2;
        private System.Windows.Forms.PictureBox picBoxResultPlayer1;
        private System.Windows.Forms.Panel panelHolds;
        private System.Windows.Forms.PictureBox picBoxHold8;
        private System.Windows.Forms.PictureBox picBoxHold7;
        private System.Windows.Forms.PictureBox picBoxHold6;
        private System.Windows.Forms.PictureBox picBoxHold5;
        private System.Windows.Forms.PictureBox picBoxHold4;
        private System.Windows.Forms.PictureBox picBoxHold3;
        private System.Windows.Forms.PictureBox picBoxHold2;
        private System.Windows.Forms.PictureBox picBoxHold1;
        private System.Windows.Forms.Label lblMoreHolds;
        private System.Windows.Forms.ImageList imageListDisp;
        private System.Windows.Forms.Button btnStop;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem MenuGame;
        private System.Windows.Forms.ToolStripMenuItem TMenuRestart;
        private System.Windows.Forms.ToolStripMenuItem TMenuSet;
        private System.Windows.Forms.ToolStripMenuItem TMenuHelp;
        private System.Windows.Forms.ToolStripMenuItem TMenuAbout;
        private System.Windows.Forms.ToolStripMenuItem TMemuExit;
    }
}
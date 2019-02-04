namespace Hold_And_Attack_2._0
{
    partial class OptionForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(OptionForm));
            this.rBENG = new System.Windows.Forms.RadioButton();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.rBCNS = new System.Windows.Forms.RadioButton();
            this.rBCNT = new System.Windows.Forms.RadioButton();
            this.lblLang = new System.Windows.Forms.Label();
            this.lblDiff = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.rBHard = new System.Windows.Forms.RadioButton();
            this.rBNormal = new System.Windows.Forms.RadioButton();
            this.rBEasy = new System.Windows.Forms.RadioButton();
            this.btnOK = new System.Windows.Forms.Button();
            this.btnCancel = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // rBENG
            // 
            this.rBENG.AutoSize = true;
            this.rBENG.Location = new System.Drawing.Point(19, 19);
            this.rBENG.Name = "rBENG";
            this.rBENG.Size = new System.Drawing.Size(65, 16);
            this.rBENG.TabIndex = 0;
            this.rBENG.Text = "English";
            this.rBENG.UseVisualStyleBackColor = true;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.rBCNS);
            this.groupBox1.Controls.Add(this.rBCNT);
            this.groupBox1.Controls.Add(this.rBENG);
            this.groupBox1.Location = new System.Drawing.Point(57, 49);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(134, 96);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            // 
            // rBCNS
            // 
            this.rBCNS.AutoSize = true;
            this.rBCNS.Checked = true;
            this.rBCNS.Location = new System.Drawing.Point(19, 69);
            this.rBCNS.Name = "rBCNS";
            this.rBCNS.Size = new System.Drawing.Size(71, 16);
            this.rBCNS.TabIndex = 2;
            this.rBCNS.TabStop = true;
            this.rBCNS.Text = "中文简体";
            this.rBCNS.UseVisualStyleBackColor = true;
            // 
            // rBCNT
            // 
            this.rBCNT.AutoSize = true;
            this.rBCNT.Location = new System.Drawing.Point(19, 44);
            this.rBCNT.Name = "rBCNT";
            this.rBCNT.Size = new System.Drawing.Size(71, 16);
            this.rBCNT.TabIndex = 1;
            this.rBCNT.Text = "中文繁體";
            this.rBCNT.UseVisualStyleBackColor = true;
            // 
            // lblLang
            // 
            this.lblLang.AutoSize = true;
            this.lblLang.Font = new System.Drawing.Font("微软雅黑", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lblLang.Location = new System.Drawing.Point(58, 26);
            this.lblLang.Name = "lblLang";
            this.lblLang.Size = new System.Drawing.Size(72, 27);
            this.lblLang.TabIndex = 2;
            this.lblLang.Text = "语言：";
            // 
            // lblDiff
            // 
            this.lblDiff.AutoSize = true;
            this.lblDiff.Font = new System.Drawing.Font("微软雅黑", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lblDiff.Location = new System.Drawing.Point(59, 167);
            this.lblDiff.Name = "lblDiff";
            this.lblDiff.Size = new System.Drawing.Size(72, 27);
            this.lblDiff.TabIndex = 4;
            this.lblDiff.Text = "难度：";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.rBHard);
            this.groupBox2.Controls.Add(this.rBNormal);
            this.groupBox2.Controls.Add(this.rBEasy);
            this.groupBox2.Location = new System.Drawing.Point(58, 190);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(134, 96);
            this.groupBox2.TabIndex = 3;
            this.groupBox2.TabStop = false;
            // 
            // rBHard
            // 
            this.rBHard.AutoSize = true;
            this.rBHard.Location = new System.Drawing.Point(19, 69);
            this.rBHard.Name = "rBHard";
            this.rBHard.Size = new System.Drawing.Size(47, 16);
            this.rBHard.TabIndex = 2;
            this.rBHard.Text = "困难";
            this.rBHard.UseVisualStyleBackColor = true;
            // 
            // rBNormal
            // 
            this.rBNormal.AutoSize = true;
            this.rBNormal.Checked = true;
            this.rBNormal.Location = new System.Drawing.Point(19, 44);
            this.rBNormal.Name = "rBNormal";
            this.rBNormal.Size = new System.Drawing.Size(47, 16);
            this.rBNormal.TabIndex = 1;
            this.rBNormal.TabStop = true;
            this.rBNormal.Text = "正常";
            this.rBNormal.UseVisualStyleBackColor = true;
            // 
            // rBEasy
            // 
            this.rBEasy.AutoSize = true;
            this.rBEasy.Location = new System.Drawing.Point(19, 19);
            this.rBEasy.Name = "rBEasy";
            this.rBEasy.Size = new System.Drawing.Size(47, 16);
            this.rBEasy.TabIndex = 0;
            this.rBEasy.Text = "简单";
            this.rBEasy.UseVisualStyleBackColor = true;
            // 
            // btnOK
            // 
            this.btnOK.Location = new System.Drawing.Point(248, 80);
            this.btnOK.Name = "btnOK";
            this.btnOK.Size = new System.Drawing.Size(83, 44);
            this.btnOK.TabIndex = 5;
            this.btnOK.Text = "确认";
            this.btnOK.UseVisualStyleBackColor = true;
            this.btnOK.Click += new System.EventHandler(this.btnOK_Click);
            // 
            // btnCancel
            // 
            this.btnCancel.Location = new System.Drawing.Point(248, 215);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(83, 44);
            this.btnCancel.TabIndex = 6;
            this.btnCancel.Text = "取消";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // OptionForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(360, 358);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnOK);
            this.Controls.Add(this.lblDiff);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.lblLang);
            this.Controls.Add(this.groupBox1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "OptionForm";
            this.Text = "OptionForm";
            this.Load += new System.EventHandler(this.OptionForm_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RadioButton rBENG;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton rBCNS;
        private System.Windows.Forms.RadioButton rBCNT;
        private System.Windows.Forms.Label lblLang;
        private System.Windows.Forms.Label lblDiff;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.RadioButton rBHard;
        private System.Windows.Forms.RadioButton rBNormal;
        private System.Windows.Forms.RadioButton rBEasy;
        private System.Windows.Forms.Button btnOK;
        private System.Windows.Forms.Button btnCancel;
    }
}
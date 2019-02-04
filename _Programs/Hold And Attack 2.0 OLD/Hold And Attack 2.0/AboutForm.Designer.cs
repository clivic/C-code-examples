namespace Hold_And_Attack_2._0
{
    partial class AboutForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(AboutForm));
            this.pBIcon = new System.Windows.Forms.PictureBox();
            this.lblVersion = new System.Windows.Forms.Label();
            this.lblCom = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pBIcon)).BeginInit();
            this.SuspendLayout();
            // 
            // pBIcon
            // 
            this.pBIcon.BackgroundImage = global::Hold_And_Attack_2._0.Properties.Resources.Default;
            this.pBIcon.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pBIcon.Location = new System.Drawing.Point(12, 12);
            this.pBIcon.Name = "pBIcon";
            this.pBIcon.Size = new System.Drawing.Size(85, 81);
            this.pBIcon.TabIndex = 0;
            this.pBIcon.TabStop = false;
            // 
            // lblVersion
            // 
            this.lblVersion.AutoSize = true;
            this.lblVersion.Font = new System.Drawing.Font("微软雅黑", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lblVersion.Location = new System.Drawing.Point(112, 12);
            this.lblVersion.Name = "lblVersion";
            this.lblVersion.Size = new System.Drawing.Size(282, 27);
            this.lblVersion.TabIndex = 1;
            this.lblVersion.Text = "Hold And Attack Version 2.0";
            // 
            // lblCom
            // 
            this.lblCom.AutoSize = true;
            this.lblCom.Font = new System.Drawing.Font("微软雅黑 Light", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lblCom.Location = new System.Drawing.Point(117, 54);
            this.lblCom.Name = "lblCom";
            this.lblCom.Size = new System.Drawing.Size(202, 27);
            this.lblCom.TabIndex = 2;
            this.lblCom.Text = "H&A Corporation 2015";
            // 
            // AboutForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(401, 120);
            this.Controls.Add(this.lblCom);
            this.Controls.Add(this.lblVersion);
            this.Controls.Add(this.pBIcon);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "AboutForm";
            this.Text = "AboutForm";
            this.Load += new System.EventHandler(this.AboutForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pBIcon)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pBIcon;
        private System.Windows.Forms.Label lblVersion;
        private System.Windows.Forms.Label lblCom;
    }
}
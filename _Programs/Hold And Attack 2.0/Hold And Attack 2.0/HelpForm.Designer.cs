namespace Hold_And_Attack_2._0
{
    partial class HelpForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(HelpForm));
            this.rtBoxHelp = new System.Windows.Forms.RichTextBox();
            this.SuspendLayout();
            // 
            // rtBoxHelp
            // 
            this.rtBoxHelp.Font = new System.Drawing.Font("微软雅黑", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.rtBoxHelp.Location = new System.Drawing.Point(11, 7);
            this.rtBoxHelp.Name = "rtBoxHelp";
            this.rtBoxHelp.ReadOnly = true;
            this.rtBoxHelp.Size = new System.Drawing.Size(295, 272);
            this.rtBoxHelp.TabIndex = 0;
            this.rtBoxHelp.Text = resources.GetString("rtBoxHelp.Text");
            this.rtBoxHelp.KeyDown += new System.Windows.Forms.KeyEventHandler(this.rtBoxHelp_KeyDown);
            this.rtBoxHelp.KeyUp += new System.Windows.Forms.KeyEventHandler(this.rtBoxHelp_KeyUp);
            // 
            // HelpForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(316, 284);
            this.Controls.Add(this.rtBoxHelp);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "HelpForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "HelpForm";
            this.Load += new System.EventHandler(this.HelpForm_Load);
            this.Click += new System.EventHandler(this.HelpForm_Click);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.RichTextBox rtBoxHelp;

    }
}
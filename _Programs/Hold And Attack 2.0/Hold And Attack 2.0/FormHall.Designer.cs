namespace Hold_And_Attack_2._0
{
    partial class FormHall
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormHall));
            this.listView1 = new System.Windows.Forms.ListView();
            this.colhID = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colhName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colhPing = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.lblWelcome = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // listView1
            // 
            this.listView1.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colhID,
            this.colhName,
            this.colhPing});
            this.listView1.Location = new System.Drawing.Point(188, 44);
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(348, 278);
            this.listView1.TabIndex = 0;
            this.listView1.UseCompatibleStateImageBehavior = false;
            // 
            // colhID
            // 
            this.colhID.Text = "玩家ID";
            this.colhID.Width = 120;
            // 
            // colhName
            // 
            this.colhName.Text = "名稱";
            this.colhName.Width = 120;
            // 
            // colhPing
            // 
            this.colhPing.Text = "網路延遲";
            // 
            // lblWelcome
            // 
            this.lblWelcome.AutoSize = true;
            this.lblWelcome.Location = new System.Drawing.Point(14, 15);
            this.lblWelcome.Name = "lblWelcome";
            this.lblWelcome.Size = new System.Drawing.Size(41, 12);
            this.lblWelcome.TabIndex = 1;
            this.lblWelcome.Text = "歡迎 !";
            // 
            // FormHall
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(548, 464);
            this.Controls.Add(this.lblWelcome);
            this.Controls.Add(this.listView1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "FormHall";
            this.Text = "聯網對戰大廳";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListView listView1;
        protected System.Windows.Forms.ColumnHeader colhID;
        protected System.Windows.Forms.ColumnHeader colhName;
        private System.Windows.Forms.ColumnHeader colhPing;
        private System.Windows.Forms.Label lblWelcome;
    }
}
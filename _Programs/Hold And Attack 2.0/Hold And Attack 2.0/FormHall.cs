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
    public partial class FormHall : Form
    {
        public FormPlay.Language lang = FormPlay.Language.CNS;
        public long userID = int.MinValue;
        public string username = "";
        FormPlay.Mode mode = FormPlay.Mode.PVP;

        public FormHall()
        {
            InitializeComponent();
        }

        public FormHall(long uID, string uName, FormPlay.Mode m, FormPlay.Language l)
        {
            InitializeComponent();
            userID = uID;
            username = uName;
            mode = m;   // Should always be PVP
            lang = l;
            UpdateDisplay();
        }

        public void UpdateDisplay()
        {
            lblWelcome.Text = "歡迎 " + username + "!";
        }

        public void InitializeList()
        {
            //this.listView1.Columns.Add("列标题1", 120, HorizontalAlignment.Left); //一步添加 
        }
    }
}

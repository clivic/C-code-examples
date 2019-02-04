using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace Hold_And_Attack_2._0
{
    public partial class FormPlay : Form
    {
        // 計時器相關
        int sliderSpeed = 2;                // 單位: pixel/ms
        bool start = false;
        Point posSliderIni;                  // 滑動塊初始位置 
        int ableLen = 50;               // 多少長度是按了按鈕有反應的
        int ableStart = 0;              // 按了有反應的區間的左邊X坐標

        // 屏鏜轟按按鈕相關
        bool canPress = false;          // 是否到了該按的地方可以按了
        bool hasPressed = false;        // 是否在可以按的時候按過了

        bool canDefend = true;
        bool canAttack = false;

        bool hasStarted = false;        // 控制start按鈕的顯示和功能
        bool hasPaused = false;

        // 生命值顯示相關
        int maxHealth = Player.HEALTH_DEFAULT;
        int harmValue = 1;              // 一下Attack扣多少血

        // 顯示結果相關
        FormResult formResult;
        string res = "";                     // 記錄戰鬥結果,邊戰鬥邊記錄
        string indent = "      ";        // 左右玩家的操作的顯示間距
        int indentPos = 0;                  // 對齊的位置

        // 播放音樂相關
        public static string gameDir = System.Environment.CurrentDirectory;   // 遊戲可執行文件所在檔案夾
        public static string musicDir = gameDir + @"\Music";   // 遊戲音樂所在檔案夾
        int textTip = 0;                // 準備時期的文字序號
        int numPre = 4;                 // 準備時期的圖片當前序號

        // 屏鏜轟主類的屬性
        public enum Mode { PVP, PVE };
        public enum Language { ENG, CNT, CNS };

        public enum PlayerID { LEFT, RIGHT };   // 用來指明是哪個玩家,用於PVP
        
        public Player leftP;			// Player 1, in PVE, it represents the person
        public Player rightP;			// Player 2, in PVE, it represents the computer
        Mode mode = Mode.PVE;
        Personality pntyAI = Personality.DEFAULT;
        Language lang = Language.ENG;		// default language
        Operation leftOp = Operation.HOLD;  // default operation
        Operation rightOp = Operation.HOLD; // default operation
        

        public FormPlay()
        {
            InitializeComponent();
            InitializePlaying();  
        }

        public FormPlay(Mode m, Personality p, Language l)
        {
            InitializeComponent();
            InitializePlaying(m, p, l);  
        }

        private void FormPlay_Load(object sender, EventArgs e)
        {
            switch (lang)
            {
                case Language.ENG: btnStart.Text = "Start"; btnStop.Text = "Give up"; this.Text = "Hold And Attack";
                                   menuStrip1.Items[0].Text = "Game(&G)";
                                   foreach(ToolStripMenuItem item in menuStrip1.Items)
                                   {
                                       item.DropDownItems[0].Text = "Restart";
                                       item.DropDownItems[1].Text = "Set";
                                       item.DropDownItems[2].Text = "Help";
                                       item.DropDownItems[3].Text = "About us";
                                       item.DropDownItems[4].Text = "Exit";
                                   }break;
                case Language.CNT: btnStart.Text = "開始"; btnStop.Text = "放棄"; this.Text = "屏鏜轟";
                                   menuStrip1.Items[0].Text = "遊戲(&G)";
                                   foreach(ToolStripMenuItem item in menuStrip1.Items)
                                   {
                                       item.DropDownItems[0].Text = "重新開始";
                                       item.DropDownItems[1].Text = "設置";
                                       item.DropDownItems[2].Text = "幫助";
                                       item.DropDownItems[3].Text = "關於我們";
                                       item.DropDownItems[4].Text = "退出";
                                   }break;
                case Language.CNS: btnStart.Text = "开始"; btnStop.Text = "放弃"; this.Text = "屏鏜波";
                                   menuStrip1.Items[0].Text = "游戏(&G)";
                                   foreach(ToolStripMenuItem item in menuStrip1.Items)
                                   {
                                       item.DropDownItems[0].Text = "重新开始";
                                       item.DropDownItems[1].Text = "设置";
                                       item.DropDownItems[2].Text = "帮助";
                                       item.DropDownItems[3].Text = "关于我们";
                                       item.DropDownItems[4].Text = "退出";
                                   }break;
                default: break;
            }
        }

        private void InitializePlaying()
        {
            InitializePlaying(Mode.PVE, Personality.DEFAULT, Language.CNS);
        }

        private void InitializePlaying(Mode m, Personality p, Language l)
        {
            // 獲取滑動塊初始位置並置頂
            posSliderIni = picBoxSlider.Location;
            picBoxSlider.BringToFront();

            // 參數初始化
            mode = m;
            pntyAI = p;
            lang = l;

            // 遊玩結構初始化
            leftP = new Player();
            rightP = new Player();
            InitializeName();
            canPress = false;
            hasPressed = false;
            leftOp = Operation.HOLD;
            rightOp = Operation.HOLD;
            canDefend = true;
            canAttack = false;
            ableLen = picBoxSlider.Location.X + picBoxSlider.Size.Width + 50;  // 多少長度是按了按鈕有反應的
            ableStart = 0;
            this.KeyPreview = true; // 可以讓鍵盤響應按鈕
            hasStarted = false;
            hasPaused = false;
            String lf = "";
            String rg = "";
            switch (lang)
            {
                case Language.ENG: lf = "Left Player: "; rg = "Right Player: "; break;
                case Language.CNT: lf = "左邊玩家: "; rg = "右邊玩家: "; break;
                case Language.CNS: lf = "左边玩家: "; rg = "右边玩家: "; break;
                default: break;
            }
            // 遊戲記錄初始化
            res = lf + leftP.GetPlName() + indent + rg + rightP.GetPlName() + "\n";
           // indentPos = res.IndexOf('右');
            switch (lang)
            {
                case Language.ENG: indentPos = res.IndexOf('R'); break;
                case Language.CNT: indentPos = res.IndexOf('右'); break;
                case Language.CNS: indentPos = res.IndexOf('右'); break;
                default: break;
            }

            // 玩家生命顯示初始化
            maxHealth = Player.HEALTH_DEFAULT;
            lblHP1.Text = leftP.GetHealth().ToString() + "/" + maxHealth;
            lblHP2.Text = rightP.GetHealth().ToString() + "/" + maxHealth;

            // 準備fight時期的準備工作
            textTip = 0;
            numPre = 4;
        }

        public void InitializeName()
        // 初始化兩個玩家名稱,人對電腦的話名稱就是玩家名和電腦默認名,人對人就是兩個玩家名.
        {
            leftP.Clear();
            rightP.Clear();
            if (mode == Mode.PVE)
            {
                // retrive system username as player's name
                string username = "Player";
                string comname = "Computer";
                switch (lang)
                {
                    case Language.ENG: username = "Player"; comname = "Computer"; break;
                    case Language.CNT: username = "玩家"; comname = "電腦"; break;
                    case Language.CNS: username = "玩家"; comname = "电脑"; break;
                    default: break;
                }
             //   char[] szUser = new char[80];
              //  int cbUser = 80;
                //if (GetUserNameA(szUser, &cbUser))	
                //    username = szUser;
                //else	
               // username = "Player";
                leftP.SetPlName(username);

                rightP.SetPlName(comname);
            }
            else
            {
                leftP.SetPlName("Player1");
                rightP.SetPlName("Player2");
            }

        }

        public void Clear()
        {
            // 滑動塊放回去
            picBoxSlider.Location = posSliderIni;

            // 遊玩結構恢復預設
            leftP.Clear();
            rightP.Clear();
            InitializeName();
            canPress = false;
            hasPressed = false;
            leftOp = Operation.HOLD;
            rightOp = Operation.HOLD;
            canDefend = true;
            canAttack = false;
            this.KeyPreview = true; // 可以讓鍵盤響應按鈕
            hasStarted = false;
            hasPaused = false;

            //// 遊戲記錄恢復預設
            //res = "左邊玩家: " + leftP.GetPlName() + indent + "右邊玩家: " + rightP.GetPlName() + "\n";
            //indentPos = res.IndexOf('右');
            String lf = "";
            String rg = "";
            switch (lang)
            {
                case Language.ENG: lf = "Left Player: "; rg = "Right Player: "; break;
                case Language.CNT: lf = "左邊玩家: "; rg = "右邊玩家: "; break;
                case Language.CNS: lf = "左边玩家: "; rg = "右边玩家: "; break;
                default: break;
            }
            // 遊戲記錄初始化
            res = lf + leftP.GetPlName() + indent + rg + rightP.GetPlName() + "\n";
            // indentPos = res.IndexOf('右');
            switch (lang)
            {
                case Language.ENG: indentPos = res.IndexOf('R'); break;
                case Language.CNT: indentPos = res.IndexOf('右'); break;
                case Language.CNS: indentPos = res.IndexOf('右'); break;
                default: break;
            }
            // 玩家生命顯示初始化
            lblHP1.Text = leftP.GetHealth().ToString() + "/" + maxHealth;
            lblHP2.Text = rightP.GetHealth().ToString() + "/" + maxHealth;

            // 準備Fight的計數器清零
            textTip = 0;
            numPre = 4;

            BtnCanNotGiveUp();              // 投降按鈕重新不可見
        }

        public void Fight()
        {
            Clear();
            MusicPlay.Play("Deliverence.mp3");
            ReadyForFight(165);
            timerSlider.Enabled = true;
            DisplayHold();      // 這時屏數是0,可以理解為清空之前的屏數
        }

        public void ReadyForFight(double bpm)
        {
            int interval = (int)(HAMath.BeatsToSeconds(4, bpm) * 1000);
            timerText.Interval = interval;
            timerText.Enabled = true;
            SetSliderSpeed(bpm);
            
            switch (lang)
            {
                case Language.ENG: lblText.Text = "Welcome to play Hold And Attack!"; break;
                case Language.CNT: lblText.Text = "歡迎遊玩屏鏜轟!"; break;
                case Language.CNS: lblText.Text = "欢迎来玩屏镗波"; break;
                default: break;
            }
        }

        public void ReadyPicRandom()
        //  Pre:    要用PictureListDisp, 並且序號範圍和隨機函數產生值一致
        //  Post:   在準備遊戲的過程中讓圖片隨機在Hold, Defend, Attack, Default里變換
        {
            Random r = new Random();
            int num;
            try
            {
                do
                {
                    num = r.Next(4);
                } while (num == numPre);
                picBoxResultPlayer1.BackgroundImage = imageListDisp.Images[num];
                picBoxResultPlayer2.BackgroundImage = imageListDisp.Images[num];
                numPre = num;
            }
            catch
            {
                MessageBox.Show("Error: 隨機數超出範圍（應該是0123）", "Error");
                Application.Exit();
            }
        }

        public void SetSliderSpeed(double bpm)
        {
            int offset = 1;
            sliderSpeed = (int)((double)(panelBar.Size.Width) / HAMath.BeatsToSeconds(0.25, bpm) / 1000);
            if (sliderSpeed > 0) sliderSpeed -= offset;
            else sliderSpeed = 1;
        }

        public string PrintRev()
        //	Post:   按照每行左邊、右邊然後指出誰得分的方式打印并返回一段文本
        {

            // 檢驗
            if (leftP.storage.Count != rightP.storage.Count)
                MessageBox.Show("Error! 左右竟然操作數不同!", "Error");

            // 通過檢驗,保證左右操作數相同
            return res;
        }

        protected void KeepRecord(Operation lOp, Operation rOp, int value)
        //  Pre;    先Act()再Record
        //  Post:   按照每行左邊、右邊然後指出誰得分的方式存儲在記錄string: res中
        //          並且在屏的顯示條中也增加或減少屏的個數顯示(調用DisplayHold())
        {
            // 記錄戰績
            int indexOffset = 3;
            string att = "";
            switch (lang)
            {
                case Language.ENG: indexOffset = 0; att = "Attack"; break;
                case Language.CNT: indexOffset = 3; att = "進攻! "; break;
                case Language.CNS: indexOffset = 3; att = "进攻! "; break;
                default: break;
            }
            res += OpToStr(lOp).PadRight(indentPos + indexOffset) + OpToStr(rOp);
            if (lOp == Operation.ATTACK && rOp == Operation.HOLD)
                res += "   <- " + leftP.GetPlName() + att + rightP.GetPlName() + "HP - " + value + "\t" + leftP.GetHealth() + " : " + rightP.GetHealth() + "\n";
            else if (rOp == Operation.ATTACK && lOp == Operation.HOLD)
                res += "   <- " + rightP.GetPlName() + att + leftP.GetPlName() + "HP - " + value + "\t" + leftP.GetHealth() + " : " + rightP.GetHealth() + "\n";
            else
                res += "\n";

            // 更新屏的顯示(只有在單人模式可用!)
            if(mode == Mode.PVE)
                DisplayHold();
        }

        protected void AddRecoredGiveUp(PlayerID winner)
        //  Post:   輸出左邊玩家的投降的記錄信息
        {
            string to = "";
            string ed = "";
            switch (lang)
            {
                case Language.ENG: to = " surrenders to "; ed = "! Game Over!\n"; break;
                case Language.CNT: to = "向"; ed = "投降! 遊戲結束!\n"; break;
                case Language.CNS: to = "向"; ed = "投降! 游戏结束!\n"; break;
                default: break;
            }
            if(winner == PlayerID.RIGHT)
            {
                res += leftP.GetPlName() + to + rightP.GetPlName() + ed;
            }
            else
            {
                res += rightP.GetPlName() + to + leftP.GetPlName() + ed;
            }
        }

        private void DisplayHold()
        //  Pre:    先Act()再Display && mode == PVE && player是left && panelHolds里祗有pictureBox
        //  Post:   在屏的顯示條中也增加或減少屏的個數顯示
        {
            int numHold = leftP.GetNumHold();
            if(numHold <= panelHolds.Controls.Count)
            {
                foreach (Control c in panelHolds.Controls)
                    c.BackgroundImage = null;
                for (int i = 0; i < numHold; i++ )
                    panelHolds.Controls[panelHolds.Controls.Count - 1 - i].BackgroundImage = 
                        global::Hold_And_Attack_2._0.Properties.Resources.Hold;
                lblMoreHolds.Text = "";
            }
            else
            {
                foreach (Control c in panelHolds.Controls)
                    c.BackgroundImage = global::Hold_And_Attack_2._0.Properties.Resources.Hold;
                lblMoreHolds.Text = "+" + (numHold - panelHolds.Controls.Count).ToString();
            
            }

        }

        protected string OpToStr(Operation op)
        //  Pre:    傳進來的op只能是屏鏜轟,ERROR_CODE和ATTACK_FAIL不能傳進來,否則此函數會忽略他們返回空值
        //  Post:   根據對應op,返回操作
        {
            switch(op)
            {
                case Operation.HOLD:
                    switch (lang)
                    {
                        case Language.ENG: return "Hold";
                        case Language.CNT: return "屏";
                        case Language.CNS: return "屏";
                        default: return "";
                    }
                case Operation.DEFENSE:
                    //return "鏜";
                    switch (lang)
                    {
                        case Language.ENG: return "Defend";
                        case Language.CNT: return "鏜";
                        case Language.CNS: return "镗";
                        default: return "";
                    }
                case Operation.ATTACK:
                   // return "轟";
                    switch (lang)
                    {
                        case Language.ENG: return "Attack";
                        case Language.CNT: return "轟";
                        case Language.CNS: return "波";
                        default: return "";
                    }
                default:
                    return "";
            }
        }

        public void SetMode(Mode m)
        {
            mode = m;
        }

        public void SetPntyAI(Personality d)
        {
            pntyAI = d;
        }

        public void SetLang(Language l)
        {
            lang = l;
        }

        public Language GetLang()
        {
            return lang;
        }

        protected Operation E_Decide()
        {
            // pass the choice to Judge() (return the choice)
            return rightP.AI_Decide(leftP, pntyAI);

        }

        protected void ErrorDetecter(Operation op, Player player)
        //	Post:	detect error and output them
        {
            switch (op)
            {
                case Operation.ATTACK_FAIL:
                    // force to hold
                    // this should not happen in game in general, thus no translation
                    //tbOutput.Text = "No HOLDs, change ATTACK to HOLD.";
                    player.Act(Operation.HOLD);
                    op = Operation.HOLD;
                    break;

                case Operation.ERROR_CODE:
                    // output ERROR INFO and abort the program
                    // !!this should not be possible to happen in game instead of debugging!!
                  //  tbOutput.Text = "Error detected during the calculation, game aborted.";
                    Application.Exit();
                    break;

                case Operation.INPUT_FAIL:
                    // output ERROR INFO and abort the program
                    // !!this should not be possible to happen in game instead of debugging!!
                   // tbOutput.Text = "invalid input, game aborted.";
                    Application.Exit();
                    break;

                default:		// not Error Operation
                    return;
            }
        }

        protected void Judge(Operation rp, Operation lp)
        //	Pre:	
        //	Post:	先檢測合法性,然後添加進每個Player的佇列,評判,并根據結果修改之後的狀態
        {
            // detect error
            ErrorDetecter(rp, rightP);
            ErrorDetecter(lp, leftP);

            // now rp, lp should only be HOLD, DEFENSE or ATTACK
            // output results
            switch (lp)
            {
                case Operation.HOLD:
                    FIFO(picBoxResultPlayer1,Hold_And_Attack_2._0.Properties.Resources.Hold);break;
                  //  picBoxResultPlayer1.BackgroundImage = global::Hold_And_Attack_2._0.Properties.Resources.Hold; break;
                case Operation.DEFENSE:
                    FIFO(picBoxResultPlayer1,Hold_And_Attack_2._0.Properties.Resources.Defend);break;
                   // picBoxResultPlayer1.BackgroundImage = global::Hold_And_Attack_2._0.Properties.Resources.Defend; break;
                case Operation.ATTACK:
                    FIFO(picBoxResultPlayer1,Hold_And_Attack_2._0.Properties.Resources.Attack);break;
                  //  picBoxResultPlayer1.BackgroundImage = global::Hold_And_Attack_2._0.Properties.Resources.Attack; break;
            }

            switch (rp)
            {
                case Operation.HOLD:
                    FIFO(picBoxResultPlayer2,Hold_And_Attack_2._0.Properties.Resources.Hold);break;
                   // picBoxResultPlayer2.BackgroundImage = global::Hold_And_Attack_2._0.Properties.Resources.Hold; break;
                case Operation.DEFENSE:
                    FIFO(picBoxResultPlayer2,Hold_And_Attack_2._0.Properties.Resources.Defend);break;
                   // picBoxResultPlayer2.BackgroundImage = global::Hold_And_Attack_2._0.Properties.Resources.Defend; break;
                case Operation.ATTACK:
                    FIFO(picBoxResultPlayer2,Hold_And_Attack_2._0.Properties.Resources.Attack);break;
                  //  picBoxResultPlayer2.BackgroundImage = global::Hold_And_Attack_2._0.Properties.Resources.Attack; break;
            }

            // add the operation in every player's queue and detect error
            ErrorDetecter(leftP.Act(lp), leftP);
            ErrorDetecter(rightP.Act(rp), rightP);

            // keep record
            KeepRecord(lp, rp, harmValue);

            // decide whether their are winner
            if (lp == Operation.HOLD && rp == Operation.ATTACK)
            {
                AttackSuccessfullyBy(PlayerID.RIGHT);
            }
            else if (rp == Operation.HOLD && lp == Operation.ATTACK)
            {
                AttackSuccessfullyBy(PlayerID.LEFT);
            }

            // 否則什麼也不做
            // 然後根據玩家所剩屏數控制按鈕的可按性
            if(mode == Mode.PVE)
                ChangeValidOp(PlayerID.LEFT);
            else
            {
                ChangeValidOp(PlayerID.LEFT);
                ChangeValidOp(PlayerID.RIGHT);
            }
        }

        protected void AttackSuccessfullyBy(PlayerID player)
        {
            if (player == PlayerID.LEFT)
            {
                if (ReduceHealth(harmValue, ref rightP)) // right player is defeated
                {
                    FightOver(PlayerID.LEFT);
                }
            }
            else if(player == PlayerID.RIGHT)
            {
                if(ReduceHealth(harmValue, ref leftP))
                {
                    FightOver(PlayerID.RIGHT);
                }
            }
        }

        protected bool ReduceHealth(int value, ref Player player)
        //  Pre:    這裡一般傳值是harmValue
        //  Post:   調用Player的函數,讓指定玩家傷血,返回是否血條打光(輸了),輸了是true
        {
            bool whetherDefeated = player.ReduceHealth(value);
            if (player.Equals(leftP))
                DisplayHealth(PlayerID.LEFT);
            else if (player.Equals(rightP))
                DisplayHealth(PlayerID.RIGHT);
            return whetherDefeated;
        }

        protected void DisplayHealth(PlayerID player)
        //  Post:   在控件上顯示HP
        {
            if(player == PlayerID.LEFT)
                lblHP1.Text = leftP.GetHealth().ToString() + "/" + maxHealth;
            else if (player == PlayerID.RIGHT)
                lblHP2.Text = rightP.GetHealth().ToString() + "/" + maxHealth;
        }

        void FightOver(PlayerID winner)
        {
            start = false;    // 滾動條停止滾動了
            if (winner == PlayerID.LEFT)
            {
                //MessageBox.Show("左邊贏啦", "作戰結果");
                //res += "左邊玩家: " + leftP.GetPlName() + "獲勝!\n";
                switch (lang)
                {
                    case Language.ENG: MessageBox.Show("Left Player Win!", "Fighting Result"); res += "Left Player: " + leftP.GetPlName() + " Win!\n"; break;
                    case Language.CNT: MessageBox.Show("左邊贏啦", "作戰結果"); res += "左邊玩家: " + leftP.GetPlName() + "獲勝!\n"; break;
                    case Language.CNS: MessageBox.Show("左边赢啦", "作战结果"); res += "左边玩家: " + leftP.GetPlName() + "获胜!\n"; break;
                    default: break;
                }
            }
            else
            {
                //MessageBox.Show("右邊贏啦", "作戰結果");
                //res += "右邊玩家: " + rightP.GetPlName() + "獲勝!\n";
                switch (lang)
                {
                    case Language.ENG: MessageBox.Show("Right Player Win!", "Fighting Result"); res += "Right Player: " + rightP.GetPlName() + " Win!\n"; break;
                    case Language.CNT: MessageBox.Show("右邊贏啦", "作戰結果"); res += "右邊玩家: " + rightP.GetPlName() + "獲勝!\n"; break;
                    case Language.CNS: MessageBox.Show("右边赢啦", "作战结果"); res += "右边玩家: " + rightP.GetPlName() + "获胜!\n"; break;
                    default: break;
                }
            }
            formResult = new FormResult(this);
            timerDispResult.Enabled = true; // 開始將這個透明窗體顯示起來
            formResult.ShowDialog();        // 顯示結果,並將自己傳給顯示窗口以顯示訊息

            BtnPauseToStart();              // 開始按鈕恢復預設
            BtnCanNotGiveUp();              // 投降按鈕重新不可見
        }

        void ChangeValidOp(PlayerID player)
        {
            if(player == PlayerID.LEFT)
            {
                // 如果沒有屏,不能轟
                if (leftP.GetNumHold() == 0)
                    DisableAttack();
                else
                    EnableAttack();

                // 如果連鏜5下,不能鏜
                if (leftP.GetNumDefense() >= 5)
                    DisableDefend();
                else
                    EnableDefend();
            }
        }

        private void ActIfHold(PlayerID player)
        //  Pre:    傳遞來的參數要是枚舉類型PlayerID,PVE模式無所謂
        //  Post:   並不判斷是否達到可以使用此操作的條件, 由其它來控制, 將操作臨時存儲下來等下一回合頭部傳給Judge()
        {
            if (canPress == true && hasPressed == false)
            {
                if(mode == Mode.PVE)
                {
                    leftOp = Operation.HOLD;
                }
                else if(mode == Mode.PVP)
                {
                    if (player == PlayerID.LEFT)
                        leftOp = Operation.HOLD;
                    else
                        rightOp = Operation.HOLD;
                }
                hasPressed = true;
            }
        }

        private void ActIfDefend(PlayerID player)
        //  Pre:    這是要保證調用前沒連鏜五下才能調用,按鈕控制要做好
        //  Post:   左邊出鏜或者聯機模式時,雙方確定出鏜
        {
            if (canPress == true && hasPressed == false && canDefend == true)
            {
                if (mode == Mode.PVE)
                {
                    leftOp = Operation.DEFENSE;
                }
                else if (mode == Mode.PVP)
                {
                    if (player == PlayerID.LEFT)
                        leftOp = Operation.DEFENSE;
                    else
                        rightOp = Operation.DEFENSE;
                }
                hasPressed = true;
            }
        }

        private void ActIfAttack(PlayerID player)
        //  Pre:    這是要保證調用前要有屏才能調用,按鈕控制要做好
        //  Post:   左邊出轟或者聯機模式時,雙方確定出轟
        {
            if (canPress == true && hasPressed == false && canAttack == true)
            {
                if (mode == Mode.PVE)
                {
                    leftOp = Operation.ATTACK;
                    // 電腦出招留到回合最後也是下一回合的頭,統一起來
                }
                else if (mode == Mode.PVP)
                {
                    if (player == PlayerID.LEFT)
                        leftOp = Operation.ATTACK;
                    else
                        rightOp = Operation.ATTACK;
                }
                hasPressed = true;
            }
        }

        private void DisableDefend()
        //  Pre:    控制如何纔按鈕不可用要在調用此函數的函數里寫喔
        //  Post:   此函數只負責執行,關閉按鈕
        {
            canDefend = false;

            // 按鈕變灰不可用
            btnDefend.Enabled = false;
            btnDefend.BackgroundImage = global::Hold_And_Attack_2._0.Properties.Resources.Defend_Disable;
        }
        private void DisableAttack()
        //  Pre:    控制如何纔按鈕不可用要在調用此函數的函數里寫喔
        //  Post:   此函數只負責執行,關閉按鈕
        {
            canAttack = false;

            // 按鈕變灰不可用
            btnAttack.Enabled = false;
            btnAttack.BackgroundImage = global::Hold_And_Attack_2._0.Properties.Resources.Attack_Disable;
        }

        private void EnableDefend()
        //  Pre:    控制如何纔按鈕不可用要在調用此函數的函數里寫喔
        //  Post:   此函數只負責執行,開啟按鈕
        {
            canDefend = true;

            // 按鈕可用了
            btnDefend.Enabled = true;
            btnDefend.BackgroundImage = global::Hold_And_Attack_2._0.Properties.Resources.Defend;
        }

        private void EnableAttack()
        //  Pre:    控制如何纔按鈕不可用要在調用此函數的函數里寫喔
        //  Post:   此函數只負責執行,開啟按鈕
        {
            canAttack = true;

            // 按鈕可用了
            btnAttack.Enabled = true;
            btnAttack.BackgroundImage = global::Hold_And_Attack_2._0.Properties.Resources.Attack;
        }

        private void BtnStartToPause()
        {
            //btnStart.Text = "Pause";
            switch (lang)
            {
                case Language.ENG: btnStart.Text = "Pause"; break;
                case Language.CNT: btnStart.Text = "暫停"; break;
                case Language.CNS: btnStart.Text = "暂停"; break;
                default: break;
            }
            hasStarted = true;
        }

        private void BtnPauseToStart()
        {
            //btnStart.Text = "Start";
            switch (lang)
            {
                case Language.ENG: btnStart.Text = "Start"; break;
                case Language.CNT: btnStart.Text = "開始"; break;
                case Language.CNS: btnStart.Text = "开始"; break;
                default: break;
            }
            hasStarted = false;
            hasPaused = false;
        }

        private void BtnCanGiveUp()
        {
            btnStop.Visible = true; // 讓"投降"按鈕可用可見
            btnStop.Enabled = true;
        }

        private void BtnCanNotGiveUp()
        {
            btnStop.Visible = false;
            btnStop.Enabled = false;
        }

        //*********************************************************************

        private void timerSlider_Tick(object sender, EventArgs e)
        {
            if (start)
            {
                if (picBoxSlider.Location.X > 0)
                {
                    picBoxSlider.Location = new Point(picBoxSlider.Location.X - sliderSpeed, posSliderIni.Y);                    
                }
                else    // 重頭來過,下一回合
                {
                    picBoxSlider.Location = posSliderIni;                    
                    
                    // 電腦還是要出招的
                    rightOp = E_Decide();

                    // 開始"算賬", 沒按過就按默認的"屏"處理
                    Judge(rightOp, leftOp);

                    // 下一回合初始化
                    canPress = false;
                    hasPressed = false;
                    leftOp = rightOp = Operation.HOLD;
                }

                if (picBoxSlider.Location.X <= ableStart+ ableLen && picBoxSlider.Location.X > ableStart)
                    canPress = true;
                else
                    canPress = false;
            }
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            if (hasStarted == false)    // 沒開始,就是開始鍵的功能
            {
                Fight();
                BtnStartToPause();
                btnStart.Enabled = false;   // 準備期間不能按
            }
            else                        // 開始了,就是暫停鍵的功能
            {
                if (hasPaused == false)
                {
                    MusicPlay.Pause();
                    //btnStart.Text = "Resume";
                    switch (lang)
                    {
                        case Language.ENG: btnStart.Text = "Resume"; break;
                        case Language.CNT: btnStart.Text = "重新開始"; break;
                        case Language.CNS: btnStart.Text = "重新开始"; break;
                        default: break;
                    }
                    timerSlider.Enabled = false;
                    hasPaused = true;
                }
                else
                {
                    MusicPlay.Resume();
                    //btnStart.Text = "Pause";
                    switch (lang)
                    {
                        case Language.ENG: btnStart.Text = "Pause"; break;
                        case Language.CNT: btnStart.Text = "暫停"; break;
                        case Language.CNS: btnStart.Text = "暂停"; break;
                        default: break;
                    }
                    timerSlider.Enabled = true;
                    hasPaused = false;
                }
            }
        }

        private void btnHold_Click(object sender, EventArgs e)
        {
            ActIfHold(PlayerID.LEFT);
        }

        private void btnDefend_Click(object sender, EventArgs e)
        {
            ActIfDefend(PlayerID.LEFT);
        }

        private void btnAttack_Click(object sender, EventArgs e)
        {
            ActIfAttack(PlayerID.LEFT);
        }

        private void FormPlay_KeyPress(object sender, KeyPressEventArgs e)
        {
            if(e.KeyChar == 'j')
            {
                btnHold.PerformClick();
            }
            else if(e.KeyChar == 'k' && canDefend == true)
            {
                btnDefend.PerformClick();
            }
            else if(e.KeyChar == 'l' && canAttack == true)
            {
                btnAttack.PerformClick();
            }
            else if(e.KeyChar == 'p' && hasStarted == true)
            {
                btnStart.PerformClick();
            }
            e.Handled = true;
        }

        private void timerDispResult_Tick(object sender, EventArgs e)
        {
            if (formResult != null) 
                formResult.Opacity += 1;
        }

        private void timerText_Tick(object sender, EventArgs e)
        //  Pre:    Clear()里要將textTip清0, 並且此函數因歌曲而異,可以用switch控制
        //  Post:   用於自定義把控音樂開頭的準備時期程式可以幹什麼,用switch語句把控,每一個bpm間隔干一次
        {
            string t1 = "";
            string t2 = "";
            string t3 = "";
            string t4 = "";
            string t5 = "";
            switch (lang)
            {
                case Language.ENG: t1 = "Welcome to play Hold And Attack!"; t2 = "This is a muisc game to relax."; t3 = "According to rhythm,when slider slide to the circle,Fight!"; t4 = "Best wish you to play happy!"; t5 = "Begin Fighting!"; break;
                case Language.CNT: t1 = "歡迎遊玩屏鏜轟!"; t2 = "這是一款音樂節奏類益智休閒遊戲。"; t3 = "根據節奏,當滑塊滑到圈圈時,發招吧!"; t4 = "祝您遊玩愉快!"; t5 = "戰鬥開始!"; break;
                case Language.CNS: t1 = "欢迎来玩屏鏜波!"; t2 = "这是一款音乐节奏类益智休闲游戏。"; t3 = "根据节奏,当滑块滑到圈圈时,发招吧!"; t4 = "祝您游玩愉快!"; t5 = "战斗开始!"; break;
                default: break;
            }
            switch(textTip)
            {
                case 0:
                    lblText.Text = t1;  break;
                case 1:
                case 2:
                    lblText.Text = t2;  break;
                case 3:
                case 4:
                    if(lang==Language.ENG)
                    {lblText.Text = t3;lblText.Font = new Font(lblText.Font.FontFamily, 10,lblText.Font.Style); }
                    else
                    {lblText.Text = t3;lblText.Font = new Font(lblText.Font.FontFamily, 18,lblText.Font.Style); }break;
                case 5:
                case 6:
                    lblText.Text = t4;lblText.Font = new Font(lblText.Font.FontFamily, 18,lblText.Font.Style);   break;
                default:
                    lblText.Text = t5;
                    start = true;
                    picBoxResultPlayer1.BackgroundImage = global::Hold_And_Attack_2._0.Properties.Resources.Default;
                    picBoxResultPlayer2.BackgroundImage = global::Hold_And_Attack_2._0.Properties.Resources.Default;
                    BtnCanGiveUp();
                    timerText.Enabled = false;
                    btnStart.Enabled = true;
                    return;

            }
            textTip += 1;

            ReadyPicRandom();
        }

        private void FormPlay_FormClosing(object sender, FormClosingEventArgs e)
        {
            MusicPlay.Stop();               // 把音樂關掉            
        }

        private void btnStop_Click(object sender, EventArgs e)
        //  Pre:    mode == PVE
        {
            if (!hasPaused)
                btnStart.PerformClick();
             
            DialogResult dlg = new DialogResult();
            switch (lang)
            {
                case Language.ENG: dlg = MessageBox.Show("Do you want to give up? It's not a behaviour of a warrior:)", "Ensure Surrender", MessageBoxButtons.OKCancel); break;
                case Language.CNT: dlg = MessageBox.Show("您确定要投降嗎？這可不是勇士的行為哦:)", "確定投降", MessageBoxButtons.OKCancel); break;
                case Language.CNS: dlg = MessageBox.Show("您确定要投降吗？这可不是勇士的行为哦:)", "确定投降", MessageBoxButtons.OKCancel); break;
                default: break;
            }
            if (dlg == DialogResult.OK)
            {
                // 玩家投降, PVE模式
                if (hasStarted)
                {
                    AddRecoredGiveUp(PlayerID.RIGHT);
                    FightOver(PlayerID.RIGHT);
                }
            }
            else
                btnStart.PerformClick();
        }

        private static void FIFO(PictureBox pb, Image image)
        {
            try
            {
                Graphics g = pb.CreateGraphics();
                g.Clear(Color.White);
                int width = image.Width;
                int height = image.Height;
                ImageAttributes attributes = new ImageAttributes();
                ColorMatrix matrix = new ColorMatrix();
                matrix.Matrix00 = (float)0.0;
                matrix.Matrix01 = (float)0.0;
                matrix.Matrix02 = (float)0.0;
                matrix.Matrix03 = (float)0.0;
                matrix.Matrix04 = (float)0.0;
                matrix.Matrix10 = (float)0.0;
                matrix.Matrix11 = (float)0.0;
                matrix.Matrix12 = (float)0.0;
                matrix.Matrix13 = (float)0.0;
                matrix.Matrix14 = (float)0.0;
                matrix.Matrix20 = (float)0.0;
                matrix.Matrix21 = (float)0.0;
                matrix.Matrix22 = (float)0.0;
                matrix.Matrix23 = (float)0.0;
                matrix.Matrix24 = (float)0.0;
                matrix.Matrix30 = (float)0.0;
                matrix.Matrix31 = (float)0.0;
                matrix.Matrix32 = (float)0.0;
                matrix.Matrix33 = (float)0.0;
                matrix.Matrix34 = (float)0.0;
                matrix.Matrix40 = (float)0.0;
                matrix.Matrix41 = (float)0.0;
                matrix.Matrix42 = (float)0.0;
                matrix.Matrix43 = (float)0.0;
                matrix.Matrix44 = (float)0.0;
                matrix.Matrix33 = (float)1.0;
                matrix.Matrix44 = (float)1.0;
                Single count = (float)0.0;

                while (count < 1.0)
                {
                    matrix.Matrix00 = count;
                    matrix.Matrix11 = count;
                    matrix.Matrix22 = count;
                    matrix.Matrix33 = count;
                    attributes.SetColorMatrix(matrix, ColorMatrixFlag.Default, ColorAdjustType.Bitmap);
                    g.DrawImage(image, new Rectangle(0, 0, pb.Width, pb.Height), 0, 0, width, height, GraphicsUnit.Pixel, attributes);
                    System.Threading.Thread.Sleep(2);
                    count = (float)(count + 0.02);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "信息提示");
            }
        }

    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace Hold_And_Attack_2._0
{
    class MusicPlay
    {
        public static uint SND_ASYNC = 0x0001;
        public static uint SND_FILENAME = 0x00020000;
        [DllImport("winmm.dll")]
        public static extern uint mciSendString(string lpstrCommand,
        string lpstrReturnString, uint uReturnLength, uint hWndCallback);
        public static void Play(string musicName)
        {
            string lpstrCommand = @"open """ + FormPlay.musicDir + @"\" + musicName + @""" alias music_alias";
            mciSendString(@"close music_alias", null, 0, 0);
            mciSendString(lpstrCommand, null, 0, 0);
            mciSendString("play music_alias repeat", null, 0, 0);
        }

        public static void Resume()
        {
            mciSendString("play music_alias", null, 0, 0);
        }
        public static void Pause(string musicName)
        {
            mciSendString("pause" + musicName, null, 0, 0);
        }

        public static void Pause()
        {
            mciSendString("pause music_alias", null, 0, 0);
        }

        public static void Stop(string musicName)
        {
            mciSendString("close " + musicName, null, 0, 0);
        }

        public static void Stop()
        {
            mciSendString("close music_alias", null, 0, 0);
        }
    }
}


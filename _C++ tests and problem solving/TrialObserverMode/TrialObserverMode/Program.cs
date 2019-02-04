using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TrialObserverMode
{
    static class Program
    {
        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
        [STAThread]
        static void Main()
        {
            //Application.EnableVisualStyles();
            //Application.SetCompatibleTextRenderingDefault(false);
            //Application.Run(new Form1());

            WeatherData weatherData =  WeatherData.GetInstance();
            WeatherReporter weatherReporter = new WeatherReporter(weatherData);

            weatherData.Temperature = 56.0f;
            weatherData.Humidity = 0.65f;
            weatherData.Pressure = 0.00f;
            weatherData.MeasurementsChanged();

            weatherReporter.Display();

            weatherData.Temperature = 32.0f;
            weatherData.Humidity = 0.86f;
            weatherData.Pressure = 0.20f;
            weatherData.MeasurementsChanged();

            weatherReporter.Display();
        }
    }
}

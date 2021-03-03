using OpenQA.Selenium;
using OpenQA.Selenium.Chrome;
using System;
using System.Threading;

namespace SeleniumSeeSharp
{
    class Program
    {
        private static IWebDriver _driver;

        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            IWebDriver driver = new ChromeDriver();
            driver.Navigate().GoToUrl("https://ultimateqa.com/complicated-page");

            IWebElement element = driver.FindElement(By.ClassName("et_pb_button"));
            element.Click();

            Console.ReadLine();
        }
    }
}

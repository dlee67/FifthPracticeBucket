using System;

namespace MyFirstConsoleApp
{
    class Program
    {

        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            CardPicker picker = new CardPicker();
            picker.pickSomeCards();
        }
    }
}

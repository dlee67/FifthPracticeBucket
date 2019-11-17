using System;
using SomeName; // In the world of C#, you don't import classes, you import the namespaces.

namespace C_Prac
{
    class Program
    {

        static void Main(string[] args)
        {
            SomeClass.SomeStruct someVar; // Declaring is enough for structs?
            someVar.someStructString = "lol";
            Console.WriteLine(someVar.someStructString);
            Console.WriteLine(SomeName.SomeClass.getString()); // You don't need to put SomeName, but did it anyway for the verbosity sake.
            Console.WriteLine("Hello World!");
            string part1 = "the ultimate question"; // If the variable is not declared nullable, they cannot be null.
            string part2 = "of something";
            int theAnswer = 2;
            int? andAnotherThing = null; // This is how you use nullability.
            // Just like Kotlin, string nonNullableReferenceFromLegacyComponent = referenceFromLegacyComponent!; // Non-null asserts also there.

            Console.WriteLine(part1 + " " + part2 + ": " + theAnswer);
            // Console.WriteLine(andAnotherThing); // This will crash the app without the nullable.

            string[] someList = {"lol", "meme", "funny", "haha"};
            foreach (string stuff in someList) { // C# has a dedicated keyword for foreach loops.
                Console.WriteLine(stuff);
            }  
        }
    }
}

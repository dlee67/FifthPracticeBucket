namespace SomeName
{
    public class SomeClass {

        public struct SomeStruct {
            public string someStructString; // You cannot initialize/assign stuff in struct.
            public string someSecondStructString;
        }

        static public string getString() {
            return "Lol, much string";
        }
    }    
}
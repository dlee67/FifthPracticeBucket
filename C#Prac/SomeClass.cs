namespace SomeName
{
    public class SomeClass {

        // At this point, it looks like Kotlin ripped a lot of stuff from C#.
        // You can do stuff like the below.
        // public int x {
        //     get
        //     {
        //         return x;
        //     }
        //     set
        //     {
        //         x = value;
        //     }
        // }

        // They call the below anonymous types, but it's really just a JavaScript object.
        // var x = new { place = "Some opera", host = "Intel"}

        // There is a computer organizational reasoning why you would want to use struct over reference type.
        // Structs, when being fetched by some program counter, it is not fetching the address of some memory location,
        // it's literally that struct data you are looking for (I think).
        public struct SomeStruct {
            public string someStructString; // You cannot initialize/assign stuff in struct.
            public string someSecondStructString;
        }

        static public string getString() {
            return "Lol, much string";
        }
    }    
}
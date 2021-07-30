using Microsoft.VisualStudio.TestTools.UnitTesting;
using ConsoleApp1;

namespace Console1.Test.Unit
{
    [TestClass]
    public class Class1Test
    {
        [TestMethod]
        public void TestAddNums()
        {
            Class1 ca = new Class1();
            Assert.AreEqual(5, ca.getNum());
        }
    }
}

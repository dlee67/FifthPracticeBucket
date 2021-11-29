using Xunit;
using ContosoPizza.Services;
using System;
using Xunit;

// If this doesn't work, try adding the "project reference" of ContosoPizza in TestProject1.
namespace TestProject1
{
    public class UnitTest1
    {
        [Fact]
        public void Test1()
        {
            Assert.Equal("Classic Italian", PizzaService.GetAll()[0].Name);
            Assert.NotEqual("New York pizza", PizzaService.GetAll()[0].Name);
        }
    }
}
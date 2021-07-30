using System;
using TechTalk.SpecFlow;

namespace SpecFlowPrac
{
    [Binding]
    public class TicTacToePlayGameSteps
    {
        [Given(@"I started a new game")]
        public void GivenIStartedANewGame()
        {
            ScenarioContext.Current.Pending();
        }
        
        [When(@"I put three crosses in a row")]
        public void WhenIPutThreeCrossesInARow()
        {
            ScenarioContext.Current.Pending();
        }
        
        [Then(@"I should win")]
        public void ThenIShouldWin()
        {
            ScenarioContext.Current.Pending();
        }
    }
}

Feature: TicTacToePlayGame
	In order to play the TicTacToe game
	as a gamer
	I want to be able to put crosses or noughts and determine a winner

@mytag
Scenario: Play game
	Given I started a new game
	When I put three crosses in a row
	Then I should win
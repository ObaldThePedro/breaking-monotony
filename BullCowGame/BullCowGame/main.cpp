#include <iostream>
#include <string>
#include "FBullCowGame.h"


using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; // instantiate a new game from FBullCowGame class.

int main()
{
	do {
		PrintIntro();
		PlayGame();
	} 
	while (AskToPlayAgain() == true);
	return 0;
}

void PrintIntro()
{
	std::cout << "\nWelcome to Bulls and Cows, a fun word game\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter of isogram I am thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MAX_TRIES = BCGame.GetMaxTries();

	// loop asking the guess while the game is not won
	// and there are still tries remaining

	// TODO change from FOR to WHILE loop once we validating tries
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MAX_TRIES)
	{
		FText Guess = GetValidGuess(); // TODO make a loop for valid guesses.
	
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		// Print number of bulls and cows.
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	//TODO add a game summary
	PrintGameSummary();
	return;
}

// loop continually until the user gives a valid guess
FText GetValidGuess()
{	
	EGuessStatus Status = EGuessStatus::Invalid_status;
	FText Guess = "";
	do
	{
		// get a guess from the user
		int32 CurrentTry = BCGame.GetCurrentTry();

		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries() << ". Enter your guess: ";
		
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::Wrong_length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word!\n\n";
			break;

		case EGuessStatus::Not_isogram:
			std::cout << "Please enter a word without repeating letters!\n\n";
			break;

		case EGuessStatus::Not_lowercase:
			std::cout << "Please enter just lowercase letter word!\n\n";
			break;

		default:
			// assume the guess is valid
			break;
		}
	} while (Status != EGuessStatus::Ok); // keep looking until we have no errors.
	return Guess;
}

bool AskToPlayAgain()
{	
	std::cout << "Do you wanna play again with the same hidden word (y/n)?";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGameSummary()
{	
	// variable creation to check whether the game is Won or not
	
	if (BCGame.IsGameWon() == true)
	{
		std::cout << "Congratulations, you won the Bulls & Cows Game." << std::endl;
	}
	else 
	{
		std::cout << "Bad luck, try again next time!" << std::endl;
	}
}



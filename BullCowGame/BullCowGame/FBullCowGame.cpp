#include "FBullCowGame.h"
#include <map>
#define TMap std::map



FBullCowGame::FBullCowGame() { Reset(); } // this piece of code is a constructor that points to Reset method.

int32 FBullCowGame::GetMaxTries() const {
	int32 WordLength = MyHiddenWord.length();
	float MaxTries = {};
	
	
	if (WordLength <= 3) {
	 MaxTries = 3;
	}
	
	else {
		MaxTries = WordLength * 0.75f;
		int32 i = round(MaxTries);
	}
	int32 i = round(MaxTries);
	TMap<int32, int32> WordLengthToMaxTries{ {WordLength, i} };
	
	return WordLengthToMaxTries[WordLength];
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{

	FString const HIDDEN_WORD = "plane";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

// receives a valid guess, increments the try number and returns count.
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	
	MyCurrentTry++;
	
	//setup a return variable
	FBullCowCount BullCowCount;
	
	// loop through all the letters in the hiddenword.
	int32 WordLength = MyHiddenWord.length(); //assuming same length as guess
	for (int32 GWChar = 0; GWChar < WordLength; GWChar++)
	{
		//compare letters against the guess.
		for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
		{
			//if they match
			if (Guess[GWChar] == MyHiddenWord[MHWChar]) 
			{
				//if they are in the same place
				if (GWChar == MHWChar) 
				{
					BullCowCount.Bulls++;	//increment bulls if they are in the same place
				}	
				else 
				{
					BullCowCount.Cows++; //increment cows
				}
			}
		}
		if (BullCowCount.Bulls == WordLength)
		{
			bGameIsWon = true;
		}
		else
		{
			bGameIsWon = false;
		}
			
	}
	return BullCowCount;
	}

bool FBullCowGame::bIsIsogram(FString Word) const
{	
	// treat 0 and 1 as isograms;
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;
	for (auto Letter : Word) // for all the letters of the word
	{	//TODO every word in the FString must be different;
		Letter = tolower(Letter); // handle mixed case
		
		if (LetterSeen[Letter])
		{
			return false;
		}
		else
		{
			LetterSeen[Letter] = true;
		}
	// add the letter to the map
	}
	return true;
}

bool FBullCowGame::bIsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))
		{
			return false;
		}
	}
	return true;
}



bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!bIsIsogram(Guess))	//if the guess is not an isogram,
	{
		return EGuessStatus::Not_isogram;
	}
	else if (!bIsLowercase(Guess)) //TODO needs method to return a richer value
	{
		return EGuessStatus::Not_lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_length;
	}

	else
	{
		return EGuessStatus::Ok;
	}
		//return ok.
}

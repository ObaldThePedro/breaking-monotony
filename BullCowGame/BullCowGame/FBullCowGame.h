#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_status,
	Ok,
	Not_isogram,
	Not_lowercase,
	Wrong_length

};

class FBullCowGame
{
public:
	FBullCowGame(); // Constructor
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;




	EGuessStatus CheckGuessValidity(FString) const;
	void Reset(); // TODO to make a more rich value
	FBullCowCount SubmitValidGuess(FString);

	// Please ignore this and focus on the public section.
private:
	// see constructor for initialization
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;
	
	bool bIsIsogram(FString) const;
	bool bIsLowercase(FString) const;
};


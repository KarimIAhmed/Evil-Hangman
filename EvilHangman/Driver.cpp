#include <iostream>
#include <string>
#include <cctype>
#include "list.h"
using namespace std;

int main() {
	list wordlist("words");
	string difficulty;
	int numGuesses;
	cout << "Welcome to this ordinary game of Hangman!!\n\n";
	cout << "Please select a difficulty level" << endl;
	cout << "1.easy\n2.medium\n3.hard\n" << endl;
	cin >> difficulty;

	if (difficulty == "easy" || difficulty == "1") {
		numGuesses = 19;
	}
	else if (difficulty == "medium" || difficulty == "2") {
		numGuesses = 16;
	}
	else if (difficulty == "hard" || difficulty == "3") {
		numGuesses = 13;
	}
	cout << "You have " << numGuesses << " wrong guesses!\n";
	string guessedLetters = "";
	int wrongCount = 0;
	bool won = false;

	while (!won && wrongCount < numGuesses) {
		cout << "Word: " << wordlist.mask() << endl;
		cout << "Guess a letter: ";
		char letter;
		cin >> letter;
		while (guessedLetters.find(letter) != string::npos) {
			cout << "You've already guessed " << letter << "!\nPlease try again: ";
			cin >> letter;
		}
		guessedLetters += letter;
		if (!wordlist.split(letter)) {
			wrongCount++;
			cout << "You were wrong! " << (numGuesses - wrongCount) << " chances left!\n";
		}
		won = wordlist.is_guessed();
	}
	if (won) {
		cout << "You won!  The word was '" << wordlist.word() << "'\n";
	}
	else {
		cout << "You lost!  The word was '" << wordlist.word() << "'\n";
	}
	return 0;
}
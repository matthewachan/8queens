/*
Matthew Chan					    PIC 10B Intermediate Programming
ID: 604178275          		  		Winter 2015
Email: matthew.a.chan@gmail.com		Assignment #4
Section: 2B
Honesty Pledge:

I, Matthew Chan, pledge that this is my own independent
work,which conforms to the guidelines of academic honesty as
described in the course syllabus.

List of known bugs: None.
*/
#include "EightQueensProblem.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	bool quit = false, validInput = true;
	// Create an ouput file stream to a text file, where the solutions to the Eight Queens Problem will be posted
	string targetFile = "Solutions.txt";
	ofstream out(targetFile);
	// Continue to play the game until the user quits
	while (!quit) {
		cout << "\n\n************************* Eights Queens Problem *************************" << endl;
		cout << "\nPosition the first queen on the chessboard:" << endl;
		int row;
		// Keep looping until the user inputs a valid number for the row
		do {
			cout << "\nEnter the row for the first queen (from 1 to 8): ";
			cin >> row;
			if (row > 8 || row < 1) validInput = false;
			else validInput = true;
		} while (validInput == false);
		cout << "From the position (" << row << ", 1), the EightQueensProblem has solution: " << endl;
		EightQueensProblem solution = EightQueensProblem();
		// Rows are indexed from 0 in our chessboard[rows][columns] array
		solution.start_game(row - 1);
		// Write the solution to the console window and to the text file
		solution.display_board(cout);
		solution.display_board(out);
		// Prompt the user to rerun the program or exit
		char option;
		cout << "\nFinished? Type 'q' to quit or any other key to try again: ";
		cin >> option;
		if (option == 'q') {
			cout << "Thanks for playing!" << endl;
			quit = true;
		}
	}
	// Close the output stream
	out.close();
	return 0;
}


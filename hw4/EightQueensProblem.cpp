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
#include <iomanip>
/*		DEFAULT CONSTRUCTOR		*/
EightQueensProblem::EightQueensProblem() : NUM_QUEENS(8) {
	// Initialize the board with no queens on it
	for (short int i = 0; i < CHESSBOARD_SIZE; i++) {
		for (short int j = 0; j < CHESSBOARD_SIZE; j++) {
			chessboard[i][j] = 0;
		}
	}
	num_queens_on_board = 0;
}
/*		MEMBER FUNCTIONS		*/
void EightQueensProblem::clear_board() {
	// Remove all queens from the board
	for (short int i = 0; i < CHESSBOARD_SIZE; i++) {
		for (short int j = 0; j < CHESSBOARD_SIZE; j++) {
			chessboard[i][j] = 0;
		}
	}
	num_queens_on_board = 0;
}
ostream& EightQueensProblem::display_board(ostream& os)  {
	// Prints out the chessboard to the console window
	os << "\n";
	for (short int i = 0; i < CHESSBOARD_SIZE; i++) {
		for (short int j = 0; j < CHESSBOARD_SIZE; j++) {
			os << setw(3) << chessboard[i][j];
		}
		os << endl << endl;
	}
	return os;
}
bool EightQueensProblem::queen_under_attack(int row, int column) {
	// Check the row and column for other queens
	for (short int i = 0; i < CHESSBOARD_SIZE; i++) {
		if (chessboard[row][i] != 0) return true;
		if (chessboard[i][column] != 0) return true;
	}
	// Check all four diagonal directions for other queens
	for (short int i = 0; (row - i) >= 0 && (column + i) < CHESSBOARD_SIZE; i++) {
		if (chessboard[row - i][column + i] != 0) return true;
	}
	for (short int i = 0; (row - i) >= 0 && (column - i) >= 0; i++) {
		if (chessboard[row - i][column - i] != 0) return true;
	}
	for (short int i = 0; (row + i) < CHESSBOARD_SIZE && (column + i) < CHESSBOARD_SIZE; i++) {
		if (chessboard[row + i][column + i] != 0) return true;
	}
	for (short int i = 0; (row + i) < CHESSBOARD_SIZE && (column - i) >= 0; i++) {
		if (chessboard[row + i][column - i] != 0) return true;
	}
	return false;
}
bool EightQueensProblem::start_game(int row) {
	// Place a queen on some row in the first column
	place_queen_on_square(row, 0);
	// Game successful if a solution could be found given the positioning of the first queen
	bool success = place_next_queen();
	if (success) return true;
	// Otherwise, the game is unsuccessful
	else return false;
}
void EightQueensProblem::place_queen_on_square(int row, int column) {
	// Place a queen on the specified space
	chessboard[row][column] = column + 1;
	num_queens_on_board++;
}
void EightQueensProblem::remove_queen_from_square(int row, int column) {
	// Remove a queen from the specified space
	chessboard[row][column] = 0;
	num_queens_on_board--;
}
/*		RECURSIVE FUNCTION		*/
bool EightQueensProblem::place_next_queen() {
	// Base case
	if (num_queens_on_board == NUM_QUEENS) return true;
	// Start at the current column
	int column = num_queens_on_board;
	// If a queen can be placed in this column, place it
	for (short int row = 0; row < CHESSBOARD_SIZE; row++) {
		if (!queen_under_attack(row, column)) {
			place_queen_on_square(row, column);
			// Recursive call, place a queen in the next column
			bool success = place_next_queen();
			// If one queen along the way could not be placed, remove the previous queen (backtracking)
			if (!success) {
				remove_queen_from_square(row, column);
			}
			// Once all queens have been successfully placed, return true
			else {
				return true;
			}
		}
	}
	// If a queen could not be placed in a given row, return false
	return false;
}
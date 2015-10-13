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
#ifndef EIGHTQUEENSPROBLEM_H
#define EIGHTQUEENSPROBLEM_H
#include <iostream>
using namespace std;
class EightQueensProblem {
public:
	EightQueensProblem();
	void clear_board();
	ostream& display_board(ostream& os);
	bool queen_under_attack(int row, int column);
	bool start_game(int row);
private:
	/*			HELPER FUNCTIONS	*/
	void place_queen_on_square(int row, int column);
	void remove_queen_from_square(int row, int column);
	bool place_next_queen();
	/*			VARIABLES			*/
	static const int CHESSBOARD_SIZE = 8;
	int chessboard[CHESSBOARD_SIZE][CHESSBOARD_SIZE];
	const int NUM_QUEENS;
	int num_queens_on_board;
};
#endif
#ifndef SNAKES_H
#define SNAKES_H

#include <string>

template <class T>
class Queue {
	/*	An array based queue to implement player turns 
		Implement additional functions as per requirement
	*/
public:
	
	Queue() {

	}

	T front() {
		return T();
	}
	T back() {
		return T();
	}

	bool is_empty() {
		return false;
	}
};

class RollStack {
	/* Implement a stack for your dice roll operations */
public:
	RollStack() {

	}

	void push_roll(int value) {
		/* Add a roll on top of the stack */
	}

	int top() {
		
		return 0;
	}

	void pop() {

	}

	bool is_empty() {
		return true;
	}

	void empty() {
		while (!is_empty()) {
			pop();
		}
	}
};


struct Tile {

	Tile *next, *previous, *up, *down;

};

class Game {
	Queue<int> turnQueue;
public:
	Game(const std::string& filename, int num_players) {
		/*
			Initialize the game board from the given file and setup players
		*/
	}

	Queue<int>& GetTurnQueue() {
		/* Return your player turn queue */
		return turnQueue;
	}

	Tile* GetTile(int pos) {
		/* returns the Tile at the given position (head, bottom left, is at pos 1) */
		return NULL;
	}

	bool IsLadder(int pos) {
		/* returns true if there is a ladder tail at 'pos' */
		return false;
	}

	bool IsSnake(int pos) {
		/* returns true if there is a snake head at 'pos' */
		return false;
	}
	
	int TraverseBoard(int current_pos, RollStack& stack) {
		/*	
			Traverse the board and return the resulting position
			beginning from 'current_pos' using the roll stack
		*/
		return 1;
	}

	void RollDice(int value) {
		/* Add a roll for the current player, update turn queue accordingly */
	}

	void Play() {
		/*	Run the game until the required number of players 
			complete the game. Print all relevant outputs during play
		*/
	}

	~Game() {
		/* deallocate and cleanup */
	}
};

#endif

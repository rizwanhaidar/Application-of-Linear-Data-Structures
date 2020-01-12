#ifndef SNAKES_H
# define SNAKES_H
#include<iostream>
#include<fstream>
#include <string.h>
#include<cstdlib>
#include<time.h>

using namespace std;

template < class T >
class Queue {

	/*	An array based queue to implement player turns
		Implement additional functions as per requirement
	*/
	T* ptr; //playes
	int num_pItmes = 0;
	int* pos; //their respective positions
	int size; //toatal number of players
	T frontval; //front of the queue
	T rearval; //rear of the queue
	int numItems; //current number of items in queue

public:

	Queue() {
		//a default constructor
		size = 0;
		frontval = -1;
		rearval = -1;
		ptr = new T;
		pos = new int;
		numItems = 0;
		num_pItmes = 0;
	}
	Queue(int size_) {
		//an overloaded constructor
		size = size_;
		ptr = new T[size];
		pos = new T[size];
		frontval = -1;
		rearval = -1;
		numItems = 0;
		num_pItmes = 0;
	}
	void setSize(int size_) {
		//function to set the size and 
		//memory allocation to pointers
		size = size_;
		ptr = new T[size];
		pos = new int[size];
	}
	bool IsFull() {
		//retrun true if queue is full
		if (numItems < size) {
			return false;
		}
		return true;
	}
	bool Is_posFull() {
		//retrun true if queue is full
		if (num_pItmes < size) {
			return false;
		}
		return true;
	}

	void enqueue(int num) {
		//enters an item to queue if it is not full
		if (!IsFull()) {
			ptr[numItems] = num;
			numItems++;
		}
	}
	void pos_enqueue(int num) {
		//enters an item to queue if it is not full
		if (!Is_posFull()) {
			pos[num_pItmes] = num;
			num_pItmes++;
		}
	}
	void setNullPos() {
		//sets all positions to 0 at initial
		for (int i = 0; i < size; i++) {
			pos[num_pItmes] = 0;
			num_pItmes++;

		}
	}
	void setPos(int pos_) {
		//sets the position of player at front
		pos[0] = pos_;

	}
	T dequeue() {
		//a circular implementation 
		//which will ist dequeue the front and then will 
		//enqueue the same value at end
		T returnval = ptr[0];
		//	int pos_ = pos[0];
		for (int i = 0; i < size - 1; i++) {
			//traversal
			ptr[i] = ptr[i + 1];
			//			pos[i] = pos[i + 1];
		}
		numItems--;
		//		num_pItmes--;
		//		pos[num_pItmes] = pos_;

		//	enqueue(returnval);
		//e_Pos(pos_);

		return returnval;
	}
	int pos_dequeue() {
		//a circular implementation 
		//which will ist dequeue the front and then will 
		//enqueue the same value at end

		int pos_ = pos[0];
		for (int i = 0; i < size - 1; i++) {
			//traversal
			pos[i] = pos[i + 1];
		}
		num_pItmes--;

		//pos[size - 1] = pos_;
		//e_Pos(pos_);
		//	pos_enqueue(pos_);
		return pos_;
	}

	T front() {
		//retruns front
		return ptr[0];
	}
	T back() {
		//returns rear
		return ptr[numItems - 1];
	}
	int getposfront() {
		//retrun front position
		return pos[0];
	}
	int getposback() {
		//retruns rear position
		return pos[numItems - 1];
	}
	bool is_empty() {
		//if queue is empty
		if (ptr[0] == -1)
			return true; // we can check “rear” too
		else
			return false;
	}
	void reverse() {
		//will reverse the whole queue
		T* ptr_ = new T[size];
		int x = 0;
		for (int i = size - 1; i >= 0; i--) {
			//copyting in reverse order
			ptr_[i] = ptr[x];
			x++;
		}
		for (int i = 0; i < size; i++) {
			//copying
			ptr[i] = ptr_[i];
			//x++;
		}
		free(ptr_);

	}~Queue() {
		//deallocating all the memory
		free(ptr);
		free(pos);
	}
};

struct NodeRollStack {
	//A node for pointers based 
	//implementation of stack

	int data; //data
	NodeRollStack* next; //next pointer

	NodeRollStack() {
		data = -1;
		next = NULL;
	}
};
class RollStack {

	NodeRollStack* tos;

	//top of the stack pointer
	/* Implement a stack for your dice roll operations */
public:
	int size;
	RollStack() {
		//a default constructor
		tos = NULL;
		size = 0;
	}

	void push_roll(int value) {
		/* Add a roll on top of the stack */
		NodeRollStack* temp = new NodeRollStack;
		temp -> data = value;
		temp -> next = NULL;

		if (tos == NULL) {
			//if top is null
			tos = temp;
		}
		else {
			//if top is not null
			temp -> next = tos;
			tos = temp;
		}
		size++;
		temp = NULL;
		delete temp;
		//free(temp);
	}

	int top() {
		//returns top value and then
		//points to the next pointer
		NodeRollStack temp;
		temp.data = tos -> data;
		pop();
		size--;
		return temp.data;
	}

	void pop() {
		//top of te stack points to next pointer
		tos = tos -> next;
	}

	bool is_empty() {
		//if stack is empty
		if (tos == NULL) {
			return true;
		}
		return false;
	}

	void empty() {
		//clears the stack
		while (!is_empty()) {
			pop();
		}
	}~RollStack() {
		//deallocates the memory
		NodeRollStack* temp;
		while (tos) {
			temp = tos;
			tos = tos -> next;
			free(temp);

		}
	}
};

struct Tile {
	//An implementation of a struct corresponding to the 
	//Node in a Linked List

	string data;

	bool snakehead = false;
	//	bool laderhead = false;
	//	bool snaketail = false;
	bool leadertail = false;

	//four pointer for the implementation of Board
	Tile* next, * previous, * up, * down;

	Tile() {
		//A Default constructor
		//Initializing everything to the NULL
		next = NULL;
		previous = NULL;
		up = NULL;
		down = NULL;
	}
};

string* arrayRead(const string& filename) {

	//A function generally using an Array 
	//for file reading and the traversing the array
	//according to the asked requirements
	string data; //A temporary variable
	string* arr = new string[100]; //Array for data reading
	string* arr2 = new string[100]; //Array saving the traversed data and
	//returning back to the calling area
	fstream file;
	//few variables to handle reading and traversing
	//implementation
	int x = 0;
	int y = 0;
	int i = 10;
	int k = 0;
	//cout << filename;
	file.open(filename, ios::in);
	//*****************File Reading**********************
	while (file >> data) {
		//		cout << data << " ";
		arr[x] = data;
		x++;
		//		if (x % 10 == 0) {
		//			cout << endl;
		//		}
	}
	/************************Data Traversing***********************/
	/************************Based on even and odd rows************/
	while (y < 10) {
		//even row case
		if (i % 2 == 0) {
			int p = i * 10;
			p = p - 10;
			int u = 0;
			while (u < 10) {
				arr2[k] = arr[p];
				k++;
				p++;
				u++;
			}
		}
		//odd row case
		else if (i % 2 != 0) {
			int p = i * 10;
			p = p - 1;
			int u = 0;
			while (u < 10) {
				arr2[k] = arr[p];
				p--;
				k++;
				u++;
			}
		}
		y++;
		i--;

	}
	return arr2;
}

class boardLinkedList {
	//Implementing LinkedList based on the Tile (Node)
	//which will be saving the data
	//accoring to the requirements
	//and Linking nodes as per requirements
	//Having head and tail pointers of TILE

private:
	Tile* head, * tail;
public:

	boardLinkedList() {
		//a default constructor
		head = NULL;
		tail = NULL;
	}
	//insert function will receie data and position
	//position to handle how to handle next, up down and 
	//previous pointers
	int v = 11; //A variable to handle the input an dall other linking

	bool insert(string data_, int pos) {
		//Implementation off a funtion to insert data into the linked list
		//By first creating a node and then handling all the exceptions

		Tile* temp = new Tile;
		temp -> data = data_;
		if (head == NULL) {
			//if linked list is empty
			head = temp;
			tail = temp;
		}
		else {
			if (pos % v != 0) {
				//if input data is not at node 11,21,31,41 and upto so on
				//		cout << pos << endl;
				//		cout << data_ << endl;
				//		cout << v << endl;
				Tile* curr = tail;
				tail = temp;
				tail -> previous = curr;
				curr -> next = tail;
			}
			else if (pos % v == 0) {
				//if input datat is at 11,21,31,41,51 and upto so on position
				//		cout << pos << endl;
				//		cout << data_ << endl;
				//		cout << v << endl;
				Tile* curr = tail;
				tail = temp;
				tail -> down = curr;
				curr -> up = tail;
				v = v + 10;
			}
		}
		return true;
	}
	Tile* GetTile(int pos) {
		/* returns the Tile at the given position (head, bottom left, is at pos 1) */
		//traverse the whole board and then finds the tile with respected position to return it
		int x = 1;
		Tile* temp = head;
		while (x != pos) {
			if (x % 10 != 0) {
				temp = temp -> next;
			}
			else {
				temp = temp -> up;
			}
			x++;
		}
		return temp;
	}
	void setLader() {
		//A function to set the lader
		//means 
		//Ist it will be counting all the lader and will save their initial from bottom
		//position accordingly and name of lader in respective arrays
		int i = 1;
		//int countladers;
		Tile* temp;

		string Lader_arr[100];
		int Lader_pos_arr[100];

		int p = 0;
		int x = 0;
		/**************************Initial Part Working******************************/
		/*******************Counting the laders and savind their data****************/
		while (i <= 100) {
			temp = GetTile(i);

			if (temp -> data[0] == 'l' || temp -> data[0] == 'L') {
				bool found = false;
				for (int i = 0; i < p; i++) {
					if (temp -> data == Lader_arr[i]) {
						found = true;
					}
				}
				if (!found) {
					Lader_arr[p] = temp -> data;
					Lader_pos_arr[p] = i;
					p++;
				}
			}
			i++;
		}

		/*
		for (int i = 0; i < p; i++) {
			cout << Lader_arr[i];
			cout << Lader_pos_arr[i];
		}*/

		/*********************Now linking all the laders with their respective upper part****************/

		for (int u = 0; u < p; u++) {
			string ltstr = Lader_arr[u]; //ltstr= lader tail string
			int pt = Lader_pos_arr[u]; //pt=position temp
			Tile* lader_tail = GetTile(pt);
			lader_tail -> leadertail = true;
			pt++;
			while (pt <= 100) {
				Tile* lader_temp = GetTile(pt);
				if (lader_temp -> data == ltstr) {
					lader_tail -> up = lader_temp;
					lader_tail = GetTile(pt);
				}
				pt++;
			}
		}

		/*
		for (int i = 0; i < p; i++) {
			cout << endl;
			printlader(Lader_pos_arr[i]);
		}*/
	}
	void setSnake() {
		//A function to set the snake
		//means 
		//Ist it will be counting all the Snake and will save their initial from top 
		//position accordingly and name of Snake in respective arrays
		int i = 100;
		//int countladers;
		Tile* temp;
		string Snake_arr[100];
		int Snake_pos_arr[100];
		int p = 0;
		int x = 0;
		/**************************Initial Part Working******************************/
		/*******************Counting the snakes and savind their data****************/
		while (i >= 1) {
			temp = GetTile(i);

			if (temp -> data[0] == 's' || temp -> data[0] == 'S') {
				bool found = false;
				for (int i = 0; i < p; i++) {
					if (temp -> data == Snake_arr[i]) {
						found = true;
					}
				}
				if (!found) {
					Snake_arr[p] = temp -> data;
					Snake_pos_arr[p] = i;
					p++;
				}
			}
			i--;
		}

		/*		for (int i = 0; i < p; i++) {
				cout << Snake_arr[i];
				cout << Snake_pos_arr[i];
			}
		*/

		/*********************Now linking all the snakes with their respective upper part****************/
		for (int u = 0; u < p; u++) {
			string Shstr = Snake_arr[u]; //sts= Snake head string
			int pt = Snake_pos_arr[u]; //pt=position temp
			Tile* Snake_head = GetTile(pt);
			Snake_head -> snakehead = true;
			pt--;
			while (pt >= 1) {
				Tile* Snake_temp = GetTile(pt);
				if (Snake_temp -> data == Shstr) {
					Snake_head -> down = Snake_temp;
					//ladertail.
					Snake_head = GetTile(pt);
				}
				pt--;
			}
		}

		/*
		for (int i = 0; i < p; i++) {
		  cout << endl;
		  printSnake(Snake_pos_arr[i]);
		}*/
	}
	/*
	void printlader(int bottom_) {
		Tile* temp = GetTile(bottom_);
		while (temp != NULL) {
			cout << temp->next->data<<endl;
			temp = temp->up;

		}
	}
	void printSnake(int bottom_) {
		Tile* temp = GetTile(bottom_);
		while (temp != NULL) {
			cout << temp->next->data << endl;
			temp = temp->down;

		}
	}*/

	~boardLinkedList() {
		//deallocates the memory of every pointer
		int x = 1;
		Tile* temp = head;
		Tile* curr;
		while (x < 100) {
			curr = temp;
			if (x % 10 != 0) {
				temp = temp -> next;
			}
			else {
				temp = temp -> up;
			}
			free(curr);
			x++;
		}
		if (temp != NULL) {
			curr = temp;
			free(curr);
		}
	}
};

class Game {
	Queue < int > turnQueue; //An Int based Queue
	string* ptr; //a pointer to read the board
	boardLinkedList Board; //boardLinkedList Board;
	RollStack dice; //a stack based implementation of Rolling a DICE
	bool reversed = false; //A bool if reversal of Queue is Required
	bool dequeue = false;
	bool play = false;
	int t_players = 0;
	bool p1lose = false;
	bool p2lose = false;
public:

	Game(const std::string& filename, int num_players) {
		/**************Initializing Queue*****************/
		turnQueue.setSize(num_players);
		for (int i = 0; i < num_players; i++) {
			turnQueue.enqueue(i + 1);
			turnQueue.pos_enqueue(0);
		}
		t_players = num_players;
		//	turnQueue.enqueue(1);
		//	turnQueue.enqueue(2);
		//	turnQueue.enqueue(3);
		//	turnQueue.enqueue(4);
		//	turnQueue.enqueue(4);
		//turnQueue.setNullPos();

		/*
		Initialize the game board from the given file and setup players
		*/
		//filename_ = filename;

		ptr = arrayRead(filename); //fiel reading alongwith data arranging
		//and returning its pointer
		int i = 0;
		while (i < 100) {
			//inserting data in board
			Board.insert(ptr[i], i + 1);
			i++;
		}
		Board.setLader(); //Snake Linking
		Board.setSnake(); //Lader Linking

	}

	Queue < int >& GetTurnQueue() {
		/* Return your player turn queue */
		return turnQueue;
	}

	Tile* GetTile(int pos) {
		/* returns the Tile at the given position (head, bottom left, is at pos 1) */
		return Board.GetTile(pos);
	}

	bool IsLadder(int pos) {
		/* returns true if there is a ladder tail at 'pos' */

		string data = getData(pos);
		Tile* temp = GetTile(pos);
		if ((data[0] == 'l' || data[0] == 'L') && (temp -> leadertail == true)) {
			return true;
		}
		return false;
	}

	bool IsSnake(int pos) {
		/* returns true if there is a snake head at 'pos' */

		string data = getData(pos);
		Tile* temp = GetTile(pos);
		if ((data[0] == 's' || data[0] == 'S') && (temp -> snakehead == true)) {
			return true;
		}
		return false;
	}

	int TraverseBoard(int current_pos, RollStack& stack) {
		/*
	  Traverse the board and return the resulting position
	  beginning from 'current_pos' using the roll stack
	*/

	//		cout << "\nI am Current Position = " << current_pos<<endl;
	//if (!play) {
		int value = 0;
		int size = stack.size;
		int p = stack.size;
		int* arr = new int[stack.size];
		if (current_pos < 100) {
			if (!play) {
				if (current_pos == 0) {

					while (!stack.is_empty()) {
						//pop up all the stack 
						//and adding it to get a prefect new 
						//value

						value += stack.top();
					}
					if (value == 6 || value == 1) {
						//if vallue is 6 or 1 start the 
						//game for that specific player
						return current_pos + 1;
					}
					return 0;

				}
				else {
					//cout << "jhakas\n";
					while (!stack.is_empty()) {
						//Poping all the values of stack
						value += stack.top();
					}
					//			cout << "\nI am Value Total = " << value<<endl;

					if (value % 3 == 0) {
						//if sum of stack values having mod by 3 equal to zero
						// so reverse the queue
						//	cout << "\nI am Mode by 3 true\n";
						reversed = true;
						turnQueue.reverse();

					}
					if (IsLadder(value + current_pos)) {

						//	cout << "\nI am Ladder true at position"<<value+current_pos<<endl;
						Tile* temp = GetTile(value + current_pos);
						while (temp -> up != NULL) {
							temp = temp -> up;
							//	cout << temp->next->data;
						}
						//cout <<"\nI am your tile position"<< getpos(temp->data)<<endl;
						return getpos(temp -> next -> data) - 1;
					}
					if (IsSnake(value + current_pos)) {
						Tile* temp = GetTile(value + current_pos);
						while (temp -> down != NULL) {
							temp = temp -> down;
						}
						return getpos(temp -> data);
					}
					return value + current_pos;

				}
			}
			else {
				if (current_pos == 0) {
					int u = size;
					int v = size;
					while (!stack.is_empty()) {
						//pop up all the stack 
						//and adding it to get a prefect new 
						//value
						value = stack.top();
						arr[v - 1] = value;
						v--;

					}
					while (p > 0) {
						value += arr[p - 1];
						p--;
					}
					if (arr[0] == 1 || arr[0] == 6) {
						current_pos = 1;
						int j = size;
						while (j > 1) {
							if (arr[j - 1] + current_pos >= 100) {
								return 100;
							}
							if (IsLadder(arr[j - 1] + current_pos)) {

								//	cout << "\nI am Ladder true at position"<<value+current_pos<<endl;
								Tile* temp = GetTile(arr[j - 1] + current_pos);
								while (temp -> up != NULL) {
									temp = temp -> up;
									//	cout << temp->next->data;
								}
								//cout <<"\nI am your tile position"<< getpos(temp->data)<<endl;
								current_pos = getpos(temp -> next -> data) - 1;
							}
							else if (IsSnake(arr[j - 1] + current_pos)) {
								Tile* temp = GetTile(arr[j - 1] + current_pos);
								while (temp -> down != NULL) {
									temp = temp -> down;
								}
								current_pos = getpos(temp -> data);
							}
							else {
								current_pos += arr[j - 1];
							}
							j--;
							if (current_pos >= 100) {
								return current_pos;
							}
						}
						return current_pos;

					}
					else if (size > 2 && arr[0] == 6 && arr[1] == 6 && arr[2] == 6) {
						p1lose = true;
						return current_pos;

					}
					else if (size > 3 && arr[0] == 6 && arr[1] == 6 && arr[2] == 6 && arr[3] == 6) {
						p2lose = true;
						return current_pos;
					}
					else if (value % 3 == 0) {
						reversed = true;
						turnQueue.reverse();
						return current_pos;
					}
				}
				else {
					int u = size;
					int v = size;
					while (!stack.is_empty()) {
						//pop up all the stack 
						//and adding it to get a prefect new 
						//value
						value = stack.top();
						//	cout << value << "\t";
						arr[v - 1] = value;
						v--;

					}
					while (p > 0) {
						value += arr[p - 1];
						p--;
					}
					int j = size;

					if (size > 2 && arr[0] == 6 && arr[1] == 6 && arr[2] == 6) {
						p1lose = true;
						return current_pos;

					}
					else if (size > 3 && arr[0] == 6 && arr[1] == 6 && arr[2] == 6 && arr[3] == 6) {
						p2lose = true;
						return current_pos;
					}
					else if (value % 3 == 0) {
						reversed = true;
						turnQueue.reverse();
						return current_pos;
					}
					else {
						while (j > 0) {
							if (arr[j - 1] + current_pos >= 100) {
								return arr[j - 1] + current_pos;
							}
							if (IsLadder(arr[j - 1] + current_pos)) {

								//	cout << "\nI am Ladder true at position"<<value+current_pos<<endl;
								Tile* temp = GetTile(arr[j - 1] + current_pos);
								while (temp -> up != NULL) {
									temp = temp -> up;
									//	cout << temp->next->data;
								}
								//cout <<"\nI am your tile position"<< getpos(temp->data)<<endl;
								current_pos = getpos(temp -> next -> data) - 1;
							}
							else if (IsSnake(arr[j - 1] + current_pos)) {
								Tile* temp = GetTile(arr[j - 1] + current_pos);
								while (temp -> down != NULL) {
									temp = temp -> down;
								}
								current_pos = getpos(temp -> data);
							}
							else {
								current_pos += arr[j - 1];
							}
							j--;
							if (current_pos >= 100) {
								return current_pos;
							}
						}
						return current_pos;
					}
				}
			}
		}
		else {
			return current_pos;
		}
	}
	int getpos(string data) {
		//It will retrun the positionn of the 'data' String
		for (int i = 0; i < 100; i++) {
			if (data == ptr[i]) {
				return i + 1;
			}
		}
		return -1;
	}
	void RollDice(int value) {

		//pushing value on stack
		dice.push_roll(value);

		//		cout << "\nFront of TurnQueue = " << turnQueue.front() << endl;//1
		//		cout << "\nInitial Position of this player = " << turnQueue.getposfront() << endl;
		//		0

		int x = TraverseBoard(turnQueue.getposfront(), dice); //calling a function that will
		//get the current position and stack and it will do operations on it 
		//and will retrun the new position according to the given
		//Specific details & restrictions(Requiremtns)

		//		cout << "\nChanged Position of this player = " << x << endl;//1

		turnQueue.setPos(x); //Setting the position in the Queue

		//		cout << "\nFront of each player position is = " << turnQueue.getposfront();//1

		if (!reversed) {
			//turnQueue.dequeue();
			turnQueue.enqueue(turnQueue.dequeue()); //dequeue of the player in a circular form
			turnQueue.pos_enqueue(turnQueue.pos_dequeue());
			//	turnQueue.pos_dequeue();
		}
		else {
			reversed = false;
		}

		//		cout << "Mjjy dequeue ke dia gya\n";

		/*  Add a roll for the current player, update  turn queue accordingly */
	}

	void Play() {

		int win_players = 0;
		while (win_players != t_players - 1) {

			int x = 0;
			//= rand() % 6;
			srand(time(NULL));
			do {

				x = 1 + rand() % 5;
				//		cout << x;
				dice.push_roll(x);
				//srand(time));
			} while (x == 6);
			play = true;
			turnQueue.setPos(TraverseBoard(turnQueue.getposfront(), dice));
			if (turnQueue.getposfront() >= 100) {
				win_players++;
				cout << win_players << " Winner is P" << turnQueue.dequeue();
				cout << " With Position " << turnQueue.pos_dequeue() << endl;
			}
			else {
				if (!reversed && !p2lose) {
					//turnQueue.dequeue();
					turnQueue.enqueue(turnQueue.dequeue()); //dequeue of the player in a circular form
					turnQueue.pos_enqueue(turnQueue.pos_dequeue());
					//	turnQueue.pos_dequeue();
				}
				else if (reversed) {
					reversed = false;
				}
				else if (p2lose) {
					turnQueue.enqueue(turnQueue.dequeue()); //dequeue of the player in a circular form
					turnQueue.pos_enqueue(turnQueue.pos_dequeue());
					turnQueue.enqueue(turnQueue.dequeue()); //dequeue of the player in a circular form
					turnQueue.pos_enqueue(turnQueue.pos_dequeue());
				}
			}

			/*	Run the game until the required number of players
			  complete the game. Print all relevant outputs during play
			*/
		}
	}
	string getData(int pos) {
		//retruns a string of the data of a specific tile
		//after getting its position
		//string* ptr = arrayRead(filename_);
		int x = 1;
		Tile* temp = GetTile(pos);
		//cout << temp->data;
		string data = temp -> data;
		return data;
	}~Game() {
		ptr = NULL;
		delete ptr;
		/* deallocate and cleanup */
	}
};

#endif
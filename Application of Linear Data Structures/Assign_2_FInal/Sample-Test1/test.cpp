#include "pch.h"
#include"../Assign_2_FInal/Header.h"


//Test Case Description: Test case checks the game board for right allocation of snake and ladder.



//Test Case Description: Test case checks the game board for right allocation of snake and ladder.
//Marks: 4
TEST(CreateBoardTest, SnakeLadderPositions) {

	Game game("map.txt", 4);

	ASSERT_TRUE(game.IsLadder(4));

	ASSERT_TRUE(game.IsSnake(32));

	ASSERT_TRUE(game.IsLadder(67));

	ASSERT_TRUE(game.IsSnake(99));

}

//Test Case Description: Test case checks the game board for correct generation i.e. pointers pointing to correct tiles.
//Marks: 4
TEST(CreateBoardTest, BoardLinks) {

	Game game("map.txt", 4);

	for (int i = 1; i < 100; ++i) {

		Tile* current = game.GetTile(i);
		Tile* next = game.GetTile(i + 1);

		if (i % 10 != 0) {
			ASSERT_TRUE(current->next == next);
			ASSERT_TRUE(next->previous == current);
		}
		else {
			ASSERT_TRUE(current->up == next);
			ASSERT_TRUE(next->down == current);
		}
	}
}


//Test Case Description: Test case checks the game board for correct generation of edge tiles i.e. pointers pointing to correct tiles.
//Marks: 4
TEST(CreateBoardTest, EdgeTiles) {


	Game game("map.txt", 4);

	for (int i = 1; i < 10; ++i) {
		ASSERT_TRUE(game.GetTile(i)->down == NULL);
	}

	for (int i = 91; i <= 100; ++i) {
		ASSERT_TRUE(game.GetTile(i)->up == NULL);
	}
}

//Test Case Description: Ensure all players start off at position 0 and enter the game on the first roll 6
//Marks: 8
TEST(RollDiceTest, GameStart) {

	Game game("map.txt", 4);

	auto& queue = game.GetTurnQueue();

	for (int i = 1; i <= 4; ++i) {
		// P1 P2 P3 P4
		// P2 P3 P4 P1
		// P3 P4 P1 P2
		// P4 P1 P2 P3 
		ASSERT_TRUE(queue.front() == i);

		game.RollDice(6);
	}
}

//Test Case Description: Test the player turns when condition of rule e occurs. 
//Marks: 15
TEST(RollDiceTest, ReverseQueue) {


	Game game("map.txt", 4);

	for (int i = 1; i <= 4; ++i) {
		// bringing all players on the board
		game.RollDice(6);
	}

	auto& queue = game.GetTurnQueue();

	ASSERT_TRUE(queue.front() == 1);

	// roll divisible by 3, queue should reverse
	game.RollDice(3);

	ASSERT_TRUE(queue.front() == 4);

	ASSERT_TRUE(queue.back() == 1);
}

//Test Case Description: Test the player movement under normal circumstance i.e. no rule condition has met. 
//Marks: 15

TEST(MovePlayerTest, NormalTraversal) {


	Game game("map.txt", 4);

	RollStack stack;

	stack.push_roll(6);
	stack.push_roll(5);

	ASSERT_TRUE(game.TraverseBoard(44, stack) == 55);

	stack.empty();

	stack.push_roll(6);
	stack.push_roll(6);
	stack.push_roll(4);

	ASSERT_TRUE(game.TraverseBoard(13, stack) == 29);
}

//Test Case Description: Test the player board traversal when a player hits a ladder tail.
//Marks: 20

TEST(MovePlayerTest, LadderTraversal) {


	Game game("map.txt", 4);

	RollStack stack;

	stack.push_roll(3);

	ASSERT_TRUE(game.TraverseBoard(1, stack) == 39);

	stack.empty();

	stack.push_roll(6);
	stack.push_roll(1);
	ASSERT_TRUE(game.TraverseBoard(60, stack) == 92);
}
//Test Case Description: Test the player board traversal when a player hits a snake head.
//Marks: 20
TEST(MovePlayerTest, SnakeTraversal) {

	Game game("map.txt", 4);

	RollStack stack;

	stack.push_roll(8);

	ASSERT_TRUE(game.TraverseBoard(24, stack) == 6);

	stack.empty();

	stack.push_roll(6);
	stack.push_roll(6);
	stack.push_roll(2);
	ASSERT_TRUE(game.TraverseBoard(85, stack) == 63);
}
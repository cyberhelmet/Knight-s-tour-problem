/*
*	Game State ADT Implementation
*	Author: <<Abhishek Tamang ( 551272 ) and Sandip Adhikari ( 555242 )>>
*	Version: May 2021
*
*	This file holds the game_state ADT.  It comprises
*	the coordinate of the knight's current position
*	(as "row" and "column"), and the board (as a
*	two-dimensional array called "board").
*
*	YOU NEED TO MAKE CHANGES TO THIS FILE!
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "game_state.h"
#include "assig_three121.h"

// types
struct game_state_int
{
	int row;
	int column;
	int moves;
	square_state board[DIMENSION][DIMENSION];
};

/*
	*	init_game_state
	*	initialiser function.
	*	Pre-condition: none
	*	Post-condition: a game_state variable is created and pointed
	*					to by the first parameter.  Its row field
	*					is set to -1 its column field is set to -1,
	*					and each element in the board table is set
	*					to 'empty'
	*	Informally: creates an initial game_state
*/
void init_game_state(game_state *gp)
{
	int x, y; // row and column indices

	trace("init_game_state: init_game_state starts"); //This is for debug purpose

	*gp = (game_state)malloc(sizeof(struct game_state_int));
	(*gp)->row = -1;
	(*gp)->column = -1;
	for (x = 1; x <= DIMENSION; x++)
	{
		for (y = 1; y <= DIMENSION; y++)
		{
			init_square_state(&((*gp)->board[x - 1][y - 1]), x, y);
		}
	}
	(*gp)->moves = 0;

	trace("init_game_state: init_game_state ends"); //This is for debug purpose
}

/*
* 	get_row
*	Get function for row field.
*	Pre-condition: none
*	Post-condition: the value of the game_state variable's row
*					field is returned
*	Informally: return the game_state variable's row
*
*	return int the current row number of the knight
*/
int get_row(game_state s)
{
	trace("get_row: get_row starts and finishes"); //This is for debug purpose

	return s->row;
}

/*
* 	get_column
*	Get function for column field.
*	Pre-condition: none
*	Post-condition: the value of the game_state variable's column
*					field is returned
*	Informally: return the game_state variable's column
*
*	return int the current column number of the knight
*/
int get_column(game_state s)
{
	trace("get_column: get_column starts and finishes"); //This is for debug purpose

	return s->column;
}

/*
* 	set_row
*	Set function for row field.
*	Pre-condition: the given game_state is defined and the given row
*					is within the bounds of that game_state variable's
*					board
*	Post-condition: the value of the game_state variable's row
*					field is updated to the given int value
*	Informally: update the game_state variable's row
*
* Param r int value to be placed into the game_state's row field
*/
void set_row(game_state s, int r)
{
	trace("set_row: set_row starts"); //This is for debug purpose

	s->row = r;

	trace("set_row: set_row ends"); //This is for debug purpose
}

/*
* 	set_column
*	Set function for column field.
*	Pre-condition: the given game_state is defined and the given column
*					is within the bounds of that game_state variable's
*					board
*	Post-condition: the value of the game_state variable's column
*					field is updated to the given int value
*	Informally: update the game_state variable's column
*
*	Param c int value to be placed into the game_state's column field
*/
void set_column(game_state s, int c)
{
	trace("set_column: set_column starts"); //This is for debug purpose

	s->column = c;

	trace("set_column: set_column ends"); //This is for debug purpose
}

/*
	*	get_moves
	*	Get count of number of moves on the board.
	*	Pre-condition: the given game_state has at least one knight on it.
	*	Post-condition: the number of knights on the board is returned.
	*	Informally: determine the number of moves which have been made
	*
	*	return int the number of moves made on the board
*/
int get_moves(game_state g)
{
	trace("get_moves: get_moves starts and finishes"); //This is for debug purpose

	return g->moves;
}

/*
	*	set_moves
	*	Set count of number of moves on the board.
	*	Pre-Condition: the given game_state has been defined.
	*	Post-Condition: the moves field of the given game_state has been
	*					updated.
	*	Informally: remember how many moves have been made
*/
void set_moves(game_state g, int m)
{
	trace("set_moves: set_moves starts"); //This is for debug purpose

	g->moves = m;

	trace("set_moves: set_moves ends"); //This is for debug purpose
}
/*
	* 	get_square
	*	Get function for a square_state.
	*	Pre-condition: the given coordinate is within the bounds of the board
	*	Post-condition: the value of the indicated square_state variable
	*					is returned
	*	Informally: return the square_state in the game_state variable's board
	*
	*	Param int r the row component of the desired square's coordinate
	*	Param int c the column component of the desired square's coordinate
	*
	*	return square_state the nominated square_state
*/
square_state get_square(game_state g, int r, int c)
{
	trace("get_square: get_square starts and finishes"); //This is for debug purpose
	//checking if the provide row and column value lies within the board dimension's boundary
	if (valid(g, r, c))
	{
		g->row = r;	   //updating the row field
		g->column = c; //updating the column field
	}
	else
	{
		fprintf(stderr, "Provided row and column value isn't valid"); //error message
		exit(1);													  //terminates and gets out of this function
	}
	return g;
}

/*
	* 	set_square
	*	Set function for a square_state.
	*	Pre-condition: the given square_state value is defined and is within the
	*				   dimension of the board array
	*	Post-condition: the square of the board at the given coordinate is updated
	*					to the given square_state value
	*	Informally: update the game_state board variable's element to the given value
	*
	*	Param set_square s value to be placed into the game_state's board field
*/
void set_square(game_state g, square_state s)
{
	int r, c; // row and column of given square_state

	trace("set_square: set_square starts"); //This is for debug purpose
	//checking if the provided square_state values lie within the dimension of the board array or not
	if (valid(s, r, c))
	{
		g->row = r;	   //updating the row field
		g->column = c; //updating the column field
	}
	else
	{
		fprintf(stderr, "Provided row and column value isn't valid");
	}

	trace("set_square: set_square ends"); //This is for debug purpose
}

/*
	* 	valid
	*	Check whether a square is on the board
	*	Pre-condition: the given game_state is defined 
	*	Post-condition: true is returned if (r,c) is within the bounds
	*					of the given game_state variable's board field,
	*					and false is returned otherwise
	*	Informally: Return whether or not a square is on the board
	*
	*	Param r int row value to check
	*	Param c int column value to check
	*
	*	return bool whether the coordinate is on the board
	*/
bool valid(game_state g, int r, int c)
{
	bool check = false;						   //creating a new boolean with default value false
	trace("valid: valid starts and finishes"); //This is for debug purpose

	if ((r > 0) && (c > 0)) //check if the provided rows and column number is enough to form a square
	{
		if ((r <= g->row) && (c <= g->column)) //checking if the provided rows and column number exceed the board's maximum column and row size
		{
			check = true;
		}
	}
	return check;
}

/*
	* 	taken
	*	Check whether a square on the board has already been visited
	*	Pre-condition: the given game_state is defined and (r,c) is
	*					within the bounds of the given game_state
	*					variable's board field
	*	Post-condition: true is returned if (r,c) has been visited (i.e.
	*					is non-zero, and false is returned otherwise
	*	Informally: Return whether or not a square has been taken
	*
	*	Param r int row value to check
	*	Param c int column value to check
	*
	*	return bool whether the nominated square contains a queen
	*/
bool taken(game_state g, int r, int c)
{
	return (g->board[r - 1][c - 1] != 0); //comparing the boards position with zero where zero represents a location on board[][] that has not been visited
}

/*
* 	land
*	Visit a square on the board
*	Pre-condition: the given game_state is defined and (r,c) is
*					within the bounds of the given game_state
*					variable's board field
*	Post-condition: the square at (r,c) has been visited and it
*					has been recorded that this is the current
*					location of the knight in the given board
*	Informally: Visit a square
*
*	Param r int row value to use
*	Param c int column value to use
*/
void land(game_state g, int r, int c)
{
	trace("land: land starts"); //This is for debug purpose
	if (valid(g, r, c))			//checking validity of the provided row and column value
	{
		if (taken(g, r, c)) //checking if whether or not a square has been taken
		{
			if ((r == get_row(g)) && (c == get_column(g)))
			{
				set_row(g, r);	  //Updates the current row value
				set_column(g, c); //Updates the current column value
			}
		}
	}
	else
	{
		fprintf(stderr, "Provided row and column value not valid."); //Printing the error message
	}

	trace("land: land ends"); //This is for debug purpose
}

/*
* 	clone_game_state
*	Deeply clone a game_state
*	Pre-condition: the given game_state is defined
*	Post-condition: a deep clone of the given game_sate is returned
*	Informally: Copy a game
*
*	return game_state the independent copy of the game_state
*/
game_state clone_game_state(game_state g)
{
	game_state p;		 //Creating a new game state
	int length, width;	 // storing dimension of clone
	const int EMPTY = 0; //represents a location on board[][] that has not been visited
	trace("clone_game_state: clone_game_state starts");

	init_game_state(&p);
	p->row = g->row;									//Setting the row size of new game_state to same as old one
	p->column = g->column;								//Setting the column size of new game_state to same as old one
	p->board[(p->row) - 1][(p->column) - 1] = g->moves; //setting moves as of the old one
	//iterating through every square and cloning them
	for (int i = 0; i < DIMENSION; i++)
	{
		for (int j = 0; j < DIMENSION; j++)
		{
			//checking if the square has been visited or not
			if (g->board[i][j] != EMPTY)
			{
				p->board[i][j] = g->board[i][j];
			}
		}
	}

	trace("clone_game_state: clone_game_state finishes"); //This is for debug purpose

	return p;
}

/*
	* 	show_game_state
	*	Display a game state
	*	Pre-condition: the given game_state is defined
	*	Post-condition: the given game_state has been displayed on
	*					the standard output stream
	*	Informally: Print the board
*/
void show_game_state(game_state g)
{
	int x, y;

	trace("show_game_state: show_game_state starts"); //This is for debug purpose

	// for all rows
	for (x = 1; x <= DIMENSION; x++)
	{
		// print row separator
		printf("+");
		for (y = 1; y <= DIMENSION * 4 - 1; y++)
		{
			printf("-");
		}
		printf("+\n");

		// print all columns
		printf("|");
		for (y = 1; y <= DIMENSION; y++)
		{
			show_square_state(get_square(g, x, y));
			printf("|");
		}
		printf("\n");
	}

	// print row separator
	printf("+");
	for (y = 1; y <= DIMENSION * 4 - 1; y++)
	{
		printf("-");
	}
	printf("+\n");

	trace("show_game_state: show_game_state ends"); //This is for debug purpose
}
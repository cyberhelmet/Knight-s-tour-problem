/*
 *	Game Tree ADT Implementation
 *	Author: <<Abhishek Tamang ( 551272 ) and Sandip Adhikari ( 555242 )>>
 *	Version: May 2021
 *	
 *	This file holds the game_tree ADT which is a
 *	general game tree.  The game_tree is built using
 *	t_node ADTs.  A game_tree variable consists of a
 *	"root" field which refers to a t_node variable
 *	which has a "data" field, "parent" and "child" and
 *	"sibling" references, and a "level" value.
 *	
 *	YOU NEED TO MAKE CHANGES TO THIS FILE!
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "t_node.h"
#include "game_state.h"
#include "game_tree.h"
#include "assig_three121.h"

const int BASELEVEL = -1; //variable for initializing level field of game_tree
struct game_tree_int
{
	t_node root; // the node at the top of the tree
};

/*
	*	init_game_tree
	*	initialiser function.
	*	Pre-condition: none
	*	Post-condition: if the parameter value (e) is true then the 
	*					game_tree variable's "root" field is set to NULL
	*					otherwise the game_tree variable's "root" field
	*					refers to a new t_node variable containing the
	*					parameter value (o) of level with parameter 
	*					value (l) with a NULL parent and child, and a 
	*					NULL sibling
	*	Informally: creates either an empty tree or a leaf node as
	*				required
*/
void init_game_tree(game_tree *tp, bool e, void *o, int l)
{
	trace("game_tree: initialiser starts"); //This is for debug purpose

	*tp = (game_tree)malloc(sizeof(struct game_tree_int)); //Allocate memory for game_tree of size struct game_tree_int
	if (e)
	{
		(*tp)->root = NULL; //setting game_tree variable's "root" field  to NULL
	}
	else
	{
		init_t_node((&(*tp)->root), o, l); //initializing a new t_node variable containing the parameter value (o) of level with parameter value (l)

		trace("game_tree: initialiser ends"); //This is for debug purpose
	}

	/*
	*	is_empty_game_tree
	*	Emptiness test.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: true is returned if the game_tree variable is
	*					empty, false is returned otherwise
	*	Informally: indicate if the game_tree contains no nodes
	*
	*	return boolean whether or not the game tree is empty
*/
	bool is_empty_game_tree(game_tree t)
	{
		trace("is_empty_game_tree: is_empty_game_tree starts and ends"); //This is for debug purpose

		return (t->root == NULL); //checks if the the tree is empty or not, and returns true if NULL
	}

	/**
	*	get_data
	*	Get function for "root" instance variable's data value.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the value of the game_tree variable's data
	*					field is returned
	*	Informally: return the value within the root node
	*
	*	return void * the data item of the root node
*/
	void *get_data(game_tree t)
	{
		trace("get_data: get_data starts"); //This is for debug purpose

		if (is_empty_game_tree(t))
		{
			fprintf(stderr, "get_data: empty game tree");
			exit(1);
		}

		trace("get_data: get_data ends"); //This is for debug purpose
		return get_t_node_data(t->root);
	}

	/*
	*	get_level
	*	Get function for "root" instance variable's level value.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the value of the game_tree variable's data
	*					field's level is returned
	*	Informally: return the level value within the root node
	*
	*	return int the level number of the root node
*/
	int get_level(game_tree t)
	{
		int levelNo; //variable to store game_tree's level field's value

		trace("get_level: get_level starts"); //This is for debug purpose

		//Checks if the tree is empty or not
		if (!is_empty_game_tree(t))
		{
			levelNo = get_t_node_level(t->root); //Getting game_tree's level field value
		}
		else
		{
			fprintf(stderr, "game_tree is empty"); //Throw an error message
		}
		return levelNo;
	}

	/*
*	get_parent
*	Get function for "root" instance variable's parent value.
*	Pre-condition: the game_tree variable is defined and valid
*	Post-condition: the value of the game_tree variable's parent
*					field is returned in a newly constructed
*					game_tree variable
*	Informally: return the game_tree variable's parent
*
*	return game_tree the parent of the current node
*/
	game_tree get_parent(game_tree t)
	{
		game_tree p;

		trace("get_parent: get_parent starts"); //This is for debug purpose

		if (is_empty_game_tree(t))
		{
			fprintf(stderr, "get_parent: empty game tree");
			exit(1);
		}

		init_game_tree(&p, true, NULL, -1);
		p->root = get_t_node_parent(t->root);

		trace("get_parent: get_parent ends"); //This is for debug purpose
		return p;
	}

	/*
*	get_child
*	Get function for "root" instance variable's child value.
*	Pre - condition: the game_tree variable is defined and valid
*	Post - condition : the value of the game_tree variable's child
*					field is returned in a newly
*					constructed game_tree variable
*	Informally : return the game_tree variable's child
*
*	return game_tree the eldest child of the current node
*/
	game_tree get_child(game_tree t)
	{
		game_tree c;

		trace("get_child: get_child starts"); //This is for debug purpose

		if (is_empty_game_tree(t))
		{
			fprintf(stderr, "get_child: empty game tree");
			exit(1);
		}

		init_game_tree(&c, true, NULL, -1);
		c->root = get_t_node_child(t->root);

		trace("get_child: get_child ends"); //This is for debug purpose
		return c;
	}

	/*
	* 	get_sibling
	*	Get function for "root" instance variable's sibling value.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the value of the game_tree variable's sibling
	*					field is returned in a newly constructed 
	*					game_tree variable
	*	Informally: return the game_tree variable's sibling
	*
	*	return game_tree the next sibling of the current node
*/
	game_tree get_sibling(game_tree t)
	{
		game_tree s; //Creating a new game_tree variable

		trace("get_sibling: get_sibling starts"); //This is for debug purpose

		//Checking if the tree is empty or not
		if (!is_empty_game_tree(t))
		{
			init_game_tree(&s, true, NULL, BASELEVEL); //creating an empty tree by initializing the game_tree s
			s->root = get_t_node_sibling(t->root);	   //Fetching the data of  sibling field of (t->root) and passing it to root field of created game_tree
		}
		else
		{
			fprintf(stderr, "No sibling found"); //Throws an error message
		}
		return s;
	}

	/*
	*	set_data
	*	Set function for "root" instance variable's data field.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the t_node variable's data field is altered to
	*					hold the given (o) value
	*	Informally: store the given value in the root node of the
	*				game_tree variable
	*
	*	param o void * to install as data for root node
*/
	void set_data(game_tree t, void *o)
	{
		trace("set_data: set_data starts"); //This is for debug purpose

		if (is_empty_game_tree(t))
		{
			fprintf(stderr, "set_data: empty game tree");
			exit(1);
		}

		set_t_node_data(t->root, o);

		trace("set_data: set_data ends"); //This is for debug purpose
	}

	/*
	*	set_level
	*	Set function for "root" instance variable's level field.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the t_node variable's level field is altered
	*					to hold the given (l) value
	*	Informally: assign the given value as the level of the
	*				game_tree variable
	*
	*	param l level number for root of current game tree
*/
	void set_level(game_tree t, int l)
	{
		trace("set_level: set_level starts"); //This is for debug purpose

		//Checking if the game_tree is empty or not
		if (!is_empty_game_tree(t))
		{
			set_t_node_level(t->root, l); //setting the level field to hold provided interger value
		}
		else
		{
			fprintf(stderr, "set_level: empty game tree"); //Throw an error message
		}

		trace("set_level: set_level ends"); //This is for debug purpose
	}

	/*
	*	set_parent
	*	Set function for "root" instance variable's parent field.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the t_node variable's parent field is altered
	*					to hold the given (p) value
	*	Informally: assign the given value as the parent of the
	*				game_tree variable
	*
	*	param p game_tree to be set as parent of current game tree
*/
	void set_parent(game_tree t, game_tree p)
	{
		trace("set_parent: set_parent starts"); //This is for debug purpose

		if (!is_empty_game_tree(t))
		{
			fprintf(stderr, "set_parent: empty game tree");
			exit(1);
		}

		trace("set_parent: set_parent ends"); //This is for debug purpose
	}

	/*
	*	set_child
	*	Set function for "root" instance variable's child field.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the t_node variable's child field is altered
	*					to hold the given (c) value
	*	Informally: assign the given value as the child of the
	*				game_tree variable
	*
	*	param c game_tree to be set as eldest child of current game tree
*/
	void set_child(game_tree t, game_tree c)
	{
		trace("set_child: set_child starts"); //This is for debug purpose

		if (is_empty_game_tree(t))
		{
			fprintf(stderr, "set_child: empty game tree");
			exit(1);
		}

		set_t_node_child(t->root, c->root);

		trace("set_child: set_child ends"); //This is for debug purpose
	}

	/*
	*	set_sibling
	*	Set function for "root" instance variable's sibling field.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the t_node variable's sibling field is altered
	*					to hold the given (s) value
	*	Informally: assign the given value as the sibling of the
	*				game_tree variable
	*
	*	param s game_tree to be set as next sibling of current game tree
*/
	void set_sibling(game_tree t, game_tree s)
	{
		trace("set_sibling: set_sibling starts"); //This is for debug purpose

		//Checking if the game_tree is empty or not
		if (!is_empty_game_tree(t))
		{
			set_t_node_sibling(t->root, s->root); //assigning the given game_tree's root node as the sibling of the game_tree t
		}
		else
		{
			fprintf(stderr, "set_sibling: empty game tree"); //Throw an error message
		}

		trace("set_sibling: set_sibling ends"); //This is for debug purpose
	}

	/*
*	generate_levelBF
*	Generate the next level of the tree in a breadth-first manner
*	Pre-condition: the given tree is defined, the given queue
*				   is defined
*	Post-condition: an additional level of possible moves has
*					been added to the given game tree and each
*					tree node of the new level also has been
*					added to the queue.
*	Informally: generate the next level of the game tree
*
*	param q Queue of reachable but unexpanded game trees
*/
	void generate_levelBF(game_tree t, queue q)
	{
		const int HORIZ_MOVES[] = {-2, -1, +1, +2, +2, +1, -1, -2}; // moves left/right
		const int VERT_MOVES[] = {-1, -2, -2, -1, +1, +2, +2, +1};	// moves up/down
		const int MOVE_COUNT = 8;									// number of potential moves

		const int START = 0;			 //Beginning of the array
		int current_row, current_column; //Creating a current row and current column
		int updatedColumn, updatedRow;	 //The possible updates to the new row and new column

		game_tree *present_gameTree;					//Create new game tree
		game_tree past_gameTree;						//Creating new game tree
		game_state parent_gameState, present_gameState; //Creating new game states for cloning
		bool siblings_absence = true;					//boolean used to check if there is presence of siblings or not in the game_tree

		int updatedLevel;									//Root of the tree is updated to the level of children generated
		trace("generate_levelBF: generate_LevelBF starts"); //This is for debug purpose
		parent_gameState = (game_state)(get_data(t));		//pasing game_state to generate children and it's level

		updatedLevel = get_level(t); //getting value of level field of game_tree t and passing it to updatedLevel variable
		updatedLevel++;

		current_row = get_row(parent_gameState);	   //Updating current row to the location of knight
		current_column = get_column(parent_gameState); //Updating current column to the location of knight

		//To loop through the every possible moves
		for (int i = 0; i < MOVE_COUNT; i++)
		{
			//updating the  possible new row and new column of the knight
			updatedRow = current_row + VERT_MOVES[i];
			updatedColumn = current_column + HORIZ_MOVES[i];

			//Checks of the new new move is (valid and taken)or not
			if ((valid(parent_gameState, updatedRow, updatedColumn)) || (!taken(parent_gameState, updatedRow, updatedColumn)))
			{
				present_gameState = clone_game_state(parent_gameState); //Clone the new game_state based on the parent gameState passed on
				move(present_gameState, updatedRow, updatedColumn);		//Move the row and column to the newly cloned gameState

				present_gameState = malloc(sizeof(game_tree));							  //Creates new memory space for pointer
				init_game_tree(present_gameTree, false, present_gameState, updatedLevel); //initializing a new game_tree

				set_parent(*present_gameTree, t); //Created a new parent game tree that will always be a game tree if passed

				//Checks if there are siblings or not
				if (!siblings_absence)
				{
					set_sibling(past_gameTree, *present_gameTree); //previously created gametree is now thw present game tree
				}
				else
				{
					set_child(t, *present_gameTree); //The first child is generated and it sets the parent child
					siblings_absence = false;		 //Terminate future loops from entering in this code
				}

				add(q, *present_gameTree); //game tree is added to the queue in order to process
			}
			else
			{
				fprintf(stderr, " Invalid or taken space"); //Throw an error message
			}
		}
		trace("generate_levelBF: generate_levelBF ends"); //This is for debug purpose
	}

	/*
*	build_gameBF
*	Generate the game tree in a breadth-first manner
*	Pre-condition: the given queue and game tree are defined, and
*				   the given int value represents the desired depth
*				   of the tree
*	Post-condition: If the given tree isn't already deep enough, an
*					additional level of possible moves is added to
*					the given game tree and each tree node of the
*					new level also is added to the queue.
*					Finally, the next tree is determined by removing
*					the front of the queue and the process continues
*					until the queue is empty
*	Informally: generate the game tree from the current point
*				in a breadth-first manner until it is "d" levels
*				deep
*
*	param q Queue of reachable but unexpanded game trees
*	param d desired depth (length of tour) that game tree should be built to
*	return	the game tree with the first found solution, or an empty game
*			tree if there is no solution
*/

	game_tree build_gameBF(game_tree t, queue q, int d)

	{
		game_tree c;								//Current gametree to be worked on and update
		int desiredDepth = d;						//passing the provided desired depth of the tree to a new int variable
		trace("build_gameBF: build_gameBF starts"); //This is for debug purpose

		init_game_tree(&c, true, NULL, BASELEVEL); //Memory to hold the new created game tree

		c = t;	   //passing state game_tree t to newly created game_tree
		add(q, t); // Adding gametree to the queue to make sure it is not empty

		//checking If the given tree is of desired depth or not
		if (get_level(t) < desiredDepth)
		{
			generate_levelBF(c, q); //no solution found, leading to creation of more children
		}
		else
		{
			return t; //solution found, no more creation is required.
		}
		//checking if the provided queue is empty or not
		if (!is_empty_queue(q))
		{
			// determining next moves
			c = (game_tree)front(q);
			rear(q);								 //removing last gameTree from top of queue
			return build_gameBF(c, q, desiredDepth); //building next parts of the tree
		}
		else
		{
			// no solution found, returning an empty tree
			init_game_tree(&c, true, NULL, BASELEVEL);
			return c;
		}
		trace("build_gameBF: build_gameBF ends"); //This is for debug purpose
	}

	/*
*	generate_levelDF
*	Generate the next level of the tree in a depth-first manner
*	Pre-condition: the given tree is defined, the given stack
*				   is defined
*	Post-condition: an additional level of possible moves has
*					been added to the given game tree and each
*					tree node of the new level also has been
*					added to the stack.
*	Informally: generate the next level of the game tree
*
*	param k Stack of reachable but unexpanded game trees
*/
	void generate_levelDF(game_tree t, stack k)
	{
		const int HORIZ_MOVES[] = {-2, -1, +1, +2, +2, +1, -1, -2}; // moves left/right
		const int VERT_MOVES[] = {-1, -2, -2, -1, +1, +2, +2, +1};	// moves up/down
		const int MOVE_COUNT = 8;									// number of potential moves

		trace("generate_levelDF: generate_levelDF starts"); //This is for debug purpose

		const int START = 0;			 //Beginning of the array
		int current_row, current_column; //Creating a current row and current column
		int updatedColumn, updatedRow;	 //The possible updates to the new row and new column

		game_tree *present_gameTree;					//Create new game tree
		game_tree past_gameTree;						//Creating new game tree
		game_state parent_gameState, present_gameState; //Creating new game states for cloning
		bool siblings_absence = true;					//boolean used to check if there is presence of siblings or not in the game_tree

		int updatedLevel;									//Root of the tree is updated to the level of children generated
		trace("generate_levelDF: generate_LevelDF starts"); //This is for debug purpose
		parent_gameState = (game_state)(get_data(t));		//pasing game_state to generate children and it's level

		updatedLevel = get_level(t); //getting value of level field of game_tree t and passing it to updatedLevel variable
		updatedLevel++;

		current_row = get_row(parent_gameState);	   //Updating current row to the location of knight
		current_column = get_column(parent_gameState); //Updating current column to the location of knight

		//To loop through the every possible moves
		for (int i = 0; i < MOVE_COUNT; i++)
		{
			//updating the  possible new row and new column of the knight
			updatedRow = current_row + VERT_MOVES[i];
			updatedColumn = current_column + HORIZ_MOVES[i];

			//Checks of the new new move is (valid and taken)or not
			if ((valid(parent_gameState, updatedRow, updatedColumn)) || (!taken(parent_gameState, updatedRow, updatedColumn)))
			{
				present_gameState = clone_game_state(parent_gameState); //Clone the new game_state based on the parent gameState passed on
				move(present_gameState, updatedRow, updatedColumn);		//Move the row and column to the newly cloned gameState

				present_gameState = malloc(sizeof(game_tree));							  //Creates new memory space for pointer
				init_game_tree(present_gameTree, false, present_gameState, updatedLevel); //initializing a new game_tree

				set_parent(*present_gameTree, t); //Created a new parent game tree that will always be a game tree if passed

				//Checks if there are siblings or not
				if (!siblings_absence)
				{
					set_sibling(past_gameTree, *present_gameTree); //previously created gametree is now the present game tree
				}
				else
				{
					set_child(t, *present_gameTree); //The first child is generated and it sets the parent child
					siblings_absence = false;		 //Terminate future loops from entering in this code
				}

				push(k, *present_gameTree); //game tree is added to the stack in order to process
			}
			else
			{
				fprintf(stderr, " Invalid or taken space"); //Throw an error message
			}

			trace("generate_levelDF: generate_levelDF ends"); //This is for debug purpose
		}

		/*
*	build_gameDF
*	Generate the game tree in a depth-first manner
*	Pre-condition: the given queue and game tree are defined, and
*				   the given int value represents the desired depth
*				   of the tree
*	Post-condition: If the given tree isn't already deep enough, an
*					additional level of possible moves is added to
*					the given game tree and each tree node of the
*					new level also is added to the stack.
*					Finally, the next tree is determined by removing
*					the top of the stack and the process continues
*					until the stack is empty
*	Informally: generate the game tree from the current point
*				in a depth-first manner until it is "d" levels
*				deep
*
*	param s Stack of reachable but unexpanded game trees
*	param d desired depth (length of tour) that game tree should be built to
*	return	the game tree with the first found solution, or an empty game
*			tree if there is no solution
*/
		game_tree build_gameDF(game_tree t, stack s, int d)
		{

			trace("build_gameDF: build_game starts"); //This is for debug purpose

			int desiredDepth = d;					   //passing the provided desired depth of the tree to a new int variable
			init_game_tree(&c, true, NULL, BASELEVEL); //Memory to hold the new created game tree

			c = t;	   //passing state game_tree t to newly created game_tree
			push(s, t) // Adding gametree to the stack to make sure it is not empty

				//checking If the given tree is of desired depth or not
				if (get_level(t) < desiredDepth)
			{
				generate_levelBF(c, s); //no solution found, leading to creation of more children
			}
			else
			{
				return t; //solution found, no more creation is required.
			}
			//checking if the provided stack is empty or not
			if (!is_empty_stack(s))
			{
				// determining next moves
				c = (game_tree)front(s);
				pop(s);									 //removing last gameTree from top of stack
				return build_gameBF(c, s, desiredDepth); //building next parts of the tree
			}
			else
			{
				// no solution found, returning an empty tree
				init_game_tree(&c, true, NULL, BASELEVEL);
				return c;
			}

			trace("build_gameDF: build_gameDF ends"); //This is for debug purpose
		}

		/*
	*	to_string_game_tree
	*	String conversion for tree
	*	Pre-condition: none
	*	Post-condition: a string variable is returned consisting of the
	*				string representation of all items in the game_tree,
	*				from top to bottom in depth-first order, separated by
	*				" " and contained within "<" and ">"
	*	Informally: produce a string representation of the game tree
	*
	*	return (char *) printable contents of game tree
*/
		char *to_string_game_tree(game_tree t)
		{
			game_tree c;
			char *s;

			trace("to_string_game_tree: to_string_game_tree starts");

			if (is_empty_game_tree(t))
			{
				trace("to_string_game_tree: to_string_game_tree ends");
				return "<>";
			}
			else
			{
				s = (char *)malloc(200 * 5 * sizeof(char));

				sprintf(s, "%s (%d,%d) ", s, get_row(get_data(t)), get_column(get_data(t)));
				c = get_child(t);
				if (!is_empty_game_tree(c))
				{
					sprintf(s, "%s %s ", s, to_string_game_tree(c));
				}
				c = get_sibling(t);
				if (!is_empty_game_tree(c))
				{
					sprintf(s, "%s %s ", s, to_string_game_tree(c));
				}
			}

			trace("to_string_game_tree: to_string_game_tree ends");

			return s;
		}

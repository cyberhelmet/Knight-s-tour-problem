/*
 * Implementation for Queue using linked-list
 *	Author: <<Abhishek Tamang ( 551272 ) and Sandip Adhikari ( 555242 )>>
 *	Version: May 2021
 *
 *	This file holds the queue ADT.  It comprises
 *	a head-of-queue field (first).
 *
 *	YOU NEED TO MAKE CHANGES TO THIS FILE!
 */

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "queue.h"

// types
struct queue_int
{
	node first;
};

/*
*	init_queue
*	initialiser function.
*	Pre-condition: none
*	Post-condition: create a new queue variable with a NULL first
*					field and the address of it assigned to the
*					parameter (qp)
*	Informally: creates an empty queue
*/
void init_queue(queue *qp)
{
	trace("queue: Initialiser starts"); //This is for debug purpose

	*qp = (queue)malloc(sizeof(struct queue_int)); //Allocate memory for queue of size struct queue_int
	(*qp)->first = NULL;						   // Setting the first node of given queue to null

	trace("queue: Initialiser ends"); //This is for debug purpose
}

/*
*	is_empty_queue
*	Emptiness test.
*	Pre-condition: the queue variable is defined and valid
*	Post-condition: true is returned if the queue variable is
*					empty, false is returned otherwise
*	Informally: indicate if the queue contains no nodes
*
*	return boolean whether or not the queue is empty
*/
bool is_empty_queue(queue q)
{
	trace("is_empty_queue: is_empty_queue starts and ends"); //This is for debug purpose

	return (q->first == NULL); //Returns true if the queue is empty else false
}

/*
*	front
*	Find value at front of queue.
*	Pre-condition: the queue variable is defined and valid
*	Post-condition: the value at the front of queue is returned
*	Informally: find the value at the front of queue
*
*	return (void *) the value on front of the queue
*/
void *front(queue q)
{
	trace("front: front starts"); //This is for debug purpose

	//Checking if the queue is empty or not
	if (!is_empty_queue(q))
	{
		return get_data_node(q->first); //returning the value of the first item of the queue
	}
	else
	{
		fprintf(stderr, "Queue is empty."); //printing out the error message
	}
}

/*
*	rear
*	Remove head of the queue
*	Pre-condition: the queue variable is defined and valid
*	Post-condition: the value at the front of queue is deleted updating
*					the "first" field accordingly
*	Informally: delete the head of the queue
*/
void rear(queue q)
{
	trace("rear: rear starts"); //This is for debug purpose
	//Checking if the queue is empty or not
	if (!is_empty_queue(q))
	{
		q->first = get_next_node(q->first); //removing the first item of the queue and updating it with the next value accordingly
	}
	else
	{
		fprintf(stderr, "Queue is empty."); //printing out the error message
	}

	trace("rear: rear ends"); //This is for debug purpose
}

/*
*	add
*	Add item to back of queue
*	Pre-condition: the queue variable is defined and valid
*	Post-condition: a new node is created containing the parameter
*					value (o) in the data field and NULL in the
*					next field and this is inserted at the rear
*					of the linked list
*
*	Param o value to be added to back of queue
*/
void add(queue q, void *o)
{
	node member, test;		  // creating two new nodes
	init_queue(&member, o);	  //initializing node member with value of pointer o
	trace("add: add starts"); //This is for debug purpose

	//checking if the queue is empty or not
	if (!is_empty_queue(q))
	{
		test = q->first;					//updating the test node with the first node of the queue q
		while (get_next_node(test) != NULL) //traversing until the value of the test's next node  is not NULL
		{
			test = get_next_node(test); //updating the node test
		}
		set_next_node(test, member); //sets the next node of the node test with the node member
	}
	else
	{
		fprintf(stderr, "Queue is empty"); //printing out the error message
		q->first = member;				   //adding the new node as the first node of the queue
	}

	trace("add: add ends"); //This is for debug purpose
}

/*
*	to_string_queue
*	String conversion for queue
*	Pre-condition: none
*	Post-condition: a string variable is returned consisting of the
*				string representation of all items in the queue,
*				from left to right, separated by " " and contained
*				within "<" and ">"
*	Informally: produce a string representation of the queue
*
*	return (char *) printable contents of queue
*/
char *to_string_queue(queue q, char *f)
{
	node c;
	char *fmt = (char *)malloc(10 * sizeof(char));
	char *s = (char *)malloc(100 * 10 * sizeof(char));

	if (is_empty_queue(q))
	{
		s = "<>";
	}
	else
	{
		s[0] = '\0';
		sprintf(fmt, "%%s%s", f);
		c = q->first;
		while (c != NULL)
		{
			sprintf(s, fmt, s, *(int *)(get_data_node(c)));
			if (get_next_node(c) != NULL)
			{
				sprintf(s, "%s, ", s);
			}
			c = get_next_node(c);
		}
	}
	return s;
}

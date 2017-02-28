#include <stdio.h>
#include <stdlib.h>
#ifndef EXAMPLE01_H
#define EXAMPLE01_H
//Prevents multiple inclusion issues

typedef struct Node
{
	struct Node * next; //Compiler doesn't know this type is called Node yet
	struct Node * previous;
	int value;
} Node;

//static Node * Node_construct ( int val ); //static functions shouldn't be declared in header

Node * List_insert_sorted ( Node * head , int val );


Node * List_insert_stack ( Node * head , int val );

Node * List_insert_queue ( Node * head , int val );

Node * List_search ( Node * head , int val );

Node * List_delete ( Node * head , int val );

Node * List_delete2 ( Node * head , int val );

void List_print ( Node * head );

//static void List_print2Help ( Node * head);

void List_print2 ( Node * head );

void List_destroy ( Node * head );

void List_destroy2 ( Node * head );
#endif

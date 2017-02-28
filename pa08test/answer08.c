#include "answer08.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0


/* charcmp is used to to compare chars for isValidState(...)
 * This function is supplied to you.
 */


int charcmp(const void * a, const void * b)
{
    return *((char*)a) - *((char*)b);
}

/* This function is supplied to you.*/


int isValidState(const char * state)
{
    int len = strlen(state);
    if(len != 16) return FALSE;
    char buffer[17];
    strcpy(buffer, state);
    qsort(buffer, len, sizeof(char), charcmp);
    const char * valid = "-123456789ABCDEF";
    if(strcmp(valid, buffer) == 0)
	return TRUE;
    return FALSE;
}

/* This function is supplied to you.*/

int isValidMoveList(const char * moves)
{
    int len = strlen(moves);
    int i;
    for(i = 0; i <  len; ++i)
	if(moves[i] != 'R' && moves[i] != 'L' && 
	   moves[i] != 'U' && moves[i] != 'D')
	    return FALSE;
    return TRUE;
}

/* This function is supplied to you.*/

void printPuzzle(const char * state)
{
    int row, col;
    for(row = 0; row < SIDELENGTH; ++row) {
	for(col = 0; col < SIDELENGTH; ++col) {
	    printf(" %c", state[row*SIDELENGTH + col]);
	}
	printf("\n");
    }
}

/* This function is supplied to you.*/


int move(char * state, char m)
{
    int dx = 0;
    int dy = 0;
    switch(m) {
    case 'U': dy = -1; break;
    case 'D': dy = 1; break;
    case 'L': dx = -1; break;
    case 'R': dx = 1; break;
    default:
	fprintf(stderr, "Invalid move '%c'!\n", m);
	return FALSE;
    }
    char * strpos = strstr(state, "-");
    if(strpos == NULL) {
	fprintf(stderr, "Invalid state '%s'!\n", state);
	return FALSE;
    }
    int pos = strpos - state;
    int row = pos / SIDELENGTH;
    int col = pos % SIDELENGTH;
    if(row + dy < 0 || row + dy >= SIDELENGTH)
	return FALSE;
    if(col + dx < 0 || col + dx >= SIDELENGTH)
	return FALSE;

    // Now we know we have a valid move...
    int target_pos = (row+dy)*SIDELENGTH + (col+dx);

    // So swap 'pos' with 'target_pos'
    state[pos] = state[target_pos];
    state[target_pos] = '-';

    return TRUE;
}

/* This function is supplied to you.*/


void processMoveList(char * state, const char * movelist)
{
    int valid = TRUE;
    int ind = 0;
    int movelist_len = strlen(movelist);
    for(ind = 0; ind < movelist_len && valid; ++ind) 
	{
		if(!move(state, movelist[ind])) 
		{
			valid = FALSE;
		} 
    }
	    
    if(!valid) {
		printf("I\n");
    } 
	else {
		printf("%s\n", state);
    }
}

//You will need to complete the following functions (except for solve(...) and MoveTree_print(...))

MoveTree * MoveTree_create(const char * state, const char * moves)
{
	//Your code goes here
	MoveTree * n = malloc(sizeof(MoveTree));
	n -> state = strdup(state);
	n -> moves =  strdup(moves);
	n -> left = NULL;
	n -> right = NULL;
	return n; 
}

void MoveTree_destroy(MoveTree * node)
{
	//Your code goes here
	if(node == NULL){return;}
	MoveTree_destroy(node -> left);
	MoveTree_destroy(node -> right);
	free(node -> state);
	free(node -> moves);
	free(node);
}

MoveTree * MoveTree_insert(MoveTree * node, const char * state, const char * moves)
{
	//Your code goes here
	if(state == NULL || moves == NULL) { return node;}
	if(node == NULL){
		return MoveTree_create(state,moves);
	}
	int cmp = strcmp(state, node -> state);
	if (cmp < 0){ node -> left = MoveTree_insert(node -> left, state, moves);}
	if (cmp > 0){ node -> right = MoveTree_insert(node -> right, state, moves);}
	if (cmp == 0){
		if( strlen(node -> moves) >  strlen(moves)){
			strcpy(node -> moves, moves);
		}
	}
	return node;

}

MoveTree * MoveTree_find(MoveTree * node, const char * state)
{
	//Your code goes here
	if(node == NULL || state ==NULL ){return NULL;}
	MoveTree * find = NULL;
	int cmp = strcmp(state, node -> state);
	if (cmp < 0){ return MoveTree_find(node -> left, state);}
	if (cmp > 0){ return MoveTree_find(node -> right, state);}
	if (cmp == 0){ find = node;}
	return find;
}

/**
 * Print the moves in a move-tree.
 * This function is supplied to you.
 */
void MoveTree_print(MoveTree * node)
{
    if(node == NULL)
		return;
    printf("%s\n", node -> state);
    MoveTree_print(node -> left);
    MoveTree_print(node -> right);
}

/*Helper function for generateAll, you do *NOT* need to use this function but you may find it useful*/
void generateAllHelper(MoveTree * root, int n_moves, const char * state, char * movelist, int ind)
{    
	//Your code goes here
	if(ind == n_moves){ return;}
	char mm[4] = {'U','D','L','R' };
	int i;
	for(i = 0; i < 4; i++){
		char * dup_state = strdup(state);
		char m = mm[i];
		if(move(dup_state,m)){
			movelist[ind] = m;
			movelist[ind+1] = '\0';			
			MoveTree_insert(root,dup_state,movelist);
			generateAllHelper(root,n_moves,dup_state,movelist,ind+1);
		}
		free(dup_state);
   	}
}

MoveTree * generateAll(char * state, int n_moves)
{ 
	//Your code goes here
	char movelist[n_moves + 1];
	MoveTree * root = MoveTree_create(state," ");
	generateAllHelper(root, n_moves, state, movelist, 0);
	return root; 
}

/* This function is supplied to you.*/

char * solve(char * state)
{
    MoveTree * tree = generateAll(state, MAX_SEARCH_DEPTH);
    MoveTree * answer = MoveTree_find(tree, FINAL_STATE);
    char * movelist = NULL;
    if(answer != NULL){
		movelist = strdup(answer -> moves);
	}
    MoveTree_destroy(tree);
    return movelist;
}


#include "answer09.h"
#include <string.h>

/* This function has been completed for you */

Node * Node_construct(int val, int ind)
{
	Node * nd = calloc(1,sizeof(Node));
	nd->next = NULL;
	nd->value = val;
	nd->index = ind;
	
	return nd;
}

/* This function has been completed for you */

static Node * List_insertHelper(Node * head , int val, int ind)
{
	if(head == NULL)
	{
		return Node_construct(val,ind);
	}
	head-> next = List_insertHelper(head->next,val,ind+1);
	return head;
}

/* This function has been completed for you */

Node * List_insert ( Node * head , int val)
{
	return List_insertHelper(head,val,0);
} 

/* This function has been completed for you */

void List_destroy ( Node * head )
{
	if(head==NULL) return;
	List_destroy(head->next);
	free(head);
}

/* This function has been completed for you */

void List_print(Node * head)
{
	while(head !=NULL)
	{
		printf("[%d]:%d ",head->index,head->value);
		head = head->next;
	}
	printf("\n");
}

int List_length(Node * head)
{
	//Write your code here
	int len = 0;
	while(head != NULL){
		head = head -> next;
		len++;
	}
	return len; //Change this
}

int List_swap(Node * head, int index1, int index2)
{
	//Write your code here	
	int len = List_length(head);
	if(index1 < 0 || index1 >= len) { return EXIT_FAILURE; }
	if(index2 < 0 || index2 >= len) { return EXIT_FAILURE; }
	if(index1 >= index2) { return EXIT_FAILURE; }
	int i;
	int tempvalue;
	Node * temphead;
	for(i = 0; i < index1; i++) { head = head -> next; }
	tempvalue = head -> value;
	temphead = head;
	for(i = index1; i < index2; i++) { head = head -> next; }
	temphead -> value = head -> value;
	head -> value = tempvalue;
	return EXIT_SUCCESS;  
}

int List_read(Node * head, int ind)
{
	//Write your code here	
	int len = List_length(head);
	if(ind < 0 || ind >= len) { return -1; }
	int i;
	for(i = 0; i < ind; i++) { head = head -> next; }
	return head -> value; 
}

int List_write(Node * head, int ind, int val)
{
	//Write your code here	
	int len = List_length(head);
	if(ind < 0 || ind >= len) { return EXIT_FAILURE; }
	int i;
	for(i = 0; i < ind; i++) { head = head -> next; }
	head -> value = val;
	return EXIT_SUCCESS;
}

void List_qsortHelp(Node *head, int first, int last){
	if (first >= last){return;}
	int pivot = List_read(head,first);
	int low = first + 1;
	int high = last;
	while(low < high){
		while(low < last && List_read(head,low) < pivot) { low++; }
		while(high > first && List_read(head,high) > pivot) { high--; }
		if(low < high){ List_swap(head,low,high); }   
	}
	if(pivot > List_read(head,high)) { List_swap(head,first,high);}  // high is one ind before low
	List_qsortHelp(head, first, high-1);
	List_qsortHelp(head, low, last);
}

Node * List_qsort(Node * head, int length)
{
	//Write your code here
	List_qsortHelp(head, 0, length - 1);
	return head;	
}

Node * List_readFromTextFile(char * filename)
{
	//Write your code here
	char str[200];
	Node * head = NULL;
	FILE * fptr = fopen(filename,"r");
	if(fptr == NULL) {return NULL; }
	while(fgets(str,200,fptr) != NULL){
		if(strcmp(str,"\n") != 0){
		int num = atoi(str);
		head = List_insert(head,num);
		}
	}
	fclose(fptr);
	return head;
}

int List_writeToTextFile(Node * head, char * filename)
{
	//Write your code here
	FILE * fptr = fopen(filename,"w");
	if(fptr == NULL) {return EXIT_FAILURE; }
	while(head !=NULL)
	{
		char * str = malloc(sizeof(char) * 200);
		sprintf(str,"%d",head -> value);
		fputs(str,fptr);
		fputs("\n",fptr);
		free(str);
		head = head->next;
	}
	fclose(fptr);
	return EXIT_SUCCESS; //Change this
}

Node * List_readFromBinaryFile(char * filename)
{
	//Write your code here	
	FILE * fptr = fopen(filename,"rb");
	if(fptr == NULL) {return NULL; }
	Node * head = NULL;
	Node * temp = malloc(sizeof(Node));
	while(fread(temp,sizeof(Node),1,fptr) == 1){
	     head = List_insert(head , temp -> value);
	}	
	free(temp);
	fclose(fptr);
	return head;
}

int List_writeToBinaryFile(Node * head, char * filename)
{
	//Write your code here
	FILE * fptr = fopen(filename,"wb");
	if(fptr == NULL) {return EXIT_FAILURE; }
	while(head !=NULL)
	{
		fwrite(head,sizeof(Node),1, fptr);
		head = head->next;
	}
	fclose(fptr);
	return EXIT_SUCCESS; 
}


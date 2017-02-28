#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "answer06.h"

List * List_createNode(const char * str){
	char * newstr = strdup(str);		
	List * newNode = malloc(sizeof(List));
	if (newNode == NULL)
		return NULL;
	newNode -> str = newstr;
	newNode -> next = NULL;
	return newNode;
}

void List_destroy(List * list){
	List * temp;
	while(list != NULL){
		temp = list -> next;
		free(list -> str);
		free(list);
		list = temp;
	}
}

int List_length(List * list){
	int len = 0;
	while(list != NULL){
		len ++;
		list = list -> next;
	}
	return len;
}

List * List_merge(List * lhs, List * rhs, int (*compar)(const char *, const char*))
{
    	if(lhs == NULL){
	    return rhs;
    	}
	else if(rhs == NULL){
	    return lhs;
	}
	List * newList;
	//initiallize
	int cmp = compar(lhs->str, rhs->str);
	if(cmp <= 0) {
	    newList = lhs;
	    lhs = lhs->next;
	} else {
	    newList = rhs;
	    rhs = rhs->next;
	}
	List * newListHead = newList;

	while(rhs !=NULL && lhs != NULL) {    //iterating through
		cmp = compar(lhs->str, rhs->str);
		if(cmp <= 0) {
		    newList -> next = lhs;
		    lhs = lhs->next;
		} else {
		    newList -> next = rhs;
		    rhs = rhs->next;
		}
		newList = newList -> next;
   	}
   	if (lhs == NULL){     // copy remaining elements
   	     newList -> next = rhs;
  	}else{
  	     newList -> next = lhs;
  	}
	return newListHead;
}


List * List_sort(List * list, int (*compar)(const char *, const char*))
{
    int len = List_length(list);
    int i;
    if(len <= 1)
	return list;
    // Recursive case: split, sort and merge.
    // Split
    int leftLen = len / 2;
    List * lhs = list;
    List * rhs;
    for(i = 0; i < leftLen; i++){
       	if (i < leftLen - 1){
		list = list -> next;
	}
	else{
		rhs = list -> next;
		list -> next = NULL;
	}
    }
    lhs = List_sort(lhs,compar);
    rhs = List_sort(rhs,compar);
    List * result = List_merge(lhs,rhs,compar);
    return result;
}

// int main(int argc, char * * argv){
// 	List *list;
	
// 	list = List_createNode("aasdf");
// 	List *head = list;

// 	list -> next = List_createNode("kksdf");
// 	list = list -> next;

// 	list -> next = List_createNode("bsdf");
// 	list = list -> next;
	
// 	list -> next = List_createNode("iisef");
// 	list = list -> next;
	
// 	list -> next = List_createNode("iisdf");
// 	list = list -> next;
	
// 	list = head;    //back to head
// 	while(list != NULL){      //print list now
// 		printf("the str is %s\n",list->str);
// 		list = list->next;
// 	}

// 	list = head;    //back head
// 	list = List_sort(list,strcmp);    //sort
// 	while(list != NULL){     //print sorted list
// 		printf("the str is %s\n",list->str);
// 		list = list->next;
// 	}
// 	List_destroy(head);
// 	return 0;
// }

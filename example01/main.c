#include <stdlib.h>
#include "tree.h"
#include "list.h"


int main (int argc, char ** argv){

	TreeNode * root = NULL;
	root = Tree_insert(root,13);
	root = Tree_insert(root,14);
	root = Tree_insert(root,15);
	root = Tree_insert(root,7);
	root = Tree_insert(root,3);
	root = Tree_insert(root,4);
	root = Tree_insert(root,2);
	root = Tree_insert(root,11);
	root = Tree_insert(root,12);
	root = Tree_insert(root,10);
	root = Tree_insert(root,8);
	root = Tree_insert(root,9);
	Tree_print(root);
	root = Tree_delete(root,7);
	Tree_print(root);
	Tree_destroy(root);

	int sortedArray[10] = {1,3,5,6,7,8,9,10,11,12};

	root = arrayToBalBST(sortedArray,0,9);
	Tree_print(root);
	Tree_destroy(root);

	Node * head1 = NULL;
	Node * head2 = NULL;
	Node * head3 = NULL;

	head1 = List_insert_stack(head1, 8);
	head1 = List_insert_stack(head1, 5);
	head1 = List_insert_stack(head1, 10);
	List_print(head1);
	
	head2 = List_insert_queue(head2, 8);
	head2 = List_insert_queue(head2, 5);
	head2 = List_insert_queue(head2, 10);
	List_print(head2);

	head3 = List_insert_sorted(head3, 8);
	head3 = List_insert_sorted(head3, 5);
	head3 = List_insert_sorted(head3, 10);
	List_print(head3);
	
	List_destroy(head1);
	List_destroy(head2);
	List_destroy(head3);
	
	return EXIT_SUCCESS;

}

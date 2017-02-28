#include "tree.h"
#include <stdlib.h>
static TreeNode * TreeNode_construct ( int val )
{
	TreeNode * tn;
	tn = malloc ( sizeof ( TreeNode ));
	tn -> left = NULL ;
	tn -> right = NULL ;
	tn -> value = val ;
	return tn;
}
TreeNode * Tree_insert ( TreeNode * tn , int val )
{
	if (tn == NULL )
	{
		// empty , create a node
		return TreeNode_construct ( val );
	}
	// not empty
	if ( val == (tn -> value ))
	{
		// do not insert the same value
		return tn;
	}
	if ( val < (tn -> value ))
	{
		tn -> left = Tree_insert (tn -> left , val );
	}
	else
	{
		tn -> right = Tree_insert (tn -> right , val );
	}
	return tn;
}

TreeNode * Tree_search ( TreeNode * tn , int val )
{
	if (tn == NULL )
	{
		// cannot find
		return NULL ;
	}
	if ( val == (tn -> value ))
	{
		// found
		return tn;
	}
	if ( val < (tn -> value ))
	{
		// search the left side
		return Tree_search (tn -> left , val );
	}
	return Tree_search (tn -> right , val );
}


static void TreeNode_print ( TreeNode *tn)
{
	printf ("%d ",tn -> value );
}

static void Tree_printPreorder ( TreeNode *tn)
{
	if (tn == NULL )
	{
	return ;
	}
	TreeNode_print (tn);
	Tree_printPreorder (tn -> left );
	Tree_printPreorder (tn -> right );
}

static void Tree_printInorder ( TreeNode *tn)
{
	if (tn == NULL )
	{
	return ;
	}
	Tree_printInorder (tn -> left );
	TreeNode_print (tn);
	Tree_printInorder (tn -> right );
}

static void Tree_printPostorder ( TreeNode *tn)
{
	if (tn == NULL )
	{
	return ;
	}
	Tree_printPostorder (tn -> left );
	Tree_printPostorder (tn -> right );
	TreeNode_print (tn);
}
void Tree_print ( TreeNode *tn)
{
	printf ("\n\n ===== Preorder =====\n");
	Tree_printPreorder (tn);
	printf ("\n\n ===== Inorder =====\n");
	Tree_printInorder (tn);
	printf ("\n\n ===== Postorder =====\n");
	Tree_printPostorder (tn);
	printf ("\n\n");
}


TreeNode * Tree_delete ( TreeNode * tn , int val )
{
	if (tn == NULL ) { return NULL ; }
	if ( val < (tn -> value ))
	{
		tn -> left = Tree_delete (tn -> left , val );
		return tn;
	}
	if ( val > (tn -> value ))
	{
		tn -> right = Tree_delete (tn -> right , val );
		return tn;
	}
	// v is the same as tn -> value
	if ((( tn -> left ) == NULL ) && (( tn -> right ) == NULL ))
	{
		// tn has no child
		free (tn);
		return NULL ;
	}
	if (( tn -> left ) == NULL )
	{
		// tn -> right must not be NULL
		TreeNode * rc = tn -> right ;
		free (tn);
		return rc;
	}
	if (( tn -> right ) == NULL )
	{
		// tn -> left must not be NULL
		TreeNode * lc = tn -> left ;
		free (tn);
		return lc;
	}
	// tn have two children
	// find the immediate successor
	TreeNode * su = tn -> right ; // su must not be NULL
	while (( su -> left ) != NULL )
	{
		su = su -> left ;
	}
	// su is tn's immediate successor
	// swap their values
	tn -> value = su -> value ;
	su -> value = val ;
	// delete su
	tn -> right = Tree_delete (tn -> right , val );
	return tn;
}

void Tree_destroy ( TreeNode * n)
{
	if (n == NULL )
	{
	return ;
	}
	Tree_destroy (n -> left );
	Tree_destroy (n -> right );
	free (n);
}

TreeNode * arrayToBalBST(int arr[], int low, int high){

	if(low>high){
		return NULL;
	}
	int mid = (low+high)/2;
	TreeNode * root = NULL;
	root = Tree_insert(root,arr[mid]);
	root->left = arrayToBalBST(arr,low,mid-1);
	root->right = arrayToBalBST(arr,mid+1,high);

	return root;
}



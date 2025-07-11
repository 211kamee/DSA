#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

TreeNode *createTreeNode(int data)
{
	TreeNode *ptr = (TreeNode *)malloc(sizeof(TreeNode));

	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;

	return ptr;
}

void Inorder(TreeNode *root)
{
	if (root == NULL)
	{
		return;
	}

	Inorder(root->left);
	printf("%i ", root->data);
	Inorder(root->right);
}

void Preorder(TreeNode *root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%i ", root->data);
	Preorder(root->left);
	Preorder(root->right);
}
void Postorder(TreeNode *root)
{
	if (root == NULL)
	{
		return;
	}

	Postorder(root->left);
	Postorder(root->right);
	printf("%i ", root->data);
}

int main()
{
	TreeNode *myRootNode = createTreeNode(1);
	myRootNode->left = createTreeNode(2);

	myRootNode->left->left = createTreeNode(4);
	myRootNode->left->right = createTreeNode(5);

	myRootNode->left->right->left = createTreeNode(6);

	myRootNode->right = createTreeNode(3);
	myRootNode->right->left = createTreeNode(7);
	myRootNode->right->right = createTreeNode(8);

	myRootNode->right->right->left = createTreeNode(9);
	myRootNode->right->right->right = createTreeNode(10);

	Inorder(myRootNode);
	printf("\n");
	Preorder(myRootNode);
	printf("\n");
	Postorder(myRootNode);
	printf("\n");

	return 0;
}
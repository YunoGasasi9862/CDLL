#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "Binary.h"
#include "CDLL.h"
void InOrder(bnode_t* root, node_t** CDLL, node_t** Temp, int* flag);
node_t* bTreetoCList(bnode_t* root)
{
	node_t* CDLL = NULL;
	node_t* Temp = NULL;
	int flag = 0;
	InOrder(root, &CDLL, &Temp, &flag);


	//make it cyclic here!
	Temp = CDLL;
	while (Temp->next != NULL)
		Temp = Temp->next;
	//this is the cyclic part!
	Temp->next = CDLL;
	CDLL->prev = Temp;

	return CDLL;
}
void InOrder(bnode_t* root, node_t** CDLL, node_t** Temp, int *flag)
{

	if (root != NULL)
	{
		InOrder(root->left, CDLL, Temp, flag);
		

		if (*flag == 0)
		{
			*CDLL = AddBeginning(*CDLL, root->data);
			*flag = 1;
			*Temp = *CDLL;
		}
		else
		{

			addAfter(*Temp, root->data);
			*Temp = (* Temp)->next;

		}


		InOrder(root->right, CDLL, Temp, flag);
	}

}

int main(void)
{
	bnode_t* root = getBinaryNode(10);
	root->right = getBinaryNode(30);
	root->left = getBinaryNode(20);
	root->left->left = getBinaryNode(40);
	root->left->right = getBinaryNode(60);


	node_t* CDLL = bTreetoCList(root);

	return 0;
}
#include "tree.h"
#include <iostream>
using namespace std;


template <typename Type>
Node<Type>* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

template <typename Type>
void traverse(Node<Type>* head)
{
	Node* tmp = head;
	while (tmp)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
};

template <typename Type>
void deletion(Node<Type>* node)
{
	if (node->next)
	{
		node->next = node->next->next;
	}
};

template <typename Type>
void insertion(Node<Type>* node, Type val)
{
	Node<Type>* tmp = Node<Type>(val);
	tmp->next = node->next;
	node->next = tmp;
};

template <typename Type>
void printInorder(Node<Type>* node)
{
	if (node == NULL)
		return;

	
	printInorder(node->left);

	
	cout << node->data << " ";

	
	printInorder(node->right);
}
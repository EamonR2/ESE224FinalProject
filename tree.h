#pragma once


//template and binary tree in user.cpp
template <typename Type>
struct Node
{
	Type value;
	Node* next;
	Node() : next(nullptr) {}
	Node(Type x, Node* ptr = nullptr) : value(x), next(ptr) {}
	~Node() {}



};
template <typename Type>
void traverse(Node<Type>* head);
template <typename Type>
void deletion(Node<Type>* node);
template <typename Type>
void insertion(Node<Type>* node, Type val);
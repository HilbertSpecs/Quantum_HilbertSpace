#include<fstream>
#include<iostream>
#include<cmath>
#include<random>
#include<string>
#include<cstdlib>
#include<iomanip>
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
using namespace std;


template <class T>
class ListNode
{
public:
	T value;
	ListNode<T> *next;

	ListNode (T nodeValue)
	{
		value = nodeValue;
		next = NULL;
	}

};

template <class T>
class LinkedList
{
	private:
		ListNode<T> *head;
	public:
		LinkedList()
		{
			head = NULL;
		}
	~LinkedList();
	
	void appendNode(T);
	void insertNode(T);
	void deleteNode(T);
	void displayList() const;

};


template <class T>
void LinkedList<T>::appendNode(T newValue)
{
	ListNode<T> *newNode;
	ListNode<T> *nodePtr;
	
	newNode = new ListNode<T>(newValue);
	
	if(!head)
		head = newNode;
	else
	{
		nodePtr = head;
		
		while(nodePtr -> next)
			nodePtr = nodePtr -> next;
		nodePtr -> next = newNode;
	}

}


template <class T>
void LinkedList<T>::displayList() const
{
    
    ListNode<T> *nodePtr;
		
	nodePtr = head;
	
	while(nodePtr)
	{
        
		cout << nodePtr -> value << endl;
	
		nodePtr = nodePtr -> next;
	}

    
}

template <class T>
void LinkedList<T>::insertNode(T newValue)
{
	ListNode<T> *newNode;
	ListNode<T> *nodePtr;
	ListNode<T> *previousNode = NULL;

	newNode = new ListNode<T>(newValue);

	if(!head)
	{
		head = newNode;
		newNode -> next = NULL;
	}

	else
	{

		nodePtr = head;
		previousNode = NULL;
	
		while(nodePtr !=  NULL && nodePtr -> value < newValue)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr -> next;
		}

		if(previousNode == NULL)
		{
			head = newNode;
			newNode -> next = nodePtr;
		}
		else
		{
			previousNode -> next = newNode;
			newNode -> next = nodePtr;
		}
	}
}

template <class T>
void LinkedList<T>::deleteNode(T searchValue)
{
	ListNode<T> *nodePtr;
	ListNode<T> *previousNode;

	if(!head)
		return;
	if(head -> value == searchValue)
	{
		nodePtr = head -> next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;
		
		while(nodePtr != NULL && nodePtr -> value != searchValue)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr -> next;
		}

		if(nodePtr)
		{
			previousNode -> next = nodePtr -> next;
			delete nodePtr;
		}
	
	}
}

template <class T>
LinkedList<T>::~LinkedList()
{
	ListNode<T> *nodePtr;
	ListNode<T> *nextNode;
	
	nodePtr = head;
	
	while(nodePtr != NULL)
	{
		nextNode = nodePtr -> next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}	

#endif

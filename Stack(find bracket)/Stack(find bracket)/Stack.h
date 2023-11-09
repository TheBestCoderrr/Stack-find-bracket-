#pragma once
#include <iostream>
using namespace std;
template<typename T>class Node { 
public:    
	explicit Node(T value, Node* next = nullptr) { 
		this->next = next;        
		this->value = value; };    
	void setValue(T value) { this->value = value; }    
	void setNext(Node* next) { this->next = next; }    
	T getValue() const { return value; }    
	Node* getNext() const { return next; }    
template<typename T> friend ostream& operator<<(ostream& out, const Node<T>& node); 
private:    
	T value;    
	Node* next; 
}; 

template<typename T>ostream& operator<<(ostream& out, const Node<T>& node) { 
	out << node.value << '\t';    
	return out; 
}

template<typename T>class Stack { 
public:    
	Stack();    
	Stack(const Stack<T>& other);    
	Stack& operator=(const Stack& stack);    
	~Stack();    
	size_t size() const;    
	bool empty() const;    
	char top() const; 
	void  push(char value);    
	void  pop();    
	void  clear();    
template<typename T>    friend ostream& operator<<(ostream& out, const Stack<T>& stack); 
private:    
	Node<T>* head;    
	size_t   counter; 
}; 

template<typename T>
Stack<T>::Stack(const Stack<T>& other) : Stack() { *this = other; }

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other){    
	if (this == &other) return *this;    
	clear();    
	Node<T>* cur = other.head;    
	Node<T>* prev = nullptr;    
	while (cur) {        
		Node<T>* newNode = new Node<T>(cur->getValue());        
		if (!head)            
			head = newNode;        
		else            
			prev->setNext(newNode);        
		prev = newNode;        
		cur = cur->getNext();        
		counter++;    
	}    
	return *this;
}

template<typename T>ostream& operator<<(ostream& out, const Stack<T>& stack) {    
	Node<T>* cur = stack.head;    
	while (cur)    
	{        
		out << *cur << '\t';        
		cur = cur->getNext();    
	}    
	out << '\n';    
	return out;
}

template<typename T>Stack<T>::Stack() :head(nullptr), counter(0) {}
template<typename T>Stack<T>::~Stack(){    clear();}
template<typename T>size_t Stack<T>::size() const { return counter; }
template<typename T>bool Stack<T>::empty() const { return !counter; }

template<typename T>char Stack<T>::top() const{    
	if (head) return head->getValue(); 
	exit(5);
}

template<typename T>void Stack<T>::push(char value) { 
	head = new Node<T>(value, head);    
	++counter;
}

template<typename T>void Stack<T>::pop(){    
	if (!head) return;    
	Node<T>* delNode = head;    
	head = head->getNext();    
	delete delNode;    
	--counter;
}

template<typename T>void Stack<T>::clear(){    while (head) pop();}

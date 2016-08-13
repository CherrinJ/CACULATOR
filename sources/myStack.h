#pragma once
#ifndef __MYSTACK__H__
#define __MYSTACK__H__

#include <iostream>

using namespace std;

#define MAXSIZE 100

template <class T>
class MyStack
{
public:
	MyStack();
	~MyStack();

	bool IsEmpty(){return m_top == -1;}
	bool IsFull() {return m_top == m_full;}

	MyStack<T>& push(const T a_t);
	T pop();

private:
	int m_full;
	int m_top;
	T* m_stack;
};

template <class T>
MyStack<T>::MyStack():m_top(-1),m_full(MAXSIZE - 1)
{
	m_stack = new T[MAXSIZE];
}

template <class T>
MyStack<T>::~MyStack()
{
	delete[] m_stack;
}

template <class T>
MyStack<T>& MyStack<T>::push(const T a_t)
{
	if(!IsFull())
	{
		m_stack[++m_top] = a_t;
		return *this;
	}
	cout<<"out of range of stack"<<endl;
}

template <class T>
T MyStack<T>::pop()
{
	if (!IsEmpty())
	{
		return m_stack[m_top--];
	}
	cout<< "the stack is empty"<<endl;
}

#endif // #ifndef __MYSTACK__H__
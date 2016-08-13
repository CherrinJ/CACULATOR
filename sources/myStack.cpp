#include "myStack.h"

//template <class T>
//MyStack<T>::MyStack():m_top(-1),m_full(MAXSIZE - 1)
//{
//	m_stack = new T[MAXSIZE];
//}
//
//template <class T>
//MyStack<T>::~MyStack()
//{
//	delete[] m_stack;
//}
//
//template <class T>
//void MyStack<T>::push(T a_t)
//{
//	if(!IsFull())
//	{
//		m_stack[++m_top] = a_t;
//		return;
//	}
//	cout<<"out of range of stack"<<endl;
//}
//
//template <class T>
//T MyStack<T>::pop()
//{
//	if (!IsEmpty)
//	{
//		return m_stack[m_top];
//	}
//	cout<< "the stack is empty"<<endl;
//}

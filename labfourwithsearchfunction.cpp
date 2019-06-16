#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class node
{
	public:
	int data;
	node *next;
	node *prev;
};

class stack
{
	public:
	node *top, *bottom;
	stack()
	{
		top = NULL;
		bottom = NULL;
	}
	
	void push(int x);
	int pop();
	
};

int stack::pop()
{
	node *temp;
	if(top != NULL && top->prev == NULL)
	{
		return top->data;
	}
	else if(top != NULL)
	{
		temp = top;
		top = top -> prev;
		top -> next = NULL;
		temp -> prev = NULL;
		return temp -> data;
		
	}
	else
	{
		cout<<"List is empty"<<endl;
	}
	return 0;
}

void stack::push(int d)
{
	node *n = new node;
	n->data = d;
	if(top == NULL)
	{
		top = n;
		bottom = n;
	}
	else
	{
		n->prev = top;
		top->next = n;
		top = n;
	}
}

int search (node *x, int y, int value)
{
	int n;
	if (x -> data == value)
	{
		cout<<"Found it "<<value<<endl;
		return y;
	}
	if (x -> prev!= NULL)
	{
		cout<<x->data<<endl;
		y++;
		n = search(x -> prev, y, value);
	}
	else
	{
		cout<<"not found"<<endl;
		return 0;
	}
	
	return n;
}

int main()
{
	stack mystack;
	int i;
	for(int j = 0; j < 5; j++)
	{
		
		cout << "Enter five values to be entered into stack\n";
	    cin >> i;
	    mystack.push(i);
	}
	
	int q, l;
	cout<<"give me a number to search for"<<endl;
	cin>>q;
	l = search(mystack.top, 0, q);
	cout<<l<<endl;
	
	/*for(int k = 1; k<=5; k++)
	{
	int x = mystack.pop();           
	cout<<x<<endl;                  
	}*/
	
}

#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

int fib(int x)
{
	int y;

	if(x <= 3)
	{
		if(x == 1)
		{
			return 0;
		}
		return 1;
	}
	else
	{
		y = fib(x-1) + fib(x-2);
		return y;
	}
}

int main()
{
	int n;
	cout<<"gimme a number"<<endl;
	cin>>n;
	cout<<fib(n)<<endl;
}

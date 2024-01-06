#include <bits/stdc++.h>
using namespace std;
class Stack{
public:
	int* arr;
	int size;

	Stack()
	{
		size = 0;
	}
	void push(int element){
		size++;
		int* a = new int[size];
		a[0] = element;
		if (size!=1){
		for (int i = 1 ;i<size;i++)
		{
			a[i] = arr[i-1];
		}
		free(arr);
	}
		arr = a;
	}
	void pop()
	{
		size--;
		int* a = new int[size];
		for (int i = 0 ;i<size ;i++)
		{
			a[i] = arr[i+1];
		}
		free(arr);
		arr = a;
	}
	int peek()
	{
		if (size == 0)
		{
			cout << "Error: returned -1"<<endl;
			return -1;
		}
		return arr[0];
	}
	bool isEmpty()
	{
		if (size==0)
		{
			return true;
		}
		return false;
	}
};
int main()
{
	Stack s;
	
	for (int i =0 ; i<5 ;i++)
	{
		int a;
		cin >> a;
		s.push(a);
	}
	cout << (bool)s.isEmpty()<<endl;
	while (!s.isEmpty())
	{
		cout << s.peek()<<" ";
		s.pop();
	}
	cout << endl;
	cout << (bool)s.isEmpty()<<endl;
}
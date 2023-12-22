#include <bits/stdc++.h>
// #include <stack>
// last in first out
using namespace std;
int main()
{
	stack<string> s;
	// adding elements in stack
	s.push("Mr");
	s.push("Samrat");
	s.push("Ray");
	cout<< "Top element " <<s.top()<<endl;
	// pop is from back
	s.pop();
	cout<< "Top element " <<s.top()<<endl;
	s.pop();
	cout<< "Top element " <<s.top()<<endl;
	 s.pop();
	// we cant find top element if no element is present

	// finding size of stack
	cout <<"Size of stack "<<s.size() <<endl;

	// finding empty or not
	cout << "Empty or not " << s.empty() <<endl;

	// adding the elements again
	s.push("Mr");
	s.push("Samrat");
	s.push("Ray");

	// finding empty or not
	cout << "Empty or not(after adding elements ) " << s.empty() <<endl;

	return 0;
}

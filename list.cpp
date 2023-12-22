// made by using double link list
#include <bits/stdc++.h>
// to use #include <list>
using namespace std;
void printlist(list<int> l)
{
	for (int i:l)
	{
		cout << i <<" ";
	}
	cout << endl;
	return;
}
int main()
{
	list<int> l;
	// adding a element to the back of the list
	l.push_back(1);
	printlist(l);

	// adding a element to the back of the list
	l.push_front(2);
	printlist(l);

	// erase a element
	l.erase(l.begin());
	printlist(l);

    cout << "new list(let)  "<<endl;
    l.push_front(2);
	l.push_back(8);
	l.push_back(7);
	l.push_back(5);
	printlist(l);
    
    // pop back operation
    cout << "pop back operation "<<endl;
	l.pop_back();
	printlist(l);
	// pop front operation
	cout << "Pop front operation "<<endl;
	l.pop_front();
	printlist(l);

	// list size
	cout << "list size "<<l.size()<<endl;

	// copying the entire list into a new list
	cout << "Copied list "; 
	list<int> p(l);
	printlist(p);

	// making a list of same multiple elements
	list<int> q(5,100);
	cout << "Printing the new made list: ";
	printlist(q);

	
	return 0;
}
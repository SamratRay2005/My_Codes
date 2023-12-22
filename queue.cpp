#include <bits/stdc++.h>
using namespace std;
// first in first out

int main()
{
	queue<string> q;
	// adding elements to the queue
	q.push("Mr");
	q.push("Samrat");
	q.push("Ray");


	// first element
	cout << "First element: "<<q.front()<<endl;


	// size before pop
	cout <<"Size "<<q.size()<<endl;


	//pop function(pop from front)
	q.pop();
	cout << "First element: "<<q.front()<<endl;


	// size after pop
	cout <<"Size "<<q.size()<<endl;

	//back operation?
	cout << q.back()<<endl;
    
    
    // as size of q.size() changes so we cant directly run a loop from 0 to q.size() for printing --> we have to store the value in a variable use it in loop and print one by one and poping 
	return 0;
}

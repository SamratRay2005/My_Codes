#include <bits/stdc++.h>
using namespace std;
int main()
{
	// discontinuous memory location
	// using push_back operation
	deque<int> d ;
	d.push_back(7);
	for(int v:d)
	{
		cout << v<<" ";
	}
	cout << endl;
	// using push_front operation
	d.push_front(6);
	for(int v:d)
	{
		cout << v<<" ";
	}
	d.push_back(9);
	d.push_back(10);
	d.push_back(34);
	cout << endl;
	for(int v:d)
	{
		cout << v<<" ";
	}
	cout << endl <<"accessing the elements "<<endl;
	//accessing the elements
	cout << d[2] <<endl;
	// another process of accessing the elements
	cout << d.at(2) << endl;
	cout <<"front "<<d.front() <<endl;
	cout << "back " << d.back() <<endl;
	cout << "empty or not "<<d.empty()<<endl;
	//before erase
	cout << "before erase "<<endl;
	for(int v:d)
	{
		cout << v<<" ";
	}
	cout << endl;
	d.erase(d.begin(),d.begin()+1); //erase operation
	// above operation can be also written as d.erase(d.begin()); ->It gives the same output
	

	//after erase
	cout << "after erase "<<endl;
    for(int v:d)
	{
		cout << v<<" ";
	}
	cout << endl;
	return 0;
}
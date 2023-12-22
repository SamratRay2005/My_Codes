#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> v = {2,3,5,6,7};
	//iterator declaration
	vector<int>::iterator it = v.begin();
	for(int i =0 ; i<v.size() ;i++)
	cout << *(it+i) << " "; 
	cout << endl;
	//different way of iterating
	for(it = v.begin() ; it!=v.end() ;it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	// different way of iterating
	for (int val :v)
	{
		cout << val << " ";
	}
	cout << endl<<endl<<endl;
	//v.begin() point on the first block of the vector
	// v.end() point on the block after last element
	//it++->next iterator (can be used in map)
	//it+1 ->next location (cannot be used in map)


	// iterator for a vector of pointer
	vector <pair<int,int>> v1 = {{1,2},{2,3}};
	vector <pair<int,int>> :: iterator t;
	t = v1.begin();
	cout << (*t).first << " " << (*t).second <<endl;
	cout << t->first << " " << t->second <<endl;
	// above two give the same output


	//use of auto keyword(can assign data type automatically)
	for (auto p:v1)
	{
	    cout << p.first << " " << p.second <<endl;
	}

	return 0;
}
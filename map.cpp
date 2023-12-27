#include <bits/stdc++.h>
using namespace std;
int main()
{
	map<int,string> m;
	m[1] = "Samrat";       // 1=>key Samrat=>value
	m[2] = "Ray";
	m[11] = "Mr";
	for (auto i:m)
	{
		 cout << i.first << " "<<i.second <<endl;
	}
   cout <<endl;

	cout << "finding 11-> "<<m.count(11)<<endl<<endl;   //1=>YES 0=>NO


	  //erasing
	m.erase(11);
    cout << "New arrangement after erasing "<<endl;
	for (auto i:m)
	{
		 cout << i.first << " "<<i.second <<endl;
	}
	m[11] = "Mr"; //adding it back
	// using find operations
	auto it = m.find(2);

	cout << "find operation:- "<<it->second <<endl;
}
//all operation time complexity O(log(n))
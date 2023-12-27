#include<bits/stdc++.h>
// only unique elements is stored ----> #include<set> used
// in ordered set numbers are stored in order
using namespace std;
void printset(set<int> s)
{
	for(int i:s)
	{
		cout << i<<" " ;
	}

	cout <<endl ;
	return ;
}
int main()
{
	set<int>  s;
	// to add elements
	s.insert(5);
	s.insert(1);
	s.insert(1);
	s.insert(1);
	s.insert(7);
	printset(s);

	// returning the iterator of the key element
	set<int> :: iterator itr = s.find(5);
	cout << "value at itr => "<< *itr <<endl;


	//element 5 is present or not
	// 1=>yes
	//0=>no
	cout <<"Element 5 present? "<<s.count(5)<<endl;


	// erase operation
	s.erase(s.begin());
	printset(s);

	//again inserting the  element 1
	s.insert(1);


	// deleting the 2nd element=>5
	auto it = s.begin();
	s.erase(++it);
	printset(s);

	//element 5 is present or not
	// 1=>yes
	//0=>no
	cout <<"Element 5 present? "<<s.count(5)<<endl;



	return 0;
}

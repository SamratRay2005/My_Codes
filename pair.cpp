#include <bits/stdc++.h>
using namespace std;
void printpair(pair<int,string> &p)
{
	cout << p.first << " " << p.second<<endl;
}
int main()
{
	pair<int,string> p1 = make_pair(2,"abc");
	cout << "P1 : ";
	printpair(p1);
	pair<int,string> p2 = make_pair(3,"def");
	cout << "P2 : ";
	printpair(p2);
	swap(p1,p2);
	cout << "NEW P1 : ";
	printpair(p1);
	cout << "NEW P2 : ";
	printpair(p2);
	return 0;
}
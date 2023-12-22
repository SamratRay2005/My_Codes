#include <bits/stdc++.h>
using namespace std;
// &v gives the same value of v rather than the copied value
void printvector(vector<int> &v)
{
	// v.size() finds the size of array
	for (int i = 0 ; i<v.size() ; i++)
	{
		cout << v[i] <<" ";
	}
	cout << endl;
	return;
}
int main()
{
	//dynamic size array(continuous size allocation)
	vector<int> v;
	v = {2,3,4,5,6};
	cout << "v" <<endl;
	printvector(v);
	v.push_back(7);
	v.push_back(8);
	cout << "New v"<<endl;
	printvector(v);
	cout << "v1"<<endl;
	vector<int> v1(10,3);
	printvector(v1);
	//v.pop_back() removes one element from the end
	cout << "New v"<<endl;
	v.pop_back();
	printvector(v);
    // front & back operation
    cout << "front: "<< v.front() <<" back: "<<v.back()<<endl;
    // front and back return the first and last operations respectively
    
    // capacity
    cout << "capacity " << v.capacity() << endl;
    cout <<endl<<endl;
	cout << "VECTOR OF PAIRS"<<endl;
	vector<pair<int,int>> v3 = {{1,3},{2,4}};
	cout << v3[0].first << " " << v3[0].second<<endl;
	cout << v3[1].first << " " << v3[1].second<<endl<<endl<<endl;


	cout << "ARRAY OF VECTORS"<<endl;
	vector<int> v4[2];
	for (int i = 0 ; i<2 ;i++)
	{
		v4[i].push_back(i+1);
		v4[i].push_back(i+2);
	}
	cout << v4[0][0] << " " << v4[0][1]<<endl;
	cout << v4[1][0]<< " " << v4[1][1]<<endl;
	// vector of vector-> vector<vector<int>>> v; //not covered
	return 0;
}
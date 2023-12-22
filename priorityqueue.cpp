// either access the elements by max order
// or access the elements by min order

#include <bits/stdc++.h>
using namespace std;
int main(){
	priority_queue<int> maxi;   // max heap

	priority_queue< int , vector<int> ,greater<int> > min;   //min heap

	cout <<"MAX HEAP CASE "<<endl;
	// adding element to max heap
	maxi.push(1);  
	maxi.push(4);  
	maxi.push(5);  
	maxi.push(2);  
	maxi.push(3);  
	cout << endl <<"Is Empty(maxi) "<<maxi.empty()<<endl;
	// size function
	cout << "Size "<<maxi.size()<<endl<<"Using pop operation to print"<<endl;
	int n = maxi.size();
	for (int i=0 ; i<n ;i++)
	{
		cout << maxi.top()<< " ";
		maxi.pop();
	}
	cout << endl <<"Is Empty(maxi) "<<maxi.empty()<<endl;
	// cant directly use maxi.size() in place of n as value of maxi.size() decreses

	cout<<endl<<endl<<endl;

	cout << "MIN HEAP CASE "<<endl;
	// adding element to min heap
	min.push(1);  
	min.push(4);  
	min.push(5);  
	min.push(2);  
	min.push(3);  
cout << endl <<"Is Empty(min) "<<min.empty()<<endl;
	// size function
	cout << "Size "<<min.size()<<endl<<"Using pop operation to print"<<endl;
	int n1 = min.size();
	for (int i=0 ; i<n1 ;i++)
	{
		cout << min.top()<< " ";
		min.pop();
	}
	cout << endl <<"Is Empty(min) "<<min.empty()<<endl;

	// cant directly use min.size() in place of n1 as value of min.size() decreses



	return 0;
}
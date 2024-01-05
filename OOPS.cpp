#include <bits/stdc++.h>
using namespace std;
//by default the element of hero is private
// for accessing element we have to use getter and setter
// or for accessing we can convert it to public
class hero{
public:
	int health;
	char level;
	void print()
	{
		cout << level <<endl;
	} 
private:
	int l2;
	int l3;
public:
	int getl2(){
		return l2;
	}
	int getl3(){
		return l3;
	}
	void setl2(int a)
	{
		l2= a;
	}
	void setl3(int b)
	{
		l3 = b;
	}



	// constructor
	hero(){
		cout <<"Constructor is called"<<endl;
	}


	// // constructor can also be paramiterised
	// hero(int health)
	// {
	// 	this->health = health;
	// 	// this keyword is a pointer to the health of hero class variable 
	// }

 

};
int main()
{
	hero h1;
	// for paramiterised constructor hero h1(10); 10 is the value of health

	h1.health = 5;
	h1.level = 'a';
	// access the print function
	h1.print();


	// //copy constractor (copy h1 to h2)
	// hero h2(h1);



	//using getter and setter
	cout << "getter setter"<<endl;
	h1.setl2(43);
	h1.setl3(34);
	cout << h1.getl2()<<endl;
	cout << h1.getl3()<<endl;
	// l2 and l3 might be private but getter and setter are public


	//read padding and greedy allignment



	//dynamic allocation of object
	hero *h2 = new hero; // also can be written as hero* h2 = new hero(); 
	h2->health = 24;
	cout << "dynamic "<<endl<< h2->health<<endl;


	// when we create a object a constructor is called
	// constructor -> invocked during object creation , No return type

	// hero h1; ->when we make a object <-()-> constructor->h1.hero(){} is called



}
#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
};
typedef node element;
typedef node* link;
link head;




//push_back operation
void push_back(link p)
{
    cout << "DO YOU WANT TO CONTINUE?(y/n)"<<endl;
    char c;
    cin >> c;
    if (c=='y')
    {
        link k = (link)malloc(1*sizeof(element));
        cout << "Enter element "<<endl;
        p->next = k;
        cin >> k->data;
        k->next = NULL;
        push_back(k);
    }
    else{
        return;
    }
}


// traversal operation
void traversal(link p,int c)
{
    if (p==NULL)
    {
        cout << "]"<<endl;
        return;
    }
    if (c==0)
    {
        cout <<"[ ";
    }
    cout << p->data<<" ";
    c++;
    p = p->next;
    traversal(p,c);
}


//sorting opration
void sort(link p)
{
    if (p==NULL)
    {
        return;
    }
    link k = p;
    int min = p->data;
    link temp = p;
    while (k!=NULL)
    {
        if (k->data<min)
        {
            min = k->data;
            temp = k;
           
        }
         k = k->next;
    }
    int t = temp->data;
    temp->data = p->data;
    p->data = t;
    // swap(temp->data,p->data);
    k = p->next;
    sort(k);
}



//storing the value into a vector
vector<int> arr;
void get_it(link p)
{
     if (p==NULL)
    {
        return;
    }
    arr.push_back(p->data);
    p = p->next;
    get_it(p);
}



// remove operation
void remove(link p,int id)
{
   if (id==1)
   {
    link k = p->next;
    free(head);
    head = k;
    return;
   }
    while (id!=2)
    {
        p = p->next;
        id--;
    }
     link k = p->next;
     link l = k->next;
     free(k);
     p->next = l;
     return;
}


// length finding operation
int length(link p)
{
    int ans = 0;
    while (p!=NULL)
    {
        ans++;
        p = p->next;
    }
    return ans;
}


// inserting operation 
void insert(link p , int id)
{
    if (id == 1)
    {
        link k = (link)malloc(sizeof(element));
        cout << "Enter the new data "<<endl;
        cin >>k->data;
        k->next = head;
        head = k;
        return;
    }
     while (id!=2)
    {
        p = p->next;
        id--;
    }
    link k = (link)malloc(sizeof(element));
    cout << "Enter the new data "<<endl;
    cin >> k->data;
    k->next = p->next;
    p->next = k;
}

int main()
{
    head = (link)malloc(1*sizeof(element));
    cout << "Enter element "<<endl;
    cin >> head->data;
    head->next = NULL;
    push_back(head);
    traversal(head,0);
    sort(head);
    traversal(head,0);
    get_it(head);
    cout << "Element index you want to delete"<<endl;
    int id;
    cin >> id;
    remove(head,id);
    traversal(head,0);
    cout << length(head)<<endl;

    cout << "Enter the index where you want to add"<<endl;
    cin >> id;
    insert(head,id);
    traversal(head,0);
}

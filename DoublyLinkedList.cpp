#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* next;
	node* prv;
};
typedef node element;
typedef node* link;
link head;

// push_back operation
void push_back(link p)
{

    cout << "DO YOU WANT TO CONTINUE?(y/n)"<<endl;
    char c;
    cin >> c;
    if (c=='y')
    {
        link k = (link)malloc(1*sizeof(element));
        cout << "Enter element "<<endl;
        cin >> k->data;
        p->next = k;
        k->prv = p;
        k->next = NULL;
        push_back(k);
    }
    else{
        return;
    }
}



// traversal operation
int c = 0;
void traversal(link p)
{

    if (p==NULL)
    {
        cout << "]"<<endl;
        c = 0;
        return;
    }
    if (c==0)
    {
        cout <<"[ ";
    }
    cout << p->data<<" ";
    c++;
    p = p->next;
    traversal(p);
}



//length of the linked list
int length(link p)
{
    int c = 0;
    while (p!=NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}


int siz = 0;




// inserting a node
void insert(int id)
  {
    link p = head;
    siz = length(head);
    if (siz+1<id)
    {
        cout <<"ERROR ->Element is not added(Wrong index)"<<endl;
        return;
    }
    if (id == siz+1)
    {
        link k = (link)malloc(sizeof(element));
        k->next = NULL;
        cout << "Enter element "<<endl;
        cin >> k->data;
        while ((p->next)!=NULL)
        {
            p = p->next;
        }
        p->next = k;
        k->prv = p;
        return;
    }

    if (id==1 )
    {
        link k = (link)malloc(sizeof(element));
        cout << "Enter element "<<endl;
        cin >> k->data;
        head->prv = k;
        k->prv = NULL;
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
    cout << "Enter element "<<endl;
    cin >> k->data;
    link l = p->next;
    k->prv = p;
    k->next = l;
    p->next = k;
    l->prv = k;
    siz = 0;
    return;
}



//deleting a node
void deleteNode(int id){
    if (id == 1)
    {
        link temp = head->next;
        head->next = NULL;
        head->prv = NULL;
        free(head);
        head = temp;
        head->prv = NULL;
        return;
    }
    if (id==length(head))
    {
        link temp = head;
        while (temp->next!=NULL)
        {
            temp = temp->next;
        }
        link k = temp->prv;
        temp->prv = NULL;
        free(temp);
        k->next = NULL;
        return;
    }
    link p = head; 
    while (id!=1)
    {
        p = p->next;
        id--;
    }
    link pre = p->prv;
    link post = p->next;
    free(p);
    pre->next = post;
    post->prv = pre;
}



int main()
{
   head = (link)malloc(sizeof(element));
   cout << "Enter element "<<endl;
   cin >> head->data;
   head->next = NULL;
   head->prv = NULL;
   push_back(head);
   traversal(head);
   cout<< "Enter the index where to input"<<endl;
   int id;
   cin >> id;
   insert(id);
   traversal(head);
   cout << "Enter the index to be deleted"<<endl;
   cin >> id;
   deleteNode(id);
   cout << "New List "<<endl;
   traversal(head);
   
}
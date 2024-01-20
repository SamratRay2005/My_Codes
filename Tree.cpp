/*
What is a tree?
In binary tree each node has child
Node give arrise to child
Sibling-> whose parents are same
root->top node is root node
ancestor -  top all node are ancestor
ancestors opposite is decendent
leaf node - no child is leaf node

Binary Tree
node{
	int data;
	node* left;
	node* right;

}

Tree with multiple child
node{
	int data;
	list<node*> childs;
}
*/




#include <bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node* left;
	node* right;
	node(int d) {
		this -> data = d;
		this -> left = NULL;
		this -> right = NULL;

	}
};

// builting the tree by going extreme left and then moving to the right in each node
void builttree(node* &root)
{
	cout << "Enter data "<<endl;
	int data;
	cin >> data;
	root = new node(data);
	if (data == -1)
	{
		root = NULL;
		return;
	}
	// first all left element
	cout << "Enter data for inserting left"<<endl;
	builttree(root->left);    
	// then all right element after left element
	cout << "Enter Data For inserting in right"<<endl;
	builttree(root->right);

}

// we access the element in accordance with each level
void levelordertraversal(node* root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	
	while (!q.empty())
	{
		node* temp = q.front();
		q.pop();
		if (temp == NULL)
		{
			cout << endl;
			if (!q.empty())
			{
				q.push(NULL);
			}
		}
		else
		{
			cout << temp->data<<" ";	
			if (temp -> left)
			{
				q.push(temp->left);
			}
			if (temp -> right)
			{
				q.push(temp->right);
			}
		}
	}

}


/* 
NOTE:-
Inorder traversal -> LNR
Pre Order traversal -> NLR
Post Order traversal -> LRN
*/

void inordertraversal(node* root)
{
	if (root==NULL)
	{
		return;
	}
	inordertraversal(root->left);
	cout << root->data << " ";
	inordertraversal(root->right);
	return;
}

void preorder(node* root)
{
	if (root==NULL)
	{
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
	return;
}

// similarly we can code for post order



// builting the tree from level order
// we have to use pass by reference
void builtfromlevelorder(node* &root)
{
	queue<node*> q;
	cout << "Enter root node data"<<endl;
	int data;
	cin >> data;
	root = new node(data);
	q.push(root);
	while (!q.empty())
	{
		node* temp = q.front();
		q.pop();

		cout << "Enter Left Node of "<<temp->data<<endl;
		int ld;
		cin >> ld;
		if (ld!=-1)
		{
			temp->left = new node(ld);
			q.push(temp->left);
		}


		cout << "Enter Right Node of "<<temp->data <<endl;
		int rd;
		cin >> rd;
		if (rd!=-1)
		{
			temp->right = new node(rd);
			q.push(temp->right);
		}

	}
}

 
int main()
{
	node* root = NULL;
	builttree(root);
	builtfromlevelorder(root);
	levelordertraversal(root);
	inordertraversal(root);
	cout << endl;
	preorder(root);
	cout << endl;
}



/* 
TEST CASES
for builttree we use
1
3
7
-1
-1
11
-1
-1
5
17
-1
-1
-1


for builtfromlevel we can use
1
3 5
7 11 17 -1
-1 -1 -1 -1 -1 -1
*/

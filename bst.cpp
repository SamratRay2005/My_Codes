#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* bst(node* root, int d)
{
    if (root==NULL)
    {
        root = new node(d);
        return root;
    }
    if (d<=root->data)
    {
        root->left = bst(root->left,d);
    }
    else
    {
         root->right =  bst(root->right,d);
    }
    return root;
}


void inorderTraversal(node* root)
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


bool searchInBST(node* root, int x) {
        if (root==NULL)
        {
            return false;
        }
        if (x>root->data)
        {
            return (false)|searchInBST(root->right,x);
        }
        else if (root->data>x)
        {
            return (false)|searchInBST(root->left,x);
        } else {
            return true;
        }
}

    node* deleteNode(node* root, int key) 
    {  
        if (!root) {
            return root;
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else {
            
            if (!root->left) {
                return root->right;
            }
            else if (!root->right) {
                return root->left;
            }
            node* replace = root->right;   
            while (replace->left) {
                replace = replace->left;
            }                        
            replace->left = root->left;
            return root->right;  
        }
        
        return root;
    }



int main()
{
    node* root =  NULL;
    cout << "Enter the number of nodes" << endl;
    int n;
    cin >> n;
    while (n-->0)
    {
        int d;
        cout << "Enter the value to be added" << endl;
        cin >> d;
        
        root = bst(root,d);
    }
    inorderTraversal(root);
    cout << "Enter the element to be searched" << endl;
    int x;
    cin >> x;
    if (searchInBST(root,x))
    {
        cout << "Found" << endl; 
    }
    else{
        cout << "Not Found" << endl;
    }

}
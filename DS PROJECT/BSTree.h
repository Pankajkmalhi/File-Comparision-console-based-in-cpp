#include <bits/stdc++.h>
#include<fstream> 

using namespace std; 

class BSTNode
{			     // Node of binary search tree
	public:
		
		string data;   // data 
		BSTNode* left;   // left node
		BSTNode* right;  // right Node
	
	BSTNode()
	{				   // constructor
		data = " ";
		left = NULL;
		right = NULL;
	}
	
	BSTNode(string d)
	{				   // parameterized constructor for data
		data = d;
		left = NULL;
		right = NULL;
	}
	
};

class BST
{    			 // class for binary search tree
	public:
		
		BSTNode *root;   //first node = root
		BST()
		{
			root = NULL;
		}
		
		void insert(string);   // insert data in tree
		void deletion();
};

void BST::insert(string d)
{

	BSTNode *newnode;
	newnode = new BSTNode(d);  //newnode->data = d
	BSTNode *par;   // parent Node
	
	if(root==NULL)
	{
		root = newnode;
	}
	
	else
	{
		par = root;
		
		while(par!=NULL)
		{
			if(par->data.compare(newnode->data)>0)
			{
				if(par->left==NULL)
				{
				        par->left = newnode;
				        break;
				}
					par = par->left;	
			}

			else if(par->data.compare(newnode->data)<0)
			{
				if(par->right==NULL)
				{
				        par->right = newnode;
				        break;
				}
					par = par->right;
			}
		}
	}
}

void inorder_insert(BSTNode *sentence1,linkedlist *list1)
{
	
	if(sentence1==NULL)
	{
	   return ; 
	}
	
	inorder_insert(sentence1->left,list1);
	list1->insertathead(sentence1->data);
	inorder_insert(sentence1->right,list1);
	
}

void BST::deletion()
{
	root = NULL;
}


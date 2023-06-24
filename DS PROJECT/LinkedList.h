#include <bits/stdc++.h>
#include <fstream> 
#include <iostream>
using namespace std; 

int sentence_count=0; 
int similar_count=0;

class Node
{ 			      // class Node which contain coefficient,base and power
	public:
		
		string data;
	    Node *next;
	    
	Node()
	{
	    data = " ";
	    next  =  NULL;
	}
	
	Node(string d)
	{
	    data = d;
    	next  =  NULL;
	}
};

class linkedlist
{			         // list that contains Node
	public:
	
		Node *head;
		
		linkedlist():head(0){ }
		void insertatindex(int ,Node* );
	    void deletelist();
	    void insertathead(string data);
	    void sentence_compare(linkedlist *);
	    
};

void linkedlist::insertathead(string data)
			{
				Node *nnode =new Node(data); 
				
				if(head==NULL)
				head = nnode;
				
				else
				nnode->next = head;
				head = nnode;
			}


void linkedlist::insertatindex(int index,Node *node1)
{															  // insert on the index of the list
    int i=1;
    Node *nnode,*curr;
    nnode = new Node(*node1);
    curr = head;
   
    if(index>0 &&head!=0)
	{
        while(curr->next!=NULL && i<index)
		{
        	curr = curr->next;
        	i++;
    	}
    		curr->next = nnode; 
   }
   
    else if(index==0)
	{
    	if(head==0)
		{
        	head = nnode;
      	}
      	
		else
		{
        	nnode->next = head;
        	head = nnode;
      	}
    }
}

void linkedlist::deletelist()
{
	head = NULL;
}

void linkedlist::sentence_compare(linkedlist *newlist)
{
	Node *curr;
	Node *curr1;
	curr1 = newlist->head;
	curr=head;
	int count=0,count1=0;
	
	while(curr!=head)
	{
	    if(curr->data.compare(curr1->data)==0)
		{
	        count1++;
		}
	        count++;
	}
		if(count==count1)
		{
			similar_count++;
		}
			  
}

void totalsimilarity()
{
	float percentage;
	percentage = (similar_count*100)/(sentence_count);
	cout<<endl;
	cout<<"	Following are the result derived from the given documents.\n";
	cout<<"	"<<percentage<<"%"<<" Plagiarism is Detected among Documents!\n";
}

string ConvertToLower(string str)
		       		{
		       			//Loop through the size of string
		       			for(int s=0; s<str.length(); s++)
		       			{
		       				//if the character is not a space
		       				if(str[s]!= ' ')
		       				{
		       					//Reset the values of the string to the 
								//new lower case letter
		       					str[s] = tolower(str[s]);
							   }
						   }
						   		return str;
    				}

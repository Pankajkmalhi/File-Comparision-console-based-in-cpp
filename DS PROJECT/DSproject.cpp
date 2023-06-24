#include <bits/stdc++.h>
#include <iostream>
#include <fstream> 
#include "LinkedList.h"
#include "BSTree.h"
#include "PlagChecker.h"
#include <string.h>

using namespace std; 

/* Driver code */
int main()  
{  
	system("color 0F");
	cout<<"\n					PLAGIARISM CHECKER\n\n";

	cout<<"	\n	Plagiarism is the practice of abuse of intellectual property rights belonging to another person  and  \n	the work  is recognized  invalid as  a  result  of personal  work";
    cout<<endl;
    cout<<"\n	A classification of  plagiarism  based  on  the proportion  or  percentage  of words,  sentences, or  \n	paragraphs hijacked,  is  divided  into three";
	cout<<endl<<"\n	Light  Plagiarism:  <30%\n	Middle Plagiarism: 30% - 70%\n	Total Plagiarism: >70%"<<endl;
	string txt[10000];  
    string sentence1 = " " ;
	string sentence2 = " " ;
    string pat[10000];
    char ch;
    int j;
    int q = 101; // A prime number  
    BST list1;
    BST list2;
    
    
	ifstream file1("file1.txt");
	ifstream file2("file2.txt");
	file2.close();
	
	char ch1=' ';
	int i=0;
	int k=0;
	int i1=1;
	int len;
	
	while(!file1.eof())
	{
		file1>>txt[i];
		for(j=0;j<txt[i].length();j++)
		{
			ch = txt[i][j];
			
			if(ch=='.' || ch==',')
			{
				
				sentence_count++;
	    }
        }
	  }
	file1.close();
	file1.open("file1.txt");
	
	while(!file1.eof())  
	{
		file1>>txt[i];
		list1.insert(txt[i]);
		sentence1 = sentence1+txt[i]; 
		i++;
		i1=1;
		
		for(j=0;j<txt[i-1].length();j++)   
		{
			ch = txt[i-1][j];
			
			if(ch=='.' || ch==',')
			{
				file2.open("file2.txt");
				k=0;
			   
			   while(!file2.eof())
			   {
		       		file2>>pat[k];
		       		list2.insert(pat[k]);
		       		
		       		sentence2 = sentence2+pat[k];
		        	k++;
		       		
					for(int j1=0;j1<pat[k-1].length();j1++)
					{
			   			ch1 = pat[k-1][j1];
			   			
			   			if(ch1=='.' || ch1==',')
						{
							pat[k-1] = " ";
	            			search(sentence1, sentence2,list1,list2, q);	
							sentence2 = " ";
							k=0;
							list2.deletion();
			    		}
		      		}
		      
         		}	
						sentence1 = " ";
						i1=0;
						file2.close();
						list1.deletion();
				
			}
			
	}
		if(i1==0)
		{
			i=0;
		}
		
}
	file1.close();
		
	totalsimilarity();
	    return 0;  
}

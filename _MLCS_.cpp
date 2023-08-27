

			#include <iostream>
			#include <fstream>
			#include <string>
			#include <cstring>
			#include <vector>
			#include <list>
			#include <set>
			#include <bits/stdc++.h>
			using namespace std;

			int bestSolution=0;
			vector<string> str;
			string best=" ";
			struct element
			{
				char ch;
				int mul;
				int dis;

			};
			vector<element> elms;


		struct node
			{
				vector<string> sr;
				
				char ch2;
				int dis;
				int mul;
				struct node* a;
				struct node* c;
				struct node* g;
				struct node* t;

			};

			int first_mul(char elm,vector<string> str )

		{
				int dist=10000;
			    int cnt=10000;
			    

			    for(int i=0; i!=str.size(); i++)
			    {
			    	int count=0, distance=0;
			    	// vector<char, int, int> sa;
			    	for (int j=0; j < str[i].length();  j++)

			    	{
			    		if(str[i][j]==elm)
			    		{   
			    			
			    			count=count+1;
			    			//cout<<count<<"\n";
			    			// cout<<str[i][j]<<"\n";
			    		}

			    	}
			    	
			    	

			    	if(count<cnt)
			    		cnt=count;
			    	
			    	//printf("count of %c  at  number %d string is %d and distance %d\n",elm, i, count, distance);
			    	
			    }
		 

			    //printf("Minimum count of %c   is %d and distance %d\n", elm, cnt, dist);
			   
			   return cnt;

		}
			
			int first_occurance(char elm,vector<string> str )

		{
				int dist=10000;
			    int cnt=10000;
			    

			    for(int i=0; i!=str.size(); i++)
			    {
			    	int count=0, distance=0;
			    	// vector<char, int, int> sa;
			    	for (int j=0; j < str[i].length();  j++)

			    	{
			    		if(str[i][j]==elm)
			    		{   
			    			
			    			count=count+1;
			    			//cout<<count<<"\n";
			    			// cout<<str[i][j]<<"\n";
			    		}

			    	}
			    	
			    	for (int j=0; j <str[i].length();  j++)

			    	{
			    		if(str[i][j]==elm)
			    		{   
			    			distance=str[i].length()-1-j;
			    			//cout<<distance<<"\n";
			    			break;
			    			// cout<<str[i][j]<<"\n";
			    		}

			    	}

			    	if(count<cnt)
			    		cnt=count;
			    	if(distance<dist)
			    		dist=distance;
			    	//printf("count of %c  at  number %d string is %d and distance %d\n",elm, i, count, distance);
			    	
			    }
			    element els;
			    els.ch=elm;
			    els.mul=cnt;
			    els.dis=dist;
			    
			    elms.push_back(els);

			    printf("Minimum count of %c   is %d and distance %d\n", elm, cnt, dist);
			   
			   return dist;

		}
		string min_str(vector<string> srt)
		{
		string min=srt[0];
			for(int i=1; i!=srt.size(); i++ )
			{
				if(srt[i].length()<min.length())
					min=srt[i];

			}
			return min;
		}
		 vector<string>  current_string(char ch,vector<string> str )

		{
			vector<string> str1;

			  for(int i=0; i!=str.size(); i++)
			    {
			    	 
			    	// vector<char, int, int> sa;
			    	for (int j=0; j < str[i].length();  j++)

			    	{
			    		if(str[i][j]==ch)
			    		{   
			    			
			    			string s=str[i].substr(j+1,str[i].length()+1);
			    			str1.push_back(s);
			    			break;
			    			// cout<<str[i][j]<<"\n";
			    		}

			    	}

			    }


			return str1;
		}

		void newNode(vector<string> srt,string best,char ch)
		{

			node a;
			
			a.ch2=ch;
			best+=ch;
			cout<<best<<"\n";
			a.sr=current_string(ch, srt);
			string h=min_str(a.sr);
			cout<<h[0]<<"\n";
			ch=h[0];
			a.dis=first_occurance(ch, srt);
			a.mul=first_mul(ch, srt);
			if(a.dis==0)
			{
				
				
				best=best.substr(0,best.length()-2);
			
			}

			
				if(a.dis>0 && a.mul>0)
				
			 newNode(a.sr,best,ch);
			
		}
		char select_character_multiplicity(vector<string> st,char ch)
		{

			
			    	
		vector<int> d;
			    	vector<int> m; 
			    	vector<char> c; 
			    //if(!((first_occurance('a', st)==0)&&(first_mul('a', st)==0)))
			    {
			    d.push_back(first_occurance('a', st));
			    m.push_back(first_mul('a', st));
			    c.push_back('a');

			    }
			    
			    //if(!((first_occurance('c', st)==0)&&(first_mul('c', st)==0)))
			    {
				d.push_back(first_occurance('c', st));
			    m.push_back(first_mul('c', st));
			    c.push_back('c');

			    }
			    
			    //if(!((first_occurance('g', st)==0)&&(first_mul('g', st)==0)))

			    {
				d.push_back(first_occurance('g', st));
			    m.push_back(first_mul('g', st));
			    c.push_back('g');

			    }
			    
			    //if(!((first_occurance('t', st)==0)&&(first_mul('t', st)==0)))
			    {
				d.push_back(first_occurance('t', st));
			    m.push_back(first_mul('t', st));
			    c.push_back('t');

			    }
			    
			    int maxmul=*max_element(m.begin(), m.end());
			    int max=0;
			    char maxchar=' ';
			    for(int i=0; i!=m.size(); i++)
			    {
			    	if((m[i]==maxmul) &&(d[i]>=max))
			    	{	
			    		max=d[i];
			    		maxchar=c[i];

			    	}
			    	

			    }
			    return maxchar;
		}
		char select_character_based_on_distance(vector<string> st,char ch)
		{

			
			    	
		vector<int> d;
			    	vector<int> m; 
			    	vector<char> c; 
			    //if(!((first_occurance('a', st)==0)&&(first_mul('a', st)==0)))
			    {
			    d.push_back(first_occurance('a', st));
			    m.push_back(first_mul('a', st));
			    c.push_back('a');

			    }
			    
			    //if(!((first_occurance('c', st)==0)&&(first_mul('c', st)==0)))
			    {
				d.push_back(first_occurance('c', st));
			    m.push_back(first_mul('c', st));
			    c.push_back('c');

			    }
			    
			    //if(!((first_occurance('g', st)==0)&&(first_mul('g', st)==0)))

			    {
				d.push_back(first_occurance('g', st));
			    m.push_back(first_mul('g', st));
			    c.push_back('g');

			    }
			    
			    //if(!((first_occurance('t', st)==0)&&(first_mul('t', st)==0)))
			    {
				d.push_back(first_occurance('t', st));
			    m.push_back(first_mul('t', st));
			    c.push_back('t');

			    }
			    
			    int maxmul=0;
			    int max=*max_element(d.begin(), d.end());
			    char maxchar=' ';
			    for(int i=0; i!=d.size(); i++)
			    {
			    	if((d[i]==max) &&(m[i]>=maxmul))
			    	{	
			    		maxmul=m[i];
			    		maxchar=c[i];

			    	}
			    	

			    }
			    return maxchar;
		}
			int main() 
			{
			    //ifstream new_file;
			                         
			    // Open a file to perform a write operation using a file object.
			    ifstream new_file("/home/hp/Desktop/motif/input.txt"); 
			       
				
			  
			   
			    
			   
			     
			    // Checking whether the file is open.
			    if (new_file.is_open()) {
			    	//Declare a string for input 
			        string sa;
			         
			        // Read data from the file object and put it into a string.
			        while (getline(new_file, sa)) { 
			        // Insert the data to a string vector.

			        	str.push_back(sa);
			        	cout<<sa<<"\n";
			            
			        }
			        
			        
			        
			    }
			    // Close the file object.
			    new_file.close();
		
			     vector<string> st=str;
			     string h=" ";
			     h=min_str(str);

		int size=str.size();
		string solution1=" ";
		string solution2=" ";
		int maxmul=0;
		int max=0;
		char maxchar=' ';
		maxchar=select_character_based_on_distance(st,' ');
				cout<<"max char "<<maxchar<<max<<"\n";
			     solution1+=maxchar;
			     
			     st= current_string(maxchar, st );
			    for(int i=0; i<=str[0].length(); i++)
			    {
			    	
			  		if(st.size()==size)
			    	{
			     maxchar=select_character_based_on_distance(st,' ');
			     cout<<"max char "<<maxchar<<max<<"\n";
			     solution1+=maxchar;
			     st= current_string(maxchar, st );
			    

			    	}
			    	
			    	 

			    }
			    st=str;
			    maxchar=' ';
			      for(int i=0; i<=str[0].length(); i++)
			    {
			    	if(st.size()==size)
			    	{
				 maxchar=select_character_multiplicity(st,' ');
			     cout<<"max char "<<maxchar<<max<<"\n";
			     solution2+=maxchar;
			     st= current_string(maxchar, st );
			    

			    	}
			    	
			    	 

			    }
			    string solution=" ";
			    if(solution1.length()>solution2.length())
			    	solution=solution1.substr(0,solution1.length()-1);
				else
					solution=solution2.substr(0,solution2.length()-1);
			   cout<<solution<<" length "<<solution.length();
			
			    return 0;
			
			}


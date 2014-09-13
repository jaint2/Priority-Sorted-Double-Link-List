#include<iostream>
#include<cstdlib>
#include "dllist.h"
using namespace std;

void Insert(int n, DLList &curr);
void appen(DLList &curr);

void prepen(DLList &curr);
bool empty(DLList &curr);
void del(int n , DLList &curr);
void sorinsrt(int key ,DLList &curr);

void sordel (int key, DLList &curr);
int main ()
{
	DLList curr;
	
cout << " \nAdding 20 random elements \n";
Insert(20,curr);
cout<<endl;
cout<<"Inserting an element 569 \n";
sorinsrt(569,curr);
cout<<endl;
cout<<"Appending \n";
appen(curr);
cout<<endl;
cout<<"Prepending \n";
prepen(curr);
cout<<endl;
cout<<"Deleting key 569 \n";
sordel(569,curr);
cout<<endl;
cout<<"Checking whether list is empty or not \n";
			if (empty(curr)== 0)
			 {cout<<"list is empty \n";}
			else 
			{cout<<"list is not empty \n";}
		
cout<<endl;
cout<<"Deleting 22 items from head \n";
del(22,curr);
cout<<endl;
cout<<"Checking whether list is empty or not \n";
			if (empty(curr)== 0)
			 {cout<<"list is empty \n";}
			else 
			{cout<<"list is not empty \n";}
		
cout<<endl; 

cout<<"if you want to do more operations type the following or enter 'e' to exit \n "; 
cout<< "please enter following character to do an operation \n";
cout << "'s' To enter no of random keys you need in the list \n";
cout << "'i' To Insert key value    \t 'd' Enter key value to be removed \n";
cout << "'a' To Append              \t 'p' To Prepend \n";
cout << "'r' To delete keys you want to remove from first(head) \n";
cout << "'b' TO check List Empty    \t 'e' To EXIT \n";
char p;
cin >> p;
	while (p!='e')
	{
		if ( p== 's')
		{
			cout<<"enter value \n";
			int i;
			cin >> i;
			Insert(i,curr);
		}
		else if ( p== 'i')
		{
			cout<<"enter key value \n";
			int i;
			cin >> i;
			sorinsrt(i,curr);
		}
		else if ( p== 'd')
		{
			cout<<"enter key value \n";
			int i;
			cin >> i;
			sordel(i,curr);

		}
		else if ( p== 'p')
		{
			prepen(curr);
		}
		else if ( p== 'a')
		{
			appen(curr);
		}
		else if ( p== 'r')
		{
			cout<<"enter key value \n";
			int i;
			cin >> i;
			del(i,curr);
		}
		else if (p == 'b')
		{
			if (empty(curr)== 0)
			 {cout<<"list is empty \n";}
			else 
			{cout<<"list is not empty \n";}
		}
		else if (p == 'e')
		{break;}
		else
		{
			cout<<"wrong input please try again \n";
			
		}
			cout <<endl;
			cout<< "please enter following character to do an operation \n";
			cout << "'s' To enter no of random keys you need in the list \n";
			cout << "'i' To Insert key value    \t 'd' Enter key value to be removed \n";
			cout << "'a' To Append              \t 'p' To Prepend \n";
			cout << "'r' To delete keys you want to remove from first(head) \n";
			cout << "'e' To EXIT \n";
			cin >> p;
	}
	

}



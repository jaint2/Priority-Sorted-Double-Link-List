#include <iostream>
#include "dllist.h"
using namespace std;

DLList::~DLList(){
	first = NULL;
	last = NULL;
}

DLLElement  :: DLLElement( void *itemPtr, int sortKey) 
{
	item = itemPtr ;
	key = sortKey ;
	next = NULL;
	prev = NULL;
		
}

DLList :: DLList ()
{
	first = NULL;
	last = NULL;	
}
bool DLList :: IsEmpty()
{
	if (first == NULL ) return false;
	else return true;

}
void DLList :: SortedInsert ( void * item , int sortKey )
{
	
	DLLElement *node = new DLLElement( item , sortKey);
	if (IsEmpty() == false ) // adding first element 
	{
		first = node;
		last  = node;
		cout << sortKey <<" added at location " << node << endl;
	} 
	//cout << first-> key << '\t' << last -> key << endl ;
	else
	{
		if (first-> next == NULL) // only one element present add the secod one
		{
			if (first->key <= node -> key) // element added in end
			{
				last=node;
				first-> next = node;
				last -> prev = first;
				//cout << "node is bigger"<<endl;
				cout << sortKey <<" added at location " << node << endl;
			}
			else	// element added at first
			{
				first=node;
				first->next= last;
				last-> prev= node;
//				cout<<"node is smaller   " << endl ;
				cout << sortKey <<" added at location " << node << endl;
			} 
		}
		else // 2 nodes added  adding more nodes
		{
			if (first-> key >= node->key) // first node changed
			{ 
				node-> next = first;
				first->prev=node;
				first=node;
				//cout <<"first node changed " <<endl;
				cout << sortKey <<" added at location " << node << endl;
			}
			else if (last->key <= node->key)//last node changed
			{
				node->prev = last;
				last-> next = node;
				last= node;
				//cout << "last node changed"<<endl;
				cout << sortKey <<" added at location " << node << endl;
			}
			else // nod must be added btw first and last
			{
				int i(1);
				DLLElement *curr;
				curr=first->next;
				while (i==1)
				{
					if ( node->key <= curr-> key )
					{
						curr->prev->next = node;
						node-> prev = curr->prev;
						curr->prev = node;
						node->next = curr;
//						cout << node->key << " added btw " << node->prev-> key << '\t' << node->next -> key<<endl;
						cout << sortKey <<" added at location " << node << endl;
						i=0; 
					}
					else
					{
						curr=curr->next;
					}
				}
				

			}
		}
		
	}
}

void DLList :: Prepend (void *item)
{

//	node->key=first->key-1;
	if (IsEmpty()==false)
	cout<<"No key \n";
	else{	
		DLLElement *node = new DLLElement(item , first->key-1);
	node->next=first;
	first->prev = node;
	first=node;
	//cout << "first node changed from " << first->next->key <<" to "<< first->key << endl;
	cout << first->key <<" added at location " << node << endl;}  
}

void DLList :: Append (void *item)
{
	
	if (IsEmpty()==false)
	cout<<"No key \n";
	else {
		DLLElement *node = new DLLElement(item , last->key+1); 
	node->prev=last;
	last->next = node;
	last=node;
//	cout << "last node changed from " << last->prev->key <<" to "<< last->key << endl;
	cout << last->key <<" added at location " << node << endl;}  
}

void* DLList :: Remove(int *keyPtr)
{
	void *item;
			
	if(first==last && IsEmpty()==true)
	{
		keyPtr=&first->key;
		cout<<first->key<<" Deleted from loction " << first << endl;
		first=NULL;
		last=NULL;
		cout<< "no key left\n";
		return item;
		
	}
	else if (IsEmpty()==false)
	{
			cout<< "list empty\n ";		
		return NULL;
}
	else
	{
		keyPtr=&first->key;
		cout<<first->key<<" Deleted from loction " << first << endl;
	first=first->next;
	first->prev=NULL;
	return item;
	}
}

void* DLList :: SortedRemove(int sortKey)
{
	DLLElement *cur;
	if (first==NULL)
	{	return NULL;}
	else
	{
		if (sortKey==first->key)
		{
			DLLElement *tmp;
			tmp = first; 			
			first=first->next;
			first->prev=NULL;
			//cout << sortKey << " first key remove new first is " << first->key<<endl;
			cout << sortKey << " Deleted from location "<< tmp << endl;
		}
		else if (sortKey==last->key)
		{
			DLLElement *tmp;
			tmp=last;			
			last=last->prev;
			last->next=NULL;
			//cout << sortKey << " last key remove new last is " << first->key<<endl;
			cout << sortKey << " Deleted from location "<< tmp << endl;
		}
		else
		{
			cur=first->next;
			while(cur != last )
			{
				if (cur->key==sortKey)
				{
					DLLElement *tmp;
					tmp=cur;					
					cur->prev->next=cur->next;
					cur->next->prev=cur->prev;
					cur=NULL;
					cout << sortKey << " Deleted from location " << tmp<< endl;
					break;
				}
				else
				cur=cur->next;

				
			}
			if (cur == last)
			{
				cout << sortKey << " not found"<<endl;				
				return NULL;
				
			}
		}
	}
	return NULL;
}
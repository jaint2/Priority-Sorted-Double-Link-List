#include "dllist.h"
#include <cstdlib>

void Insert(int n, DLList &curr)
{
	for(int i(0);i<n;i++)
	{
		int key;		
		void *item;		
		key = rand() % 1000000 ;
 
		curr.SortedInsert(item , key);
	}
}
void appen(DLList &curr)
{
	void *item;
	curr.Append(item);
}

void prepen(DLList &curr)
{
	void *item;
	curr.Prepend(item);
}
bool empty(DLList &curr)
{return curr.IsEmpty();
}
void del(int n , DLList &curr)
{

	for (int i(0);i<n;i++)
	{
		int *j;
		curr.Remove(j);
	}
	
}
void sorinsrt(int key ,DLList &curr)
{
	void *item;
	curr.SortedInsert(item,key);
}

void sordel (int key, DLList &curr)
{
	curr.SortedRemove( key);
}
//Linked List Stacks
//LIFO STRUCTUE

#include<iostream.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
#include<conio.h>
#include<string.h>

struct Node
{	int Item;
	Node* next;
}*ptr, *save, *top;

Node* CreateNewPtr()
{
	ptr = new Node;
	ptr->next=NULL;
	if(ptr==NULL)
	return 0;// Node Not created
	else
	return ptr; //Node created
}
void Push(Node*np)
{      if(top=NULL) top=np;
       else{
	save=top;
	top=np;
	np->next=save;
}
int Pop()
{	if(top==NULL) return -1;
	else
	{
		ptr= top;
		top=top->next;
		delete ptr;
	}
	return 0;
}
void Display(Node*np)
{
	while(np!=NULL)
	{
		cout<<"Item:"<<Item<<endl;
		cout<<np->next<<endl<<endl;
		np=np->next;
	}
}

void main()
{ clrscr();


  getch();
}

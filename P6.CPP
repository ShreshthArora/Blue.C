//Stack is a LIFO Structure .
#include<iostream.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
#include<conio.h>
#include<string.h>

const int size=50;

int Push(int Stack[],int &top,int Item){
	if(top==size-1)
	return -1; //The stack got filled.

	else{
		top++;
		Stack[top]=Item;
	}
	return 0;
}
void Display(int Stack[], int &top){
if(top>=0)
	{
	cout<<Stack[top]<<"<--"<<endl;
	int i=0;
	for(i=top-1;i>=0;i--)
		cout<<Stack[i]<<endl;
	}
else
cout<<"There is no Item in stack";

}
int Pop(int Stack[], int&top)
{   int ret;
     if(top==-1)
	return -1; //Underflow Situation Nothing to delete
	else
	{       ret=Stack[top];
		top--;
	}
	 return ret;
}

void main()
{ clrscr();     int n;
	int Stack[size],Item,top=-1,res;char c;
	system("cls");
	do{
		cout<<"\n1.Push an item in Stack\n2.Pop an item out of Stack\n3.Display Stack\n4.Exit\n";
		do{
		  n=getch()-'0';
		}while((n>4)&&(n<1));
		switch(n)
		{
			case 1:
			       cout<<"\n Enter Item for insertion:";
			       cin>>Item;
			       res=Push(Stack,top, Item);
			       if(res==-1)
				cout<<"\n Overflow No Item added to STACK:";
			       getch();
			break;
			case 2:
			       cout<<"\n Confirm whether you wish to Pop ITEM[Y/N]:";
			       cin>>c;
			       if(c=='Y')
			       {
				res=Pop(Stack,top);
			       if(res==-1)
			       cout<<"\n Underflow No Items in Stack";
			       else
			       cout<<"\n Item Popped is :"<<res;
			       }

			       getch();

			break;
			case 3:
				cout<<"\n Here is the Stack\n ";
				Display(Stack,top);
				getch();
			break;
		}
	    clrscr();
	}while(n!=4);
}

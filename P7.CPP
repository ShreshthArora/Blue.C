//Queue is a FIFO structure
#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
const int size=10;
int Queue[size],front=-1,rear=-1;

int Insert(int Queue[],int Item)
{
	if(rear==size-1)
	return -1;//Overflow Queue
	else if(rear==-1)
	front=rear=0;
	else
	rear++;

	Queue[rear]=Item;
	return 0;
}
int Delete(int Queue[])
{
	int ret;
	if(front==-1)
	return-1;//underflow situation;
	else
	{	ret=Queue[front];
		if(front==rear)
			front=rear=-1;
		else
			front++;
	}
	return ret;
}
void Display(int Queue[],int front,int rear)
{    int i;
	if(rear==-1)
	cout<<"No Item in Queue to display";
	else
	{	for(i=front;i<=rear;i++)
		cout<<Queue[i]<<endl;
	}
}
void main()
{    int Item,res,n;char c;

	do{

	cout<<"\n1:Insert in Queue\n2:Delete from Queue\n3:Display Queue\n4:Exit\n";
	do
	{
		n=getch()-'0';
	}while((n>4)&&(n<1));
		  switch(n)
		  {	case 1:
			cout<<" \n Insert in Queue Item :";
			cin>>Item;
			res=Insert(Queue,Item);
			if(res==-1)
			cout<<"\n Overflow cannot enter more items, Last Item not enterd";
			else
			cout<<"\n Item enetered in Queue";
			getch();

			break;
			case 2: cout<<" \n confirm to delete Items [Y/N]:";
				   cin>>c;
				if(c=='Y')
				{
					res=Delete(Queue);
					if(res==-1)
					cout<<"\n Underflow  no elements in Queue";
					else
					cout<<"\n The Deleted Element is"<<res;
				}
				getch();
			break;
			case 3:
			       cout<<"\n Displaying the Queue \n";
			       Display(Queue, front, rear);
			       getch();
			break;

		  }
		  clrscr();
	}while(n!=4);
}
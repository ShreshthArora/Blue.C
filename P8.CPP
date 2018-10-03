#include<iostream.h>
//Stacks Using Circular Queues
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
#include<conio.h>
#include<string.h>

const int size=10;
int Queue[size], front=-1, rear=-1;
int Insert(int Queue[], int Item)
{       if(((front==0)&&(rear==size-1))||(front==rear+1))
	   return -1; //overflow
	else if(rear==-1)
		front=rear=0;//Nothing is in the Queue;
	else if(rear==size-1)
		rear=0;//Wrap arround.
	else
	rear++;

	Queue[rear]=Item;
   return 0;//Item added
}
int Delete(int Queue[])
{
	int ret;//retainer for deleted object.
	if(front==-1)
		return -1;//Underflow
	else
	{
		ret=Queue[front];
		if(front==rear)//this is the condition when there is a single object.
		front=rear=-1;//Now there is nothing.
		else if(front==size-1)
			front=0;//Wrap arround
		else
		front++;
	}
 return ret;
}
void Display()
{
	int i=0;
	if(front==-1)
	cout<<"\n  Display : Fail ( Error Name : Empty Queue)";
	if(rear>=front)
	{
		for(i=0;i<front;i++)
		cout<<"_";

		cout<<">>>";
		for(i=front;i<rear;i++)
		cout<<Queue[i]<<',';
		cout<<Queue[rear]<<"<<<";
		for(i=rear+1; i<size;i++)
		cout<<"_";

	}
	else
	{
	    for(i=0; i<rear;i++)
		cout<<Queue[i]<<",";

	    cout<<Queue[rear]<<"<<<";

	    for(;i<front;i++)
		cout<<"_";

	    cout<<">>>";

	    for(i=front;i<size;i++)
		cout<<Queue[i]<<",";
	    cout<<"...Wrap Around...";
	}
}
void main()
{ clrscr();
	int Item=0,res,n;
	char c;

	do{

	cout<<"\n1:Insert in Circular Queue\n2:Delete from Circular Queue\n3:Display Circular Queue\n4:Exit\n";
	do
	{
		n=getch()-'0';
	}while((n>4)&&(n<1));

			switch(n)
			{
				case 1:
						cout<<"\n Enter the Item :";
						cin>>Item;
						res=Insert(Queue,Item);
						if(res==-1)
							cout<<" \n Item added : False (Queue Full)";
						else
							cout<<"\n Item added : Success";
						getch();
				break;

				case 2:
						cout<<" \n Do you wish to Delete Item [Y/N]:";
						cin>>c;
						if(toupper(c)=='Y')
						{
							res=Delete(Queue);
							if(res==-1)
								cout<<" \n Delete : Fail (Error Name: No Item in Queue)";
							else
								cout<<"\n Delete : Success (Delete Item :"<<res<<")";
						}
						getch();
				break;

				case 3:
					cout<<" \n Displaying Circular Queue ";
					Display();
					getch();
				break;
			}
	clrscr();
}while(n!=4);
}



#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdio.h>
#include<fstream.h>
#include<ctype.h>
#include<string.h>

class stock{

private:
	int ItemNo;
	char Name[20];

public:
	void get()
	{
		cout<<"\n ITEM NO:";
		cin>>ItemNo;
		cout<<"\n Item Name :";
		gets(Name);
	}
	void show()
	{
		cout<<"\n ITEM NO:";
		cout<<ItemNo;
		cout<<"\n Item Name :";
		puts(Name);
	}
	int ItemNum()
	{
	return ItemNo;
	}
}a;

void main()
{
	clrscr();
	int i ,n, c;
	cout<<"\n No. of stock required.";
	cin>>n;
	ofstream fout("STOCK1.DAT",ios::out|ios::app|ios::binary);
	cout<<"\n Writing to file";
	for(i=0; i<n; i++)
	{
		a.get();
		fout.write((char*)&a,sizeof(a));
	}
	fout.close();

	cout<<"\n Writing to file complete.";
	getch();
	clrscr();
	cout<<"Item you wish to find";
	cin>>c;
	ifstream fin("STOCK1.DAT",ios::in|ios::binary);

	if(fin)
	{
		for(i=0; i<n;i++)
		{
			fin.read((char*)&a,sizeof(a));
			if(a.ItemNum()==c)
			{
					cout<<"\n ITEM FOUND :";
					a.show();
			}
		}
	}
	else
	{
		cout<<"File openeing error";
	}

cout<<"Closing program...";
getch();

}
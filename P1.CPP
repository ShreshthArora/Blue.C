#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<ctype.h>
#include<string.h>


void create_file()
{
	char b;
	ofstream fout;
	fout.open("dlog.txt",ios::binary);
	char l[50];
	do
	{
		cout<<"provide the Input \n";
		gets(l);
		fout<<l;
		cout<<"do you want to add more[Y/N] :";
		cin>>b;
	}while( toupper(b)=='Y');
	fout.close();
}

void main()
{
	clrscr();
	 char c,d;
	create_file();
	cout<<"Which letter do you want to search \n";
	cin>>c;
	d=toupper(c);
	
	int count=0,i; char l[50];
	ifstream fin;
	fin.open("dlog.txt",ios::binary);
	
	while(!fin.eof())
	{
		fin.getline(l,50);
		for(i=0;i<50;i++)
		{
			if(toupper(l[i])==d)
				count++;
		}
	}
	fin.close();

	cout<<"The no. of times"<<"\""<<c<<"\" was found(case insensetive) :"<<count;
	getch();
}
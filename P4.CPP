#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdio.h>
#include<fstream.h>
#include<ctype.h>
#include<string.h>

void main()
{
	clrscr();
	int x=0,choice;
	char word[100];
	int i;
	ofstream fout("STORY1.TXT",ios::in);

	do{

		cout<<"\n GIVE INPUT FOR THE STORY:";
		gets(word);
		fout<<word<<endl;
		cout<<"\n Do you wish to enter more[Y/N]";
		cin>>choice;

	}while(choice=='Y');

	fout.close();

	clrscr();

	cout<<"\n Now Reading \" the \" from STORY.TXT";

	ifstream fin("STORY1.TXT", ios::in);
	if ( fin )
	{
		while(1)
		{
			fin>>word;

			for (i=0; word[i]!='\0';i++)
			{
				word[i]=tolower(word[i]);
			}
			if(!isalnum(word[i-1]))
			{
				word[i-1]='\0';
			}
			x+=(strcmp(word,"the")==0);
			if(fin.eof())
			{
				break;
			}
		}
	}
	cout<<" \n No. of \"the\" from STORY.TXT : "<<x;
	fin.close();
	getch();
}


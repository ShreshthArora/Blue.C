//[12:32 pm 28th Jan 2018]:ERROR AFTER  TRANSFER FUNCTION At RUNTIME
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdio.h>
#include<fstream.h>
#include<ctype.h>
#include<string.h>

class PL
{
private:
	char Name[20];
	char address[30];
	char AreaCode[5];
	char PhoneNo[15];

public:
	void Reg()
	{
		cout<<"\n Name";
		gets(Name);
		cout<<"\n Address:";
		gets(address);
		cout<<" \n Area Code";
		gets(AreaCode);
		cout<<"\n Phone No:";
		gets(PhoneNo);

	  }
	void show()
	{
		cout<<"\n Name";
		puts(Name);
		cout<<"\n Address:";
		puts(address);
		cout<<" \n Area Code";
		puts(AreaCode);
		cout<<"\n Phone No:";
		puts(PhoneNo);

	}
	int checkcode(char AC[])
	{
		return strcmp(AreaCode, AC);
	}
};

void transfer()
{
	PL b;
	ifstream f1;
	ofstream f2;
	f1.open("Phone1.dat",ios::binary,ios::in);
	f2.open("Phoneb.dat",ios::out, ios::binary);

	while(!f1.eof())
	{
		f1.read((char*)&b,sizeof(b));

		if(b.checkcode("DEL")==0)
			{
				f2.write((char*)&b, sizeof(b));
			}
	}
	f1.close();
	f2.close();
}

void main(){

	PL a,b,c;
	clrscr();
	{
		ofstream f1;
		f1.open("Phone1.dat",ios::binary|ios::app);
		int i, n;
		cout<<" \n How many elements do you wish to have(integer):";
		cin>>n;

		for(i=0;i<n;++i)
			{
				a.Reg();
				f1.write((char*)&a,sizeof(a));
			}
		f1.close();
		cout<<"\n Now transferring Files";
		getch();
		clrscr();
		transfer();

		cout<<"Transfer complete";

		ifstream f;
		f.open("Phone1.dat",ios::binary|ios::app);
		if(f){
			cout<<endl<<"phone1.DAT \n ";
			while(1)
			{
				f.read((char*)&b,sizeof(b));
				if(f.eof())
				{
					break;
				}
				b.show();
			}
		}

		f.close();
		getch(); clrscr();
		fstream f2("Phoneb.DAT",ios::in|ios::binary);

		if(f2)
		{
			cout<<"\n Phoneb.DAT \n ";
			while(1)
			{
				f2.read((char*)&c,sizeof(c));
				if(f2.eof())
					break;
				c.show();
			}

		}


	}
}
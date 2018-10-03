//[8:52 am 28th Jan 2018]:there is some error in dispalying the file.
//[9:23 am 28th Jan 2018]: Display error resolved, code working properly
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<ctype.h>
#include<string.h>

class employee
{
private:
	int Eno;
	char Ename[30];
public:
		void Get()
		{
			cout<<"\n Employee Name: ";
			gets(Ename);
			cout<<" \n Employee No.:";
			cin>>Eno;
		}
		void ShowIt()
		{cout<<"\n Employee Name:"<<Ename<<"\n Employee No :"<<Eno<<endl;}
};

void main(){

	clrscr();

	employee a; int i,n ;
	ofstream f;
	f.open("LOE.dat",ios::binary);

	cout<<" \n  No. of Employees :";
	cin>>n;
	for(i=0;i<n;i++)
	{
		a.Get();
		f.write((char*)&a, sizeof(a));
	}

	f.close();

	clrscr();

	char b;
	cout<<" \n Display all Employees [Y/N]:";
	cin>>b;

	ifstream fin;
	fin.open("LOE.dat",ios::binary);

	if(toupper(b)=='Y')
	{

		for(i = 0; i < n; ++i)
		{
		fin.read((char* )&a, sizeof(a));
		a.ShowIt();
		}
	}

	cout<<" \n displayed all employees Exiting...";
	fin.close();
	getch();
}

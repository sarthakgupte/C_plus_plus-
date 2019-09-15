#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
class doc
{
	int id;
	char dname[20];
	char desgn[10];
	char spcia[15];
	char avail[15];
	public:
	void gdata();
	void sdata();
	void modify();
	void deld();
	int getid()
	{
		return id;
	}

};
class patient
{
	int regno;
	char regdate[11];
	char pname[20];
	int age;
	char gndr;
	char bgrp[5];
	char cntct[12];
	char addrs[30];
	char city[15];
	public:
	void getdata();
	void showdata();
	void modify();
	void delp();
	int getrno()
	{
		return regno;
	}
};
patient p;
doc d;
int i;
char ch;
char pswd[15];
void inputp();
void inputd();
void searchp();
void searchd();
void displayp();
void displayd();
void chk();
void dlay();
void dscreen();
void mscreen();
void mainscreen();
void patientmenu();
void docmenu();
void mainmenu();
void main()
{
	clrscr();
	//dlay();
	mscreen();
	chk();
	//mainmenu();
	//p.showdata();
	//dscreen();
	//d.gdata();
	//d.sdata();
	//patientmenu();
	//docmenu();
	getch();
}
void chk()
{
	char pswd[5];
	clrscr();
	cout<<"\n\t ENTER PASSWORD :- ";
	pswd[0]=getch();
	cout<<"*";
	pswd[1]=getch();
	cout<<"*";
	pswd[2]=getch();
	cout<<"*";
	pswd[3]=getch();
	cout<<"*";
	pswd[4]=getch();
	cout<<"*";
	pswd[5]='\0';
	if(strcmp(pswd,"pswrd")==0)
	{
		cout<<"\n PASSWORD IS CORRECT ";
		dlay();
		mainmenu();
	}
	else
	{
		cout<<"\n INCORRECT PASSWORD ";
	}
}
void mainmenu()
{
	int c;
	do
	{
		clrscr();
		gotoxy(20,7);
		cout<<"\t\t MAIN MENU ";
		cout<<"\n\n \t 1. PATIENT ";
		cout<<"\n \t 2. DOCTOR  ";
		cout<<"\n \t 3. EXIT ";
		cout<<"\n\n   ENTER YOUR CHOICE(1-3) ";
		cin>>c;
		switch(c)
		{
			case 1 : patientmenu();
				 break;
			case 2 : docmenu();
				 break;
			case 3 : exit(0);
			default : cout<<"\n INVALID CHOICE ....";
				  break;
		}
		clrscr();
		gotoxy(20,20);
		cout<<"WANNA VISIT MAIN MENU AGAIN (Y OR N): ";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
}
void dlay()
{
	gotoxy(24,9);
	for(i=0;i<35;++i)
	cout<<char(205);
	cout<<char(187);
	gotoxy(25,10);
	cout<<"PLEASE WAIT.....";
	gotoxy(59,13);
	cout<<char(188);
	gotoxy(23,13);
	cout<<char(200);
	for(i=0;i<35;++i)
	cout<<char(205);
	gotoxy(23,10);
	for(i=11;i<14;++i)
	{
		cout<<char(186);
		gotoxy(23,i);
	}
	gotoxy(59,10);
	for(i=11;i<14;++i)
	{
		cout<<char(186);
		gotoxy(59,i);
	}
	gotoxy(23,9);
	cout<<char(201);
	gotoxy(25,11);
	for(i=0;i<33;++i)
	{
		delay(80);
		cout<<char(220);
	}
}
void mscreen()
{
	gotoxy(0,1);
	cout<<char(201);
	for(i=0;i<77;++i)
	cout<<char(205);
	cout<<char(187);
	gotoxy(79,25);
	cout<<char(188);
	gotoxy(1,25);
	cout<<char(200);
	for(i=0;i<77;++i)
	cout<<char(205);
	gotoxy(1,2);
	for(i=3;i<26;++i)
	{
		cout<<char(186);
		gotoxy(1,i);
	}
	gotoxy(79,2);
	for(i=3;i<26;++i)
	{
		cout<<char(186);
		gotoxy(79,i);
	}
	gotoxy(29,6);
	cout<<" SANJEEVANI HOSPITAL ";
	gotoxy(19,9);
	cout<<" 45 - A HOLKAR STREET, NEAR CHRISTIAN PARK ";
	gotoxy(29,12);
	cout<<"INDORE [M.P],452012";
	delay(3500);
}
void inputd()
{
	d.gdata();
	ofstream fout;
	fout.open("Doctor.txt",ios::out|ios::app);
	fout.write((char*)&d,sizeof(d));
	fout.close();
}
void displayd()
{
	ifstream fio("Doctor.txt",ios::in);
	fio.seekg(0);
	while((fio.read((char*)&d,sizeof(d))) && (ch=='y'||ch=='Y'))
	{
		d.sdata();
		gotoxy(14,20);
		cout<<"DO YOU WANT TO DISPLAY MORE RECORDS... (Y OR N) ";
		cin>>ch;
	}
	fio.close();
}
void searchd()
{
	int s,f=0;
	ifstream fin1;
	fin1.open("Doctor.txt",ios::in);
	cout<<"\n ENTER ID NUMBER OF A DOCTOR TO BE SEARCHED :";
	cin>>s;
	while(!fin1.eof())
	{
		 fin1.read((char*)&d,sizeof(d));
		 if(d.getid()==s)
		 {
			d.sdata();
			f++;
			break;
		 }
	}
	if(f==0)
	   cout<<"\n NO RESULT FOUND !!!!!";
	fin1.close();

}
void doc::modify()
{
	fstream fio("Doctor.txt",ios::in|ios::out);
	int s,f=0;
	long pos;
	cout<<"ENTER ID OF DOCTOR TO BE MODIFIED : ";
	cin>>s;
	while(!fio.eof())
	{
		pos=fio.tellg();
		fio.read((char*)&d,sizeof(d));
		if(d.getid()==s)
		{
			d.gdata();
			fio.seekg(pos);
			fio.write((char*)&d,sizeof(d));
			f++;
			break;
		}
	}
	if(f==0)
		cout<<"\n\n Record not found !!!1";
	fio.seekg(pos);
	clrscr();
	fio.read((char*)&d,sizeof(d));
	cout<<"Modified data";
	d.sdata();
	fio.close();
}
void doc::deld()
{
	ifstream f1("Doctor.txt",ios::in);
	ofstream f2("temp.txt",ios::out);
	int g,f=0;
	char q='n';
	cout<<"\nENTER ID OF DOCTOR YOU WANT TO DELETE :";
	cin>>g;
	while(!f1.eof())
	{
		f1.read((char*)&d,sizeof(d));
		if(d.getid()==g)
		{
			p.showdata();
			f++;
			cout<<"\n ARE YOU SURELY WANT TO DELETE THIS DOCTOR :";
			cin>>q;
			if(q=='n')
			f2.write((char*)&d,sizeof(d));
		}
		else
			f2.write((char*)&d,sizeof(d));
	}
	if(f==0)
	cout<<"\n RECORD NOT FOUND!!!!";
	f1.close();
	f2.close();
	remove("Doctor.txt");
	rename("temp.txt","Doctor.txt");
	cout<<"\n\n RECORD DELETED !!!";
}
void docmenu()
{
	int c;
	gotoxy(35,7);
	do
	{
		clrscr();
		cout<<"\n\t\t\t"<<char(1)<<" MENU "<<char(1);
		cout<<endl<<endl<<"\t\t\t 1. NEW ENTRY FOR DOCTOR ";
		cout<<endl<<"\t\t\t 2. DISPLAY ALL RECORDS OF DOCTOR";
		cout<<endl<<"\t\t\t 3. SEARCH A DOCTOR ";
		cout<<endl<<"\t\t\t 4. MODIFY A DOCTOR ";
		cout<<endl<<"\t\t\t 5. DELETE A DOCTOR ";
		cout<<endl<<"\t\t\t 6. EXIT ";
		cout<<"\n ENTER YOUR CHOICE :";
		cin>>c;
		switch(c)
		{
			case 1 : inputd();
				 break;
			case 2 : displayd();
				 break;
			case 3 : searchd();
				 break;
			case 4 : d.modify();
				 break;
			case 5 : d.deld();
				 break;
			case 6 : break;
			default :cout<<"\n INVALID CHOICE ";
				 break;
		}
		gotoxy(20,23);
		cout<<"\n WANNA VISIT DOCTOR MENU AGAIN (Y OR N): ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
}
void inputp()
{
	p.getdata();
	ofstream fout;
	fout.open("Patient.txt",ios::out|ios::app);
	fout.write((char*)&p,sizeof(p));
	fout.close();
}
void displayp()
{
	ifstream fio("Patient .txt",ios::in);
	fio.seekg(0);
	while((fio.read((char*)&p,sizeof(p))) && (ch=='y'||ch=='Y'))
	{
		p.showdata();
		gotoxy(14,22);
		cout<<"DO YOU WANT TO DISPLAY MORE RECORDS... (Y OR N) ";
		cin>>ch;
	}
	fio.close();
}
void searchp()
{
	int s,f=0;
	ifstream fin1;
	fin1.open("Patient.txt",ios::in);
	cout<<"\n ENTER REGISTRATION NUMBER OF A PATIENT TO BE SEARCHED :";
	cin>>s;
	while(!fin1.eof())
	{
		 fin1.read((char*)&p,sizeof(p));
		 if(p.getrno()==s)
		 {
			p.showdata();
			f++;
			break;
		 }
	}
	if(f==0)
	   cout<<"\n NO RESULT FOUND !!!!!";
	fin1.close();

}
void patient::modify()
{
	fstream fio("Patient.txt",ios::in|ios::out);
	int s,f=0;
	long pos;
	cout<<"\nENTER REGISTRATION NO. TO BE MODIFIED : ";
	cin>>s;
	while(!fio.eof())
	{
		pos=fio.tellg();
		fio.read((char*)&p,sizeof(p));
		if(p.getrno()==s)
		{
			p.getdata();
			fio.seekg(pos);
			fio.write((char*)&p,sizeof(p));
			f++;
			break;
		}
	}
	if(f==0)
		cout<<"\n\n RECORD NOT FOUND !!!!";
	fio.seekg(pos);
	clrscr();
	fio.read((char*)&p,sizeof(p));
	p.showdata();
	gotoxy(34,22);
	cout<<"MODIFIED DATA";
	fio.close();

}
void patient::delp()
{
	ifstream f1("Patient.txt",ios::in);
	ofstream f2("temp.txt",ios::out);
	int g,f=0;
	char q='n';
	cout<<"\nENTER REGISTATION NO. OF PATIENT YOU WANT TO DELETE :";
	cin>>g;
	while(!f1.eof())
	{
		f1.read((char*)&p,sizeof(p));
		if(p.getrno()==g)
		{

			p.showdata();
			f++;
			cout<<"\n ARE YOU SURELY WANT TO DELETE THIS PATIENT :";
			cin>>q;
			if(q=='n')
			f2.write((char*)&p,sizeof(p));
		}
		else
			f2.write((char*)&p,sizeof(p));
	}
	if(f==0)
	cout<<"\n RECORD NOT FOUND!!!!";
	f1.close();
	f2.close();
	remove("Patient.txt");
	rename("temp.txt","Patient.txt");
	cout<<"\n\n RECORD DELETED !!!";
}
void patientmenu()
{
	int c;
	gotoxy(35,7);
	do
	{
		clrscr();
		cout<<"\n\t\t\t"<<char(1)<<" MENU "<<char(1);
		cout<<endl<<endl<<"\t\t\t 1. NEW ENTRY FOR PATIENT ";
		cout<<endl<<"\t\t\t 2. DISPLAY ALL RECORDS ";
		cout<<endl<<"\t\t\t 3. SEARCH A PATIENT ";
		cout<<endl<<"\t\t\t 4. MODIFY A PATIENT ";
		cout<<endl<<"\t\t\t 5. DELETE A PATIENT ";
		cout<<endl<<"\t\t\t 6. EXIT ";
		cout<<"\n ENTER YOUR CHOICE :";
		cin>>c;
		switch(c)
		{
			case 1 : inputp();
				 break;
			case 2 : displayp();
				 break;
			case 3 : searchp();
				 break;
			case 4 : p.modify();
				 break;
			case 5 : p.delp();
				 break;
			case 6 : break;
			default: cout<<"\n INVALID CHOICE ";
				 break;
		}
		gotoxy(15,23);
		cout<<"\n WANNA VISIT PATIENT MENU AGAIN (Y OR N): ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
}
void dscreen()
{
	clrscr();
	gotoxy(2,1);
	for(i=0;i<77;i++)
	cout<<char(205);
	cout<<char(187);
	gotoxy(1,1);
	cout<<char(201);
	gotoxy(1,2);
	for(i=3;i<26;i++)
	{
		cout<<char(186);
		gotoxy(1,i);
	}
	cout<<char(200);
	for(i=1;i<78;i++)
	cout<<char(205);
	cout<<char(188);
	gotoxy(79,2);
	for(i=3;i<26;i++)
	{
		cout<<char(186);
		gotoxy(79,i);
	}
	gotoxy(1,5);
	cout<<char(204);
	gotoxy(2,5);
	for(i=0;i<77;i++)
	cout<<char(205);
	cout<<char(185);
	gotoxy(27,3);
	cout<<" DOCTOR INFORMATION FORM ";
	gotoxy(3,7);
	cout<<"DOCTOR ID   :";
	gotoxy(40,7);
	cout<<"DESIGNATION :";
	gotoxy(3,10);
	cout<<"DOCTOR NAME :";
	gotoxy(40,10);
	cout<<"SPECIALITY  :";
	gotoxy(3,13);
	cout<<"AVAILABILITY:";
}
void doc::gdata()
{
	dscreen();
	gotoxy(17,7);
	cin>>id;
	gotoxy(54,7);
	gets(desgn);
	gotoxy(17,10);
	gets(dname);
	gotoxy(54,10);
	cin>>spcia;
	gotoxy(17,13);
	cin>>avail;
}
void doc::sdata()
{
	dscreen();
	gotoxy(17,7);
	cout<<id;
	gotoxy(54,7);
	puts(desgn);
	gotoxy(17,10);
	puts(dname);
	gotoxy(54,10);
	cout<<spcia;
	gotoxy(17,13);
	cout<<avail;
}
void patient::getdata()
{
	mainscreen();
	gotoxy(17,7);
	cin>>regno;
	gotoxy(54,7);
	gets(regdate);
	gotoxy(17,10);
	gets(pname);
	gotoxy(54,10);
	cin>>age;
	gotoxy(17,13);
	cin>>gndr;
	gotoxy(54,13);
	gets(bgrp);
	gotoxy(17,16);
	gets(city);
	gotoxy(54,16);
	cin>>cntct;
	gotoxy(17,19);
	gets(addrs);
}
void patient::showdata()
{
	mainscreen();
	gotoxy(17,7);
	cout<<regno;
	gotoxy(54,7);
	puts(regdate);
	gotoxy(17,10);
	puts(pname);
	gotoxy(54,10);
	cout<<age;
	gotoxy(17,13);
	cout<<gndr;
	gotoxy(54,13);
	puts(bgrp);
	gotoxy(17,16);
	puts(city);
	gotoxy(54,16);
	cout<<cntct;
	gotoxy(17,19);
	puts(addrs);
	getch();
}
void mainscreen()
{
	clrscr();
	gotoxy(2,1);
	for(i=0;i<77;i++)
	cout<<char(205);
	cout<<char(187);
	gotoxy(1,1);
	cout<<char(201);
	gotoxy(1,2);
	for(i=3;i<26;i++)
	{
		cout<<char(186);
		gotoxy(1,i);
	}
	cout<<char(200);
	for(i=1;i<78;i++)
	cout<<char(205);
	cout<<char(188);
	gotoxy(79,2);
	for(i=3;i<26;i++)
	{
		cout<<char(186);
		gotoxy(79,i);
	}
	gotoxy(1,5);
	cout<<char(204);
	gotoxy(2,5);
	for(i=0;i<77;i++)
	cout<<char(205);
	cout<<char(185);
	gotoxy(27,3);
	cout<<" PATIENT INFORMATION FORM ";
	gotoxy(3,7);
	cout<<"REG NO.     :";
	gotoxy(40,7);
	cout<<"REG. DATE   :";
	gotoxy(3,10);
	cout<<"NAME        :";
	gotoxy(40,10);
	cout<<"AGE         :";
	gotoxy(3,13);
	cout<<"GENDER (M/F):";
	gotoxy(40,13);
	cout<<"BLOOD GRP.  :";
	gotoxy(3,16);
	cout<<"CITY        :";
	gotoxy(40,16);
	cout<<"CONTACT     :";
	gotoxy(3,19);
	cout<<"ADDRESS     :";
}
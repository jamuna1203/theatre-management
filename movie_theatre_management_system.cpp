// movie theatre management system
#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <cstdio.h>
#include <string.h>
#include <process.h>
#include <iomanip.h>

void allm ();
void write_mov ();
void write_movieb ();
void display_all ();
void display_movie ();
void admin_menu ();
void invoice (int);
void display_sr (int);
void display_mov (int);
void modify_record (int);
void modify_movie (int);
void delete_record ();
void del_movie ();
void menu ();

class movie
{
  int movied;
  char moviena[30];
  int mins;
public:
  void emovie ()
  {
    cout << " Enter Movie ID: ";
    cin >> movied;
    cout << "\n Enter Movie Name: ";
    gets (moviena);
    cout << "\n Enter Runtime (mins): ";
    cin >> mins;
  }
  void smovie ()
  {
    cout << "Movie ID: " << movied << endl;
    cout << "Title: " << moviena << endl;
    cout << "Runtime(mins): " << mins << endl;
  }
  int retmovied ()
  {
    return movied;
  }
  char *retmoviena ()
  {
    return moviena;
  }
  int retmins ()
  {
    return mins;
  }
  void report ()
  {
    cout << " " << movied << "    " << moviena << "                       " <<
      mins << endl;
  }
} mbs;

class movieb
{
  int movien;
  char cname[30];
  char phnno[11];
  int number;
  int cid;
  int showt;
  int cost;
public:
  void enter ()
  {
    cout << "Enter Movie ID: ";
    cin >> movien;
    cout << endl;
    cout << "Enter Customer Name: ";
    gets (cname);
    cout << endl;
    cout << "Enter Customer ID(provided beforehand): ";
    cin >> cid;
    cout << endl;
    cout << "Enter Phone Number of customer: ";
    gets (phnno);
    cout << endl;
    cout << "Enter Number of Tickets: ";
    cin >> number;
    cout << endl;
    cout << "Enter Show Time (options given above(1-5)): ";
    cin >> showt;
    cout << endl;
    if (showt == 1 || showt == 2)
      cost = (number * 250);
    else if (showt == 3 || showt == 4)
      cost = (number * 350);
    else if (showt == 5)
      cost = (number * 300);
    getch ();
  }

  void show ()
  {
    cout << "Movie ID : " << movien << endl;
    cout << "Customer Name : " << cname << endl;
    cout << "Customer ID : " << cid << endl;
    cout << "Customer Phone Number : " << phnno << endl;
    cout << "Number of Tickets : " << number << endl;
    cout << "Show : " << showt << endl;
    cout << "Amount to be paid : " << cost << "/- only" << endl;
  }

  void bill ()
  {
    cout << endl;
    cout << "=======================================" << endl;
    cout << "***************************************" << endl;
    cout << endl;
    cout << "                SM CINEMAS" << endl;
    cout << " Movie ID :--------|" << setw (12) << movien << endl;
    cout << " Customer Name :---|" << setw (12) << cname << endl;
    cout << " Customer ID :-----|" << setw (12) << cid << endl;
    cout << " Phone Number :----|" << setw (12) << phnno << endl;
    cout << " No. of Tickets :--|" << setw (12) << number << endl;
    cout << " Show :------------|" << setw (12) << showt << endl;
    cout << " Total Amount :----|" << setw (12) << cost << endl;
    cout << "\n       Thank you for visiting us!" << endl;
    cout << "***************************************" << endl;
    cout << "=======================================" << endl;
  }

  int retmno ()
  {
    return movien;
  }
  char *retname ()
  {
    return cname;
  }
  char *retphnno ()
  {
    return phnno;
  }
  int retn ()
  {
    return number;
  }
  int retcost ()
  {
    return cost;
  }
  int retcid ()
  {
    return cid;
  }
};

fstream fp;
movieb mb;

void write_mov ()
{
  clrscr ();
  fp.open ("mov.dat", ios::out | ios::app);
  mbs.emovie ();
  fp.write ((char *) &mbs, sizeof (mbs));
  fp.close ();
  cout << "\n The record has been entered ";
  getch ();
  menu ();
}

void allm ()
{
  fp.open ("mov.dat", ios::in);
  if (!fp)
    {
      cout << "ERROR!!! FILE COULD NOT BE OPENED ";
      getch ();
      return;
    }

  cout << "\n\t           MOVIE LIST\n";
  cout <<
    "====================================================================\n";
  cout << " Movie ID" << setw (10) << "Title" << setw (30) << "Runtime\n";
  cout <<
    "====================================================================\n";

  while (fp.read ((char *) &mbs, sizeof (mbs)))
    {
      mbs.report ();
    }

  fp.close ();
  getch ();
}

void write_movieb ()
{
  clrscr ();
  cout << "Movie Timings: " << endl;
  cout << "Show 1: 10:30 am                  Show 2: 01:30 pm " << endl;
  cout << "Show 3: 05:00 pm                  Show 4: 08:30 pm " << endl;
  cout << "Show 5: 11:00 pm " << endl;
  allm ();
  cout << endl;
  fp.open ("cust.dat", ios::out | ios::app);
  mb.enter ();
  fp.write ((char *) &mb, sizeof (mb));
  fp.close ();
  mb.bill ();
  getch ();
  menu ();
}

void display_all ()
{
  clrscr ();
  cout << "\n DISPLAY ALL RECORDS \n";
  fp.open ("cust.dat", ios::in);
  while (fp.read ((char *) &mb, sizeof (mb)))
    {
      mb.show ();
      cout << "\n";
      getch ();
    }
  fp.close ();
  getch ();
}

void display_movie ()
{
  clrscr ();
  cout << "\n DISPLAY ALL RECORDS \n";
  fp.open ("mov.dat", ios::in);
  while (fp.read ((char *) &mbs, sizeof (mbs)))
    {
      mbs.smovie ();
      cout << "\n";
      getch ();
    }
  fp.close ();
  getch ();
}

void admin_menu ()
{
  clrscr ();
  char cgj[20];
  char pas[20] = "pass";
  cout << "Login to enter ADMIN mode: " << endl;
  cout << "Enter password: ";
  gets (cgj);
  int ref = strcmp (cgj, pas);
  if (ref == 0)
    {
      clrscr ();
      int ch2;
      cout << "\n \t Please Enter Your Choice (1-10) ";
      cout << "\n \t ADMIN MENU";
      cout << "\n \t 1.DISPLAY ALL BOOKINGS";
      cout << "\n \t 2.DISPLAY ALL MOVIES";
      cout << "\n \t 3.CUSTOMER QUERY";
      cout << "\n \t 4.MODIFY CUSTOMER RECORD";
      cout << "\n \t 5.DELETE CUSTOMER RECORD";
      cout << "\n \t 6.ENTER MOVIE";
      cout << "\n \t 7.MOVIE QUERY";
      cout << "\n \t 8.MODIFY MOVIE RECORD";
      cout << "\n \t 9.DELETE MOVIE RECORD";
      cout << "\n \t 10.LOGOUT " << endl;;
      cin >> ch2;
      switch (ch2)
	{
	case 1:
	  display_all ();
	  break;
	case 2:
	  display_movie ();
	  break;
	case 3:
	  int numd;
	  clrscr ();
	  cout << "\nPlease Enter Customer ID :";
	  cin >> numd;
	  display_sr (numd);
	  break;
	case 4:
	  int num;
	  clrscr ();
	  cout << "\nPlease Enter Customer ID :";
	  cin >> num;
	  modify_record (num);
	  break;
	case 5:
	  delete_record ();
	  break;
	case 6:
	  write_mov ();
	  break;
	case 7:
	  int numb;
	  clrscr ();
	  cout << "\nPlease Enter The Movie ID. ";
	  cin >> numb;
	  display_mov (numb);
	  break;
	case 8:
	  int nums;
	  clrscr ();
	  cout << "\nPlease Enter The Movie ID. ";
	  cin >> nums;
	  modify_movie (nums);
	  break;
	case 9:
	  del_movie ();
	  break;
	case 10:
	  menu ();
	  getch ();
	default:
	  admin_menu ();
	}
    }
  else if (ref == 1)
    {
      cout << "Invalid Password!";
      menu ();
      getch ();
    }
}


void display_sr (int n)
{
  clrscr ();
  int flag = 0;
  fp.open ("cust.dat", ios::in);
  while (fp.read ((char *) &mb, sizeof (mb)))
    {
      if (mb.retcid () == n)
	{
	  clrscr ();
	  mb.show ();
	  flag = 1;
	}
    }
  fp.close ();
  if (flag == 0)
    cout << "\n Record Does Not Exist!";
  getch ();
}

void display_mov (int n)
{
  clrscr ();
  int flag = 0;
  fp.open ("mov.dat", ios::in);
  while (fp.read ((char *) &mbs, sizeof (mbs)))
    {
      if (mbs.retmovied () == n)
	{
	  clrscr ();
	  mbs.smovie ();
	  flag = 1;
	}
    }
  fp.close ();
  if (flag == 0)
    cout << "\n Record Does Not Exist!";
  getch ();
}

void
modify_record (int no)
{
  int found;
  fp.open ("cust.dat", ios::in | ios::out);
  while (fp.read ((char *) &mb, sizeof (mb)) && found == 0)
    {
      if (mb.retcid () == no)
	{
	  mb.show ();
	  cout << "\nPlease Enter The New Details of Record: " << endl;
	  mb.enter ();
	  int pos = -1 * sizeof (mb);
	  fp.seekp (pos, ios::cur);
	  fp.write ((char *) &mb, sizeof (mb));
	  cout << "\n\t Record Updated";
	  found = 1;
	  mb.bill ();
	}
    }
  fp.close ();
  if (found == 0)
    cout << "\n\n Record Not Found ";
  getch ();
}

void modify_movie (int no)
{
  int found;
  fp.open ("mov.dat", ios::in | ios::out);
  while (fp.read ((char *) &mbs, sizeof (mbs)) && found == 0)
    {
      if (mbs.retmovied () == no)
	{
	  mbs.smovie ();
	  cout << "\nPlease Enter The New Details of Record: " << endl;
	  mbs.emovie ();
	  int pos = -1 * sizeof (mbs);
	  fp.seekp (pos, ios::cur);
	  fp.write ((char *) &mbs, sizeof (mbs));
	  cout << "\n\t Record Updated";
	  found = 1;
	}
    }
  fp.close ();
  if (found == 0)
    cout << "\n\n Record Not Found ";
  getch ();
}

void delete_record ()
{
  int no;
  clrscr ();
  cout << "\n Delete Record";
  cout << "\n Enter the Customer ID of the Record you want to delete";
  cin >> no;
  fp.open ("cust.dat", ios::in | ios::out);
  fstream fp2;
  fp2.open ("temp.dat", ios::out);
  fp.seekg (0, ios::beg);
  while (fp.read ((char *) &mb, sizeof (mb)))
    {
      if (mb.retcid () != no)
	{
	  fp2.write ((char *) &mb, sizeof (mb));
	}
    }
  fp2.close ();
  fp.close ();
  remove ("cust.dat");
  rename ("temp.dat", "cust.dat");
  cout << "\n \t Record Deleted ..";
  getch ();
  menu ();
}

void del_movie ()
{
  int no;
  clrscr ();
  cout << "\n Delete Record";
  cout << "\n Enter the ID of the Movie record you want to delete";
  cin >> no;
  fp.open ("mov.dat", ios::in | ios::out);
  fstream fp3;
  fp3.open ("temp.dat", ios::out);
  fp.seekg (0, ios::beg);
  while (fp.read ((char *) &mbs, sizeof (mbs)))
    {
      if (mbs.retmovied () != no)
	{
	  fp3.write ((char *) &mbs, sizeof (mbs));
	}
    }
  fp3.close ();
  fp.close ();
  remove ("mov.dat");
  rename ("temp.dat", "mov.dat");
  cout << "\n \t Record Deleted ..";
  getch ();
  menu ();
}

void menu ()
{
  cout << "\n\tPlease Select Your Option (1-3) ";
  int cho;
  cout << "\n \t\t\t MAIN MENU" << endl;
  cout << "\t 01. MOVIE TICKET BOOKING" << endl;
  cout << "\t 02. ADMINISTRATOR MENU" << endl;
  cout << "\t 03. EXIT" << endl;
  cin >> cho;
  switch (cho)
    {
    case 1:
      clrscr ();
      write_movieb ();
      getch ();
      break;
    case 2:
      admin_menu ();
      break;
    case 3:
      exit (0);
      break;
    default:
      cout << "Enter a valid option !" << endl;
      menu ();
      break;
    }
}

void main ()
{
  clrscr ();
  intro ();
  menu ();
  getch ();
}
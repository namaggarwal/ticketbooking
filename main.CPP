#include<fstream.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
void wrongchoice();
void showdet();
void canceltick();
class
details
{
int choice,seats,price,i,j,tot,tickno,tickets;
char address[80],films[80],time[20],date[30],name[20];
public:
void custumdet();
void tickdet(int n);
void showtick();
void savedet();
void dispdet();
int picname(int j);
int returntickno();
int returntickets();
int returntot();
}k;


void details::custumdet()
{
gotoxy(14,5);
cout<<"Your Name Please ";
gets(name);
gotoxy(14,7);
cout<<"Hello "<<name<<" hope you have Enquired about the Films ";
gotoxy(14,9);
cout<<"Please Enter Your Address ";
gets(address);
}// function customdetail closing
int details::picname(int j)
{
switch(j)
{
case 2412:strcpy(films,"PHIR HERA PHERI ");
	  break;
case 2413:strcpy(films,"CHUP CHUP KE ");
	  break;
case 2414:strcpy(films,"MISSION IMPOSSIBLE 3");
	  break;
case 2415:strcpy(films,"KRRISH ");
	  break;
case 2416:strcpy(films,"KABHI ALVIDA NA KEHNA ");
	  break;
case 2417:strcpy(films,"DHOOM 2");
	  break;
default:return 3;
}// switch j ending
return 2;
}

void details::tickdet(int n)
{int ticknot,l=0,cod,ret;
clrscr();
gotoxy(14,11);
cout<<name<<" Enter The Code Of The Film You Want To See ";
cin>>cod;
ret=picname(cod);
if(ret==3)
{clrscr();
gotoxy(19,9);
cout<<"Sorry This Film Is Currently Not Available ";
gotoxy(19,10);
cout<<"Or The Entered Code Is Wrong Please Check the Code ";
gotoxy(19,11);
cout<<"By Pressing 4 On The Main menu ";
gotoxy(19,27);
cout<<"Exiting...................................... ";
delay(4000);
exit(1);
}
gotoxy(14,13);
cout<<"Dated at ";
gets(date);
gotoxy(14,15);
cout<<"Time of Show ";
gets(time);
choice0:
clrscr();
gotoxy(14,10);
cout<<"1. Enter 1 for Front Seats ";
gotoxy(14,12);
cout<<"2. Enter 2 for Rear Seats ";
gotoxy(14,14);
cout<<"3. Enter 3 for Balcony Seats ";
cin>>seats;
if(seats==1)
price=50;
else
if(seats==2)
price=100;
else
if(seats==3)
price=150;
else
{wrongchoice();
goto choice0;
} // else of seats closing
tickpos:
clrscr();
gotoxy(14,9);
cout<<"The Capacity of our Theatre is 100 ";
gotoxy(14,11);
cout<<n<<" Tickets are Sold ";
gotoxy(14,13);
cout<<"You Can Have Maximum of "<<100-n<<" tickets ";
gotoxy(14,16);
cout<<"How Many Tickets Do You Want ";
cin>>tickets;
if(tickets>100-n)
{clrscr();
gotoxy(24,11);
cout<<"Sorry You Cannot have This Much Of Tickets "<<'\n';
gotoxy(24,13);
cout<<"Enter 1 To Re-Enter Number of tickets ";
gotoxy(24,15);
cout<<"Enter Any Other Key To Exit ";
cin>>ticknot;
if(ticknot==1)
{
goto tickpos;
}// if ticknot 1 closing
else
{
exit(1);
} // else of ticknot closing
} // if tickets > 100-n closing
else
{n=n+tickets;
tot=tickets*price;
fstream k("tickno",ios::in|ios::binary);
while(k)
{k>>l;                                       // to generate ticket number
}
tickno=l;                                     //  sequence wise
l++;
k.close();
fstream f("tickno",ios::out|ios::binary);
f<<l;                                          // to update ticket no
f.close();
fstream g("ticksold",ios::out|ios::binary);
g<<n;                                           // to update the ticktes sold
g.close();
gotoxy(14,18);
cout<<name<<" Please Pay Rupees "<<tot;
delay(3000);
} // else of ticket > 100-n closing
} // function ticketdetail closing


void details::showtick()
{
clrscr();
gotoxy(22,10);
cout<<"Thank You "<<name<<" for Rupees "<<tickets*price;
gotoxy(22,12);
cout<<name<<" You get "<<tickets<<" tickets of film "<<films;
gotoxy(22,15);
cout<<"Please Collect Your Ticket ";
delay(3000);
clrscr();
for(i=9;i<76;i++)
{
gotoxy(i,2);
cout<<"-";
gotoxy(i,22);
cout<<"-";
} // for loop i ending
for(j=2;j<=22;j++)
{
gotoxy(9,j);
cout<<"|";
gotoxy(75,j);
cout<<"|";
}// for loop j ending
gotoxy(12,3);
cout<<"Ticket no. "<<tickno;
gotoxy(34,4);
cout<<name;
gotoxy(54,3);
cout<<"PVR Cinemas PVT LTD ";
gotoxy(32,7);
cout<<films;
gotoxy(33,10);
cout<<time;
gotoxy(31,13);
cout<<date;
gotoxy(27,20);
cout<<address;
delay(5000);
} // function show ticket ending


void details::savedet()
{fstream o("Pvr",ios::app|ios::binary);
o.write((char*)&k,sizeof(k));
o.close();
} // function save details ending
void details::dispdet()
{clrscr();
gotoxy(18,7);
cout<<"Ticket Number : "<<tickno;
gotoxy(18,9);
cout<<"Name : ";
puts(name);
gotoxy(18,11);
cout<<"Address : ";
puts(address);
gotoxy(18,13);
cout<<"Film : ";
puts(films);
gotoxy(18,15);
cout<<"Time : ";
puts(time);
gotoxy(18,17);
cout<<"Date : ";
puts(date);
gotoxy(18,19);
cout<<"No Of Tickets Bought : "<<tickets;
gotoxy(18,21);
cout<<"Total Money Paid : "<<tot;
delay(2000);
}// function display details ending

int details::returntickno()
{
return tickno;
}// functin return closing

int details::returntickets()
{
return tickets;
}// func return tick ending


int details::returntot()
{
return tot;
}// func return tot ending


void wrongchoice()
{clrscr();
gotoxy(18,7);
cout<<"Wrong choice Please Re Enter The Choice ";
delay(2000);
} // function wrong choice Ending
void showdet()
{detstart:
int number,m=0;
clrscr();
gotoxy(24,5);
cout<<"Enter The Ticket Number ";
cin>>number;
fstream wt("Pvr",ios::in|ios::binary);
while(wt)
{
wt.read((char*)&k,sizeof(k));
if(number==k.returntickno())
{
k.dispdet();
m=2;
} // if closing
} // while wt closing
wt.close();
if(m!=2)
{clrscr();
gotoxy(24,5);
cout<<"Sorry In Valid Ticket Number ";
delay(2000);
goto detstart;
}// m ! ending
} // function showdet closing

void canceltick()
{
int number,d=0,temptick,temptot,t;
char ch;
canclstrt:
clrscr();
gotoxy(24,4);
cout<<"Please Enter Your Ticket Number ";
cin>>number;
gotoxy(24,6);
cout<<"Are You Sure You Want To Cancel Your Tickets ";
cin>>ch;
if(ch=='y'||ch=='Y')
{
fstream o("pvr",ios::in|ios::binary);
while(o)
{o.read((char*)&k,sizeof(k));
if(number==k.returntickno())
{k.dispdet();
d=2;
temptick=k.returntickets();
temptot=k.returntot();
}// if loop ending
} // while o ending
o.close();
if(d!=2)
{clrscr();
gotoxy(24,6);
cout<<"Invalid Ticket Number ";
delay(2000);
goto canclstrt;
} // d ! = Ending
clrscr();
gotoxy(24,6);
cout<<"canceling........................................ ";
delay(2000);
clrscr();
gotoxy(24,4);
cout<<"Your "<<temptick<<" Tickets Have Been Canceled ";
gotoxy(24,6);
cout<<"Please Collect Your "<<temptot<<" Rupees ";
delay(2000);
fstream m("ticksold",ios::in|ios::binary);
while(m)                                 // Updating Tickets Sold
{m>>t;
}
m.close();
t=t-temptick;
fstream j("ticksold",ios::out|ios::binary);
j<<t;                                        // Updating Tickets Sold
j.close();
fstream s("pvr",ios::in|ios::binary);
fstream b("temp",ios::app|ios::binary);
while(s)
{
s.read((char*)&k,sizeof(k));              // Updating Pvr
if(number!=k.returntickno())
b.write((char*)&k,sizeof(k));
}      // while loop s ending
s.close();
b.close();
remove("pvr");                         // Updating Pvr
rename("temp","pvr");
}// if ch==y Ending
} // Function Cancel Tickets Ending


void main()
{
int chmenu,h,choice,choice1,n=0;
for(h=0;h<50;h++)
{textcolor(h);
clrscr();
gotoxy(24,10);
cout<<"Welcome to PVR Cinemas ";
gotoxy(24,11);
cout<<"Life is Where Theatre is.... ";
delay(100);
}  // for loop closing
textcolor(WHITE);
start1:
clrscr();
gotoxy(26,1);
cout<<"PVR Cinemas PVT LTD ";
gotoxy(24,10);
cout<<"Press 1 For Customer's Menu ";
gotoxy(24,12);
cout<<"Enter 2 For Worker's Menu ";
gotoxy(24,14);
cout<<"Enter 3 To Exit ";
cin>>chmenu;
if(chmenu==1)
{start:
clrscr();
gotoxy(24,4);
cout<<"Welcome To The Customer's Menu Of PVR Cinemas ";
gotoxy(18,9);
cout<<"1. Enter 1 to Book Tickets of The Current Box Office Hits ";
gotoxy(18,11);
cout<<"2. Enter 2 to See Latest Running Films ";
gotoxy(18,13);
cout<<"3. Enter 3 To See Upcoming Films ";
gotoxy(18,15);
cout<<"4. Enter 4 To See Codes Of Movie ";
gotoxy(18,17);
cout<<"5. Enter 5 To See Rates Of Ticket ";
gotoxy(18,19);
cout<<"6. Enter 6 To Go To Next Page Of Menu " ;
gotoxy(18,21);
cout<<"7. Enter 7 To Exit ";
cin>>choice;
clrscr();
if(choice==1)
{k.custumdet();
clrscr();
gotoxy(14,11);
cout<<"We Have Daily Shows Timed at -";
gotoxy(14,13);
cout<<"9:00 am - 12:00 noon ";
gotoxy(14,14);
cout<<"1:00 pm - 4:00 pm ";
gotoxy(14,15);
cout<<"6:00 pm - 9:00 pm ";
gotoxy(14,16);
cout<<"9:30 pm - 12:30 am ";
delay(3000);
fstream l("ticksold",ios::in|ios::binary);
l>>n;                                      // for the number of ticket sold
k.tickdet(n);
k.showtick();
k.savedet();
goto start;
} // if choice 1  closing
else if(choice==2)
{
gotoxy(20,2);
cout<<"Daily 4 Shows ";
gotoxy(18,4);
cout<<"The Latest Running Films Are -------- ";
gotoxy(9,9);
cout<<"PHIR HERA PHERI : Starring -- Akshay Kumar And Sunil Shetty";
gotoxy(9,12);
cout<<"CHUP CHUP KE : Starring -- Shahid Kapoor And Kareena Kapoor";
gotoxy(9,15);
cout<<"MISSION IMPOSSIBLE 3 : Starring -- Tom Cruise ";
delay(4000);
goto start;
}// if choice 2 closing
else
if(choice==3)
{
gotoxy(22,2);
cout<<"Releasing sooooooooooon..... ";
gotoxy(23,4);
cout<<"The Upcoming Films Are ";
gotoxy(9,9);
cout<<"KRRISH : Starring -- Hrithik Roshan And Priyanka Chopra";
gotoxy(9,12);
cout<<"KABHI ALVIDA NA KEHNA : Starring -- Sharukh Khan And Priety Zinta";
gotoxy(9,15);
cout<<"DHOOM 2 : Starring -- Hrithik Roshan and Aishwarya Rai ";
delay(4000);
goto start;
}// if choice 3 closing
else
if(choice==4)
{
gotoxy(16,4);
cout<<"Movie ";
gotoxy(57,4);
cout<<"Code ";
gotoxy(9,7);
cout<<"PHIR HERA PHERI ";
gotoxy(57,7);
cout<<"2412";
gotoxy(9,9);
cout<<"CHUP CHUP KE ";
gotoxy(57,9);
cout<<"2413";
gotoxy(9,11);
cout<<"MISSION IMPOSSIBLE 3";
gotoxy(57,11);
cout<<"2414";
gotoxy(9,13);
cout<<"KRRISH";
gotoxy(57,13);
cout<<"2415";
gotoxy(9,15);
cout<<"KABHI ALVIDA NA KEHNA ";
gotoxy(57,15);
cout<<"2416";
gotoxy(9,17);
cout<<"DHOOM 2 ";
gotoxy(57,17);
cout<<"2417";
delay(4000);
goto start;
}  // choice=4 ending
else
if(choice==5)
{
gotoxy(19,9);
cout<<"The Rates Of Tickets Are As Follows ";
gotoxy(20,13);
cout<<"Front Seats ------ Rs 50/Person ";
gotoxy(20,16);
cout<<"Rear Seats ------ Rs 100/Person ";
gotoxy(20,19);
cout<<"Balcony Seats ------ Rs 150/Person ";
delay(4000);
goto start;
} // if choice 4 closing
else if(choice==6)
{gotoxy(24,4);
cout<<"Welcome To The Menu Of PVR Cinemas ";
gotoxy(18,14);
cout<<"1. Enter 1 to Display The Details Of Tickets Sold ";
gotoxy(18,16);
cout<<"2. Enter 2 to Cancel The Tickets ";
gotoxy(18,18);
cout<<"3. Enter 3 To Go Back To First Menu ";
cin>>choice1;
clrscr();
if(choice1==1)
{
showdet();
goto start;
}  // if choice1 = 1 closing
else
if(choice1==2)
{
canceltick();
goto start;
} // choice1 = 2 closing
else
if(choice1==3)
{
goto start;
} // if choice1 = 3 closing
else
{
wrongchoice();
goto start1;
} // else of choice1 closing
}  // if choice 5 closing

else
if(choice==7)
exit(1);
else
{wrongchoice();
}// else of choice closing
}// if chmenu 1 closing
else
if(chmenu==2)
{
char pass[20],apass[20],n=0;
strcpy(apass,"namantheator");
while(n<3)
{clrscr();
gotoxy(24,10);
cout<<"Please Enter The Password To Proceed ";
cin>>pass;
if(strcmp(pass,apass)==0)
break;
else
{clrscr();
gotoxy(26,12);
cout<<"Wrong Password! Please Re-Enter ";
delay(2000);
n=n+1;
}// else closing
}// while closing
if(n==3)
{
exit(1);
}// if n=3 closing
else
{int q;
wmenu:
clrscr();
gotoxy(24,4);
cout<<"Welcome To The Worker's Menu ";
gotoxy(18,9);
cout<<"1. Enter 1 To See All The Details ";
gotoxy(18,11);
cout<<"2. Enter 2 To Delete All The Records ";
gotoxy(18,13);
cout<<"3. Enter 3 To Exit ";
cin>>q;
switch(q)
{
case 1:fstream o("Pvr",ios::in|ios::binary);
       while(o)
       {o.read((char*)&k,sizeof(k));
       k.dispdet();
       }// while loop o closing
       o.close();
       goto wmenu;
case 2:char h;
       clrscr();
       cout<<"Are you Sure You Want to Delete All Details ";
       cin>>h;
       if(h=='y'||h=='Y')
       {
       remove("pvr");
       fstream g("ticksold",ios::out|ios::binary);
       g<<0;
       g.close();
       clrscr();
       cout<<"All Records Deleted ";
       delay(2000);
       }
       else
       {
       clrscr();
       cout<<"Exiting............................. ";
       delay(4000);
       exit(1);
       }
       goto wmenu;
case 3: exit(1);

default:wrongchoice();
	goto wmenu;

}// closing of switch q
} // closing of n else
} //chmenu==2 closing
else
if(chmenu==3)
exit(1);
else
{wrongchoice();
goto start1;
}// else chmenu closing
getch();
} // main closing

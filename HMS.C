#include<stdio.h>
#include<conio.h>
#include<graphics.h>

char pass[10]={"king"};

void login();
void main_menu();
void room_booking();
void room_booking_details();
void check_status();
void update_record();
void rooms();
void enter_new();
void list_of_rooms();

struct rooms
{
	int room_no;
	char type[20];
	char bed_type[20];
	int tariff;
}ro;

struct bookings
{
	struct guest_info
	{
		char f_name[20];
		char l_name[20];
		char address[20];
		char city[15];
		char state[15];
		char country[15];
		char id_type[15];
		char id_no[20];
	}g;
	struct room_info
	{
		int room_no;
		char room_type[20];
		int no_of_adults;
		int no_of_minor;
		int days;
		int tariff;
	}r;
	char date_in[10];
	char date_out[10];
	int total_rs;
	int paid_rs;
	int due_rs;
}b;

FILE *booking;
FILE *listrooms;

void main()
{
	clrscr();
	login();
	getch();
}
void login()
{
	int gd= DETECT, gm;
	char ch, pwd[20];
	int i= 0;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	setcolor(YELLOW);
	outtextxy(200, 80, "LODGING MANAGEMENT SYSTEM");
	outtextxy(208, 150, "WELCOME TO DELITE HOTEL");
	setcolor(BLUE);
	rectangle(10,20,590,460);
	setcolor(RED);
	rectangle(210,290,380,270);
	setcolor(GREEN);
	outtextxy(185,220,"Enter Password To Continue...");
	gotoxy(18, 35);
	ch= getch();
	while(ch!=13)
	{
		if(ch!= 13 && ch!= 8)
		{
			printf("*");
			pwd[i]= ch;
			i++;
		}
		ch= getch();
	}
	pwd[i]= '\0';
	if(strcmp(pass,(pwd))==0)
	{
		outtextxy(220, 330, "Password Match");
		outtextxy(220, 360, "Continuing in 3 seconds ...");
		delay(3000);
		closegraph();
		main_menu();
	}
	else
	{
		outtextxy(220, 330, "Incorrect Password");
		outtextxy(220, 360, "Exiting in 3 seconds ...");
		delay(3000);
		closegraph();
		exit(0);
	}
	getch();
}
void main_menu()
{
	int gd= DETECT, gm;
	int choice;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	setcolor(GREEN);
	outtextxy(75,100,"*************** LODGING MANAGENMENT SYSTEM ***************");
	outtextxy(87, 150, "*************** WELCOME TO DELITE HOTEL ***************");
	setcolor(BLUE);
	rectangle(3,30,630,450);
	setcolor(YELLOW);
	rectangle(20,216,610,350);
	setcolor(GREEN);
	outtextxy(70,270,"1.Room");
	outtextxy(67,290,"Booking");
	setcolor(RED);
	rectangle(50,230,140,335);
	setcolor(GREEN);
	outtextxy(178,270,"2.Check");
	outtextxy(180,290,"Status");
	setcolor(RED);
	rectangle(160,230,250,335);
	setcolor(GREEN);
	outtextxy(282,270,"3.Update");
	outtextxy(285,290,"Record");
	setcolor(RED);
	rectangle(270,230,360,335);
	setcolor(GREEN);
	outtextxy(395,270,"4.Rooms");
	setcolor(RED);
	rectangle(380,230,470,335);
	setcolor(GREEN);
	outtextxy(510,270,"5.Exit");
	setcolor(RED);
	rectangle(490,230,580,335);
	setcolor(RED);
	rectangle(350,380,475,400);
	setcolor(YELLOW);
	outtextxy(150,385,"Please Enter Your Choice:");
	gotoxy(26, 47);
	scanf("%d", &choice);
	if(choice== 1)
	{
		closegraph();
		room_booking();
	}
	else if(choice== 2)
	{
		closegraph();
		check_status();
	}
	else if(choice== 3)
	{
		closegraph();
		update_record();
	}
	else if(choice== 4)
	{
		closegraph();
		rooms();
	}
	else if(choice== 5)
	{
		closegraph();
		printf("\n\n\tProgrammed By,");
		printf("\n\n\t\t1.   Name: Avinash Kumar\n\t\tSeat No.: 1613924036\n\t\tBCA 2nd Year");
		printf("\n\n\t\t2.   Name: Daksh Oberoi\n\t\tSeat No.: 1613924027\n\t\tBCA 2nd Year");
		printf("\n\n\t\t3.   Name: Nabin Chand\n\t\tSeat No,: 1613924008\n\t\tBCA 2nd Year");
		printf("\n\n\n\n\tWith Unexplainable Help of Dr. Deepali Shahane.");
		printf("\n\n\n\n\n\n\n\t\t\tExiting in 10 Seconds......");
		delay(10000);
		exit(1);
	}
	else
	{
		setcolor(RED);
		outtextxy(200, 420, "Enter Correct Value.");
		delay(3000);
		closegraph();
		main_menu();
	}
	getch();
}
void room_booking()
{
	int gd= DETECT, gm;
	int ch;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	setcolor(GREEN);
	outtextxy(75,100,"*************** LODGING MANAGENMENT SYSTEM ***************");
	outtextxy(87, 150, "*************** WELCOME TO DELITE HOTEL ***************");
	setcolor(BLUE);
	rectangle(3,30,630,450);
	setcolor(YELLOW);
	rectangle(120,216,500,350);
	setcolor(GREEN);
	outtextxy(165,270,"1.Book");
	outtextxy(168,290,"Room");
	setcolor(RED);
	rectangle(145,230,235,335);
	setcolor(GREEN);
	outtextxy(285,270,"2.Check");
	outtextxy(287,290,"Status");
	setcolor(RED);
	rectangle(265,230,355,335);
	setcolor(GREEN);
	outtextxy(400,270,"3.Exit");
	outtextxy(420,285, "To");
	outtextxy(395, 300, "Main Menu");
	setcolor(RED);
	rectangle(385,230,475,335);
	setcolor(RED);
	rectangle(350,380,475,400);
	setcolor(YELLOW);
	outtextxy(150,385,"Please Enter Your Choice:");
	gotoxy(26, 47);
	scanf("%d", &ch);
	if(ch == 1)
	{
		closegraph();
		room_booking_details();
	}
	else if(ch == 2)
	{
		closegraph();
		check_status();
	}
	else if(ch == 3)
	{
		closegraph();
		main_menu();
	}
	else
	{
		setcolor(RED);
		outtextxy(200, 420, "Enter Correct Value.");
		delay(3000);
		closegraph();
		room_booking();
	}
	getch();
}
void room_booking_details()
{
	int gd= DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	booking= fopen("booking.txt", "a");
	setcolor(GREEN);
	outtextxy(87, 20, "*************** WELCOME TO DELITE HOTEL ***************");
	setcolor(YELLOW);
	outtextxy(98, 40, "*************** Room Booking Details ***************");
	setcolor(BLUE);
	rectangle(2,5,630,470);
	setcolor(WHITE);
	outtextxy(40, 60, "Guest Information");
	outtextxy(400, 60, "Room Information");
	outtextxy(40, 300, "Identification Information");
	setcolor(GREEN);
	outtextxy(15, 87, "First Name:");
	outtextxy(15, 117, "Last Name:");
	outtextxy(15, 147, "Address:");
	outtextxy(15, 177, "City:");
	outtextxy(15, 207, "State:");
	outtextxy(15, 237, "Country:");
	outtextxy(350, 87, "Room No.:");
	outtextxy(350, 117, "Room Type:");
	outtextxy(350, 147, "No. of. Adults:");
	outtextxy(350, 177, "No. of. Minor:");
	outtextxy(350, 207, "No. of. Days:");
	outtextxy(350, 237, "Tariff (Rs):");
	outtextxy(350, 267, "Date IN:");
	outtextxy(360, 285, "(dd/mm/yy)");
	outtextxy(350, 315, "Date OUT:");
	outtextxy(360, 333, "(dd/mm/yy)");
	outtextxy(15, 340, "ID Type:");
	outtextxy(15, 395, "ID No.:");
	setcolor(YELLOW);
	outtextxy(370, 355, "Total Rs.");
	outtextxy(410, 385, "Paid Rs.");
	outtextxy(240, 385, "Due Rs.");
	setcolor(RED);
	rectangle(110, 75, 210, 98);
	rectangle(110, 110, 210, 130);
	rectangle(110, 140, 210, 160);
	rectangle(110, 175, 210, 195);
	rectangle(110, 205, 210, 225);
	rectangle(110, 235, 210, 260);
	rectangle(480, 75, 580, 98);
	rectangle(480, 110, 580, 130);
	rectangle(480, 140, 580, 160);
	rectangle(480, 175, 580, 195);
	rectangle(480, 205, 580, 225);
	rectangle(480, 235, 580, 260);
	rectangle(480, 268, 580, 288);
	rectangle(480, 316, 580, 336);
	rectangle(100, 335, 230, 355);
	rectangle(100, 382, 230, 405);
	setcolor(GREEN);
	rectangle(480, 350, 580, 370);
	rectangle(480, 380, 580, 400);
	rectangle(300, 380, 380, 400);
	gotoxy(6, 15);
	scanf("%s", b.g.f_name);
	gotoxy(8, 15);
	scanf("%s", b.g.l_name);
	gotoxy(10, 15);
	scanf("%s", b.g.address);
	gotoxy(12, 15);
	scanf("%s", b.g.city);
	gotoxy(14, 15);
	scanf("%s", b.g.state);
	gotoxy(16,15);
	scanf("%s", b.g.country);
	gotoxy(22, 14);
	scanf("%s", b.g.id_type);
	gotoxy(26, 14);
	scanf("%s", b.g.id_no);
	gotoxy(6, 62);
	scanf("%d", &b.r.room_no);
	gotoxy(8, 62);
	fflush(stdin);
	scanf("%s", b.r.room_type);
	gotoxy(10, 62);
	scanf("%d", &b.r.no_of_adults);
	gotoxy(12, 62);
	scanf("%d", &b.r.no_of_minor);
	gotoxy(14, 62);
	scanf("%d", &b.r.days);
	gotoxy(16, 62);
	scanf("%d", &b.r.tariff);
	gotoxy(18, 62);
	scanf("%s", b.date_in);
	gotoxy(21, 62);
	scanf("%s", b.date_out);
	gotoxy(23, 62);
	scanf("%d", &b.total_rs);
	gotoxy(25, 62);
	scanf("%d", &b.paid_rs);
	gotoxy(35, 40);
	scanf("%d", &b.due_rs);
	fprintf(booking, "\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%d\t%d\t%d\t%d\t%s\t%s\t%d\t%d\t%d\t", b.g.f_name, b.g.l_name, b.g.address, b.g.city, b.g.state, b.g.country, b.g.id_type, b.g.id_no, b.r.room_no, b.r.room_type, b.r.no_of_adults, b.r.no_of_minor, b.r.days, b.r.tariff, b.date_in, b.date_out, b.total_rs, b.paid_rs, b.due_rs);
	fclose(booking);
	outtextxy(150, 420, "Booking Room.....");
	delay(1000);
	outtextxy(150, 440, "Room Booked...");
	delay(1000);
	closegraph();
	main_menu();
	getch();
}
void check_status()
{
	int a=5;
	char ch;
	int gd= DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	booking= fopen("booking.txt", "r");
	setcolor(GREEN);
	outtextxy(87, 20, "*************** WELCOME TO DELITE HOTEL ***************");
	setcolor(YELLOW);
	outtextxy(107, 35, "*************** Booked Room Status ***************");
	setcolor(BLUE);
	rectangle(10,10,610,470);
	setcolor(RED);
	outtextxy(30, 60, "Name");
	outtextxy(100, 60, "Room No.");
	outtextxy(200, 60, "No. of. Days");
	outtextxy(330, 60, "Check IN");
	outtextxy(420, 60, "Check OUT");
	outtextxy(510, 60, "Amount Due");
	while(!feof(booking))
	{
		fscanf(booking, "\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%d\t%d\t%d\t%d\t%s\t%s\t%d\t%d\t%d\t", &b.g.f_name, &b.g.l_name, &b.g.address, &b.g.city, &b.g.state, &b.g.country, &b.g.id_type, &b.g.id_no, &b.r.room_no, &b.r.room_type, &b.r.no_of_adults, &b.r.no_of_minor, &b.r.days, &b.r.tariff, &b.date_in, &b.date_out, &b.total_rs, &b.paid_rs, &b.due_rs);
		gotoxy(a, 15);
		printf("\n  %s  \t%d\t\t%d       %s       %s\t  %d", b.g.f_name, b.r.room_no, b.r.days, b.date_in, b.date_out, b.due_rs);
		a+=2;
	}
	fclose(booking);
	gotoxy(45, 10);
	printf("Press 'b' for Booking Menu or 'm' for Main Menu: ");
	ch= getch();
	if(ch=='b' || ch=='B')
	{
		closegraph();
		room_booking();
	}
	else if(ch=='m' || ch=='M')
	{
		closegraph();
		main_menu();
	}
}
void update_record()
{
	FILE *temp;
	char name[20];
	int rno, due, paid;
	int gd= DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	booking= fopen("booking.txt", "r");
	temp= fopen("tem.txt", "a");
	setcolor(GREEN);
	outtextxy(87, 50, "*************** WELCOME TO DELITE HOTEL ***************");
	setcolor(YELLOW);
	outtextxy(123, 75, "*************** Update Record ***************");
	setcolor(BLUE);
	rectangle(10,30,610,450);
	setcolor(GREEN);
	outtextxy(50, 130, "Enter First Name:");
	outtextxy(50, 170, "Enter Room No.:");
	outtextxy(50, 210, "Due Remaining:");
	outtextxy(50, 250, "Paid:");
	setcolor(RED);
	rectangle(200, 120, 310, 145);
	rectangle(200, 155, 310, 180);
	rectangle(200, 205, 310, 225);
	rectangle(200, 235, 310, 260);
	gotoxy(9, 27);
	scanf("%s", &name);
	gotoxy(11, 27);
	scanf("%d", &rno);
	gotoxy(14, 27);
	scanf("%d", &due);
	gotoxy(16, 27);
	scanf("%d", &paid);
	while(!feof(booking))
	{
		fscanf(booking, "\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%d\t%d\t%d\t%d\t%s\t%s\t%d\t%d\t%d\t", &b.g.f_name, &b.g.l_name, &b.g.address, &b.g.city, &b.g.state, &b.g.country, &b.g.id_type, &b.g.id_no, &b.r.room_no, &b.r.room_type, &b.r.no_of_adults, &b.r.no_of_minor, &b.r.days, &b.r.tariff, &b.date_in, &b.date_out, &b.total_rs, &b.paid_rs, &b.due_rs);
		if(strcmp(b.g.f_name, (name))==0)
		{
			if(rno==b.r.room_no)
			{
				fprintf(temp, "\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%d\t%d\t%d\t%d\t%s\t%s\t%d\t%d\t%d\t", b.g.f_name, b.g.l_name, b.g.address, b.g.city, b.g.state, b.g.country, b.g.id_type, b.g.id_no, b.r.room_no, b.r.room_type, b.r.no_of_adults, b.r.no_of_minor, b.r.days, b.r.tariff, b.date_in, b.date_out, b.total_rs, paid, due);
			}
		}
		else
		{
			fprintf(temp, "\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%d\t%d\t%d\t%d\t%s\t%s\t%d\t%d\t%d\t", b.g.f_name, b.g.l_name, b.g.address, b.g.city, b.g.state, b.g.country, b.g.id_type, b.g.id_no, b.r.room_no, b.r.room_type, b.r.no_of_adults, b.r.no_of_minor, b.r.days, b.r.tariff, b.date_in, b.date_out, b.total_rs, b.paid_rs, b.due_rs);
		}
	}
	fclose(booking);
	fclose(temp);
	remove("booking.txt");
	rename("tem.txt","booking.txt");
	setcolor(GREEN);
	outtextxy(150, 320, "Updating Details.....");
	delay(1000);
	outtextxy(150, 340, "Details Updated...");
	delay(1000);
	closegraph();
	main_menu();
	getch();
}
void rooms()
{
	int gd= DETECT, gm;
	int ch;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	setcolor(GREEN);
	outtextxy(75,100,"*************** LODGING MANAGENMENT SYSTEM ***************");
	outtextxy(87, 150, "*************** WELCOME TO DELITE HOTEL ***************");
	setcolor(BLUE);
	rectangle(3,30,630,450);
	setcolor(YELLOW);
	rectangle(120,216,500,350);
	setcolor(GREEN);
	outtextxy(165,270,"1.Enter");
	outtextxy(168,290,"New");
	setcolor(RED);
	rectangle(145,230,235,335);
	setcolor(GREEN);
	outtextxy(285,270,"2.Check");
	outtextxy(287,290,"List");
	setcolor(RED);
	rectangle(265,230,355,335);
	setcolor(GREEN);
	outtextxy(400,270,"3.Exit");
	outtextxy(420,285, "To");
	outtextxy(395, 300, "Main Menu");
	setcolor(RED);
	rectangle(385,230,475,335);
	setcolor(RED);
	rectangle(350,380,475,400);
	setcolor(YELLOW);
	outtextxy(150,385,"Please Enter Your Choice:");
	gotoxy(26, 47);
	scanf("%d", &ch);
	if(ch == 1)
	{
		closegraph();
		enter_new();
	}
	else if(ch == 2)
	{
		closegraph();
		list_of_rooms();
	}
	else if(ch == 3)
	{
		closegraph();
		main_menu();
	}
	else
	{
		setcolor(RED);
		outtextxy(200, 420, "Enter Correct Value.");
		delay(3000);
		closegraph();
		rooms();
	}
	getch();
}
void enter_new()
{
	int gd= DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	listrooms= fopen("room.txt", "a");
	setcolor(GREEN);
	outtextxy(87, 50, "*************** WELCOME TO DELITE HOTEL ***************");
	setcolor(YELLOW);
	outtextxy(80, 80, "*************** Enter Details of New Room ***************");
	setcolor(BLUE);
	rectangle(10,30,610,450);
	setcolor(GREEN);
	outtextxy(50, 130, "Enter Room No.:");
	outtextxy(50, 170, "Enter Room Type:");
	setcolor(YELLOW);
	outtextxy(320, 170, "(Enter AC or NonAC)");
	setcolor(GREEN);
	outtextxy(50, 210, "Enter Bed Type:");
	setcolor(YELLOW);
	outtextxy(320, 210, "(Enter Single or Double)");
	setcolor(GREEN);
	outtextxy(50, 250, "Enter Tariff (Rs):");
	setcolor(RED);
	rectangle(200, 120, 310, 145);
	rectangle(200, 155, 310, 180);
	rectangle(200, 205, 310, 225);
	rectangle(200, 235, 310, 260);
	gotoxy(9, 27);
	scanf("%d", &ro.room_no);
	gotoxy(11, 27);
	scanf("%s", &ro.type);
	gotoxy(14, 27);
	scanf("%s", &ro.bed_type);
	gotoxy(16, 27);
	scanf("%d", &ro.tariff);
	fprintf(listrooms, "\n%d\t%s\t%s\t%d", ro.room_no, ro.type, ro.bed_type, ro.tariff);
	fclose(listrooms);
	setcolor(GREEN);
	outtextxy(150, 320, "Saving Room Details.....");
	delay(1000);
	outtextxy(150, 340, "Room Details Saved...");
	delay(1000);
	closegraph();
	rooms();
	getch();
}
void list_of_rooms()
{
	int a=5;
	char ch;
	int gd= DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	listrooms= fopen("room.txt","r");
	setcolor(GREEN);
	outtextxy(87, 20, "*************** WELCOME TO DELITE HOTEL ***************");
	setcolor(YELLOW);
	outtextxy(125, 35, "*************** List of Rooms ***************");
	setcolor(BLUE);
	rectangle(10,10,610,470);
	setcolor(RED);
	outtextxy(30, 60, "Room No.");
	outtextxy(200, 60, "Type");
	outtextxy(350, 60, "Bed Type");
	outtextxy(500, 60, "Tariff (Rs)");
	while(!feof(listrooms))
	{
		fscanf(listrooms, "\n%d\t%s\t%s\t%d", &ro.room_no, &ro.type, &ro.bed_type, &ro.tariff);
		gotoxy(a, 15);
		printf("\n       %d\t\t  %s\t\t     %s\t\t    %d", ro.room_no, ro.type, ro.bed_type, ro.tariff);
		a+=2;
	}
	fclose(booking);
	gotoxy(45, 10);
	printf("Press 'r' for Rooms Menu or 'm' for Main Menu: ");
	ch= getch();
	if(ch=='r' || ch=='R')
	{
		closegraph();
		rooms();
	}
	else if(ch=='m' || ch=='M')
	{
		closegraph();
		main_menu();
	}
}
void gotoxy(int x,int y)
{
	printf("%c[%d;%df", 0x1B, x, y);
}
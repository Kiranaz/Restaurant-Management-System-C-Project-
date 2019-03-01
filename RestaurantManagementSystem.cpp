#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>
#include<iostream.h>
FILE *ft;
FILE *fn;
FILE *fm;
FILE *ff;
void order(void);
void viewbill(void);
void givefeed(void);
void list(void);
void feedback(void);
void call1(void);
void call2(void);
void starter(void);
void maincourse(void);
void beverages(void);
void deserts(void);
void timeNdate(void);
void viewgraph(void)  ;
void graph (int ,int, int, int, int, int, int, int ,int, int ,int, int,int, int, int , int );
void pass(void);
void thanks(void);
void wait(void);
void welcome(void);
void home(void);
void revieworder(void);
void customer(void);
void show_customer_record(void);
int i,cs,gb,chs,fr,mc,ap,fc,gs,cp,es,hc,fco,rv,lc,hf,cc,w,final,indicator=0;
long int total=0;

struct customer_record
{
 char name[20];
 char number[12];
 int visit;
 }cust[2];

struct manager
{  char name[20];
  int price;
  int quantity;
}m;
struct customer
{ char name[20];
  int price;
  int quantity;
 }c[20];
char feed[30],another='y';
char choice,choose,choose1,ehh,choose2,dish[20],select1,select2,select3,select4;
int x,again=0;
/********************MAIN********************/
int main()
 {
 clrscr();
 welcome();
  textcolor(YELLOW);
	textbackground(MAGENTA);
  home();
  return 0;
     }
     
     /********************************show_customer_record********************************/
     
    void show_customer_record(void)
     {

          textcolor(YELLOW);
	textbackground(MAGENTA);
         clrscr();
         FILE *fp;
         fp=fopen("CUSTOMER.DAT","rb+");
         fseek(fp,0,0);
while( fread(&cust[1],sizeof(cust[1]),1,fp)==1 )
{  printf("\nNAME:%s\nNUMBER:%s\nVISITS:%d times\n______________________________________",cust[1].name,cust[1].number,cust[1].visit);   }
     fclose(fp);
     getch();
     }


/************************customer***********************************/

     void cutomer (void)
     {
         textcolor(YELLOW);
	textbackground(MAGENTA);
         clrscr();
         FILE *fp;
 printf("ENTER YOUR NAME:");
 gets(cust[0].name);
 printf("ENTER YOUR PHONE NUMBER :");
 gets(cust[0].number);
 fp=fopen("CUSTOMER.DAT","rb+");

 fseek(fp,SEEK_SET,0);
 while ( fread(&cust[1],sizeof(cust[1]),1,fp)==1 )
 {
  if ( strcmp(cust[0].number,cust[1].number)==0 )
  {
   printf("\n\n\n\t\t\tWELCOME %s YOU HAVE VISITED US %d times\n",cust[1].name,cust[1].visit);
   cust[1].visit++;
   fseek(fp,-34,1); /*GOES 42 BYTES BACK */
   fwrite(&cust[1],sizeof(cust[1]),1,fp); /*UPDATES THE VISITS*/
   indicator=1;
   break;
  }
 }

 if (indicator==0)
  {
 printf("\n\n\n\t\t\tWELCOME %s YOU ARE OUR NEW CUSTOMER\n",cust[0].name);
  cust[0].visit=1;
  fseek(fp,SEEK_SET,2);
  fwrite(&cust[0],sizeof(cust[0]),1,fp);
  }



  fclose(fp);
 getch();

     }



 /**************************FEEDBACK*************************/
    void feedback (void)
    {
     textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
	ff=fopen("feed.dat","ab+");
	while(fread(&feed,sizeof(feed),1,ff)==1){


       textcolor(YELLOW);
	textbackground(MAGENTA);
	printf("%s\n",feed);     }
	fclose(ff);
	getch();
     }
    /************************LIST**********************/
     void list(void)

     {
	  clrscr();
	  textcolor(YELLOW);
	textbackground(MAGENTA);
	fn=fopen("new.dat","rb+");
	fseek(fn,0,0);
	  textcolor(YELLOW);
	textbackground(MAGENTA);

	printf("*** PREVIOUS ORDERS READ FROM THE FILE ***\n\n");
	printf("QUANTITY\tDISH\tPRICE\n");
	while(fread(&m,sizeof(m),1,fn)==1)

	{

       textcolor(YELLOW);
	textbackground(MAGENTA);
	printf("%d\t%s\tRS %d\n", m.quantity,m.name,m.price*m.quantity);}
	fclose(fn);
	remove("myfile.dat");
	rename("temp.dat","myfile.dat");

	getch();

	}
      /********************************ORDER**********************/
      void order(void)
	{
	    while(1)
	{
	   clrscr();
	    textcolor(YELLOW);
	textbackground(MAGENTA);
    gotoxy(30,3);
    printf("    MENU  ");
    gotoxy(30,6);
    printf("1.STARTERS");
    gotoxy(30,8);
    printf("2.MAIN COURSE");
    gotoxy(30,10);
    printf("3.BEVERAGES");
    gotoxy(30,12);
    printf("4.DESSERTS");
    gotoxy(30,14);
    printf("5.BACK");


    choice=getch();
    if (choice=='1')
    {starter();
    break;}
    else if (choice=='2')
    {maincourse();
     break;}
  else if (choice=='3')
  {beverages();
  break;}
  else if (choice=='4')
   {deserts();
   break;}

  else if (choice=='5')
   {call2();
    break;}

      else
      { order();
	  }
	}
	}

      /******************************VIEWBILL***********************/
	 void viewbill(void)
	{
	       textcolor(YELLOW);
	textbackground(MAGENTA);
	     clrscr();
	    for(i=0;i<again;i++){
	    if(strcmp(c[i].name,dish)==0)
	    {
	      total=total-(c[i].quantity*c[i].price);
	       c[i].quantity=0;
	       c[i].price=0;
	       strcpy(c[i].name,0);
	     }
	      }
	      wait();
	      clrscr();
		textcolor(YELLOW);
	textbackground(MAGENTA);

	printf("\n\t\t***FINAL BILL GENERATED***\n\n");
	printf("QUANTITY\t\tDISH\t\tPRICE\n\n");

	total=0;
	float discount;
	   for(i=0;i<again;i++)
	   {
	if (c[i].price!=0){	printf("%d\t\t%s\t\tRS %d\n",c[i].quantity,c[i].name,c[i].price*c[i].quantity); total=total+(c[i].quantity*c[i].price);}

	}
	if ( cust[1].visit>3 ) {printf("\n\t\tBINGO!! YOU HAVE BEEN AWARDED A 10% DISCOUNT!!"); discount = 0.1 * total; total=total- discount;}


	printf("\n\n\t\t\tTOTAL = RS %d",total);
	printf("\n\t\tYour food will be prepared in 20 minutes.");
	timeNdate();

	getch(); }


     /********************************GIVEFEED********************/

	void givefeed(void)
	{

	 textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
	printf("***GIVE US YOUR FEEDBACK***\n");
	gets(feed);
	ff=fopen("feed.dat","ab+");
	fwrite(&feed,sizeof(feed),1,ff);
	fclose(ff);
	getch();
	thanks();
		    }
	/***************CALL1*************/
	void call1(void)
	{  clrscr();
     textcolor(YELLOW);
	textbackground(MAGENTA);

	gotoxy(30,4);
    printf("1.VIEW FEEDBACKS");
    gotoxy(30,8);
    printf("2.PREVIOUS LIST OF ORDERS");
    gotoxy(30,12);
    printf("3.VIEW GRAPH");
    gotoxy(30,16);
    printf("4.VIEW CUSTOMERS RECORD");
    gotoxy(30,20);
    printf("5.TO GO BACK");
    
    choose1=getche();
    switch(choose1){
    case'1':
     feedback();
     call1();
     break;

    case'2':
    list();
    call1();
    break;

    case'3':
    viewgraph();
    call1();
    break;
    
    case'4':
    show_customer_record();
    call1();
    break;


	case'5':
    pass();

    default:
    call1();}

    getch();
     }


     /***************************CALL2*************************/

    void call2(void)

   {
       while(1)
       {
	textcolor(YELLOW);
	textbackground(MAGENTA);

	 clrscr();
	 gotoxy(20,2);
	 printf("PLEASE FOLLOW THE STEPS IN SEQUENCE");
     gotoxy(30,4);
    printf("1.GIVE ORDER");
    gotoxy(30,6);
    printf("2.REVIEW ORDER");
    gotoxy(30,8);
    printf("3.VIEW BILL");
    gotoxy(30,10);
    printf("4.GIVE US FEEDBACK");
    gotoxy(30,12);
    printf("5.TO GO BACK");
    fflush(stdin);
    choose2=getch();
    if (choose2=='1')
	{
	    while(another=='y'||another=='Y'){
      order ();
      clrscr();
      printf("\n\n\n\n\n\n\n\n\tDo You Want To Add More In Your Order?\n");
      printf("\tEnter y for YES and n for NO !	");
      another=getch();}
    }


  else if (choose2=='2')
  {revieworder();}
  else if (choose2=='3')
   {viewbill() ;}
  else if (choose2=='4')
   {givefeed();}
  else if (choose2=='5')
  {home();}
 else
 { call2();
 }
       }


       }




/*_________________________________STARTER________________________________*/
   void starter (void)
   {
    textcolor(YELLOW);
	textbackground(MAGENTA);

   clrscr();
     gotoxy(30,2);
     printf("             STARTER             ");
     gotoxy(30,6);
     printf("1.CAESAR SALAD		RS 850");
     gotoxy(30,8);
     printf("2.GARLIC BREAD		RS 700");
     gotoxy(30,10);
     printf("3.CHICKEN STRIPS           RS 650");
     gotoxy(30,12);
     printf("4.FRIES                    RS 400");
     fflush(stdin);
     select1=getch();
     system("cls");
     if (select1=='1')
     {

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
     strcpy(c[again].name,"CAESER SALAD");
       c[again].price=850;
	strcpy(m.name,"CAESER SALAD");
	 m.price=850;}
     else if (select1=='2')
     {

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
     strcpy(c[again].name,"GARLIC BREAD");
       c[again].price=700;
	 strcpy(m.name,"GARLIC BREAD");
	  m.price=700;}
     else if (select1=='3')
     {

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
     strcpy(c[again].name,"CHICKEN STRIPS");
     c[again].price=650;
     strcpy(m.name,"CHICKEN STRIPS");
      m.price=650;}
     else if (select1=='4')
     {

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
     strcpy(c[again].name,"FRIES");
      c[again].price=400;
	strcpy(m.name,"FRIES");
	m.price=400;}

	else
      {
	 starter();
	  }


       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
	gotoxy(30,14);
      printf("Enter Quantity:\t");
      scanf("%d",&c[again].quantity);
      m.quantity=c[again].quantity;
      total=total+(c[again].quantity*c[again].price);
      fm=fopen("myfile.dat","ab+");
      fseek(fm,SEEK_SET,SEEK_END);
      fwrite(&m,sizeof(m),1,fm);
      fclose(fm);
      again++;

	   }

	   /*_________________________________MAINCOURSE________________________________*/

      void maincourse(void)
      { clrscr();
       textcolor(YELLOW);
	textbackground(MAGENTA);

     gotoxy(30,2);
     printf("               MAINCOURSE          ");
     gotoxy(30,6);
     printf("1.MORROCON CHICKEN           RS 850");
     gotoxy(30,8);
     printf("2.ALFREDO PASTA              RS 700");
     gotoxy(30,10);
     printf("3.FISH N CHIPS               RS 650");
     gotoxy(30,12);
     printf("4.GRILLED SANDWICH           RS 800");
     fflush(stdin);
     select2=getch();

     system("cls");
     if (select2=='1')
     {

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
     strcpy(c[again].name,"MORROCON CHICKEN");
     c[again].price=850;
     strcpy(m.name,"MORROCON CHICKEN");
     m.price=850;}
     else if (select2=='2')
     {

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
     strcpy(c[again].name,"ALFREDO PASTA");
     c[again].price=700;
     strcpy(m.name,"ALFREDO PASTA");
     m.price=700;}
     else if (select2=='3')
     {

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
     strcpy(c[again].name,"FISH N CHIPS");
     c[again].price=650;
     strcpy(m.name,"FISH N CHIPS");
     m.price=650;}
     else if (select2=='4')
     {

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
     strcpy(c[again].name,"GRILLED SANDWICH");
     c[again].price=800;
     strcpy(m.name,"GRILLED SANDWICH");
     m.price=800;}

	     else
     {
     maincourse();
	 }


       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
     gotoxy(30,14);
      printf("Enter Quantity:\t");
      scanf("%d",&c[again].quantity);
      m.quantity=c[again].quantity;
      total=total+(c[again].quantity*c[again].price);
      fm=fopen("myfile.dat","ab+");
      fseek(fm,SEEK_SET,SEEK_END);
      fwrite(&m,sizeof(m),1,fm);
      fclose(fm);
      again++;


      }

      /*_____________________________________BEVERGES__________________________________________*/

      void beverages(void)
	 { clrscr();
	  textcolor(YELLOW);
	textbackground(MAGENTA);

	 gotoxy(30,2);
	 printf("          BEVERAGES          ");
     gotoxy(30,6);
     printf("1.CAPPUCHINO		RS 300");
     gotoxy(30,8);
     printf("2.ESPRESSO                 RS 350");
     gotoxy(30,10);
     printf("3.HOT CHOCOLATE            RS 280");
     gotoxy(30,12);
     printf("4.PINA COLADA              RS 350");
     fflush(stdin);
     select3=getch();
     system("cls");
     if (select3=='1')
     {

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
     strcpy(c[again].name,"CAPPUCHINO");
     c[again].price=300;
     strcpy(m.name,"CAPPUCHINO");
     m.price=300;}
     else if (select3=='2')
     {

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
     strcpy(c[again].name,"ESPRESSO");
     c[again].price=350;
     strcpy(m.name,"ESPRESSO");
     m.price=350;}
     else if (select3=='3')
     {

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
     strcpy(c[again].name,"HOT CHOCOLATE");
     c[again].price=280;
     strcpy(m.name,"HOT CHOCOLATE");
     m.price=280;}
     else if (select3=='4')
     {

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
     strcpy(c[again].name,"PINA COLADA");
     c[again].price=350;
     strcpy(m.name,"PINA COLADA");
     m.price=350;}


	else
	{
		beverages();
	}


       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
     gotoxy(30,14);
      printf("Enter Quantity:\t");
      scanf("%d",&c[again].quantity);
      m.quantity=c[again].quantity;
      total=total+(c[again].quantity*c[again].price);
      fm=fopen("myfile.dat","ab+");
      fseek(fm,SEEK_SET,SEEK_END);
      fwrite(&m,sizeof(m),1,fm);
      fclose(fm);
      again++;


      }


      /*______________________DESSERT_________________________________*/

     void deserts (void)
   { clrscr();
    textcolor(YELLOW);
	textbackground(MAGENTA);

     gotoxy(30,2);
     printf("                  DESSERT             ");
     gotoxy(30,6);
     printf("1.RED VELVET CAKE 		     RS 380");
     gotoxy(30,8);
     printf("2.LAVA CAKE 		     RS 500");
     gotoxy(30,10);
     printf("3.HOT FUDGE BROEWNIE            RS 450");
     gotoxy(30,12);
     printf("4.NEWYORK CHEESE CAKE           RS 400");
     fflush(stdin);
     select4=getch();

     system("cls");
     if (select4=='1')
     {

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
     strcpy(c[again].name,"RED VELVET CAKE");
     c[again].price=380;
     strcpy(m.name,"RED VELVET CAKE");
     m.price=380;}
     else if (select4=='2')
     {

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
     strcpy(c[again].name,"LAVA CAKE");
     c[again].price=500;
     strcpy(m.name,"LAVA CAKE");
     m.price=500;}
     else if (select4=='3')
     {

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
     strcpy(c[again].name,"HOT FUDGE BROWNIE");
     c[again].price=450;
     strcpy(m.name,"HOT FUDGE BROWNIE");
     m.price=450;}
     else if (select4=='4')
     {

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
     strcpy(c[again].name,"NEWYORK CHEESE CAKE");
     c[again].price=400;
     strcpy(m.name,"NEWYORK CHEESE CAKE");
     m.price=400;}



	else
	{
		deserts();
	}
       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
     gotoxy(30,14);
      printf("Enter Quantity:\t");
      scanf("%d",&c[again].quantity);
      m.quantity=c[again].quantity;
      total=total+(c[again].quantity*c[again].price);
      fm=fopen("myfile.dat","ab+");
      fseek(fm,SEEK_SET,SEEK_END);
      fwrite(&m,sizeof(m),1,fm);
      fclose(fm);
      again++;



      }
       /****************************VIEWGRAPH***********************/
      void viewgraph(void)
      {
	clrscr();


	fn=fopen("new.dat","rb+");
	clrscr();
	while(fread(&m,sizeof(m),1,fn)==1)
	 { if(strcmp(m.name,"CAESER SALAD")==0)
	 { cs=cs+m.quantity ;
	      }
	   else if(strcmp(m.name,"GARLIC BREAD")==0)
	  {gb=gb+m.quantity;
	    }
	  else if(strcmp(m.name,"CHICKEN STRIPS")==0)
	  {chs=chs+m.quantity ;
	   }
	  else if(strcmp(m.name,"FRIES")==0)
	  {fr=fr+m.quantity;
	    }
	  else if(strcmp(m.name,"MORROCON CHICKEN")==0)
	  {mc=mc+m.quantity ;
	   }
	     else if(strcmp(m.name,"ALFREDO PASTA")==0)
	  {ap=ap+m.quantity;
	    }
	  else if(strcmp(m.name,"FISH N CHIPS")==0)
	  {fc=fc+m.quantity ;
	   }
	  else if(strcmp(m.name,"GRILLED SANDWICH")==0)
	  {gs=gs+m.quantity;
	    }
	  else if(strcmp(m.name,"CAPPUCHINO")==0)
	  {cp=cp+m.quantity ;
	   }
	  else if(strcmp(m.name,"ESPRESSO")==0)
	  {es=es+m.quantity ;
	   }
	  else if(strcmp(m.name,"HOT CHOCOLATE")==0)
	  {hc=hc+m.quantity;
	    }
	  else if(strcmp(m.name,"PINA COLADA")==0)
	  {fco=fco+m.quantity ;
	   }
	  else if(strcmp(m.name,"RED VELVET CAKE")==0)
	  {rv=rv+m.quantity;
	    }
	  else if(strcmp(m.name,"LAVA CAKE")==0)
	  {lc=lc+m.quantity ;
	   }
	  else if(strcmp(m.name,"HOT FUDGE BROWNIE")==0)
	  {hf=hf+m.quantity;
	    }
	  else if(strcmp(m.name,"NEWYORK CHEESE CAKE")==0)
	  {cc=cc+m.quantity ;	  }
	       }

   graph(cs,gb,chs,fr,mc,ap,fc,gs,cp,es,hc,fco,rv,lc,hf,cc);
   getch();
   fclose(fn);
   getch();

	  }
/*******************************GRAPH***************************/

void graph (int a,int b, int c,int d , int e, int f,int g ,int h, int i,int j , int k ,int l,int m2,int n, int o, int  p)
{
   int gm;
	int gd=DETECT;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 cleardevice();

   char a1[5],b1[5],c1[5],d1[5],e1[5],f1[5],g1[5],h1[5],i1[5],j1[5],k1[5],l1[5],m1[5],n1[5],o1[5],p1[5];
   float m[16];
   float sum=a+b+c+d+e+f+g+h+i+j+k+l+m2+n+o+p;
   m[0]=(a/sum)*360;

   m[1]=(b/sum)*360;

   m[2]=(c/sum)*360;

   m[3]=(d/sum)*360;

   m[4]=(e/sum)*360;

   m[5]=(f/sum)*360;

   m[6]=(g/sum)*360;

   m[7]=(h/sum)*360;

   m[8]=(i/sum)*360;

   m[9]=(j/sum)*360;

   m[10]=(k/sum)*360;

   m[11]=(l/sum)*360;

   m[12]=(m2/sum)*360;

   m[13]=(n/sum)*360;

   m[14]=(o/sum)*360;

   m[15]=(p/sum)*360;

   sprintf(a1,"%d",a);

   sprintf(b1,"%d",b);

   sprintf(c1,"%d",c);

   sprintf(d1,"%d",d);

   sprintf(e1,"%d",e);

   sprintf(f1,"%d",f);

   sprintf(g1,"%d",g);

   sprintf(h1,"%d",h);

   sprintf(i1,"%d",i);

   sprintf(j1,"%d",j);

   sprintf(k1,"%d",k);

   sprintf(l1,"%d",l);

   sprintf(m1,"%d",m2);

   sprintf(n1,"%d",n);

   sprintf(o1,"%d",o);

   sprintf(p1,"%d",p);



settextstyle(BOLD_FONT,HORIZ_DIR,2);
   outtextxy(305,30,"PIE CHART"); outtextxy(306,30,"PIE CHART");
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
   setcolor(15);

outtextxy(12,10,"CEASER SALAD");
outtextxy(600,10,a1);
setfillstyle(CLOSE_DOT_FILL,WHITE);
bar(0,15,10,30);


outtextxy(12,30,"GARLIC BREAD");
outtextxy(600,30,b1);
setfillstyle(XHATCH_FILL,GREEN);
bar(0,35,10,50);


outtextxy(12,50,"CHICKEN STRIPS");
outtextxy(600,50,c1);
setfillstyle(LINE_FILL,LIGHTRED);
bar(0,55,10,70);


outtextxy(12,70,"FRIES");
outtextxy(600,70,d1);
setfillstyle(CLOSE_DOT_FILL,BLUE);
bar(0,75,10,90);


outtextxy(12,90,"MORROCON CHICKEN");
outtextxy(600,90,e1);
setfillstyle(XHATCH_FILL,CYAN);
bar(0,95,10,110);


outtextxy(12,110,"ALFREDO PASTA");
outtextxy(600,110,f1);
setfillstyle(LINE_FILL,RED);
bar(0,115,10,130);


outtextxy(12,130,"FISH N CHIPS");
outtextxy(600,130,g1);
setfillstyle(CLOSE_DOT_FILL,MAGENTA);
bar(0,135,10,150);


outtextxy(12,150,"GRILLED SANDWICH");
outtextxy(600,150,h1);
setfillstyle(XHATCH_FILL,BROWN);
bar(0,155,10,170);


outtextxy(12,170,"CAPPUCHINO");
outtextxy(600,170,i1);
setfillstyle(LINE_FILL,LIGHTGRAY);
bar(0,175,10,190);


outtextxy(12,190,"ESPRESSO");
outtextxy(600,190,j1);
setfillstyle(LINE_FILL,DARKGRAY);
bar(0,195,10,210);


outtextxy(12,210,"HOT CHOCOLATE");
outtextxy(600,210,k1);
setfillstyle(CLOSE_DOT_FILL,LIGHTBLUE);
bar(0,215,10,230);


outtextxy(12,230,"PINA COLADA");
outtextxy(600,230,l1);
setfillstyle(XHATCH_FILL,LIGHTGREEN);
bar(0,235,10,250);


outtextxy(12,250,"RED VELVET CAKE");
outtextxy(600,250,m1);
setfillstyle(LINE_FILL,LIGHTMAGENTA);
bar(0,255,10,270);


outtextxy(12,270,"LAVA CAKE");
outtextxy(600,270,n1);
setfillstyle(LINE_FILL,YELLOW);
bar(0,275,10,290);


outtextxy(12,290,"HOT FUDGE BROWNIE");
outtextxy(600,290,o1);
setfillstyle(HATCH_FILL,CYAN);
bar(0,295,10,310);


outtextxy(12,310,"NEWYORK CHEESE CAKE");
outtextxy(600,310,p1);
setfillstyle(WIDE_DOT_FILL,BLUE);
bar(0,315,10,330);

   int midx = (getmaxx()/2)+100;
   int midy = getmaxy()/2;
   setcolor(WHITE);

   setfillstyle(CLOSE_DOT_FILL,WHITE);
   pieslice(midx, midy, 0, m[0], 150);


   setfillstyle(XHATCH_FILL,GREEN);
   pieslice(midx, midy, m[0], m[0]+m[1], 150);

   setfillstyle(LINE_FILL,LIGHTRED);
   pieslice(midx, midy, m[0]+m[1] , m[0]+m[1]+m[2] , 150);


   setfillstyle(CLOSE_DOT_FILL,BLUE);
   pieslice(midx, midy, m[0]+m[1]+m[2], m[0]+m[1]+m[2]+m[3], 150);


   setfillstyle(XHATCH_FILL,CYAN);
   pieslice(midx, midy, m[0]+m[1]+m[2]+m[3], m[0]+m[1]+m[2]+m[3]+m[4], 150);

   setfillstyle(LINE_FILL,RED);
   pieslice(midx, midy, m[0]+m[1]+m[2]+m[3]+m[4] , m[0]+m[1]+m[2]+m[3]+m[4]+m[5] , 150);


   setfillstyle(CLOSE_DOT_FILL,MAGENTA);
   pieslice(midx, midy, m[0]+m[1]+m[2]+m[3]+m[4]+m[5], m[0]+m[1]+m[2]+m[3]+m[4]+m[5]+m[6], 150);


   setfillstyle(XHATCH_FILL,BROWN);
   pieslice(midx, midy, m[0]+m[1]+m[2]+m[3]+m[4]+m[5]+m[6], m[0]+m[1]+m[2]+m[3]+m[4]+m[5]+m[6]+m[7], 150);


   setfillstyle(LINE_FILL,LIGHTGRAY);
   pieslice(midx, midy, m[0]+m[1]+m[2]+m[3]+m[4]+m[5]+m[6]+m[7], m[0]+m[1]+m[2]+m[3]+m[4]+m[5]+m[6]+m[7]+m[8], 150);


   setfillstyle(LINE_FILL,DARKGRAY);
   pieslice(midx, midy, m[0]+m[1]+m[2]+m[3]+m[4]+m[5]+m[6]+m[7]+m[8], m[0]+m[1]+m[2]+m[3]+m[4]+m[5]+m[6]+m[7]+m[8]+m[9], 150);

   setfillstyle(CLOSE_DOT_FILL,LIGHTBLUE);
   pieslice(midx, midy, m[0]+m[1]+m[2]+m[3]+m[4]+m[5]+m[6]+m[7]+m[8]+m[9] , m[0]+m[1]+m[2]+m[3]+m[4]+m[5]+m[6]+m[7]+m[8]+m[9]+m[10] , 150);

setfillstyle(XHATCH_FILL,LIGHTGREEN);
   pieslice(midx, midy, m[0]+m[1]+m[2]+m[3]+m[4]+m[5]+m[6]+m[7]+m[8]+m[9]+m[10] , m[0]+m[1]+m[2]+m[3]+m[4]+m[5]+m[6]+m[7]+m[8]+m[9]+m[10]+m[11] , 150);


   setfillstyle(LINE_FILL,LIGHTMAGENTA);
   pieslice(midx, midy,m[0]+m[1]+m[2]+m[3]+m[4]+m[5]+m[6]+m[7]+m[8]+m[9]+m[10]+m[11] , m[0]+m[1]+m[2]+m[3]+m[4]+m[5]+m[6]+m[7]+m[8]+m[9]+m[10]+m[11]+m[12], 150);


   setfillstyle(LINE_FILL,YELLOW);
   pieslice(midx, midy, m[0]+m[1]+m[2]+m[3]+m[4]+m[5]+m[6]+m[7]+m[8]+m[9]+m[10]+m[11]+m[12], m[0]+m[1]+m[2]+m[3]+m[4]+m[5]+m[6]+m[7]+m[8]+m[9]+m[10]+m[11]+m[12]+m[13], 150);

   setfillstyle(HATCH_FILL,CYAN);
   pieslice(midx, midy,  m[0]+m[1]+m[2]+m[3]+m[4]+m[5]+m[6]+m[7]+m[8]+m[9]+m[10]+m[11]+m[12]+m[13] , m[0]+m[1]+m[2]+m[3]+m[4]+m[5]+m[6]+m[7]+m[8]+m[9]+m[10]+m[11]+m[12]+m[13]+m[14] , 150);

   setfillstyle(WIDE_DOT_FILL,BLUE);
   pieslice(midx, midy,  m[0]+m[1]+m[2]+m[3]+m[4]+m[5]+m[6]+m[7]+m[8]+m[9]+m[10]+m[11]+m[12]+m[13]+m[14] ,  m[0]+m[1]+m[2]+m[3]+m[4]+m[5]+m[6]+m[7]+m[8]+m[9]+m[10]+m[11]+m[12]+m[13]+m[14]+m[15] , 150);

   getch();

  closegraph();
 }
	    /***************************PASS*****************/
	   void pass(void)
	   {

       textcolor(YELLOW);
	textbackground(MAGENTA);
	    FILE *fa;
	     char array[9];
	     char a[9],c,j=0;
	     clrscr();
	     gotoxy(30,6);
	     printf("SELECT ANY..");
	     gotoxy(30,10);
	     printf("1.LOG IN");
	     gotoxy(30,12);
	     printf("2.CHANGE PASSWORD");
	     gotoxy(30,14);
	     printf("3.EXIT");
	     fflush(stdin);
	     c=getch();
	     switch(c)
	     { case'1':

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
	       gotoxy(30,12);
	       printf("Enter Password : ");
	       while(j!=13)
	       {
		j=getch();
		if(j!=13)
		{
			printf("*");
			a[i]=j;
			i++;
			   }
		   }
		   a[i]='\0';
	       fa=fopen("pass.dat","rb+");
	       fread(array,sizeof(array),1,fa);
	       if(strcmp(array,a)==0)
	      {

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
		gotoxy(30,2);
		printf("*WELCOME SIR*");
		clrscr();
		call1(); }
		else
	       {

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
		gotoxy(30,14);
		printf("INCORRECT PASSWORD !!!"); }
		break;

		case'2':

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
	      gotoxy(30,12);
		printf("Enter Previous Password:\t");
		gets(a);
		fa=fopen("pass.dat","rb+");
		fread(array,sizeof(array),1,fa);
		if(strcmp(a,array)==0)
		{

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
		fclose(fa);
		  clrscr();
		  fa=fopen("pass.dat","wb+");
		  gotoxy(30,14);
		  printf("Enter The New Password");
		  gets(array);
		  fwrite(array,sizeof(array),1,fa);
		  fclose(fa);
		  clrscr();
		  gotoxy(30,4);
		  printf("Password Updated Successfully!");
		  getch();
		  clrscr();
		  call1();   }
		  else

		{

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
		 gotoxy(30,18);
		 printf("INCORRECT PASSWORD!!!");
		  getch();}
		  break;

		case'3':
			home();
			break;
			default:
				pass();
	     }
	     }
       /********************HOME*************************/
    void home(void)
	 {
	while(1)
	{

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
	timeNdate();
	gotoxy(30,3);
	printf("SELECT ANY...");
      gotoxy(30,6);
  printf("1.MANAGER");
  gotoxy(30,8);
  printf("2.CUSTOMER");
  gotoxy(30,10);
  printf("3.EXIT");
  choose=getch();
   switch(choose)  {
   case'1':
       textcolor(YELLOW);
	textbackground(MAGENTA);
	pass();


    break;
    case '2':
    
       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
	cutomer();
	call2();
    break;

    case'3':
    exit(0);

    default:
    home();


    }
     getch();            }
}

  /****************************REVIEWORDER************************/
    void revieworder(void)
     {

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();

	printf("You've Ordered The Following Items\n\n");
	printf("QUANTITY\tDISH\tPRICE\n");
	fm=fopen("myfile.dat","rb+");
	while(fread(&m,sizeof(m),1,fm)==1){
	printf("%d\t%s\t\tRS %d\n", m.quantity,m.name,m.price*m.quantity); }
	fclose(fm);
	getch();
	gotoxy(15,14);
	printf("Is This Order Confirmed? Press y for YES and n for NO...");
	if(getch()=='y'||getch()=='Y')
      {

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
      gotoxy(30,16);
	printf("Your Order Is Being Processed...");
	getch();
		fm=fopen("myfile.dat","rb+");
	while(fread(&m,sizeof(m),1,fm)==1){
	 fn=fopen("new.dat","ab+");
	 fwrite(&m,sizeof(m),1,fn);
	 fclose(fn);    }
	 fclose(fm);
	 remove("myfile.dat");
	 rename("myfile.dat","temp.dat");

	 }

	else
	{

       textcolor(YELLOW);
	textbackground(MAGENTA);
	 gotoxy(25,16);
	  printf("Do You Want To Add OR Delete Something?");
	  gotoxy(35,18);
	  printf("\n\t\tPress 1 For Add And 2 For Delete...");
	  ehh=getch();
	  switch(ehh)
	  { case'1':

       textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
	   order();
	     gotoxy(30,x);
	     printf("\nQUANTITY\t\tDISH\t\tPRICE\n");
	    for(i=0;i<again;i++)
	   {
	if(c[i].name!=0 && c[i].quantity!=0 && c[i].price!=0){
	printf("\t%d\t",c[i].quantity);
	printf("\t%s\t\t",c[i].name);
	printf("RS %d\n",c[i].price*c[i].quantity);
	x=x+2;}
	    }
		fm=fopen("myfile.dat","rb+");
	while(fread(&m,sizeof(m),1,fm)==1){
	 fn=fopen("new.dat","ab+");
	 fwrite(&m,sizeof(m),1,fn);
	 fclose(fn);    }
	 fclose(fm);
	 remove("myfile.dat");
	 rename("myfile.dat","temp.dat");


	   break;
	   case '2':

       textcolor(YELLOW);
	textbackground(MAGENTA);
	   gotoxy(25,20);
	   printf("\n\tEnter The Dish Name In Upper Case:\t");
	   gets(dish);
	   for(i=0;i<again;i++)
	   { if(strcmp(c[i].name,dish)==0)         {
	       c[i].quantity=0;
	       c[i].price=0;
	     strcpy(c[i].name,'\0');

	     }     }
	     clrscr();

	      printf("QUANTITY\tDISH\tPRICE\n");
		fm=fopen("myfile.dat","rb+");
	while(fread(&m,sizeof(m),1,fm)==1)
	{if (strcmp(m.name,dish)!=0) {
	
	 printf("%d\t%s\tRS %d\n",m.quantity,m.name,m.price*m.quantity);
	 fn=fopen("new.dat","ab+");
	 fwrite(&m,sizeof(m),1,fn);
	 fclose(fn);
	 }                            }
	 fclose(fm);     
	 default:
		gotoxy(2,20);

	 printf("\n\nWrong Entry..Now your is being proceed");    }
	 getch();
	 remove("myfile.dat");
	 rename("myfile.dat","temp.dat");
 }
      }
     /***********************timeNdate*******************************/
	  void timeNdate(void)
  {
	char dateStr [9];
   char timeStr [9];
   _strdate( dateStr );
   gotoxy(63,2);
   printf( "Date ::: %s \n", dateStr);
   _strtime( timeStr );
   gotoxy(63,3);
   printf( "Time ::: %s \n", timeStr);

  }
  /**********************************WAIT************************/
  void wait(void)
{
 int x,y,i;
 int g=DETECT, d;
 initgraph(&g, &d,"C:\\TURBOC3\\BGI");
 cleardevice();
 x=getmaxx()/2;
 y=getmaxy()/2;
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
 setbkcolor(rand());
 setcolor(4);
 int c=150;
for(int e=0;e<6;e++)
 {
  for(int i=50;i<100;i++)
  {
    setcolor(3);
    settextstyle(SMALL_FONT, HORIZ_DIR, 10);
    outtextxy(x,y,"Loading...");
    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
    outtextxy(x+5,y+5,"Please Wait... ");
    circle(x,y,i);
    circle(x,y,c);
    c--;
    delay(10);
    cleardevice();
  }
  }
  setcolor(6);
  settextstyle(SMALL_FONT, HORIZ_DIR, 10);
  settextjustify(x,y);
  outtextxy(x-70,y-60,"Your");
  delay(150);
  outtextxy(x-70,y-20,"Bill");
  delay(150);
  outtextxy(x-10,y-20,"	  Has Been");
  delay(150);
  outtextxy(x-70,y+15,"Generated...");
  delay(150);
  outtextxy(x-70,y+45,"Press Any Key To");
  delay(150);
  outtextxy(x-70,y+85,"Continue...");
  getch();
 closegraph();

 }

 /**********************************WELCOME*************************/
 void welcome(void)
 {

  int gd=DETECT,gm,i,j;
    int x,y,button;
  int v=12,f=0;
  initgraph(&gd,&gm,"C:\\turboc3\\BGI");
  setbkcolor(YELLOW);
  setfillstyle(LTBKSLASH_FILL,RED);
  for(i=1;i<=500;i++)
  {
	bar(1,1,20,i);
	delay(5);
	}
	for(i=1;i<=700;i++)
	{
	bar(1,1,i,20);
	delay(5);
	}
	for(i=1;i<=500;i++)
	{
	bar(620,1,700,i);
	delay(5);
	}
	for(i=900;i>=1;i--)
	{
	bar(900,900,i,460);
	delay(5);
	}
   setcolor(RED);

 line(0,30,30,0);
  line(2,32,32,2);
  line(639,30,609,0);
  line(637,32,607,2);
  line(0,449,30,479);
  line(2,447,32,477);
  line(639,449,609,479);
  line(637,447,607,477);


 settextstyle(8,0,6);
  outtextxy(170,100,"WELCOME TO");
  settextstyle(8,0,7);
  outtextxy(100,200,"NOSH PALACE");
  setcolor(GREEN);
  rectangle(275,320,385,425);
  rectangle(274,319,384,424);
  setcolor(RED);
    for(i=280;i<=295;i++)
    {
    delay(20);
   line(280,400,i,400);
    }
   for(i=400;i>=350;i--)
   {
   delay(20);
   line(295,400,295,i);
   }
   for(i=295,j=350;i<=340,j<=400;i++,j++)
   {
   delay(20);
   line(295,350,i,j);
   }
   for(i=350;i<=400;i++)
   {
   delay(20);
   line(340,350,340,i);
   }
   for(i=340;i<=380;i++)
   {
   delay(20);
   line(340,350,i,350);
   }
   for(i=350;i<=375;i++)
   {
   delay(20);
   line(380,350,380,i);
   }

   for(i=380;i>=340;i--)
   {
   delay(20);
   line(380,375,i,375);
   }
 getch();
   closegraph();
   /******************************2ndPage******************/
  initgraph(&gd,&gm,"c:\\turboc3\\bgi");

setbkcolor(YELLOW);
delay(90);
setfillstyle(SOLID_FILL,RED);
bar(65,20,80,330);
delay(90);
setfillstyle(SOLID_FILL,RED);
bar(65,20,180,330);
delay(90);
setfillstyle(SOLID_FILL,RED);
bar(65,20,280,330);
delay(90);
setfillstyle(SOLID_FILL,RED);
bar(65,20,580,330);

     do
{


delay(100);
setfillstyle(SOLID_FILL,GREEN);
bar(65,420,580,330);
delay(35);

	setfillstyle(LTBKSLASH_FILL,RED);
	bar(1,1,20,500);
	bar(1,1,700,20);
	bar(620,620,700,1);
	bar(900,900,1,460);


moveto(65,335);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
setcolor(WHITE);
delay(90);
outtext("PL PROJECT 2017");


f++;

settextstyle(7,HORIZ_DIR,3);
setcolor(WHITE);
moveto(90,120);
outtext("SOFTWARE DEVELOPLED BY:");
moveto(90,140);
outtext("KIRAN NAZ             	FESE-012");
moveto(90,160);
outtext("KHADIJA HUSSAIN   	  FESE-030");
moveto(90,180);
outtext("AYESHA NADEEM       FESE-036");
f++;

}

while(f!=v);
moveto(430,430);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
setcolor(BLUE);
delay(90);
outtext("PLEASE WAIT...");

delay(90);
setfillstyle(SOLID_FILL,RED);
bar(55,430,65,430);
delay(1770);
setfillstyle(SOLID_FILL,RED);
bar(55,430,165,430);
delay(600);
setfillstyle(SOLID_FILL,RED);
bar(55,430,265,430);
delay(690);
setfillstyle(SOLID_FILL,RED);
bar(55,430,300,430);
delay(500);
setfillstyle(SOLID_FILL,RED);
bar(55,430,400,430);
delay(500);
setfillstyle(SOLID_FILL,RED);
bar(55,430,500,430);
delay(500);
setfillstyle(SOLID_FILL,RED);
bar(55,430,570,430);
delay(500);
setfillstyle(SOLID_FILL,RED);
bar(55,430,590,430);
moveto(430,430);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
setcolor(WHITE);
delay(10);
outtext("PLEASE WAIT...");


moveto(430,430);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
setcolor(BLUE);
delay(10);
outtext("Press Any Key..");
getch();
  closegraph();
    }
  void thanks(void)
  {
	int gd=DETECT,gm;
   initgraph(&gd,&gm,"C:\\turboc3\\BGI");
  setcolor(YELLOW);
  setbkcolor(BLACK);
	setfillstyle(LTBKSLASH_FILL,RED);
	  for(i=1;i<=500;i++)
	  {
	bar(1,1,20,i);
	delay(5);
	}
	for(i=1;i<=700;i++)
	{
	bar(1,1,i,20);
	delay(5);
	}
	for(i=1;i<=620;i++)
	{
	bar(620,i,700,i);
	delay(5);
	}
	for(i=900;i>=1;i--)
	{
	bar(900,900,i,460);
	delay(5);
	}
  setcolor(RED);
  settextstyle(1,0,4);
  outtextxy(170,150,"Thank You For Coming");
   delay(30);
  settextstyle(1,0,4);
  outtextxy(150,250,"Please Visit Us Next Time");
   setcolor(YELLOW);
   circle(320,345,25);
   setfillstyle(SOLID_FILL,YELLOW);
   floodfill(300,350,YELLOW);

   setcolor(BLACK);
   setfillstyle(SOLID_FILL,BLACK);
  fillellipse(310,345,2,6);
   fillellipse(330,345,2,6);

   ellipse(320,350,205,350,20,10);
   ellipse(320,350,205,350,20,11);
   ellipse(320,350,205,350,20,12);

   getch();
   closegraph();
  }





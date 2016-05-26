#include <iostream>// library that contains basic input/output functions
#include <fstream>// library that contains file input/output functions
#include <string>

const int size = 50;

 int i = 3;

 class books
 {

  private:

   char *author; //name of author of book
   char *title; //name of title of book
   char *publisher; //publisher name of book
   float *price; //price of each copy
   int *stock; //represents number of copies of each book

  public:

   static int c1;
   static int c2;

   books()

                        {

    author=new char[1];
    title=new char[1];
    publisher=new char[1];
    price=new float(0);
    stock=new int(0);

   }

   books(char *str1,char *str2,char *str3,float cost,int st)

   {

    author=new char[strlen(str1)+1],strcpy(author,str1);
    title=new char[strlen(str2)+1],strcpy(title,str2);
    publisher=new char[strlen(str3)+1],strcpy(publisher,str3);
    price=new float(cost);
    stock=new int(st);

   }

   int search(char *ptr1,char *ptr2)

   {

    if((strcmpi(author,ptr1)==0)&&(strcmpi(title,ptr2)==0))

    {

     return 1;

    }

    else

    {

     return 0;

    }

   }

   void details()

   {

    cout<<"\n\n\tTitle of Book = \t"<

   }

   void request(int n)

   {

    char k;
    if(*stock>=n)

    {

     cout<<"\nTotal cost of books="<
     cout<<"\nDo you want to buy(y/n)?";
     cin>>k;
     if(k=='Y'|| k=='y')

     {

      cout<<"\n\nQuery processed !! Collect Money";
      c1++; //keep the track of successful transaction
      *stock=*stock-n;
      cout<<"\n\n FINAL STOCK AVAILABLE IS :- \t"<<*stock<

     }

     else if(k=='N' || k=='n')

     {

      cout<<"\n YOU OPT 4 NOT PURCHASING ANY BOOK ..... !!!!!!!!!!! \n";
      c2++;

     }

     else

     {

      cout<<"\n PLEASE ENTER A CORRECT KEY .... !!!!!! \n";

     }

    }

    else if(n>*stock)

    {

     cout<<"\nRequired copies not in stock";
     c2++; //keep the track of unsuccessful transaction

    }

    else if(n==0)

    {

     cout<<"\nYOU DIDN'T PURCHASE ANY BOOK ....!!!!\n";
     c2++;

    }
   }

   float modifyprice(char *ptr1,char *ptr2,float cost)

   {

    if((strcmp(title,ptr1)==0)&&(strcmp(author,ptr2)==0))

    {

     priceupdate(cost);
     return 1;

    }

    else

     return 0;

   }

  private:

   void priceupdate(float cost)

   {

    *price=cost;
    cout<<"\nsuccessfully new price updated";

   }

 };


 int books :: c1=0;

 int books :: c2=0;

 void main()

 {

  clrscr();

  books *obj[size];

  *obj[0]=books("BALA","C++","TATA",250,1000);
  *obj[1]=books("SUMITRA","CS","DHANPAT",300,1000);
  *obj[2]=books("GAMER","JAVA","KOTHARI",500,2000);
  *obj[3]=books("LAFORE","PRIME","RUPA",350,1000);

  char str1[200],str2[200],str3[200];
  int n;
  float cost;
  int st,j;

  cout<<"\n******Inventory of books******\n";

  do

  {

   cout<<"\n\tMENU\n\t1.Entry new book in the shop\n\t2.search the book in the list\n\t3.modify the price of book\n\t4.Transaction\n\t5.Exit";
   cout<<"\n\tEnter your choice:";
   switch (getche( ))

   {

    case '1':

     cout<<"\n\nEnter Author name,Title name,publisher name,cost of book,number of copies:\n";
     gets(str1);
     gets(str2);
     gets(str3);
     cin>>cost;
     cin>>st;

     obj[i++]=new books(str1,str2,str3,cost,st);

    break;


    case '2':

     cout<<"\n\n\nEnter author AND title name of the book:\n";
     gets(str1);
     gets(str2);

     for(j=0;j<=i;j++)

     if(obj[j]->search(str1, str2)==1)

     {

      obj[j]->details();

      cout<<"\nEnter the number of copies required:";
      cin>>n;

      obj[j]->request(n);
      st=st-n;

      break;

     }

     if(obj[j]->search(str1, str2)!=1)

     {

      cout<<"\n THE REQUIRED BOOK IS NOT AVAILABLE ...... \n";
      books::c2++;

     }

     break;

    break;


    case '3':

     cout<<"\nEnter the title and Author name of book:";
     gets(str1);
     gets(str2);

     cout<<"\nEnter the new cost of book:";
     cin>>n;

     for(j=0;j

     if(obj[j]->modifyprice(str1,str2,n)==1)

     break;

     if(j==i)

      cout<<"\n\tBook is not available in the stock";

    break;


    case '4':

     cout<<"\nNumber of successful transaction :\t"<
     cout<<"\nNumber of unsuccessful transaction :\t"<

    break;


    case '5':

     exit(0);


    default:

     cout<<"\nplease enter correct choice!";

   }

  }


  while(getche()!=5);

  getch();

 }


#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class admin{
public:
virtual void menu(){                                            //virtual function
   cout <<"1. Add movie "<<endl;
}

};

class customer:public admin{
   string name;
   long long number;
   char gender;
   string date;

public:
   customer()                                               //constructor
   { this->name = " ";
      this->number = 0;
      this->gender = 'z'; }
   customer(string name, long long number, char gender)                   //parametrized constructor
   { this->name = name;
      this->number = number;
      this->gender = gender; }
    
   inline void get_info(){                                                               //inline function
         cout <<"\n\t\t\t\t Enter the details:"<<endl;
         cout <<"\n\t\t\t\t Name:"<<" ";
         cin.ignore();
            getline(cin, name);
         cout <<"\n\t\t\t\t Contact number:"<<" ";
         cin >> number;
         }
   void set_name(string n)
   { this->name = n;}
   void set_date(string d){
      this-> date =d;
   }
   string get_date(){
      return date;
   }
   friend class membership;                                       //friend function used
   string getname()
   { return name;}
   
   void set_phone(long long p)
   {  number = p;}
   long long get_phone()
   {return number;}
   void set_gender(char y)
   {this->gender = y;}
   char getgender()
   {return gender;}

   void menu()                                             //function overridding
   {
      cout << "\n\t\t\t -------------------------------------------------" << endl;

      cout << "\n\t\t\t\t WELCOME TO BIG CINEMA                         " << endl;
      cout << "\n\t\t\t -------------------------------------------------" << endl;
      cout<<"\n\t\t\t\t Welcome Customer!";	
      cout << " \n\t\t\t\t 1. Book a ticket" << endl;
      cout << "\n\t\t\t\t 2. See your booking" << endl;
      cout << "\n\t\t\t\t 3. Show movie list and timings" << endl;
      cout << "\n\t\t\t\t 4. Get/renew a membership" << endl;
      cout << "\n\t\t\t\t 5. Exit" << endl;
      cout << " \n\t\t\t--------------------------------------------------" << endl;
   }
}c ;

class membership {                                               //inheritance 
    public: 
    string member;
    void benefits();
    void member1(){
     string name, check_name, date, timeprd;
    long long phone;
    char gender;
    char getmember;
     cout <<"\n\t\t\t\t Do you have a membership(Y/N)"<<endl;
     cin >> member;
     fstream record;
    if (member == "Y")
    {
        cout <<"\n\t\t\t\t To renew your membership, enter your name and customerid (without any spaces):"<<" ";
        cin >> check_name;
       
        record.open(check_name, ios:: in);
          if (!record)
         { system("CLS");
            cout << "\n\t\t\t\t NO CURRENT MEMBERSHIPS ON THIS CUSTOMER ID  !!!!!!" << endl; 
         system("PAUSE");}
         else
         {
            cout <<"\n\t\t\t\t CUSTOMER VERIFIED"<<endl;
            cout <<"\n\t\t\t\t Price to renew memebership is Rs.500"<<endl;
            cout <<"\n\t\t\t\t paid?(Y/N)"<<endl;
            char paid;
            cin >> paid;
            if (paid == 'Y')
            {
               system("CLS");
                cout <<"CONGRATULATIONS your membership has been renewed"<<endl;
                system("PAUSE");
            }
         }
        record.close();
        
    }
    
    else if (member == "N")
    {  system("CLS");
          cout<<"\t\t\t\tWelcome to start a new journey with our cinemas \n";																										
				cout<<"Thank you. \n Please see the benefits of the card on the next page. -->";
				char f;
				cout<<"\n For selecting the page to go to benefits say (y/n)\n";
				cin>>f;
				if(f=='y')
				{
               system("CLS");
					cout<<"Thank you for registrating \n The priveleges provided are as follows:";
               benefits();
              system("PAUSE");
					
				}
            cout<<endl;
            cout<<endl;
            cout <<"Plans for membership are as follows:"<<endl;
            cout<<"1. Monthly plan for Rs. 900 per month"<<endl;
            cout <<"2. 6 months for Rs.1500 "<<endl;
            cout <<"3. 1 yr for Rs. 2100"<<endl;

      cout <<"\n\t\t\t\t Do to want to get a membership?(y/n)"<<" ";
      cin >> getmember;
      if (getmember == 'y')
      { system("CLS");

        cout <<" \n\t\t\t\t To get a membership, kindly enter following details:"<<endl;
        cout <<"\n\t\t\t\t Your name (add name in the format: mem_name):"<<" ";
        cin >> name;
        c.set_name(name);
        cout <<"\n\t\t\t\t Phone number:"<<" ";
        cin >> phone;
        c.set_phone(phone);
        cout <<"Date:"<<" ";
        cin.ignore();
        getline(cin, date);
        cout <<" Time period of the membership:"<<" ";
        cin.ignore();
        getline(cin,timeprd);
        record.open(name, ios:: app);
        record <<"Name:"<<"       "<<name<<endl;
        record<<"Phone Number:"<<" "<<phone<<endl;
        record<<"Date of registration:"<<" "<<date<<endl;
        record <<"Time period:"<<" "<<timeprd<<endl;
        record.close(); 
      }
    } }
}mem;
void membership::benefits(){
               cout<<"\n 1. For every purchase of a movie ticket you get 25 points(1point = 1Rs.) so after 16 movies you get a free movie ticket.";
					cout<<"\n 2. You are provided with regular updates regarding the movie and the showtimings.";
					cout<<"\n 3. Anytime prebook tickets for the upcoming movie and preffered seats will be provided.";
               cout<<endl;
}

class movie
{
public:
   int movie_no;
   string movie_name;
   string type, release_date, time_duration, language;

public:
   movie()
   {
      this->movie_name = " ";
      this->release_date = " ";
      this->type = " ";
      this->time_duration = " ";
      this->language = " ";
   }
   string get_movie()
   {return movie_name;}
   void set_language(string lan)
   {
      this->language = lan;
   }
   string get_language()
   {
      return language;
   }
   void set_moviename(string name)
   {
      this->movie_name = name;
   }
   void set_release(string release)
   {
      this->release_date = release;
   }
   string get_release()
   {
      return release_date;
   }
   void set_time(string time)
   {
      this->time_duration = time;
   }
   string get_time()
   {
      return time_duration;
   }
   string get_type()
   {
      return type;
   }
   void set_type(string type)
   {
      this->type = type;
   }
   void addmovies()
   {
      string a, b, c, d, e, f;
      fstream list;
      cout << "\n\t\t\t\t Enter movie name:"; 
      cin.ignore();                          
      getline(cin, a);
      cout << "\n\t\t\t\t Enter release date:"<<" ";
      cin.ignore(); 
      getline(cin, b);
      cout << "\n\t\t\t\t Enter time duration for the movie:"<<" ";
      cin.ignore(); 
      getline(cin, f);
      cout << "\n\t\t\t\t Enter the language of the movie:"<<" ";
      cin.ignore(); 
      getline(cin,e);
      cout << "\n\t\t\t\t Enter genre:"<<" ";
      cin.ignore(); 
      getline(cin,c);

      cout << endl;
      cout << "\n\t\t\t\t The movie has been SUCCESSFULLY ADDED" << endl;
      list.open("oops.txt", ios ::app);
      if (!list)
      {
         cout << "File does not exist" << endl;
      }
      else
      {
         list <<endl;
         list << a << "     " << b << "      " << c << "       " << e << "      " << f << endl;
         list.close();
      }
   }
} m;
class ticket {
    public: 
    int id;
    double price1;
    int number;
    int available;
    string type;
    public:
     ticket(){
    this -> id = 0;
    this-> price1 = 0;
    this-> available =100;
    }

    void setid(int i){
        this-> id = i;
    }
    int getid(){
        return id;
    }
    void set_tickettype(string ty){
     this-> type = ty;
    }
    string get_type(){
        return type;
    }
    void setseat(int seat){
     this-> available = seat;
    }
    int getseat(){
     return available;
    }
    void setprice(double p){
        this-> price1 = p;
    }
    double getprice(){
        return price1;
    }
   void setnumber(int n){
    this-> number = n;}
     int getnumber(){
    return number;
   }
   customer c;                            //containership

    void number_of_ticket(){
    cout << "\n\t\t\t\t Enter the number of seats you want to book:"<<endl;
    int seat;
    cout<<"\t\t\t\t";
    cin >> seat;
    setnumber(seat);
    available = available -seat;
    if (available <1)
    {
      cout << "\n\t\t\t\t   NO SEATS available for the show "<<endl;
    }
    else
    {
      cout <<"\n\t\t\t\t  Select your TICKET TYPE (silver/gold):"<<" ";
    cout <<"\n\t\t\t\t Silver ticket costs Rs. 250 and gold ticket costs Rs. 450"<<endl;
    cout <<"\n\t\t\t\t Enter s for silver and g for gold"<<endl;
    cout <<"\n\t\t\t\t  Please enter your choice:"<<endl;
    cout<<"\n\t\t\t\t";
    string cho;;
    cin.ignore();
    getline(cin, cho);

    if (cho == "s")
    {

        setprice(250*seat);
        set_tickettype ("silver");
    }
    else if (cho == "g")
    {
        setprice(450*seat);
        set_tickettype("gold");
    }
    cout <<"\n\t\t\t\t Total price:"<< getprice()<<endl;
    system("PAUSE");
    system("CLS");
   }
    }   
    }t;
    int main()
    {
        cout<<"\t\t\t WELCOME TO SHOPPING MALL\n";
    
            system("cls");
         char choice;
   int menu1, admin_choice;
   admin *a;
   char cont;
   int offers;
   
   string off[offers];
   membership mem;
   string movie_watch, booking_name, booking_date;
   string date;
   ticket t;
   string user, pass;
    cout << "\n\t\t\t\t WELCOME TO BIG CINEMA                         " << endl;
   cout << "\n\t\t\t\t ADMIN(a) / CUSTOMER login(c)? " << endl;
   cout<<" \n\t\t\t\t";
   cin >> choice;
   fstream list;
   string ch;
   fstream record;
    customer c;
   switch (choice )
   {
   case 'a':
   system("CLS");
    cout <<"\n\t\t\t\t Enter your username:"<<" ";
     cin >> user;
     if (user == "username"){
     do
     {
      cout <<"\n\t\t\t\t Enter password:"<<" ";
      cin >> pass;
      system("cls");
	
      if (pass == "password")
      {
         system("CLS");
          cout <<"1. Add movie "<<endl;
          cout <<"\n\t\t\t\tEnter your choice:"<<" ";
          cout <<"\n\t\t\t\t";
          cin >> admin_choice;
          if (admin_choice == 1)
          {
             m.addmovies();
          }
        else
        {
         cout <<"INVALID INPUT"<<endl;
        }
                       
   
      }
      else
      {
         cout <<"\n\t\t\t\t WRONG PASSWORD"<<endl;
         cout <<"\n\t\t\t\t Enter valid password"<<endl;
      }
     } while (pass != "password");
       }
      break;
   case 'c':
  
   do
   { 
    system("CLS");
     c. menu();
      cout << "\n\t\t\t\t Enter your choice:" << " ";
      cin >> menu1;
      switch (menu1)
      {
      case 1:
      system("CLS");
      cout<<"Enter date:"<<" ";
      cin.ignore();
      getline(cin, date);
       c.set_date(date);
       c.get_info();
       system("CLS");
       cout <<"\n\t\t\t\t Which movie do you want to watch?"<<endl;
       cout <<endl;
       list.open("oops.txt", ios ::in);                                                  //file handling
         if (!list)
         { cout <<" File does not exist" << endl; }
         else
         { string ch;
            while (!list.eof())
            { getline(list, ch, '\0');
               cout << ch; }
            cout << endl;}
         list.close();
         cout <<"\n\t\t\t\t Enter movie name:"<<" ";
         cin.ignore();
         getline(cin, movie_watch);
         
         system("PAUSE");
         system("CLS");
         m.set_moviename(movie_watch);
         t.number_of_ticket();
         record.open(c.getname(), ios:: app);
          if (!record)
         { cout << "File does not exist" << endl; }
         else{
            record<<endl;
            record <<" DATE:"<<"      "<<c.get_date()<<endl;
            record<<" Name:"<<"   "<< c.getname()<<"                                 "<<"phone number"<<" "<< c.get_phone()<<endl;
            record<<"---------------------------------------------------------------------------"<<endl;
            record<<"Movie Name:"<<"     "<<m.get_movie()<<endl;
            cout<<endl;
            record<<"Number of seats:"<<"   "<< t.getnumber()<<endl;
         
            record<< "Seat type:"<<"  "<<t.get_type()<<endl;
         
            record<<"Price : "<<"      "<<t.getprice()<<endl;
          
         }
         system("CLS");
        cout << "\n\t\t\t\t  ==================================================="<<endl;
    cout <<"   \n\t\t\t\t  your ticket has been successfully booked"<<endl;
    cout << "\n\t\t\t\t  ==================================================="<<endl;
    system("PAUSE");
    system("CLS");
    cout << "\n\t\t\t\t ======================================================="<<endl;
    cout <<"\n\t\t\t\t\t BOOKING DETAILS:"<<endl;
    cout <<"\n\t\t\t\t Name:"<<" "<< c.getname()<<"                      " <<"Date:"<<" "<< c.get_date()<<endl;
    cout <<"\n\t\t\t\t Movie name:"<<"  "<<m.get_movie()<<endl;              
    cout <<"\n\t\t\t\t  ticket type:"<<" "<<t.get_type()<<endl;
    cout <<"\n\t\t\t\t ticket price"<<" "<<t.getprice()<<endl;
    cout << "\n\t\t\t\t ======================================================="<<endl;
    system("PAUSE");
         cout<<"Do you want to select other option?(y/n)"<<" ";
         cin >> cont;

         break;
      case 2:
      system("CLS");
      cout <<"\n\t\t\t\t TO VIEW YOUR BOOKING DETAILS:"<<endl;
      cout <<"\n\t\t\t\t Enter name:"<<" ";
      cin >> booking_name;
      
      record.open(booking_name, ios:: in);
        if (!record)
         { cout << "File does not exist" << endl; }
         else
         { cout<<"\n\t\t\t\t YOUR BOOKING DETAILS UPTO DATE ARE:"<<endl;
            
            
            { while (!record.eof())
            { getline(record, ch, '\0');
               cout << ch; }
            cout << endl;
            }
         }
      record.close();
       cout<<"Do you want to select other option?(y/n)"<<" ";
         cin >> cont;
         break;

      case 3:
      system("CLS");

      list.open("oops.txt", ios ::in);
         if (!list)
         { cout <<" File does not exist" << endl; }
         else
         { string ch;
            while (!list.eof())
            { getline(list, ch, '\0');
               cout << ch; }
            cout << endl;}
         list.close();
          cout<<"Do you want to select other option?(y/n)"<<" ";
         cin >> cont;
         break;
      case 4:
       system("CLS");
        mem.member1();
         cout<<"Do you want to select other option?(y/n)"<<" ";
         cin >> cont;
         break;

      case 5:
      system("CLS");
		cout<<"\n\t\t\t\tTHANK YOU AND VISIT AGAIN!\n\n\t\t\t\t";
		system("PAUSE");
		exit(0); 
         break;

      default:
         cout << "INVALID INPUT" << endl;
         break;
      }
   } while (cont == 'y');
   }   
        return 0;
    }
    
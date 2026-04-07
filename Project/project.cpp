#include<iostream>
#include<string>
#include<fstream>
using namespace std;
const double rate = 20.0 / 100;
// project file
// functions: cars(updated car details,Remove cars,rental prices,payment methods(cash/visa),list of cars,check cars,cancel reservation,Rent car)
struct car {
	float price;      //rental price = price per month
	bool available;   //(true/false)
	string car[50];
	string model[200];
	string lp[50];    //lp=licence plate
	char condition;   //(T=total loss,D=damged,G=Good,P=perfect)
	double rate;         //(Intrest rate if late on payment)
	string details[1000];

 };
 //user  info (customer or staff or manager or quality control info)

 //customer:Id,age,phone no.,gender,payment method,optional(credit score)
struct customer {
	string name[100];
	double id;
	int age;
	char gender;
	int pn;       //PHONE NUMBER=pn
	string address[50];
	string job[20];    //job title
  };
 //staff:Id,age,phone no.,gender,salary,rank 
  
 
 //manager:Id,age,phone no.,gender,bioghraphy,salary.
struct manager {
	string name[100];
		double id;
		int age;
		int pn;     //PHONE NUMBER=pn
		char gender;
		string biography[1000];
		int salary;
};
 //quality control: their staff,date of inspection,severity of inspection(number of defective cars and their conditions)
struct control {
	string name[100];


};
 //login and sign up and the info is saved in an array
struct sign {
	
};
int main()
{	
    string user;
	string password;
	char c;
	cout << "DO you want to sign up or login (s/l)" << endl;
	cin >> c;
	while (true) 
	{
		if (c == 's')
		{
			cout << "Please enter your username" << endl;
			cin.ignore();
			getline(cin, user);
			cout << "Please enter your password" << endl;
			cin.ignore();
			getline(cin, password);
			ofstream file("login.txt");
			file << user << password;
			file.close();
			break;
		}
		else if (c == 'l')
		{
			cout << "Please enter your username" << endl;
			cin.ignore();
			getline(cin, user);
			cout << "Please enter your password" << endl;
			cin.ignore();
			getline(cin, password);
			ifstream file("login.txt");                          //we just need to make the login loop and make the program make sure that the username and password are correct 
			file >> user >> password;                            //and then we can move on to the next part of the program
														   
			
		}
		else
			cout << "There was an error please enter the right letter " << endl;
	}
	cout << "Welcome to our rental cars online program" << endl;
}
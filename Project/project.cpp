#include<iostream>
#include<string>
#include<fstream>
using namespace std;
// project file
// functions: cars(updated car details,Remove cars,rental prices,payment methods(cash/visa),list of cars,check cars,cancel reservation,Rent car)
struct car {
	double price;      //rental price = price per month
	bool available;   //(true/false)
	string car_type[50];
	string model[200];
	string lp[50];    //lp=licence plate
	char condition;   //(T=total loss,D=damged,G=Good,P=perfect)
	double rate;         //(Intrest rate if late on payment)
	string details[1000];
	double milage;     //milage of the car
	double year;      //year of the car
	string color[20];
	double reservation;  //reservation fee
	double deposit;      //deposit fee
	double late;         //late fee
	double insurance;     //insurance fee
	double reservation_num;  //reservation number
	double total;         //total price of the rental
 };
 //user  info (customer or staff or manager or quality control info)

 //customer:Id,age,phone no.,gender,payment method,optional(credit score)
struct customer {
	string name[100];
	double id;
	int age;
	char gender;
	int pn;                 //PHONE NUMBER=pn
	string address[50];
	string job[20];         //job title
	string payment[20];     //payment method(cash/visa)
	string credit[20];      //credit score
	double num_of_rentals;     //number of rentals
	int late_payments;        //number of late payments
	double total_paid;        //total amount paid by the customer
	double total_due;         //total amount due by the customer that has not been paid yet
	string email[50];
	string feedback[1000];      //customer feedback
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
		string email[50];           //email of the manager(optional)
		string number_of_deals;     //number of deals closed by the manager(optional)
		int customer_satisfaction;  //customer satisfaction rating for the manager(optional)
		int number_of_complaints;     //number of complaints against the manager(optional)
		int years_in_company;          //number of years the manager has been with the company(optional)
};
 //quality control: their staff,date of inspection,severity of inspection(number of defective cars and their conditions)
struct control {
	string name[100];


};
 //login and sign up and the info is saved in an array
bool login(string user, string password) {
	ifstream file("login.txt");
	string record;
	while (file >> record) {
		if (record == user + "," + password) {
			return true;
		}
	}
	return false;

};
int main()
{
	double total;
	const double rate = 20.0 / 100;
	string line;
	string record;
	string user;
	string password;
	char c;

	record = user + "," + password;
	bool verified = false;
	while (true)
	{  
		cout << "choose the role(customer/staff/manager/quality control) (c/s/m/q)" << endl;
		char r;
		cin >> r;
		cin.ignore();
		if(r!='c' && r!='s' && r!='m' && r!='q'){
			cout << "There was an error please enter the right letter " << endl;
			continue;
		}
		while (r=='c')
		{
			cout << "DO you want to sign up or login (s/l)" << endl;
			cin >> c;
			cin.ignore();
			if (c == 's')
			{
				cout << "Please enter your username" << endl;
				getline(cin, user);
				cout << "Please enter your password" << endl;
				getline(cin, password);
				ofstream file("login.txt");
				file << user << "," << password;
				file.close();
				cout << "You have successfully signed up :)" << endl;
				break;
			}
			else if (c == 'l')
			{
				bool status = login(user, password);
				{
					if (status) {
						cout << "welcome back" << user << endl;
						break;
					}
					else
					{
						cout << "There was an error please enter the right letter " << endl;
					}

				}


			}

		}
		while (r == 's') {
			cout << "DO you want to sign up or login (s/l)" << endl;
			cin >> c;
			cin.ignore();
			if (c == 's')
			{
				cout << "Please enter your username" << endl;
				getline(cin, user);
				cout << "Please enter your password" << endl;
				getline(cin, password);
				ofstream file("login.txt");
				file << user << "," << password;
				file.close();
				cout << "You have successfully signed up :)" << endl;
				break;
			}
			else if (c == 'l')
			{
				bool status = login(user, password);
				{
					if (status) {
						cout << "welcome back" << user << endl;
						break;
					}
					else
					{
						cout << "There was an error please enter the right letter " << endl;
					}

				}


			}
		
		}
		while(r=='m'){
			cout << "DO you want to sign up or login (s/l)" << endl;
			cin >> c;
			cin.ignore();
			if (c == 's')
			{
				cout << "Please enter your username" << endl;
				getline(cin, user);
				cout << "Please enter your password" << endl;
				getline(cin, password);
				ofstream file("login.txt");
				file << user << "," << password;
				file.close();
				cout << "You have successfully signed up :)" << endl;
				break;
			}
			else if (c == 'l')
			{
				bool status = login(user, password);
				{
					if (status) {
						cout << "welcome back" << user << endl;
						break;
					}
					else
					{
						cout << "There was an error please enter the right letter " << endl;
					}

				}


			}
		}
		while(r=='q'){
			cout << "DO you want to sign up or login (s/l)" << endl;
			cin >> c;
			cin.ignore();
			if (c == 's')
			{
				cout << "Please enter your username" << endl;
				getline(cin, user);
				cout << "Please enter your password" << endl;
				getline(cin, password);
				ofstream file("login.txt");
				file << user << "," << password;
				file.close();
				cout << "You have successfully signed up :)" << endl;
				break;
			}
			else if (c == 'l')
			{
				bool status = login(user, password);
				{
					if (status) {
						cout << "welcome back" << user << endl;
						break;
					}
					else
					{
						cout << "There was an error please enter the right letter " << endl;
					}

				}


			}
		}
		
	}
	cout << "Welcome to our rental cars online program" << endl;
}
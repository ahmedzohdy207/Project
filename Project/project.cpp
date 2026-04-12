#include<iostream>
#include<string>
#include<fstream>
using namespace std;
// project file
// functions: cars(updated car details,Remove cars,rental prices,payment methods(cash/visa),list of cars,check cars,cancel reservation,Rent car)
struct car {
	double price;      //rental price = price per week
	bool available;   //(true/false)
	string car_type;
	string model;
	string lp;    //lp=licence plate
	char condition;   //(T=total loss,D=damged,G=Good,P=perfect)
	double rate;         //(Intrest rate if late on payment)
	string details;
	double milage;     //milage of the car
	double year;      //year of the car
	string color;
	double reservation;  //reservation fee
	double deposit;      //deposit fee
	double late;         //late fee
	double insurance;     //insurance fee
	double reservation_num;  //reservation number
	double total;         //total price of the rental
}inventory[100]; 
//fuctions: payment ,methods(cash/visa)
struct visa {
	string first_name;
	string last_name;
	string card_type;   //card type(visa/mastercard/american express) 
	double card_number;
	double total_amount;     //total amount to be paid
	int cvv;
	string expiration_date;   //expiration date of the card  
	string billing_address[100];   //billing address of the cardholder
	double pn;     //PHONE NUMBER=pn
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
	visa credit[100];
	int day;
	int month;
	int year;
	const double rate = 20.0 / 100;
	string line;
	string record;
	string user;
	string password;
	char c;
	car inventory[100];
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
			if (c != 'l' && c != 's') {
				cout << "There was an error please enter the right letter " << endl;
			}
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
				ifstream infile;
				infile.open("login.txt");
				getline(infile, user, ',');
				getline(infile, password);
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
				ifstream infile;
				infile.open("login.txt");
				getline(infile, user, ',');
				getline(infile, password);
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
				ifstream infile;
				infile.open("login.txt");
				getline(infile, user, ',');
				getline(infile, password);
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
				ifstream infile;
				infile.open("login.txt");
				getline(infile, user, ',');
				getline(infile, password);
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
	int carcount;
	cout << "Welcome "<<user<<" to our rental cars online program" << endl;
	if (c == 's') {
			cout << "You can add cars to the inventory by providing details such as car type, model, license plate, condition, milage, year and color(a) or remove cars from inventory (r) or view Inspection date(d)" << endl;
			char z;
			cin >> z;
			if (z=='a') {
				cout << "how many cars do you want to add?" << endl;
				int num;
				cin >> num;
				cin.ignore();
				int carCount = 0;
			
				for (int i = 0; i < num; i++)
				{
					carCount = i + 1;
					carcount = carCount;
					cout << "car " << i + 1 << endl;
					cout << "Enter the car type" << endl;
					getline(cin, inventory[i].car_type);
					cout << "Enter the model" << endl;
					getline(cin, inventory[i].model);
					cout << "Enter the license plate" << endl;
					getline(cin, inventory[i].lp);
					cout << "Enter the condition (T=total loss,D=damaged,G=Good,P=perfect)" << endl;
					cin >> inventory[i].condition;
					cout << "Enter the milage" << endl;
					cin >> inventory[i].milage;
					cout << "Enter the year" << endl;
					cin >> inventory[i].year;
					cin.ignore();
					cout << "Enter the color" << endl;
					getline(cin, inventory[i].color);
					cout << "is the car available for rent? (1 for yes, 0 for no)" << endl;
					cin >> inventory[i].available;
					cout << "Enter the rental price per week " << endl;
					cin >> inventory[i].price;
					cout << "Do you want to add more cars to inventory(y/n)" << endl;
					char g;
					cin >> g;
					if (g == 'n') {
						break;
					}
					else {
						continue;
					}
				}
			}
		
		else if (z == 'r') {
			cout << "You can remove cars from the inventory" << endl;
			cout << "enter the number of the car you want to remove" << endl;
			int remove;
			while (true) {
				cin >> remove;
				int target = 0;
				target = remove - 1;
				if (target >= 0 && target < carcount) {
					for (int i = target; i < carcount; i++) {
						inventory[i] = inventory[i + 1];
					}
			
					carcount--;
					cout << "car number " << remove << "has been removed sucessfully" << endl;
					cout << "Do you want to remove another car(y/n)" << endl;
						char g;
					cin >> g;
					if (g == 'n') {
						break;
					}
					else {
						continue;
					}
				}
				else {
					cout << "Error:That car number does not exist please try again" << endl;
				}
			}
		}
		else if (z == 'v') {
				ifstream infile;
				infile.open("date.txt");
				char slash='/';
				infile >> day >> slash >> month>>slash >> year;
			}
			}
		
	

	else if(c=='c'){
		cout << "As a customer you can browse available cars, make reservations, and manage your rentals" << endl;
		cout << "car number" << "---" << "type" << "---" << "model" << "---" << "license plate" << "---" << " color" << "---" << "car condition" << "---" <<"Milage"<<"---" << "year" << "---" << " price" << endl;
		for (int i = 0; i < 100; i++) {
			cout << i + 1 << "---" << inventory[i].car_type << "---" << inventory[i].model << "---" << inventory[i].lp << "---" << inventory[i].color << "---" << inventory[i].condition;
			cout << "---" << inventory[i].milage << "---" << inventory[i].year << "---" << inventory[i].price << endl;
		}
		while (true) {
			cout << "what is the number of the car you want to rent" << endl;
			int num2;
			cin >> num2;
			cout << num2 << "---" << inventory[num2].car_type << "---" << inventory[num2].model << "---" << inventory[num2].lp << "---" << inventory[num2].color << "---" << inventory[num2].condition;
			cout << "---" << inventory[num2].milage << "---" << inventory[num2].year << "---" << inventory[num2].price << endl;
			cout << "is this is the car you want to rent(y/n)" << endl;
			char b;
			cin >> b;
			if (b == 'n') {
				continue;
			}
			else if (b != 'y' && b != 'n') {
				cout << "Please enter the right letter" << endl;
				continue;
			}
			else if (b == 'y') {
				cout << "The rent price for the car is:" << inventory[num2].price << endl;
				cout << "would you like to pay cash(c) or visa(v)"<<endl;
				char e;
				if (e == 'c') {
					cout << "Please come at our nearest store to you to pay for your rental car:)" << endl;
				}
				else if (e == 'v') {
					cout << "please enter your first name" << endl;
					cin.ignore();
					getline(cin, credit->first_name);
					cout << "please enter your last name" << endl;
					getline(cin, credit->last_name);
					cout << "please enter your card type" << endl;
					getline(cin, credit->card_type);
					cout << "please enter your card number" << endl;
					cin >> credit->card_number;
					cout << "please enter your cvv number" << endl;
					cin >> credit->cvv;
					cout << "please enter your expiration date" << endl;
					cin.ignore();
				    getline(cin,credit->expiration_date);
					cout << "Thank you for using our online rental car system:)" << endl;
				}
			}
		}
	}
	else if (c == 'q') {
		cout << "As a quality control you can view staff(v) , add date of inspection(d),severity of inspection(s)(number of defective cars and their conditions)" << endl;
		char o;
		cin >> o;
		if (o == 'v') {
                                                    //do we put the staff login or details or struct and put the login and name or delete it ?
			                                        //it only needs thereservation too and it will be completed
		}
		else if (o == 'd') {
			cout << "enter day of inspection" << endl;
			cin >> day;
			cout << "enter month of inspection" << endl;
			cin >> month;
			cout << "enter year of inspection" << endl;
			cin >> year;
			cout << "Inspection date is " << day << "/" << month << "/" << year << "/" << endl;
			ofstream file("date.txt");
				file << day<<"/"<<month<<"/"<<year;
				file.close();

		}
		else if (o == 's') {
			int Total_loss=0;
			int Damaged=0;
			int Good=0;
			int Perfect=0;
			for (int i = 0; i < 100; i++) {
				cout << "The car number" << i + 1 << "is" << inventory[i].condition<<"Where (T=total loss,D=damaged,G=Good,P=perfect)  " << endl;
				if (inventory[i].condition == 'T') {
					Total_loss = Total_loss + 1;
				}
				else if (inventory[i].condition == 'D') {
					Damaged = Damaged + 1;
				}
				else if (inventory[i].condition == 'G') {
					Good = Good + 1;
				}
				else if (inventory[i].condition == 'P') {
					Perfect = Perfect + 1;
				}
				
			}
			cout << "number of total loss cars is:" << Total_loss << endl;
			cout << "number of damaged cars is:" << Damaged<< endl;
			cout << "number of cars in good condition is:" << Good << endl;
			cout << "number of cars in perfect condition is:" << Perfect<< endl;
		}

	}

}
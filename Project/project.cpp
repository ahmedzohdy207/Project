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
	int year;      //year of the car
	string color;
	double reservation;  //reservation fee
	double deposit;      //deposit fee
	double late;         //late fee
	double insurance;     //insurance fee
	long long reservation_num;  //reservation number
	double total;         //total price of the rental
}; 
//fuctions: payment ,methods(cash/visa)
struct visa {
	string first_name;
	string last_name;
	string card_type;   //card type(visa/mastercard/american express) 
	long long card_number;
	double total_amount;     //total amount to be paid
	int cvv;
	string expiration_date;   //expiration date of the card  
	string billing_address;   //billing address of the cardholder
	string pn;     //PHONE NUMBER=pn
};
 //user  info (customer or staff or manager or quality control info)

 //customer:Id,age,phone no.,gender,payment method,optional(credit score)
struct customer {
	string name;
	long long id;
	int age;
	char gender;
	string pn;                 //PHONE NUMBER=pn
	string address;
	string job;         //job title
	string payment;     //payment method(cash/visa)
	string credit;      //credit score
	double num_of_rentals;     //number of rentals
	int late_payments;        //number of late payments
	double total_paid;        //total amount paid by the customer
	double total_due;         //total amount due by the customer that has not been paid yet
	string email;
	string feedback;      //customer feedback
};
 

 //login and sign up and the info is saved in an array
bool login(string m, string j, string filename) {
	ifstream file(filename);
	string record;
	while (getline(file, record)) {
		if (record == m + "," + j) {
			return true;
		}
	}
		return false;
}
void save_counter(int& counter) {
	ofstream ifile;
	ifile.open("counter.txt");
	ifile << counter << endl;      // Save the counter value to the file
	ifile.close();
}
void load_counter(int& counter) {
	ifstream ifile("counter.txt");
	if (ifile.is_open()) {
		ifile >> counter;           // Load the counter value from the file
	}
	else {
		counter = 0;                // If the file doesn't exist, start with a counter of 0
	}
	ifile.close();
}
void save_inventory(car inventory[100], int& carcount) {
	ofstream ifile;

	ifile.open("inventory.txt");
	ifile << carcount << endl;      // Save the number of cars at the beginning of the file
	for (int i = 0; i < carcount; i++) {
		ifile << inventory[i].car_type << endl;
		ifile << inventory[i].model << endl;
		ifile << inventory[i].lp << endl;
		ifile << inventory[i].color << endl;
		ifile << inventory[i].condition << endl;
		ifile << inventory[i].milage << endl;
		ifile << inventory[i].year << endl;
		ifile << inventory[i].price << endl;
		ifile << inventory[i].available << endl;
	}
	ifile.close();
}
void reservation(car inventory[100], visa credit[100], customer guest[100],int& ID, int& visacount, int& counter,int&num2, char& e) {
	cout << "Please enter your ID number" << endl;
	cin >> ID;
	if (ID < 1000 || ID >= 1000 + counter) {
		cout << "Error: Invalid ID number please enter a valid ID." << endl;
		return;
	}
	cin.ignore();
	ofstream ifile;
	ifile.open("Reservations.txt",ios::app);
	if (e == 'c') {
		ifile << "Payment method: Cash" << endl;
		ifile << guest[ID - 1000].name << "," << guest[ID - 1000].age << "," << guest[ID - 1000].gender << "," << guest[ID - 1000].pn << "," << guest[ID - 1000].address << endl;
	}
	else if (e == 'v') {
		ifile << "Payment method: Visa" << endl;
		ifile << guest[ID - 1000].name << "," << guest[ID - 1000].age << "," << guest[ID - 1000].gender << "," << guest[ID - 1000].pn << "," << guest[ID - 1000].address << endl;
		ifile << credit[visacount].first_name << "," << credit[visacount].last_name << "," << credit[visacount].card_type << "," << credit[visacount].card_number << "," << credit[visacount].cvv << endl;
	}

	cout << "Car number " << num2 << " has been reserved successfully" << endl;
	inventory[num2-1].available = false;
	ifile.close();
	visacount++;
}	
void load_inventory(car inventory[100], int& carcount) {
	ifstream ifile("inventory.txt");
	string line;
	if (!ifile.is_open()) {
		carcount = 0;                                                         // If the file doesn't exist, start with an empty inventory
		return;
	}
	ifile >> carcount;
	ifile.ignore();                                                           // Ignore the newline character after reading carcount
	for (int i = 0; i < carcount; i++) {
		getline(ifile, inventory[i].car_type);
		getline(ifile, inventory[i].model);
		getline(ifile, inventory[i].lp);
		getline(ifile, inventory[i].color);
		ifile >> inventory[i].condition;
		ifile >> inventory[i].milage;
		ifile >> inventory[i].year;
		ifile >> inventory[i].price;
		ifile >> inventory[i].available;
		ifile.ignore();
	}
	ifile.close();
}
void list_customer(string username, string password, int& counter ,int& ID, customer guest[]) {
	ID = 1000 + counter;
	counter++;
	save_counter(counter); 
	ofstream ifile;
	string line;
	ifile.open("customer.txt", ios::app);
	cout << "please enter your name" << endl;
	getline(cin, guest[counter-1].name);
	cout << "please enter your age" << endl;
	cin >> guest[counter-1].age;
	cin.ignore();
	cout << "please enter your gender (m/f): ";
	cin >> guest[counter-1].gender;
	while (guest[counter-1].gender != 'm' && guest[counter-1].gender != 'f') {
		cout << "Invalid input. Please enter 'm' for male or 'f' for female: ";
		cin >> guest[counter-1].gender;
	}
	cin.ignore();
	cout << "please enter your phone number" << endl;
	string pn_str;
	cin >> pn_str;                                                 // Temporary string to read phone number input
	while (pn_str.length() != 11) {
		cout << "Error: Phone number must be exactly 11 digits!" << endl;
		cout << "please enter your phone number" << endl;
		cin >> pn_str;
		}
	guest[counter-1].pn = pn_str;
	cin.ignore();
	cout << "please enter your address" << endl;
	getline(cin, guest[counter-1].address);
	ifile << username << "," << password << "," << guest[counter-1].name << "," << guest[counter-1].age << "," << guest[counter-1].gender << "," << guest[counter-1].pn << "," << guest[counter-1].address << endl;
	cout << "your ID is:" << ID << endl;
	cout << "keep your ID number for future reference when you want to make a reservation or cancel a reservation:)" << endl;
	ifile.close();
}
void load_customer(customer guest[100], int& counter) {
	ifstream ifile("customer.txt");
	string user, password, name, age, gender, pn, address;
	if (!ifile.is_open()) {
		return;
	}
	for (int i = 0; i < counter; i++) {
		getline(ifile, user,',');
		getline(ifile, password,',');
		getline(ifile, guest[i].name,',');
		getline(ifile,age,',');
		guest[i].age = stoi(age);                 // Convert age from string to integer]
		getline(ifile, gender,',');
		guest[i].gender = gender[0];              // Convert gender from string to character
		getline(ifile, guest[i].pn,',');
		getline(ifile, guest[i].address);
	}
	ifile.close();
}
//we can make a function for canceling the reservation and it will take the reservation number as an input and it will remove the reservation from the Reservations.txt file
// and it will also make the car available for rent again in the inventory
//and one for checking the reservation and it will take the reservation number as an input and it will check if the reservation exists in the Reservations.txt file
// and it will also show the details of the reservation if it exists
void staff_menu(car inventory[100], int& carcount) {
	load_inventory(inventory, carcount);
	while (true) {
		int day;
		int month;
		int year;
		string user;
		string password;
		char c;
		cout << "DO you want to sign up or login or exit to tthe main menu (s/l/e)" << endl;
		cin >> c;                                         //variable to choose between sign up and login for staff
		cin.ignore();
		if (c == 'e') {
			break;                                                          //To end the staff infinte loop and return to the main menu
		}
		if (c != 's' && c != 'l' && c != 'e') {
			cout << "please enter the right letter " << endl;
			continue;
		}
		if (c == 's')
		{
			cout << "Please enter your username" << endl;
			getline(cin, user);
			cout << "Please enter your password" << endl;
			getline(cin, password);
			ofstream file("login.txt", ios::app);
			file << user << "," << password << endl;
			file.close();
			cout << "You have successfully signed up :)" << endl;
			break;
		}
		else if (c == 'l')
		{
			cout << "Enter user and password" << endl;
			cout << "user:" << endl;
			string m;                      //username input for login
			getline(cin, m);
			cout << "password:" << endl;
			string j;                      //password input for login
			getline(cin, j);
			bool status = login(m, j, "login.txt");
			{
				if (!status) {
					cout << "Incorrect user or password please try again " << endl;
					continue;
				}
				else if (status)
				{
					cout << "welcome back " << m << endl;
					cout << "You can add cars to the inventory by providing details such as car type, model, license plate, condition, milage, year and color(a) or remove cars from inventory (r) or view Inspection date(d) or view the number of cars(v)" << endl;
					char z;                                  //variable to choose between adding cars to the inventory, removing cars from the inventory, or viewing the inspection date for quality control
					cin >> z;
					if (z != 'a' && z != 'r' && z != 'd' && z != 'v') {
						cout << "please enter the right letter " << endl;
						continue;
					}
					if (z=='v') {
						cout << "The number of cars in the inventory is: " << carcount << endl;
						break;
					}
					if (z == 'a') {
						cout << "how many cars do you want to add?" << endl;
						int num;                                 //number of cars that the staff wants to add to the inventory
						cin >> num;
						cin.ignore();                                                        //if num lower than 0 and more than 100 then cout error
						if (carcount + num > 100) {
							cout << "Error: Inventory is full, cannot add more cars." << endl;
							continue;
						}
						if (num >= 0 && num <= 100 && carcount + num <= 100) {
							for (int i = 0; i < num; i++)
							{
								cout << "car " << carcount + 1 << endl;
								cout << "Enter the car type" << endl;
								getline(cin, inventory[carcount].car_type);
								cout << "Enter the model" << endl;
								getline(cin, inventory[carcount].model);
								while (cin.fail()) {
									cout << "Error: Invalid input for model. Please enter a valid model." << endl;
									cin.clear();
									cin.ignore(10000, '\n');
									getline(cin, inventory[carcount].model);
								}
								cout << "Enter the license plate" << endl;
								getline(cin, inventory[carcount].lp);
								cout << "Enter the condition (T=total loss,D=damaged,G=Good,P=perfect)" << endl;
								cin >> inventory[carcount].condition;
								while (cin.fail() || inventory[carcount].condition != 'T' && inventory[carcount].condition != 'D' && inventory[carcount].condition != 'G' && inventory[carcount].condition != 'P') {
									cout << "Invalid input. Please enter 'T' for total loss, 'D' for damaged, 'G' for good, or 'P' for perfect: ";
									cin >> inventory[carcount].condition;
								}
								cout << "Enter the milage" << endl;
								cin >> inventory[carcount].milage;
								while (cin.fail() || inventory[carcount].milage < 0) {
									cout << "Error: Milage must be a non-negative number!" << endl;
									cout << "Enter the milage" << endl;
									cin.clear();
									cin.ignore(10000, '\n');
									cin >> inventory[carcount].milage;
								}
								cout << "Enter the year" << endl;
								cin >> inventory[carcount].year;
								while (cin.fail() || inventory[carcount].year < 1886 || inventory[carcount].year > 2024) {
									cout << "Error: Year must be between 1886 and 2024!" << endl;
									cout << "Enter the year" << endl;
									cin.clear();
									cin.ignore(10000, '\n');
									cin >> inventory[carcount].year;
								}
								cin.ignore();
								cout << "Enter the color" << endl;
								getline(cin, inventory[carcount].color);
								cout << "is the car available for rent? (1 for yes, 0 for no)" << endl;
								cin >> inventory[carcount].available;
								cout << "Enter the rental price per week " << endl;
								cin >> inventory[carcount].price;
								carcount++;
								save_inventory(inventory, carcount);
								cout << "Do you want to add more cars to inventory(y/n)" << endl;
								char g;                                    //variable to choose whether the staff wants to add more cars to the inventory or not
								cin >> g;
								cin.ignore();
								if (g == 'n') {
									break;
								}
								else if (g == 'y') {
									continue;
								}
								else if (g != 'y' && g != 'n') {
									cout << "please enter the right letter " << endl;
								}
							}
						}
						else {
							cout << "Error: number of cars must be between 0 and 100" << endl;
						}
					}

					else if (z == 'r') {
						cout << "You can remove cars from the inventory" << endl;
						cout << "enter the number of the car you want to remove" << endl;
						int remove;                                     //number of the car that the staff wants to remove from the inventory and it is used to access the car details in the inventory array
						while (true) {
							cin >> remove;
							int target = 0;
							target = remove - 1;
							if (target >= 0 && target < carcount) {
								for (int i = target; i < carcount - 1; i++) {
									inventory[i] = inventory[i + 1];
								}
								carcount--;
								save_inventory(inventory, carcount);
								cout << "car number " << remove << "has been removed sucessfully" << endl;
								cout << "Do you want to remove another car(y/n)" << endl;
								char g;                                    //variable to choose whether the staff wants to remove another car from the inventory or not
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
								cin.clear();
								cin.ignore(10000, '\n');
							}
						}
					}
					else if (z == 'd') {
						ifstream infile;
						infile.open("date.txt");
						char slash = '/';
						infile >> day >> slash >> month >> slash >> year;
						cout << day << "/" << month << "/" << year << endl;
						infile.close();
					}
					break;
				}

			}


		}
	}
}
void control_menu(car inventory[100],int& carcount) {                              //quality control: their staff,date of inspection,severity of inspection(number of defective cars and their conditions)
	while (true) {
		cout << "DO you want to sign up or login or exit to the main menu (s/l/e)" << endl;
		int day;
		int month;
		int year;
		string user;
		string password;
		char c;
		cin >> c;                                        //variable to choose between sign up and login for quality control
		cin.ignore();
		if (c == 'e') {
			break;                                                          //To end the quality control infinte loop and return to the main menu
		}
		if (c != 's' && c != 'l' && c != 'e') {
			cout << "please enter the right letter " << endl;
			continue;
		}
		if (c == 's')
		{
			cout << "Please enter your username" << endl;
			getline(cin, user);
			cout << "Please enter your password" << endl;
			getline(cin, password);
			ofstream file("login(q).txt", ios::app);
			file << user << "," << password << endl;
			file.close();
			cout << "You have successfully signed up :)" << endl;
			break;
		}
		else if (c == 'l')
		{
			cout << "Enter user and password" << endl;
			cout << "user:" << endl;
			string m;
			getline(cin, m);
			cout << "password:" << endl;
			string j;
			getline(cin, j);
			bool status = login(m, j, "login(q).txt");
			{
				if (!status) {
					cout << "Incorrect user or password please try again " << endl;
					continue;
				}
				else if (status)
				{
					cout << "welcome back " << m << endl;
					cout << "Welcome " << m << " to our rental cars online program" << endl;
					cout << "Add date of inspection(d),severity of inspection(s)(number of defective cars and their conditions)" << endl;
					char o;                                       //variable to choose between adding the date of inspection or the severity of inspection for quality control
					cin >> o;
					if (o != 'd' && o != 's') {
						cout << "please enter the right letter " << endl;
						continue;
					}
					if (o == 'd') {
						cout << "enter day of inspection" << endl;
						cin >> day;
						cout << "enter month of inspection" << endl;
						cin >> month;
						cout << "enter year of inspection" << endl;
						cin >> year;
						cout << "Inspection date is " << day << "/" << month << "/" << year << endl;
						ofstream file("date.txt");
						file << day << "/" << month << "/" << year;
						file.close();

					}
					else if (o == 's') {
						load_inventory(inventory, carcount);
						int Total_loss = 0;
						int Damaged = 0;
						int Good = 0;
						int Perfect = 0;
						for (int i = 0; i < carcount; i++) {
							cout << "The car number" << i + 1 << "is" << inventory[i].condition << "Where (T=total loss,D=damaged,G=Good,P=perfect)  " << endl;
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
						cout << "number of damaged cars is:" << Damaged << endl;
						cout << "number of cars in good condition is:" << Good << endl;
						cout << "number of cars in perfect condition is:" << Perfect << endl;
					}
					break;
				}
				
			}

			
		}
		
	}
}



int main()
{   
	int number;                            //number of cae reserved by the customer and it is used to access the car details in the inventory array
	customer guest[100];
	int counter = 0;
	int visacount = 0;
	int carcount = 0;
	visa credit[100];
	int day;                                   //day of inspection for quality control
	int month;                                 //month of inspection for quality control
	int year;                                  //year of inspection for quality control
	string line;
	string user;                                 //username for login and sign up
	string password;                             //password for login and sign up
	char c;                                      //variable to choose between sign up and login 
	car inventory[100];
	int ID;                                     //ID of the customer that is generated when the customer signs up and it is used to access the customer details in the guest array
	load_counter(counter);
	load_customer(guest, counter);
	load_inventory(inventory, carcount);
	ifstream infile;
	infile.open("inventory.txt");
	while (true)
	{
		cout << "choose the role(customer/staff/quality control/exit) (c/s/q/e)" << endl;
		char r;                               //role of the user (customer/staff/quality control/exit) (c/s/q/e)
		cin >> r;
		cin.ignore();
		if (r == 'e') {
			break;
		}
		if (r != 'c' && r != 's' && r != 'q' && r != 'e') {
			cout << "There was an error please enter the right letter " << endl;
			continue;
		}
		while (r == 'c')
		{
			cout << "DO you want to sign up or login or exit to the main menu (s/l/e) " << endl;
			cin >> c;
			cin.ignore();
			if (c != 'l' && c != 's' && c != 'e') {
				cout << "There was an error please enter the right letter " << endl;
			}
			if (c == 'e') {
				break;                                                          //To end the customer infinte loop and return to the main menu
			}
			if (c == 's')
			{
				cout << "Please enter your username" << endl;
				getline(cin, user);
				cout << "Please enter your password" << endl;
				getline(cin, password);
				ofstream file("login(c).txt", ios::app);
				file << user << "," << password << endl;
				file.close();
				cout << "You have successfully signed up :)" << endl;
				list_customer(user, password, counter, ID, guest);
				break;
			}
			else if (c == 'l')
			{
				cout << "Enter user and password" << endl;
				cout << "user:" << endl;
				string m;                                //username input for login
				getline(cin, m);
				cout << "password:" << endl;
				string j;                                //password input for login
				getline(cin, j);
				bool status = login(m, j, "login(c).txt");
				{
					if (!status) {
						cout << "Incorrect user or password please try again " << endl;
						continue;
					}
					else if (status)
					{
						cout << "Please enter your ID number" << endl;
						cin >> ID;
						if (ID < 1000 || ID >= 1000 + counter) {
							cout << "Error: Invalid ID number please enter a valid ID." << endl;
							continue;
						}

						if (carcount == 0) {
							cout << "No cars available for rent at the moment please check back later:)" << endl;
							break;
						}

						cout << "welcome back " << m << endl;
						cout << "As a customer you can browse available cars, make reservations, and manage your rentals" << endl;
						cout << "car number" << "---" << "type" << "---" << "model" << "---" << "license plate" << "---" << " color" << "---" << "car condition" << "---" << "Milage" << "---" << "year" << "---" << " price" << endl;
						for (int i = 0; i < carcount; i++) {
							if (inventory[i].available == true) {
								cout << i + 1 << "---" << inventory[i].car_type << "---" << inventory[i].model << "---" << inventory[i].lp << "---" << inventory[i].color << "---" << inventory[i].condition << "---" << inventory[i].milage << "---" << inventory[i].year << "---" << inventory[i].price << endl;
							}
							else if (inventory[i].available==false) {
								continue;
							}
						}
						infile.close();


					}
					while (true) {
						cout << "what is the number of the car you want to rent" << endl;
						int num2;                                    //number of the car that the customer wants to rent and it is used to access the car details in the inventory array
						cin >> num2;
						number = num2;
						if (num2 > 0 && num2 <= carcount) {
							if (inventory[num2 - 1].available == false) {
								cout << "Sorry that car is not available for rent at the moment please choose another car" << endl;
								continue;
							}
							else if (inventory[num2 - 1].available == true) {
								cout << num2 << "---" << inventory[num2 - 1].car_type << "---" << inventory[num2 - 1].model << "---" << inventory[num2 - 1].lp << "---" << inventory[num2 - 1].color << "---" << inventory[num2 - 1].condition;
								cout << "---" << inventory[num2 - 1].milage << "---" << inventory[num2 - 1].year << "---" << inventory[num2 - 1].price << endl;
								cout << "is this is the car you want to rent(y/n)" << endl;
							}
							char b;                                    //variable to confirm the car that the customer wants to rent
							cin >> b;
							if (b == 'n') {
								continue;
							}
							else if (b != 'y' && b != 'n') {
								cout << "Please enter the right letter" << endl;
								continue;
							}
							else if (b == 'y') {
								cout << "The rent price for the car is:" << inventory[num2 - 1].price << endl;
								cout << "would you like to pay cash(c) or visa(v)" << endl;
								char e;                                    //variable to choose payment method
								cin >> e;
								cin.ignore();
								if (e == 'c') {                            //if the customer chooses to pay cash
									cout << "Please come at our nearest store to you to pay for your rental car:)" << endl;
									reservation(inventory, credit, guest, ID, visacount, counter, num2,e);
									inventory[num2 - 1].available = false;
								}
								else if (e == 'v') {                       //if the customer chooses to pay with visa
									cout << "please enter your first name" << endl;
									getline(cin, credit[visacount].first_name);
									cout << "please enter your last name" << endl;
									getline(cin, credit[visacount].last_name);
									cout << "please enter your card type" << endl;
									getline(cin, credit[visacount].card_type);
									cout << "please enter your card number" << endl;
									cin >> credit[visacount].card_number;
									string card_str = to_string(credit[visacount].card_number);
									while (card_str.length() != 16) {
										cout << "Error: Card number must be exactly 16 digits!" << endl;
										cout << "please enter your card number" << endl;
										cin >> credit[visacount].card_number;
										card_str = to_string(credit[visacount].card_number);
									}
									cout << "please enter your cvv number" << endl;
									cin >> credit[visacount].cvv;
									string cvv_str = to_string(credit[visacount].cvv);
									while (cvv_str.length() != 3) {
										cout << "Error: CVV number must be exactly 3 digits!" << endl;
										cout << "please enter your cvv number" << endl;
										cin >> credit[visacount].cvv;
										cvv_str = to_string(credit[visacount].cvv);
									}

									cout << "please enter your expiration date" << endl;
									cin.ignore();
									getline(cin, credit[visacount].expiration_date);
									ofstream file("visa.txt", ios::app);
									file << credit[visacount].first_name << "," << credit[visacount].last_name << "," << credit[visacount].card_type << "," << credit[visacount].card_number << "," << credit[visacount].cvv << endl;
									cout << "Thank you for using our online rental car system:)" << endl;
									reservation(inventory, credit, guest, ID, visacount, counter, num2,e);
								}
								else if (e != 'c' && e != 'v') {
									cout << "Please enter the right letter" << endl;
									continue;
								}
								save_inventory(inventory, carcount);


							}
							break;
						}
						else if (num2 < 1 || num2 > carcount) {                                                                     //if the customer enters a car number that does not exist in the inventory
							cout << "The car number that you have entered does not exist please enter the right car number" << endl;
							continue;
						}

						break;
					}



				}


			}

		}
	





		while (r == 's') {
			staff_menu(inventory, carcount);
			break;

		}
		while (r == 'q') {
			control_menu(inventory, carcount);
			break;
		}

	}

}
	

	


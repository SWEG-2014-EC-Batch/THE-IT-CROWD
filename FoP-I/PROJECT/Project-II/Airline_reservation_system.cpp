// Airline reservation system
#include <iostream>
#include <string.h>
using namespace std;
		//Program for an airline reservation system
// declaration and initialization
struct customer {
	string name, passport;
	int age;
	char sex;
};
	int first_class= 0, economic_class=30;
	char yes_no;
	void main_choice1(customer[]), main_choice2(customer[]), main_choice3(customer[]), detailsInput(customer& ), detailsOutput(customer& person, int& seatNum, string section), display2(customer[], int);
	inline void pauseClean();
	inline void colorClean(char color[]);
int main() {
	int main_choice;
	customer person[100];
	// do- while loop for continues program
	do {
		system("color F1");// to make background color white and text color blue
		cout<<endl;
//main page option
		cout<<"\t*********************************************************************************************"<<endl;
		cout<<"\t*___________________________________________________________________________________________*"<<endl;;
		cout<<"\t*                               Airline Reservation System                                  *"<<endl;
		cout<<"\t*___________________________________________________________________________________________*"<<endl;
		cout<<"\t*  Book a flight------------------------------------------------------------------------[1] *"<<endl;
		cout<<"\t*___________________________________________________________________________________________*"<<endl;
		cout<<"\t*  Search for attendance----------------------------------------------------------------[2] *"<<endl;
		cout<<"\t*___________________________________________________________________________________________*"<<endl;
		cout<<"\t*  List  all passengers-----------------------------------------------------------------[3] *"<<endl;
		cout<<"\t*___________________________________________________________________________________________*"<<endl;
		cout<<"\t*  Exit---------------------------------------------------------------------------------[4] *"<<endl;
		cout<<"\t*___________________________________________________________________________________________*"<<endl;
		cout<<"\t*********************************************************************************************"<<endl;
		cout<<"   Enter your choice here : "; //ask the user to choice among the main option
		cin>>main_choice;
		switch(main_choice)
		if(main_choice==1) {
            main_choice1(person);
        }
		 else if(main_choice==2) {
			main_choice2(person);
		}
//  to display all list of passengers
		else if(main_choice==3) {
			main_choice3(person);
		}
// to exit the program
		else if(main_choice==4) {
			return 0;
		} else {
			cout<<"Invalid input. please try again"<<endl;
			pauseClean();
		}
	} while(true);
	return 0;
}
void main_choice1(customer person[]){
	int sub_choice;
		if(first_class>=30 && economic_class>=100) {
				system("CLS");
				cout<<"ALL SEATS ARE BOOKED "<<endl;
				pauseClean();
			} else {
				colorClean("color 06");
				cout<<endl;
				//list of available class
				cout<<"\t*********************************************************************************"<<endl;
				cout<<"\t*____________________List of available classes__________________________________*"<<endl;
				cout<<"\t*  First class --------------------------------------------------------------[1]*"<<endl;
				cout<<"\t*_______________________________________________________________________________*"<<endl;
				cout<<"\t* Economy class -------------------------------------------------------------[2]*"<<endl;
				cout<<"\t*********************************************************************************"<<endl;
choice :
				cout<<"   Enter your choice here : ";
				cin>>sub_choice;
				if(sub_choice != 1 && sub_choice!=2) {
					cout<< "invalid input"<<endl;
					goto choice;
				}
				// code to make reservation class for first class
				if(sub_choice==1) {
					system("CLS");
					if(first_class>=30) {
						//ask the user if he/she wants to take reservation in economy class
						cout<<"First class is full. do you want to book economic class? (y/n)"<<endl;
						cin>>yes_no;
						if(toupper(yes_no) == 'Y') {
							// prompt the user name,sex , age and passport number
							detailsInput(person[first_class]);
							//display boarding pass according to the user information
							detailsOutput(person[first_class], first_class, "first");
						} else {
							cout<<"NEXT FLIGHT LEAVES IN 3 HOURS"<<endl;
						}
					} else {
						// prompt the user name,sex , age and passport number
						detailsInput(person[first_class]);
						//display boarding pass according to the user information
						detailsOutput(person[first_class], first_class, "first");
					}
				}
				// code to make reservation class for economy class
				else if (sub_choice==2) {
					colorClean("color 06");
					if(economic_class>=100) {
						//ask the user if he/she wants to take reservation in first class
						cout<<"economic class is full. do you want to book first class (y/n)"<<endl;
						cin>>yes_no;
						if(yes_no=='y' || yes_no=='Y') {
							// prompt the user name,sex , age and passport number
							detailsInput(person[first_class]);
							//display boarding pass according to the user information
							detailsOutput(person[first_class], first_class, "first");
						} else {
							cout<<"NEXT FLIGHT LEAVES IN 3 HOURS"<<endl;
						}
					} else {
						// prompt the user name,sex , age and passport number
						detailsInput(person[economic_class]);
						//display boarding pass according to the user information
						detailsOutput(person[economic_class],economic_class,"economy");
					}
				} else {
					cout<<"Invalid input please enter 1 or 2";
				}
				pauseClean();
}}

void detailsInput(customer& person){
	cout<<"\nEnter your name please : ";
	cin.ignore();
	getline(cin, person.name);
	cout<<"Enter your sex (m/f) : ";
	cin>>person.sex;
	cout<<"Enter your age : ";
	cin>>person.age;
	cout<<"Enter your passport : ";
	cin>>person.passport;
	cout<<"\n";
}

void detailsOutput(customer& person, int& seatNum, string section){
	//display boarding pass according to the user information
	cout<<"\t******* Boarding pass **********"<<endl;
	cout<<"\t* Name : "<<person.name<<endl;
	cout<<"\t* Sex  : "<<person.sex<<endl;
	cout<<"\t* Age  : "<<person.age<<endl;
	cout<<"\t* Passport number  : "<<person.passport<<endl;
	cout<<"\t*-------------------------------"<<endl;
	cout<<"\t* Seat number : "<< ++seatNum<<endl;
	cout<<"\t*Section: "<<section<<"               " << endl;
	cout<<"\t*Enjoy your flight!             " << endl;
	cout<<"\t*-------------------------------"<<endl;
	cout<<"\t*********************************\n"<<endl;
}

void main_choice2(customer person[]){
	// declaration and initialization variables and strings for passport searching
			int idx;
			colorClean("color 06");
			string tobesearched_passport;
			cout<<"please enter the passport "<<endl;
			cin>>tobesearched_passport;
			bool passport_found= false;

			//search among all alternative
			for(int i=0 ; i<100 ; i++) {
				if(person[i].passport == tobesearched_passport) {
					idx=i;
					passport_found=true;
					break;
				}
			}

			//display if the input passport is found
			if(passport_found) {
				colorClean("color 02");
				cout<<endl;
				cout << "\t\nPassport Found!"<<endl<<endl;
				cout<<"\t-------------------------------------------"<<endl;
				display2(person, idx);
			} else {
				// display the output prompt with red color if passport is not found
				system("CLS");
				system("color 04");
				cout<<"\n\t*************************************************************"<<endl;
				cout <<"\tPassport Not Found !"<<endl;
				cout<<"\t*************************************************************\n"<<endl;
			}
			pauseClean();
}

void display2(customer person[], int idx){
		cout<<"\t* Name : "<<person[idx].name<<endl;
		cout<<"\t* Sex  : "<<person[idx].sex<<endl;
		cout<<"\t* Age  : "<<person[idx].age<<endl;
		cout<<"\t* Passport number  : "<<person[idx].passport<<endl;
		cout<<"\t*-------------------------------"<<endl;
		cout<<"\t* Seat number : "<< ++idx<<endl;
	if(idx < 30)
		cout<<"\t*Section: first               " << endl;
	else
		cout<<"\t*Section: Economy               " << endl;
		cout<<"\t*Enjoy your flight!             " << endl;
		cout<<"\t*-------------------------------"<<endl;
		cout<<"\t*********************************\n"<<endl;
}

void main_choice3(customer person[]){
			colorClean("color 09");
			for(int i = 0; i < 100; i++) {
				if(person[i].name.size() != 0){
					cout<<"\n";
					cout<<"\t******* Boarding pass **********"<<endl;
					display2(person, i);
				}
		}
				cout<<"\n-------------------------------------------------"<<endl;
				pauseClean();
}

void pauseClean(){
	system("pause");
	system("CLS");
}

void colorClean(char color[]){
	system(color);
	system("CLS");
}

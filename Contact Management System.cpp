
#include <iostream>
#include <string>
using namespace std;

struct Contact{

	string contactName;
	string contactNum;
	string contactEmail;

	Contact* next; // a node to point on the next node, create a link list

	Contact(string contactName, string contactNum, string contactEmail) :
			contactName(contactName), contactNum(contactNum), contactEmail(contactEmail), next(NULL){}

};

class ContactList{

	private:
		Contact* head; // point to the first node/customer

	public:

		ContactList() : head(NULL){}

		void addContact(string& contactName, string& contactNum, string& contactEmail){

			Contact* newContact = new Contact(contactName, contactNum, contactEmail);
			newContact -> next = head; // new contact point to head, new contact is added into link list
			head = newContact; // head point to new contact
			cout << "Contact successfully added.\n";

		}

		void deleteContact(string& contactName){

			Contact* current = head; // start from head/first customer
			Contact* previous = NULL;

			while(current != NULL && current -> contactName != contactName){
				// if (current == NULL) meaning we had reached the end of the link list
				// loop will end if we reach the end of the link list or we found the contact in our link list
				previous = current;
				current = current -> next;

			}

			if(current == NULL){
				cout << "***Contact not found.***\n";
				return;
			}

			if(previous == NULL){
				head = current -> next;
			}
			else{
				previous -> next = current -> next;
			}

			delete current;

			cout << "Contact '" << contactName << "' had successfully deleted.\n";

		}

		Contact* searchNumber(string& contactNum){

			Contact* current = head; // start from head/first contact

			while(current != NULL){
				// loop will end if current node is NULL and meaning that the contact is not found in the link list
				if(current -> contactNum == contactNum) return current;
				current = current -> next;
			}

			return NULL;

		}

		Contact* searchName(string& contactName){

			Contact* current = head;

			while(current != NULL){
				if(current -> contactName == contactName) return current;
				current = current -> next;
			}

			return NULL;
		}

		void displayContact(){

			int i = 0;
			Contact* current = head;

			cout << "------------------------------------\n";
			cout << "|           CONTACT LIST           |\n";
			cout << "------------------------------------\n";

			while(current != NULL){

				cout << "Contact Name: " << current -> contactName << endl;
				cout << "Contact Number: " << current -> contactNum << endl;
				cout << "Email Address: " << current ->contactEmail << endl;
				cout << "------------------------------------\n";
				i++;
				current = current -> next;

			}

			cout << "Total: " << i << " contact(s).\n";
			cout << "------------------------------------\n";

		}

};

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {

	ContactList contactList;
	string name, num, email;
	int choice;
	char cont;

	clearConsole();

	while(true){

		cout << "-------------------------------------\n";
		cout << "|     CONTACT MANAGEMENT SYSTEM     |\n";
		cout << "-------------------------------------\n";
		cout << "|[1]Add Contact                     |\n";
		cout << "|[2]Delete Contact                  |\n";
		cout << "|[3]Search Contact by Name          |\n";
		cout << "|[4]Search Contact by Number        |\n";
		cout << "|[5]Display Contact List            |\n";
		cout << "|[6]Exit Program                    |\n";
		cout << "-------------------------------------\n";
		cout << "Enter [#] to select: ";

		cin >> choice;

		switch(choice){
		case 1:
			cout << "Enter Contact Name: ";
			cin.ignore();
			getline(cin, name);
			cout << "Enter Contact Number: ";
			getline(cin, num);
			cout << "Enter Contact E-mail: ";
			getline(cin, email);

			contactList.addContact(name, num, email);

			break;

		case 2:
			cout << "Enter Contact's Name to Delete: ";
			cin.ignore();
			getline(cin, name);

			contactList.deleteContact(name);

			break;

		case 3:
			cout << "Enter Contact's Name to Search: ";
			cin.ignore();
			getline(cin, name);

			if(Contact* contact = contactList.searchName(name)){
				cout << "***         Contact Found         ***\n";
				cout << "Contact Name: " << contact -> contactName << endl;
				cout << "Contact Number: " << contact -> contactNum << endl;
				cout << "Contact E-mail: " << contact -> contactEmail << endl;
			}
			else{
				cout << "***       Contact Not Found       ***\n";
			}

			break;

		case 4:
			cout << "Enter Contact's Number to Search: ";
			cin.ignore();
			getline(cin, num);

			if(Contact* contact = contactList.searchNumber(num)){
				cout << "***         Contact Found         ***\n";
				cout << "Contact Name: " << contact -> contactName << endl;
				cout << "Contact Number: " << contact -> contactNum << endl;
				cout << "Contact E-mail: " << contact -> contactEmail << endl;
			}
			else{
				cout << "***       Contact Not Found       ***\n";
			}

			break;

		case 5:
			clearConsole();
			contactList.displayContact();

			break;

		case 6:
			clearConsole();
			cout << "-------------------------------------\n";
			cout << "|             Exiting...            |\n";
			cout << "-------------------------------------\n";
			return 0;

		default:
			cout << "\n***INVALID INPUT***\n";
			break;

		} //switch

		cout << "Continue? [Y/N]: ";
		cin >> cont;

		if(toupper(cont) == 'Y' ){
			clearConsole();
		}
		else {
			clearConsole();
			cout << "-------------------------------------\n";
			cout << "|             Exiting...            |\n";
			cout << "-------------------------------------\n";
			return 0;
		}

	} //main

	return 0;
}

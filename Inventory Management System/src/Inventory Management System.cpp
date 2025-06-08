#include <iostream>
#include <stack>
#include <string>
#include <iomanip>

using namespace std;

// create a class for item which include item name and quantity
class Item {
public:
    string name;
    int quantity;
    Item(string name, int quantity) : name(name), quantity(quantity) {}
};

class Inventory {
private:
    stack<Item> inventoryStack;

public:
    // Add a new item to the inventory
    void addItem(string name, int quantity) {
        Item newItem(name, quantity);
        inventoryStack.push(newItem);
        cout << "Item '" << name << "[" << quantity << "]' added to the inventory." << endl;
    }

    // Withdraw an item from the inventory and sell
	void withdrawItem(string item, int quantity){
		stack <Item> tempStack; // create temporary stack to hold the item that doesn't match the user input
		bool itemFound = false; // use to check whether the item is availble or the quantity of the item is enough for user withdraw

		// using .empty() as a condition in while loop
		while(!inventoryStack.empty()){
			Item currentItem = inventoryStack.top(); // store the item which at top in the main stack
			inventoryStack.pop(); // pop the item from main stack, so we can continue check on the next item in main stack

			if(currentItem.name == item && currentItem.quantity >= quantity){
				currentItem.quantity -= quantity;
				tempStack.push(currentItem);
				itemFound = true;
				cout << "Item '" << currentItem.name << " [" << quantity << "]' successfully withdrawn from inventory." << endl;
				break;
			}
			else{
				tempStack.push(currentItem);
			}

		}

		// this is use to push the item from the temporary stack back into main stack
		while(!tempStack.empty()){
			inventoryStack.push(tempStack.top());
			tempStack.pop();
		}

		if(!itemFound){
			cout << "Item '" << item << "' not found or insufficient quantity." << endl;
		}

	}


    void displayStock() {
		cout << "------------------------------------\n";
		cout << "|            YOUR STOCK            |\n";
		cout << "------------------------------------\n";
        if (inventoryStack.empty()) {
            cout << left << setw(34) << "| Your inventory is empty." << " |" << endl;
        } else {
        	cout << left << setw(20) << "| ITEM" << left << setw(15) << "QUANTITY" << "| "  << endl;
            stack<Item> displayStack = inventoryStack; // duplicate a stack from main stack,
            										  // so we can display the stack using the duplicated stack instead

            while (!displayStack.empty()) {
                Item currentItem = displayStack.top();

                // if item quantity below or equal to 3, a warning message will be display to alert user that specific product is running low on stock
                if(currentItem.quantity <= 3){
                    cout << "| " << left << setw(18) << currentItem.name << left << setw(15) << currentItem.quantity << "| " << "*[Warning]Stock running low!*"<< endl;
                }
                else{
                	cout << "| " << left << setw(18) << currentItem.name << left << setw(15) << currentItem.quantity << "| "  << endl;
                }
                displayStack.pop();
            }
        }

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
    Inventory storeInventory;
    int choice;
    string itemName;
    int itemQuantity;
    char cont;

    clearConsole();

    while (true) {
		cout << "-------------------------------------\n";
		cout << "|    INVENTORY MANAGEMENT SYSTEM    |\n";
		cout << "-------------------------------------\n";
		cout << "|[1]Add Item                        |\n";
		cout << "|[2]Withdraw Item                   |\n";
		cout << "|[3]Display Inventory               |\n";
		cout << "|[4]Exit Program                    |\n";
		cout << "-------------------------------------\n";
		cout << "Enter [#] to select: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item name: ";
                cin.ignore();
                getline(cin,itemName);
                cout << "Enter item quantity: ";
                cin >> itemQuantity;
                storeInventory.addItem(itemName, itemQuantity);

                break;


            case 2:
            	storeInventory.displayStock();
                cout << "Enter item name: ";
                cin.ignore();
                getline(cin,itemName);
                cout << "Enter item quantity: ";
                cin >> itemQuantity;
                storeInventory.withdrawItem(itemName, itemQuantity);


                break;

            case 3:
                storeInventory.displayStock();

                break;

            case 4:
    			system("clear");
    			cout << "-------------------------------------\n";
    			cout << "|             Exiting...            |\n";
    			cout << "-------------------------------------\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

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
    }

    return 0;
}

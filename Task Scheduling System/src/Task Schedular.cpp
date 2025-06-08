#include<iostream>
#include<string>
using namespace std;

struct Task{

	string name; // name of task
	int days; // remaining days to deadline

	Task* left; // store smaller value
	Task* right; // store larger value

	Task(string n, int d) : name(n), days(d), left(NULL), right(NULL){}

};

class Schedular{

private:
	Task* root;

	Task* addTask(Task* root, string name, int days){ // user can add task and the remaining days for the task to complete

		if(root == NULL){ // if the current node is NULL, the task will added to the node
			return new Task(name, days);
		}
		if(days < root -> days){ // if the data value is smaller than the root / parent node,
			root -> left = addTask(root -> left, name, days); // using recursive method to find a NULL node
		}
		else if(days > root -> days){ // if the data value is larger than the root / parent node,
			root -> right = addTask(root -> right, name, days);
		}

		return root; // return root is to maintains the integrity and correctness of the binary search tree structure after each operation.

	}

	Task* findMin(Task* root){ //findMin() is used while we want to delete a node
		// we will only need to check the left side node
		while(root -> left != NULL){ // while the left side of a node is NULL, meaning that the current node is the smallest
			root = root -> left;
		}

		return root;

	}

	Task* deleteTask(Task* root, string name){

		if(root == NULL){ // This handles the case when the tree is empty or when the node to be deleted is not found.
			return root;
		}
		if(name < root -> name){
			root -> left = deleteTask(root -> left, name);
		}
		else if(name > root -> name){
			root -> right = deleteTask(root -> right, name);
		}
		else{
			// the delete node is found and the node has no or only one children
        	// the children node will replace the deleted node
			if(root -> left == NULL){
					Task* temp = root -> right;
					delete root;
					return temp;
				}
				else if(root -> right == NULL){
					Task* temp = root -> left;
					delete root;
					return temp;
				}
            //below is to handle when the delete node has two children node
            // find the leftmost node in the right children node and the leftmost node will replace the deleted node
				Task* temp = findMin(root -> right);
				root -> name = temp -> name;
				root -> days = temp -> days;
				root -> right = deleteTask(root -> right, temp -> name);

			}

		return root;

	}

	Task* searchTask(Task* root, string name){ // search task by using task name

		if(root == NULL) return NULL;
		if(root -> name == name) return root;
		if(name < root -> name) return searchTask(root -> left, name);
		return searchTask(root -> right, name);

	}

	void inorderTraversal(Task* root){
		// left subtree > root > right subtree
		if(root != NULL){
			inorderTraversal(root -> left);
			cout << "Task: " << root -> name << " (Remaining days: " << root -> days << ")" << endl;
			inorderTraversal(root -> right);
		}

	}

	void preorderTraversal(Task* root){
		// root > left subtree > right subtree
		if(root != NULL){
			cout << "Task: " << root -> name << " (Remaining days: " << root -> days << ")" << endl;
			preorderTraversal(root -> left);
			preorderTraversal(root -> right);
		}

	}

	void postorderTraversal(Task* root){
		// left subtree > right subtree > root
		if(root != NULL){
			postorderTraversal(root -> left);
			postorderTraversal(root -> right);
			cout << "Task: " << root -> name << " (Remaining days: " << root -> days << ")" << endl;
		}
	}

public:
	Schedular() : root(NULL){}

	void add(string name, int days){
		root = addTask(root, name, days);
		cout << "Task [" << name << "] added." << endl;
	}

	void remove(string name){
		root = deleteTask(root, name);
		cout << "Task [" << name << "] removed." << endl;
	}

	bool search(string name){
		Task* foundTask = searchTask(root, name);
		if(foundTask){
			cout << "Task [" << name << "] found, remaining [" << foundTask -> days <<"] days" << endl;
			return true;
		}
		else{
			cout << "Task '" << name << "' not found." << endl;
			return false;
		}
	}

	void inorder(){
		cout << "In-order Traversal:" << endl;
		inorderTraversal(root);
		cout << endl;
	}

	void preorder(){
		cout << "Pre-order Traversal:" << endl;
		preorderTraversal(root);
		cout << endl;
	}

	void postorder(){
		cout << "Post-order Traversal:" << endl;
		postorderTraversal(root);
		cout << endl;
	}

};

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main(){

	Schedular schedular;
	int choice;
	string name;
	int days;
	char cont;

	while(true){

		cout << "-------------------------------------\n";
		cout << "|      TASK SCHEDULING SYSTEM       |\n";
		cout << "-------------------------------------\n";
		cout << "|[1]Add Task                        |\n";
		cout << "|[2]Remove Task                     |\n";
		cout << "|[3]Search Task by Name             |\n";
		cout << "|[4]Display Task : In-order         |\n";
		cout << "|[5]Display Task : Pre-order        |\n";
		cout << "|[6]Display Task : Post-order       |\n";
		cout << "|[7]Exit Program                    |\n";
		cout << "-------------------------------------\n";
		cout << "Enter [#] to select: ";

		cin >> choice;

		switch(choice){
		case 1:

			cout << "Enter Task Name: ";
			cin.ignore();
			getline(cin, name);
			cout << "Enter Remaining Days: ";
			cin >> days;

			schedular.add(name, days);

			break;

		case 2:

			cout << "Enter Task's Name to Delete: ";
			cin.ignore();
			getline(cin, name);

			schedular.remove(name);

			break;

		case 3:

			cout << "Enter Task's Name to Search: ";
			cin.ignore();
			getline(cin, name);

			schedular.search(name);

			break;

		case 4:

			schedular.inorder();

			break;

		case 5:

			schedular.preorder();

			break;

		case 6:

			schedular.postorder();

			break;

		case 7:

			clearConsole();
			cout << "-------------------------------------\n";
			cout << "|             Exiting...            |\n";
			cout << "-------------------------------------\n";

			return 0;

		default:
			cout << "\n***INVALID INPUT***\n";

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




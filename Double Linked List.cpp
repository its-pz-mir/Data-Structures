#include <iostream>
#include <conio.h>
using namespace std;

class Node {
	public:
		Node *prev_add;
		int data;
		Node *next_add;
};


class Double_Linked_List {
	public:
		Node *head = NULL;
		Node *tail = NULL;
		// Insert Function
		void insert() {
			int n;
			cout << "\n\n Enter the value : ";
			cin >> n;
			Node * new_node = new Node;
			new_node -> prev_add = NULL;
			new_node -> data = n;
			new_node -> next_add = NULL;
			if(head == NULL) {
				head = new_node;
				tail = new_node;
			} else {
				tail -> next_add = new_node;
				new_node -> prev_add = tail;
				tail = new_node;
			}
			cout << "\n\n New node inserted Successfully...";
		}

		// Count Function

		void count() {
			if(head == NULL) {
				cout << "\n\n Linked List is empty";
			} else {


				int n = 0;
				Node *ptr = head;
				while(ptr != NULL) {
					n++;
					ptr = ptr -> next_add;
				}
				cout << "\n\n Total Nodes are " << n;
			}
		}

		// Search Function

		void search() {
			if(head == NULL) {
				cout << "\n\n Linked list is empty";
			} else {
				int n, found = 0;
				cout << "\n\n Enter the Value to Search : ";
				cin >> n;
				Node *ptr = head;
				while(ptr != NULL) {
					if(n == ptr->data) {
						cout << "\n\n value is found...";
						found++;
						break;
					}
					ptr = ptr -> next_add;
				}
				if(found == 0) {
					cout << "\n\n Value " << n << "can't found";
				}
			}
		}

		// Update Function

		void update() {
			if(head == NULL) {
				cout << "\n\n Linked list is empty";
			} else {
				int n, found = 0;
				cout << "\n\n Enter the Value for Updation";
				cin >> n;
				Node *ptr = head;
				while(ptr != NULL) {
					if(n == ptr->data) {
						cout << "\n\n Enter the new Value";
						cin >> ptr -> data;
						cout << "\n\n Value Updated Successfully...";
						found++;
						break;
					}
					ptr = ptr -> next_add;
				}
				if(found == 0) {
					cout << "\n\n The value "<< n << "can't found";
				}
			}
		}

		void del() {
			if(head == NULL) {
				cout << "\n\n Linked List is empty...";
			} else {
				int n,found = 0;
				cout << "Enter the Value of Deletion : ";
				cin >> n;
				if(head == tail && n == head -> data) {
					Node *ptr = head;
					head = NULL;
					tail = NULL;
					delete ptr;
					found++;
					cout << "\n\n Node Deleted Successfully";
				} else if(n == head ->data) {
					Node *ptr = head;
					head = head -> next_add;
					delete ptr;
					found ++;
					cout << "\n\n Node Deleted Successfully";
				} else if(n == tail -> data) {
					Node *ptr = tail;
					tail = tail -> prev_add;
					delete ptr;
					found ++;
					cout << "\n\n Node Deleted Successfully";
				} else {
					Node *pre_ptr = head;
					Node *ptr = head -> next_add;
					Node *next_ptr = ptr -> next_add;
					while(ptr -> next_add != NULL) {
						if(n == ptr -> data) {
							pre_ptr -> next_add = next_ptr;
							next_ptr -> prev_add = pre_ptr;
							delete ptr;
							found++;
							cout << "\n\n Node Deleted Successfully";
							break;
						}
						pre_ptr = ptr;
						ptr = next_ptr;
						next_ptr = next_ptr -> next_add;
					}

					if(found == 0) {
						if(n == ptr -> data) {
							tail = tail -> prev_add;
							delete ptr;
							found++;
							cout << "\n\n Node Deleted Successfully";
						}
					}
				}

				if(found == 0) {
					cout << "\n\n The value "<< n << "can't found";
				}
			}
		}
		
		void show_for(){
			cout << "\n\n";
			Node *ptr = head;
			while(ptr != NULL){
				cout << " " << ptr -> data;
				ptr = ptr -> next_add;
			}
		}
		
		void show_rev(){
			cout << "\n\n";
			Node *ptr = tail;
			while(ptr != NULL){
				cout << " " << ptr -> data;
				ptr = ptr -> prev_add;
			}
		}

};

int main() {
Double_Linked_List obj;

p:
system("cls");

int choice;
cout << "\n\n 1. Insert Node.";
cout << "\n\n 2. Count Nodes.";
cout << "\n\n 3. Search Node.";
cout << "\n\n 4. Update Node.";
cout << "\n\n 5. Delete Node.";
cout << "\n\n 6. Show Forward Node.";
cout << "\n\n 7. show Backward Node.";
cout << "\n\n 8. Exit";
cout << "\n\n\n Your Choice.";
cin >> choice;
switch(choice){
	case 1:
		obj.insert();
		break;
	case 2:
		obj.count();
		break;
	case 3:
		obj.search();
		break;
	case 4:
		obj.update();
		break;
	case 5:
		obj.del();
		break;
	case 6:
		obj.show_for();
		break;
	case 7:
		obj.show_rev();
		break;
	case 8:
		exit(0);
	default:
		cout << "\n\n Enter the correct Value...";
}

getch();
goto p;

return 0;
}

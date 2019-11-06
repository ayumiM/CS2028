// lab7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

//Linked list class
template <class T>
class LList {
private:
	struct ListNode {
		T value;
		struct ListNode* next;
	};

	ListNode* head;

	//object for seenext and seeat function
	ListNode* P = head;

public:

	//constructor
	LList() {
		head = NULL;
	}

	//destructor
	~LList() {
		ListNode* nodePtr;
		ListNode* nextNode;

		nodePtr = head;

		while (nodePtr != NULL) {
			nextNode = nodePtr->next;
			delete nodePtr;
			nodePtr = nextNode;
		}
	};

	//addItem function
	void AddItem(T num) {
		ListNode* newNode;
		ListNode* Nodeptr;

		newNode = new ListNode;
		newNode->value = num;
		newNode->next = NULL;

		if (!head) {
			head = newNode;
		}
		else {
			Nodeptr = head;
			while (Nodeptr->next) {
				Nodeptr = Nodeptr->next;
			}
			Nodeptr->next = newNode;
		}
	}

	//Getitem function
	T GetItem(T item) {
		ListNode* nodePtr;
		ListNode* previous = NULL;
		ListNode* temp = NULL;

		if (!head) {
			throw logic_error("The list is empty");
		}
		if (head->value == item) {
			//temp->value = head;
			nodePtr = head->next;
			temp = head;
			delete head;
			head = nodePtr;

			//previous= head->value;
		}
		else {
			nodePtr = head;
			while (nodePtr != NULL && nodePtr->value != item) {
				previous = nodePtr;
				nodePtr = nodePtr->next;
			}
			if (nodePtr) {

				previous->next = nodePtr->next;
				temp = nodePtr;
				delete nodePtr;
				//return temp;
			}

		}
		return temp->value;
	}

	//isinlist function
	bool IsInlist(T item) {
		ListNode* nodePtr;


		if (!head) {
			return false;
		}
		else {
			nodePtr = head;
			while (nodePtr->next) {
				if (nodePtr->value == item) {
					return true;
					break;
				}

				nodePtr = nodePtr->next;
			}
			return false;
		}

	}

	//isempty function
	bool isEmpty() {
		if (!head) {
			return true;
		}
		else {
			return false;
		}
	}

	//size funciton
	int size() {
		ListNode* nodePtr;
		int count = 0;
		if (!head) {
			return 0;
		}
		else {
			nodePtr = head;
			while (nodePtr != NULL) {
				count++;
				nodePtr = nodePtr->next;

			}
			return count;
		}
	}

	//seenext function
	T SeeNext() {
		ListNode* nodePtr = P;
		if (!head) {
			throw logic_error("No node");
		}
		if (P == head) {
			P = P->next;
			return head->value;
		}
		else if (P == NULL) {
			Reset();
			return P->value;
		}
		else {
			P = P->next;
			return nodePtr->value;

		}
	}

	//seeat function
	T SeeAt(int pos) {
		ListNode* nodePtr = P;
		int count = 0;
		//LList* num;
		if (!head) {
			throw logic_error("Empty");
		}
		else if (pos > size() - 1 || pos < 0) {
			throw logic_error("Index invalid");
		}
		else {
			nodePtr = head;
			while (nodePtr->next != NULL) {
				if (count == pos) {
					P = nodePtr;
					return nodePtr->value;
					break;
				}
				nodePtr = nodePtr->next;
				count++;
			}


		}
	}

	//reset function
	void Reset() {
		P = head;
	}



	//overloaded == operator
	bool operator == (LList<T>& other) const {
		ListNode* temp;
		ListNode* current;
		current = head;
		temp = other.head;
		while (other.head != NULL && current != NULL) {
			if (current->value != temp->value) {
				return false;
			}
			current = current->next;
			temp = temp->next;
		}
		return true;
	}

	bool operator != (LList<T>& other) const {
		ListNode* temp;
		ListNode* current;
		current = head;
		temp = other.head;
		while (other.head != NULL && current != NULL) {
			if (current->value == temp->value) {
				return false;
			}
			current = current->next;
			temp = temp->next;
		}
		return true;
	}

	//overloaded < operator
	bool operator < (LList<T>& other) const {
		ListNode* temp;
		ListNode* current;
		current = head;
		temp = other.head;
		while (other.head != NULL && current != NULL) {
			if (current->value >= temp->value) {
				return false;
			}
			current = current->next;
			temp = temp->next;
		}
		return true;
	}

	//overloaded > operator
	bool operator > (LList<T>& other) const {
		ListNode* temp;
		ListNode* current;
		current = head;
		temp = other.head;
		while (other.head != NULL && current != NULL) {
			if (current->value <= temp->value) {
				return false;
			}
			current = current->next;
			temp = temp->next;
		}
		return true;
	}

	//    friend ostream& operator<<(ostream& output, const LList& I) {
	//            output << "Item value: " << I << endl;
	//            return output;
	//        }



};

//task 2. Item class
class Item {
private:
	double PartNumber;
	string Description;
	double Price;
	string UOM;
	int QualityOnHand;
	int LeadTime;

public:
	//constructor
	Item() {
		PartNumber = 0;
		Description = " ";
		Price = 0;
		UOM = " ";
		QualityOnHand = 0;
		LeadTime = 0;
	}

	//constructor
	Item(double PN, string D, double P, string U) {
		PartNumber = PN;
		Description = D;
		Price = P;
		UOM = U;
		QualityOnHand = 0;
	}

	//constructor
	Item(double PN) {
		PartNumber = PN;
	}
	//getpartinfo function
	string GetPartInfo() {
		string info;
		info = to_string(PartNumber);
		return info + " " + Description;
	}

	//getprice function
	double GetPrice() {
		return Price;
	}

	//instock function
	bool InStock() {
		if (QualityOnHand > 0) {
			return true;
		}
		else {
			false;
		}
	}

	//available function
	bool Available(int date) {
		if (QualityOnHand > 0) {
			return true;
		}
		else {
			if (date > LeadTime) {
				return true;
			}
			else {
				return false;
			}
		}
	}

	//overloaded operator
	bool operator == (const Item& other) {
		return (PartNumber == other.PartNumber);
	}
	bool operator != (const Item& other) {
		return (other.PartNumber != PartNumber);
	}

	bool operator < (const Item& other) {
		return (other.PartNumber < PartNumber);
	}

	bool operator > (const Item& other) {
		return (other.PartNumber > PartNumber);
	}

	//friend operator to print out item
//    friend ostream& operator<<(ostream& output, const Item& I) {
//        output << "Item value: " << I << endl;
//        return output;
//    }
};



int main()
{
	LList<int> mylist;
	mylist.AddItem(1);
	mylist.AddItem(10);
	mylist.AddItem(15);
	mylist.AddItem(25);
	cout << "Size is " << mylist.size() << endl;
	//mylist.PrintList();
	cout << endl;
	//mylist.GetItem(1);
	//cout << mylist.IsInlist(0) << endl;

	//mylist.SeeAt(1);
	//mylist.PrintList();

	LList<Item> ItemList;
	Item j, i;
	ItemList.AddItem(j);
	ItemList.AddItem(i);

	char Uchoice = 'v';
	double partnumber;
	string description;
	double price;
	string uom;


	while (Uchoice != 'q') {
		cout << "Which function would you like to try?" << endl;
		cout << "AddItem - 'a'" << endl;
		cout << "GetItem - 'b'" << endl;
		cout << "IsInList - 'c' " << endl;
		cout << "IsEmpty - 'd'" << endl;
		cout << "Size - 'e'" << endl;
		cout << "SeeNext - 'f' " << endl;
		cout << "SeeAt - 'g' " << endl;
		cout << "Reset - 'h'" << endl;
		cout << "Or enter 'q' to quit" << endl;
		cout << "Enter alphabet: ";


		cin >> Uchoice;
		cout << endl;

		switch (Uchoice)
		{
		case 'a': {
			cout << "Enter partnumber, description, price, and unit of measure. " << endl;
			cout << "Part number (string): ";
			cin >> partnumber;
			cout << "Description (string): ";
			cin >> description;
			cout << "Price (double): ";
			cin >> price;
			cout << "Unit of measure (string): ";
			cin >> uom;
			Item I(partnumber, description, price, uom);
			ItemList.AddItem(I);
			//cout<<ItemList<<endl;

			//ItemList.PrintList();
			cout << endl;
			break;
		}
		case 'b': {
			double pa;
			cout << "Enter part number: ";
			cin >> pa;

			Item It(pa);


			cout << ItemList.GetItem(It).GetPartInfo() << endl;
			cout << endl;
			break;
		}
		case 'c': {
			cout << "Enter the item part number which you would like to see?: ";
			cin >> partnumber;
			bool list = ItemList.IsInlist(partnumber);
			if (list == true) {
				cout << partnumber << " is in the list" << endl;
			}
			else {
				cout << partnumber << " is not in the list" << endl;
			}
			cout << endl;
			break;
		}

		case 'd': {
			bool E = ItemList.isEmpty();
			if (E == true) {
				cout << "The list is empty" << endl;
			}
			else {
				cout << "The list is not empty" << endl;
			}
			cout << endl;
			break;
		}
		case 'e': {
			int S = ItemList.size();
			cout << "The list size is " << S << endl;
			cout << endl;
			break;
		}
		case 'f': {
			cout << ItemList.SeeNext().GetPrice() << endl;
			cout << endl;
			break;
		}
		case 'g': {
			int position;
			cout << "Enter the item location which you would like to check: ";
			cin >> position;
			//Item see;
			ItemList.SeeAt(position);
			//cout<<ItemList.SeeAt(position).GetPrice();
			//cout << see << endl;
			cout << endl;
			break;
		}
		case 'h': {
			ItemList.Reset();
			cout << endl;
			break;
		}
		default: {
			cout << "Choose from a to h" << endl;
			cout << endl;
			break;
		}
		}
	}
	std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

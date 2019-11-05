#include <iostream>

using namespace std;

template <class T>
class LList {
private:
	struct ListNode {
		T value;
		struct ListNode* next;
	};

	ListNode* head;
	ListNode* P = head;

public:
	class NoNode{};

	LList() {
		head = NULL;
	}
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

	LList::ListNode* GetItem(T item) {
		ListNode* nodePtr;
		ListNode* previous = NULL;
		ListNode* temp;

		if (!head) {
			throw "Error";
		}
		if (head->value == item) {
			//temp->value = head;
			nodePtr = head->next;
			temp = head;
			delete head;
			head = nodePtr;
			return temp;
			//previous= head->value;
		}
		else {
			nodePtr = head;
			while (nodePtr != NULL && nodePtr->value != item) {
				previous = nodePtr;
				nodePtr = nodePtr->next;
			}
			if (nodePtr->value == item) {
				temp = nodePtr;
				previous->next = nodePtr->next;
				delete nodePtr;
				return temp;
			}
			else {
				temp = NULL;
				return temp;
			}
		}

	}

	bool IsInlist(T item) {
		ListNode* nodePtr;
		ListNode* nextNode;

		if (!head) {
			return -1;
		}
		else {
			nodePtr = head;
			while (nodePtr->value != item && nodePtr->next != NULL) {
				nodePtr = nodePtr->next;
			}
				if (nodePtr->value = item) {
					return true;
				}
				else {
					return false;
				}

			}
		
	}

	bool isEmpty() {
		if (!head) {
			return true;
		}
		else {
			return false;
		}
	}

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

	LList::ListNode* SeeNext() {
		ListNode* nodePtr = P;
		if (!head) {
			throw logic_error("No node");
		}
		else if (P == NULL) {
			return NULL;
		}
		else {
			P = P->next;
			return P;
		}
	}

	LList::ListNode* SeeAt(int pos) {
		ListNode* nodePtr = P;
		int count = 0;
		//LList* num;
		if (pos > size()-1) {
			throw logic_error("Index invalid");
		}
		else {
			nodePtr = head;
			while (P->next != NULL) {
				if (count == pos) {
					return P->value;
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

	//print function 
	void PrintList() const{
		ListNode* nodePtr;
		nodePtr = head;

		while (nodePtr) {
			cout << nodePtr->value << endl;
			nodePtr = nodePtr->next;
		}
	}

	//overloaded == operator 
	bool operator == (LList<T> &other) const {
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

};

class Item {
private:
	string PartNumber;
	string Description;
	double Price;
	double UOM;
	int QualityOnHand;
	int LeadTime;

public:
	Item() {

	}


	Item(string PN, string D, double P, double U){
		PartNumber = PN;
		Description = D;
		Price = P;
		UOM = U;
		QualityOnHand = 0;
	}

	Item(string PN) {
		PartNumber = PN;
	}

	string GetPartInfo() {
		return PartNumber + " " + Description;
	}

	double GetPrice() {
		return Price;
	}

	bool InStock() {
		if (QualityOnHand > 0) {
			return true;
		}
		else {
			false;
		}
	}

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

	bool operator == (Item& other) {
		return (other.PartNumber == PartNumber);
	}
	bool operator != (Item& other) {
		return (other.PartNumber != PartNumber);
	}

	bool operator < (Item& other) {
		return (other.PartNumber < PartNumber);
	}

	bool operator > (Item& other) {
		return (other.PartNumber > PartNumber);
	}
};



int main()
{
	LList<int> mylist;
	mylist.AddItem(1);
	mylist.AddItem(10);
	mylist.AddItem(15);
	mylist.AddItem(25);
	cout << "Size is "<<mylist.size() << endl;
	mylist.PrintList();
	cout << endl;
	//mylist.GetItem(1);
	//cout << mylist.IsInlist(0) << endl;
	
	//mylist.SeeAt(1);
	mylist.PrintList();

	LList<Item> ItemList;
	char Uchoice;
	string partnumber;
	string description;
	double price;
	double uom;

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
			cout << "Part number: ";
			cin >> partnumber;
			cout << "Description: ";
			cin >> description;
			cout << "Price: ";
			cin >> price;
			cout << "Unit of measure: ";
			cin >> uom;
			Item I(partnumber, description, price, uom);
			ItemList.AddItem(I);
			//ItemList.PrintList();
			break;
		}
		case 'b': {
			cout << "Enter part number: ";
			cin >> partnumber;

			Item It(partnumber);
			ItemList.GetItem(It);
			break;
		}
		case 'c': {
			cout << "Enter the item part number which you would like to see?";
			cin >> partnumber;
			bool list = ItemList.IsInlist(partnumber);
			if (list == true) {
				cout << partnumber << " is in the list" << endl;
			}
			else {
				cout << partnumber << " is not in the list" << endl;
			}
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
			break;
		}
		case 'e': {
			int S = ItemList.size();
			cout << "The list size is " << S << endl;
			break;
		}
		case 'f': {
			//LList<Item>
		}
		case 'g': {
			int position;
			cout << "Enter the item location which you would like to check";
			cin >> position;
			ItemList.SeeAt(position);
			break;
		}
		case 'h': {
			ItemList.Reset();
		}
		default: {
			cout << "Choose from a to h" << endl;
			break;
		}
		}
	}
    std::cout << "Hello World!\n";
}

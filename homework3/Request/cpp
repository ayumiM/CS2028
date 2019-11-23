#include "Request.h"

#include <iostream>
#include <string>


using namespace std;

Request::Request() {
	head = nullptr;
}

Request::~Request() {
	RequestNode* nodePtr;
	RequestNode* nextNode;

	nodePtr = head;

	while (nodePtr != nullptr) {
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

void Request::appnedRequest(int R) {
	RequestNode* newNode;
	RequestNode* nodePtr;

	newNode = new RequestNode;
	newNode->value = R;
	newNode->next = nullptr;

	if (!head) {
		head = newNode;
	}
	else {
		nodePtr = head;
		while (nodePtr->next) {
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newNode;
	}
}

void Request::insertRequestGoUp(int R) {
	RequestNode* newNode;
	RequestNode* nodePtr;
	RequestNode* previousNode = nullptr;

	newNode = new RequestNode;
	newNode->value = R;

	if (!head) {
		head = newNode;
		newNode->next = nullptr;
	}
	else {
		nodePtr = head;
		previousNode = nullptr;

		while (nodePtr != nullptr && nodePtr->value < R) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (previousNode == nullptr) {
			head = newNode;
			newNode->next = nodePtr;
		}
		else {
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

void Request::insertRequestGoDown(int R) {
	RequestNode* newNode;
	RequestNode* nodePtr;
	RequestNode* previousNode = nullptr;

	newNode = new RequestNode;
	newNode->value = R;

	if (!head) {
		head = newNode;
		newNode->next = nullptr;
	}

	else {
		nodePtr = head;
		previousNode = nullptr;

		while (nodePtr != nullptr && nodePtr->value > R) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (previousNode == nullptr) {
			head = newNode;
			newNode->next = nodePtr;
		}
		else {
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}

}

void Request::deleteFirstRequest() {
	
	if (!head) {
		return;
	}
	else {
		RequestNode* temp = head;
		head = head->next;

		delete temp;
	}
}

void Request::deleteRequest(int R) {
	RequestNode* nodePtr;
	RequestNode* previousNode = nullptr;

	if (!head) {
		return;
	}

	if (head->value = R) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else {
		nodePtr = head;
		while (nodePtr != nullptr && nodePtr->value != R) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (nodePtr) {
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

void Request::displayRequest() {
	RequestNode* nodePtr;
	nodePtr = head;

	while (nodePtr) {
		cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}
	cout << endl;
}

bool Request::CheckRequest(int R) {
	RequestNode* nodePtr;

	if (!head) {
		return false;
	}
	else {
		nodePtr = head;
		while (nodePtr->next) {
			
			if (nodePtr->value == R) {
				return true;
			}
			nodePtr = nodePtr->next;
		}
	}
	return false;
}

int Request::getFloor() {
	//RequestNode* nodePtr;
	//int GoFloor;

	if (!head) {
		return homeFloor;
	}
	else {
		return head->value;
		
	}

}

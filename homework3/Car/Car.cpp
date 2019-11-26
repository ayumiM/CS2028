#include "Car.h"
#include "Request.h"

#include <iostream>
#include <vector>
#include <string>
#include <cmath>


int originalFloor = 3;

using namespace std;

Car::Car() {
	id = " ";
	currentLevel = 3;
	destinationLevel = 0;
}

//Car::Car(string i, int c, int d) {
//	id = i;
//	currentLevel = c;
//	destinationLevel = d;
//}

Car::~Car() {

}

void Car::setCarID(string i) {
	id = i;
}

string Car::getCarID() {
	return id;
}

void Car::setPassengercount() {
	passengerCount++;
}

int Car::getPassengercount() {
	return passengerCount;
}

void Car::setCurLevel(int c) {
	currentLevel = c;
}

int Car::getCurLevel() {
	return currentLevel;
}

void Car::setDestLevel(int d) {
	destinationLevel = d;
}

int Car::getDestLevel() {
	return destinationLevel;
}

string Car::getDirection() {
	if (currentLevel < destinationLevel) {
		Direction = "Up";
	}
	else if (currentLevel > destinationLevel) {
		Direction = "Down";
	}
	else {
		Direction = "Error";
	}
	//cout << Direction << endl;
	return Direction;
}

bool Car::directionisGood() {
	if (Direction == "Up" || Direction == "Down") {
		return true;
	}
	else {
		return false;
	}
}

void Car::PassengerRequest(int R) {
	bool check = CheckRequest(R);

	if (check == true) {
		cout << "Someone else already requested the floor" << endl;
	}
	else if (check == false) {
		if (getCurLevel() < getDestLevel()){
			insertRequestGoUp(R);
		}
		else if (getCurLevel() > getDestLevel()) {
			insertRequestGoDown(R);
		}
		cout << "Inserting your request" << endl;
	}
}

//void Car::addReq() {
//	// Elv.push_back(currentLevel);
//	Elv.push_back(destinationLevel);
//}

void Car::Move() {
	if (!directionisGood()) {
		cout << "Error. Elevator goes down or up" << endl;
		deleteFirstRequest();
	}
	else if (directionisGood() ) {
		if (Direction == "Up" && currentLevel > destinationLevel) {
			cout << "Sorry. The elevator is going up" << endl;
			deleteRequest(destinationLevel);
		}
		else if (Direction == "Down" && currentLevel < destinationLevel) {
			cout << "Sorry. The elevator is going down" << endl;
			deleteRequest(destinationLevel);
		}
		else {
			int Floordifference = abs(currentLevel - destinationLevel);
			for (int i = 0; i < Floordifference; i++) {
				CarMoveSenser();
			}
			tripCounter++;
			floorServedByTrip.push_back(originalFloor);
			floorServedByTrip.push_back(destinationLevel);
			//currentLevel = destinationLevel;
			cout << "The elevator is now in the " << currentLevel << " th fllor" << endl;
			deleteFirstRequest(); //request completed. delete first node
		}
	}

}

void Car::CarMoveSenser() {
	setCurLevel(currentLevel + 1);
}

double Car::PassengerWaitTime(int c, int o) {
	double FloorDifference = abs(c - o);
	double TravelForFloordiff = FloorDifference * moveOneFloorT;
	double accelerateTotal = accelerateUpT * FloorDifference;
	double decelerateTotal = decelerateUpT * FloorDifference;
	double wait = TravelForFloordiff + accelerateTotal + decelerateTotal;
	return wait;
}

double Car::countTime() {
	double FloorDifference = abs(destinationLevel - originalFloor);
	double TravelForFloordiff = FloorDifference * moveOneFloorT;
	double accelerateTotal = accelerateUpT * FloorDifference;
	double decelerateTotal = decelerateUpT * FloorDifference;
	double PassengerGetIn = passengerCount * PassengerGetInT;
	double Pbutton = passengerCount * PressButtonT;

	double totalTime = openDoorT + PassengerGetIn + Pbutton + closeDoorT + TravelForFloordiff + accelerateTotal +
		decelerateTotal + CarStopT + openDoorT;

	return totalTime;
}

void Car::DisplayResult() {
	cout << "Today's total trip was " << tripCounter << endl;
	cout << "This is the track of all the trips: " << endl;
	for (int i = 0; i < floorServedByTrip.size(); i++) {
		cout << floorServedByTrip.at(i) << "th floor" << endl;
	}
}

#include "Passenger.h"
#include "Car.h"




//I do not need down thing for homework 3 but still here for homework 4

Passenger::Passenger() {
	PID = 0;
	originFloor = 3;
	destFloor = 0;
	TimeOfRequest = 0;
	waitTime = 0;
	travelTime = 0;
	//destFloor = 0;
}

Passenger::Passenger(int p, int o) {
	PID = p;
	originFloor = o;
	setCurLevel(o);
	setCarID("CarA");

	//destFloor = d;

}

Passenger::~Passenger() {

}

int Passenger::getPID() {
	return PID;
}

void Passenger::SetHallwayUpButton() {
	PressUpButton(originFloor);
}

void Passenger::SetHallwayDownButton() {
	PressDownButton(originFloor);
}

void Passenger::PressCarButton(int X) {
	CompleteUpButton(); //when passemger press a car button, hallway button is completed 
	setdestinationFloor(X);
	setDestLevel(X);  //set destination floor for car class 
	//setCar(); //set a car
	int F = getdestinationFloor();
	PassengerRequest(F);
}

//void Passenger::setCar() {
	//int o = getoriginFloor();
	//int d = getdestinationFloor();
	//string carID = "CarA";
	//Car(carID, o, d);
//}


int Passenger::getoriginFloor() {
	return originFloor;
}

void Passenger::setdestinationFloor(int D) {
	destFloor = D;
}


int Passenger::getdestinationFloor() {
	return destFloor;
}

void Passenger::Travel() {
	getDirection();
	Move();
}

int Passenger::getTimeOfRequest() {
	return TimeOfRequest;
}

double Passenger::getTravelTime() {
	travelTime = countTime();
	return travelTime;
}

void Passenger::setWaitTime(int c, int o) {
	waitTime = PassengerWaitTime(c, o);
}

double Passenger::getWaitTime() {
	//waitTime = PassengerWaitTime(c, o);
	return waitTime;
}

void Passenger::travelsummary() {
	cout << "Passenger ID: " << getPID() << endl;
	cout << "Total wait time was: " << getWaitTime() << " seconds" << endl;
    cout <<"Total travel time was " << getTravelTime() << " seconds" << endl;
	cout << endl;
	
}

void Passenger::getSummary() {
	cout << getCarID() << " summary: \n";
	DisplayResult();
}

//void Passenger::PassengerRequest(int R) {
//	//Passenger P;
//	bool check = Request::CheckRequest(R);
//
//	if (check == true) {
//		cout << "Someone else already requested the floor" << endl;
//	}
//	else if (check == false) {
//		if (getoriginFloor() < getdestinationFloor()) {
//			Request::insertRequestGoUp(R);
//		}
//		else if (getoriginFloor() > getdestinationFloor()) {
//			Request::insertRequestGoDown(R);
//		}
//		cout << "Inserting your request" << endl;
//	}
//}

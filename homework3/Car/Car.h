#include <iostream>
#include <vector>
#include <string>

#include "Request.h"


using namespace std;

//the elevator is in the home floor(3rd floor) if it is not running for homwwork 3

class Car : public Request
{
private:
	string id;
	int tripCounter;
	vector<int> floorServedByTrip;
	int passengerCount = 0;

	//I made these. I don't know if I need them
	string Direction;
	int currentLevel;
	int destinationLevel;
	string move;
	//vector<int> Elv;


	//seconds 
	double openDoorT = 5; //seconds
	double PassengerGetInT = 2; //per person
	double PressButtonT = 2; //per person
	double closeDoorT = 5;
	double moveOneFloorT = 5; 
	double accelerateUpT = 2;
	double accelerateDownT = 2;
	double decelerateUpT = 2;
	double decelerateDownT = 2;
	double CarStopT = 3;

public:
	Car();
	//Car(string, int, int);
	~Car();
	void setCarID(string);
	string getCarID();
	void setPassengercount();
	int getPassengercount();
	void setCurLevel(int);
	int getCurLevel();
	void setDestLevel(int);
	int getDestLevel();
	string getDirection();
	bool directionisGood();

	void PassengerRequest(int);

	//void addReq();
	void Move();
	void CarMoveSenser();

	double PassengerWaitTime(int, int);
	double countTime();
	void DisplayResult();


};

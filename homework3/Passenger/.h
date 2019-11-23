#include "Hallway.h"
#include "Car.h"





//Base floor is 3rd for now
//only goes up 

class Passenger : public Hallway, public Car
{
private:
	int PID;
	int TimeOfRequest;
	int originFloor;
	int destFloor;
	double waitTime;
	double travelTime;

public:
	Passenger();
	Passenger(int, int);
	~Passenger();
	int getPID();

	
	void SetHallwayUpButton();
	void SetHallwayDownButton();

	void PressCarButton(int);
	//void setCar();
	void Travel();

	int getTimeOfRequest();
	int getoriginFloor();
	void setdestinationFloor(int);
	int getdestinationFloor();
	void setWaitTime(int, int);
	double getWaitTime();
	double getTravelTime();
	void travelsummary();
	//void PassengerRequest(int);
	void getSummary();
};

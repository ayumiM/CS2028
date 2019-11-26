#include <iostream>
#include <vector>
#include <string>
#include <time.h>

#include "Passenger.h"
#include "Car.h"
#include "Hallway.h"
#include "Request.h"

using namespace std;

//Just Up hallway button is usable for homework 3
//Passenger can push hallway button at 3rd floor 
//base floor and lowest floor 3rd 
//highest floor 7
//origin floor is always 3 for homework 3

int main()
{
	//base floor is 3rd 
	int originFloor = 3; 
	//int object for passenger id 
	int pcount = 1;

	//double vector object to get average waiting time 
	vector<double> waitingT;

	//double vector to get average travel time
	vector<double> travelT;

	Car C1;
	C1.setCarID("car1");

	//create passenger objects 
	Passenger P1 = Passenger(pcount, originFloor);
	//increase pcount to increase passenger id 
	pcount++; 
	Passenger P2 = Passenger(pcount, originFloor);
	pcount++; 
	Passenger P3 = Passenger(pcount, originFloor);
	pcount++; 
	Passenger P4 = Passenger(pcount, originFloor);
	pcount++;

	//create passenger vector to store passenger objects 
	vector<Passenger> PassengerVec = { P1, P2, P3, P4 };
	
	//P1
	int waitTforP1 = PassengerVec[0].getCurLevel();
	PassengerVec[0].SetHallwayUpButton();
	PassengerVec[0].setWaitTime(waitTforP1, originFloor);
	waitingT.push_back(PassengerVec[0].getWaitTime());
	PassengerVec[0].PressCarButton(5); //P1 goes to 5th floor
	PassengerVec[0].Travel();
	PassengerVec[0].travelsummary();
	travelT.push_back(PassengerVec[0].getTravelTime());

	//P2 
	PassengerVec[1].SetHallwayUpButton();
	//Assume P2 presss the hallway button when the elevator was on the 5th floor(P1's destination floor)
	int waitTforP2 = PassengerVec[0].getCurLevel();
	PassengerVec[1].setWaitTime(waitTforP2, originFloor);
	waitingT.push_back(PassengerVec[1].getWaitTime());
	PassengerVec[1].PressCarButton(7); //P2 goes to 7th floor
	PassengerVec[1].Travel();
	PassengerVec[1].travelsummary();
	travelT.push_back(PassengerVec[1].getTravelTime());

	//P3
	PassengerVec[2].SetHallwayUpButton();
	//Assume P3 presss the hallway button when the elevator is on the base floor
	int waitTforP3 = PassengerVec[2].getCurLevel();
	PassengerVec[2].setWaitTime(waitTforP3, originFloor);
	waitingT.push_back(PassengerVec[2].getWaitTime());
	PassengerVec[2].PressCarButton(4); //P3 goes to 4th floor
	PassengerVec[2].Travel();
	PassengerVec[2].travelsummary();
	travelT.push_back(PassengerVec[2].getTravelTime());

	//P4
	PassengerVec[3].SetHallwayUpButton();
	int waitTforP4 = PassengerVec[2].getCurLevel();
	PassengerVec[3].setWaitTime(waitTforP4, originFloor);
	waitingT.push_back(PassengerVec[3].getWaitTime());
	PassengerVec[3].PressCarButton(6); //P4 goes to 6th floor
	PassengerVec[3].Travel();
	PassengerVec[3].travelsummary();
	travelT.push_back(PassengerVec[3].getTravelTime());

	//Another passenger came P5
	Passenger P5 = Passenger(pcount, originFloor);
	pcount++; 
	PassengerVec.push_back(P5);
	PassengerVec[4].SetHallwayUpButton();
	//PassengerVec.push_back(P5);
	int waitTforP5 = PassengerVec[4].getCurLevel();
	PassengerVec[4].setWaitTime(waitTforP5, originFloor);
	waitingT.push_back(PassengerVec[4].getWaitTime());
	PassengerVec[4].PressCarButton(7); //P5 goes to 7
	PassengerVec[4].Travel();
	PassengerVec[4].travelsummary();
	travelT.push_back(PassengerVec[4].getTravelTime());

	//Another passenger came P6
	Passenger P6 = Passenger(pcount, originFloor);
	pcount++;
	PassengerVec.push_back(P6);
	PassengerVec[5].SetHallwayUpButton();
	int waitTforP6 = PassengerVec[4].getCurLevel(); //asumme P5 comes when the car is in the P4's destination floor
	PassengerVec[5].setWaitTime(waitTforP6, originFloor);
	waitingT.push_back(PassengerVec[5].getWaitTime());
	PassengerVec[5].PressCarButton(4); //P6 goes to 4
	PassengerVec[5].Travel();
	PassengerVec[5].travelsummary();
	travelT.push_back(PassengerVec[5].getTravelTime());

	//P7
	Passenger P7 = Passenger(pcount, originFloor);
	pcount++;
	PassengerVec.push_back(P7);
	PassengerVec[6].SetHallwayUpButton();
	int waitTforP7 = PassengerVec[5].getCurLevel(); // asumme P6 comes when the car is in the P5's destination floor
	PassengerVec[6].setWaitTime(waitTforP7, originFloor);
	waitingT.push_back(PassengerVec[6].getWaitTime());
	PassengerVec[6].PressCarButton(6); //P7 goes to 6th
	PassengerVec[6].Travel();
	PassengerVec[6].travelsummary();
	travelT.push_back(PassengerVec[6].getTravelTime());

	//P8, P9, P10
	Passenger P8 = Passenger(pcount, originFloor);
	pcount++;
	Passenger P9 = Passenger(pcount, originFloor);
	pcount++;
	Passenger P10 = Passenger(pcount, originFloor);
	pcount++;

	//put p8, p9, p10 into the passenger vector
	PassengerVec.push_back(P8);
	PassengerVec.push_back(P9);
	PassengerVec.push_back(P10);

	//generate random number for P8 to P10's destination floor
	int DesF8, DesF9, DesF10;
	srand(time(NULL));

	//generate random number from 4 to 7 floors
	DesF8 = rand() % 4 + 4;
	DesF9 = rand() % 4 + 4;
	DesF10 = rand() % 4 + 4;

	//P8
	PassengerVec[7].SetHallwayUpButton();
	int waitTforP8 = PassengerVec[7].getCurLevel(); 
	PassengerVec[7].setWaitTime(waitTforP8, originFloor);
	waitingT.push_back(PassengerVec[7].getWaitTime());
	PassengerVec[7].PressCarButton(DesF8); //P8 goes to the floor that is randomly created 
	PassengerVec[7].Travel();
	PassengerVec[7].travelsummary();
	travelT.push_back(PassengerVec[7].getTravelTime());

	//P9
	PassengerVec[8].SetHallwayUpButton();
	int waitTforP9 = PassengerVec[7].getCurLevel(); // asumme P9 comes when the car is in the P8's destination floor
	PassengerVec[8].setWaitTime(waitTforP9, originFloor);
	waitingT.push_back(PassengerVec[8].getWaitTime());
	PassengerVec[8].PressCarButton(DesF9); //P9 goes to the floor that is randomly created 
	PassengerVec[8].Travel();
	PassengerVec[8].travelsummary();
	travelT.push_back(PassengerVec[8].getTravelTime());

	//P10
	PassengerVec[9].SetHallwayUpButton();
	int waitTforP10 = PassengerVec[8].getCurLevel(); // asumme P10 presses the button when th e car is in the P9's destination floor
	PassengerVec[9].setWaitTime(waitTforP10, originFloor);
	waitingT.push_back(PassengerVec[9].getWaitTime());
	PassengerVec[9].PressCarButton(DesF10); //P10 goes to the floor that is randomly created 
	PassengerVec[9].Travel();
	PassengerVec[9].travelsummary();
	travelT.push_back(PassengerVec[9].getTravelTime());

	//calculate average waiting time and travel time
	double Wsum = 0;
	double Tsum = 0;
	double AveWaitT;
	double AveTravelT;

	for (int i = 0; i < waitingT.size(); i++) {
		Wsum = Wsum + waitingT[i];
	}
	for (int j = 0; j < travelT.size(); j++) {
		Tsum = Tsum + travelT[j];
	}

	AveWaitT = Wsum / waitingT.size();
	AveTravelT = Tsum / travelT.size();

	cout << "Average waiting time is: " << AveWaitT << " seconds"<< endl;

	cout << "Average travel time is: " << AveTravelT << " seconds" << endl;

	//cout << PassengerVec.size();


	//for (int i = 0; i < PassengerVec.size(); i++) {
		//PassengerVec[i].DisplayResult();

	//}



	
    std::cout << "Hello World!\n";
	return 0;
}

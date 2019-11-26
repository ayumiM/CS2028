#include <iostream>
#include <vector>
#include <string>
#include <queue>



using namespace std;

class Hallway 
{
private:
	string UpButton;
	string DownButton;
	queue<int> Up;
	queue<int> Down;

public:
	Hallway();
	~Hallway();
	void PressUpButton(int);
	void PressDownButton(int);
	string getUpButton();
	string getDownButton();
	void UpRequest(int);
	void DownRequest(int);
	void CompleteUpButton();
	void CompleteDownButton();
	void CompleteUpRequest();
	void CompleteDownRequest();

};

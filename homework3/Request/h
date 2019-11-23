#include <iostream>
#include <string>



using namespace std;

class Request 
{
private:
	struct RequestNode {
		int value;
		struct RequestNode* next;
	};
	RequestNode* head;

	int homeFloor = 3;

public:
	Request();
	~Request();

	void appnedRequest(int);
	void insertRequestGoUp(int);
	void insertRequestGoDown(int);
	void deleteFirstRequest();
	void deleteRequest(int);
	void displayRequest();
	bool CheckRequest(int);
	int getFloor();

};

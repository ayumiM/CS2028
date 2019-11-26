#include "Hallway.h"

#include <iostream>
//#include <vector>
#include <string>
#include <queue>

using namespace std;

//For homework 3, just upbutton no downbutton 
Hallway::Hallway() {
	UpButton = " ";
	DownButton = " ";
}

Hallway::~Hallway() {

}

void Hallway::PressUpButton(int u) {
	UpButton = "Pressed";
	UpRequest(u);
}

void Hallway::PressDownButton(int d) {
	DownButton = "Pressed";
	DownRequest(d);
}

string Hallway::getUpButton() {
	return UpButton;
}

string Hallway::getDownButton() {
	return DownButton;
}

void Hallway::UpRequest(int u) {
	Up.push(u);
}

void Hallway::DownRequest(int d) {
	Down.push(d);
}

void Hallway::CompleteUpButton() {
	UpButton = " ";
	CompleteUpRequest();
}

void Hallway::CompleteDownButton() {
	DownButton = " ";
	CompleteDownRequest();
}

void Hallway::CompleteUpRequest() {
	Up.pop();
}

void Hallway::CompleteDownRequest() {
	Down.pop();
}

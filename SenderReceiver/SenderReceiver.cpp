// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <csignal>
#include <windows.h>

using namespace std;

class Sensor {
public:
	string name;

	void setName(string _name) {
		name = _name;
	}
	string getName(void) {
		return name;
	}
	double measure(void) {
		return (rand() % 100) + 1;
	}
};

class Receiver {
public:
	string name;
	int numberOfMsgs = 0;
	Receiver(string _sensor_name) {
		name == _sensor_name;
	}

	void incrementN(void) {
		numberOfMsgs += 1;
	}

};



int main()
{
	srand(time(NULL));



	Sensor sensor1;
	Sensor sensor2;
	sensor1.setName("Sensor 1");
	sensor1.setName("Sensor 2");

	Receiver receiver1("Sensor 1");
	Receiver receiver2("Sensor 2");

	SHORT key = 0;


	double data;
	
		while (key == 0) {

		cout << "Sensor 1 send: ";
		data = sensor1.measure();
		cout << data << endl;
		if (data != NULL) receiver1.incrementN();

		cout << "Sensor 2 send: ";
		data = sensor2.measure();
		cout << data << endl;
		if (data != NULL) receiver2.incrementN();
		key = GetKeyState('A');
		Sleep(100);

	}

	cout << "Programm stopped" << endl;
	cout << "Receiver 1 got: " << receiver1.numberOfMsgs << "Messages" << endl;
	cout << "Receiver 2 got: " << receiver2.numberOfMsgs << "Messages" << endl;
	system("pause");
	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

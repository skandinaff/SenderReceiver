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

	void set_name(string _name) {
		name = _name;
	}
	string get_name(void) {
		return name;
	}
	double measure(void) {
		return (rand() % 100) + 1;
	}
};

class Receiver {
public:
	string sensor_name;
	string name;
	int number_of_msgs = 0;
	double all_messages = 0;

	void incrementN(void) {
		number_of_msgs += 1;
	}
	void add_messages(int message){
		all_messages += message;
	}
	double get_average(void) {
		return all_messages / number_of_msgs;
	}

	string connected_to_what(void) {
		return sensor_name;
	}
	void set_name(string _name) {
		name = _name;
	}
	string get_name(void) {
		return name;
	}

};



int main()
{
	srand(time(NULL));



	Sensor sensor1;
	Sensor sensor2;
	sensor1.set_name("Sensor 1");
	sensor2.set_name("Sensor 2");

	Receiver receiver1;
	receiver1.name = "Receiver 1";
	receiver1.sensor_name = sensor1.get_name();

	Receiver receiver2;
	receiver2.name = "Receiver 2";
	receiver2.sensor_name = sensor2.get_name();

	SHORT key = 0;

	double data;
	
		while (key == 0) {
			if(rand()%2==0) data = sensor1.measure();
			else data = NULL;
			if (data != NULL) {
				cout << "Sensor 1 send: ";
				cout << data << endl;
				receiver1.incrementN();
				receiver1.add_messages(data);
			}
			data = sensor2.measure();
			if (data != NULL) {
				cout << "Sensor 2 send: ";
				cout << data << endl;
				receiver2.incrementN();
				receiver2.add_messages(data);
			}
			key = GetKeyState('A');
			cout << "Press A to stop reception" << endl;
		Sleep(10);

		}

	cout << "Reception stopped" << endl;

	cout << receiver1.get_name() << " got: " << receiver1.number_of_msgs << " Messages ";
	cout << " from " << receiver1.connected_to_what() << endl;
	cout << "Average of " << receiver1.connected_to_what() << " is: " << receiver1.get_average() << endl;

	cout << receiver2.get_name() << " got: " << receiver2.number_of_msgs << " Messages ";
	cout << " from " << receiver2.connected_to_what() << endl;
	cout << "Average of " << receiver2.connected_to_what() << " is: " << receiver2.get_average() << endl;

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

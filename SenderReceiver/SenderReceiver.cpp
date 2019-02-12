#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <vector>
#include <climits>

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
		return (rand() % 100) + 1; // Produce a randome measurement 
	}
};

class Receiver {
public:
	string sensor_name;
	string name;
	int number_of_msgs = 0;
	double all_messages = 0;

	void increment_N(void) {
		number_of_msgs += 1;
	}
	void add_messages(double message){
		all_messages += message;
	}
	double get_average(void) {
		if(number_of_msgs != 0) return all_messages / number_of_msgs;
		else return 0;
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

void get_sensor_data(double* data, Sensor& sensor, Receiver& receiver) {
	string sensor_name = sensor.get_name();
	if (rand() % 2 == 0) { // Add some randomness factor to data creation
		*data = sensor.measure();
		cout << sensor_name << " send value: ";
		cout << *data << endl;
		receiver.increment_N();
		receiver.add_messages(*data);
	}
	else return;
}

int main()
{
	srand(time(NULL));

	vector<Sensor> sensors;
	vector<Receiver> receivers;
	int num_of_conn = 0;

	cout << "Please enter number of sensors: " << endl;
	cin >> num_of_conn;
	
	while (num_of_conn > 99 || num_of_conn <= 0) {
		cout << "Maximum number of sensors is 99. Try again." << endl;
		cin.clear();
		cin >> num_of_conn;
	}

	sensors.resize(num_of_conn);
	receivers.resize(num_of_conn);
	
	for (int i = 0; i < num_of_conn; i++)
	{
		string sensor_name = "Sensor ";
		sensor_name += to_string(i);
		sensors[i].set_name(sensor_name);
	}

	for (int i = 0; i < num_of_conn; i++)
	{
		string receiver_name = "Receiver ";
		receiver_name += to_string(i);
		receivers[i].set_name(receiver_name);
		receivers[i].sensor_name = sensors[i].get_name();
	}

	SHORT key = 0;

	double data = 0;
	double* pDat = &data;
		
	cout << "To start receivng press A. To stop press S" << endl;
	
	while (key == 0) key = GetKeyState('A');
	key = 0;

		while (key == 0) {
			for (int i = 0; i < num_of_conn; i++) {
				get_sensor_data(pDat, sensors[i], receivers[i]);
			}
			key = GetKeyState('S');
		Sleep(4);
		}

	cout << "Reception stopped\n\r" << endl;
	for (int i = 0; i < num_of_conn; i++) {
		cout << receivers[i].get_name() << " got: " << receivers[i].number_of_msgs << " Messages ";
		cout << " from " << receivers[i].connected_to_what() << endl;
		cout << "Average of " << receivers[i].connected_to_what() << " is: " << receivers[i].get_average() << "\n\r" << endl;

	}
	system("pause");
	return 0;

}

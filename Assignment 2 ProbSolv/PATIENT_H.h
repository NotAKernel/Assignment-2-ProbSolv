#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>

using namespace std;

class Patient {
private:
	int Priority;
	string Name;

public:
	Patient();
	Patient(string name, int priority);

	string getName();
	int getPriority();

};

#endif // PATIENT_H
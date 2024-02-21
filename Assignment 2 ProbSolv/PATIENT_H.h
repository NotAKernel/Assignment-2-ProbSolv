#pragma once

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

	bool operator==(const Patient& other) const {
		return this->Priority == other.Priority; 
	}
	
	bool operator>(const Patient& other) const {
		return this->Priority > other.Priority; 
	}

	bool operator<(const Patient& other) const {
		return this->Priority < other.Priority; 
	}

	bool operator>=(const Patient& other) const {
		return this->Priority >= other.Priority; 
	}

	bool operator<=(const Patient& other) const {
		return this->Priority <= other.Priority; 
	}

	bool operator!=(const Patient& other) const {
		return this->Priority != other.Priority; 
	}

};


//========

Patient::Patient()
{
}

Patient::Patient(string name, int priority) {
	this->Name = name;
	this->Priority = priority;
}

string Patient::getName()
{
	return this->Name;
}

int Patient::getPriority()
{
	return this->Priority;
}
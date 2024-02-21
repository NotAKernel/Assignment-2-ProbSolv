#include "PATIENT_H.h"

Patient::Patient()
{
}

Patient::Patient(string name, int priority) {
	this->Name = name;
	this->Priority = priority;
	this->Timestamp = std::chrono::system_clock::now();
}

string Patient::getName()
{
	return this->Name;
}

int Patient::getPriority()
{
	return this->Priority;
}
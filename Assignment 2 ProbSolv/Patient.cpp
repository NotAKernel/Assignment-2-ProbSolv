#include "PATIENT_H.h"

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
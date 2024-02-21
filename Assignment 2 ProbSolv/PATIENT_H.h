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

	friend std::ostream& operator<<(std::ostream& os, const Patient& p) {
		os << "Name: " << p.Name << "\nPriority: " << p.Priority;
		return os;
	}
};

#endif // PATIENT_H
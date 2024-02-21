#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
#include <chrono>

using namespace std;

class Patient {
private:
    int Priority;
    string Name;
    std::chrono::system_clock::time_point Timestamp;

public:
    Patient();
    Patient(string name, int priority);

    string getName();
    int getPriority();

    bool operator==(const Patient& other) const {
        return (this->Priority == other.Priority && this->Timestamp == other.Timestamp);
    }

    bool operator>(const Patient& other) const {
        if (this->Priority != other.Priority)
            return this->Priority > other.Priority;
        else
            return this->Timestamp < other.Timestamp;
    }

    bool operator<(const Patient& other) const {
        if (this->Priority != other.Priority)
            return this->Priority < other.Priority;
        else
            return this->Timestamp > other.Timestamp;
    }

    bool operator>=(const Patient& other) const {
        if (this->Priority != other.Priority)
            return this->Priority >= other.Priority;
        else
            return this->Timestamp <= other.Timestamp;
    }

    bool operator<=(const Patient& other) const {
        if (this->Priority != other.Priority)
            return this->Priority <= other.Priority;
        else
            return this->Timestamp >= other.Timestamp;
    }

    bool operator!=(const Patient& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Patient& p) {
        os << "Name: " << p.Name << "\nPriority: " << p.Priority;
        return os;
    }
};

#endif // PATIENT_H

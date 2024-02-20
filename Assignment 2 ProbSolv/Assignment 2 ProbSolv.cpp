#include "PATIENT_H.h"
#include "HEAP_H.h"
#include "Heap.cpp"

using namespace std;
void AddPatient(string& name, int& priority);
void DisplayMenu();

int main()
{
    string name;
    int priority;

    Patient pList[100];
    Heap<Patient> pHeap(pList);

    int size = 5;
    pList[0] = Patient("Dave", 3);
    pList[1] = Patient("Earl", 4);
    pList[2] = Patient("Geoff", 5);
    pList[3] = Patient("John", 5);
    pList[4] = Patient("Yup", 1);


    int option;

    do {
        DisplayMenu();
        cin >> option;

        switch (option) {
        case 1:
            AddPatient(name, priority);
            pList[size] = Patient(name, priority);
            size++;
            break;
        case 2:
            break;
        case 3:

            break;
        case 0:
            break;
        default:
            cout << "Invalid option!";
        }
    } while (option != 0);

    return 0;
}


void AddPatient(string& name, int& priority)
{
    cout << "Please enter a name: ";
    cin >> name;
    
    do {
        cout << "Please enter a number between 1 and 5: ";
        cin >> priority;
    } while (priority < 1 || priority > 5);

}

void DisplayMenu()
{
    cout << "---Patient Program---\n\n"
        << "1. Add Patient\n"
        << "2. Call Next Patient\n"
        << "3. Print Queue\n"
        << "0. Exit\nEnter Choice: ";
}

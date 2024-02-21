#include "PATIENT_H.h"
#include "HEAP_H.h"
#include "Heap.cpp"
#include "PQ_H.h"
#include "PQ.cpp"

using namespace std;
void AddPatient(PriorityQueue<Patient>& q);
void CallPatient(PriorityQueue<Patient>& q);
void DisplayMenu();
void PauseAndClear();

int main()
{

    PriorityQueue<Patient> pList(100);
    pList.Enqueue(Patient("Dave", 1));
    pList.Enqueue(Patient("Elf", 3));
    pList.Enqueue(Patient("Joe", 5));
    pList.Enqueue(Patient("Yep", 2));
    pList.Enqueue(Patient("Sure", 4));


    int option;

    do {
        DisplayMenu();
        cin >> option;

        switch (option) {
        case 1:
            std::system("CLS");
            AddPatient(pList);
            PauseAndClear();
            break;
        case 2:
            std::system("CLS");
            CallPatient(pList);
            PauseAndClear();
            break;
        case 3:
            std::system("CLS");
            pList.PrintQueue();
            PauseAndClear();
            break;
        case 0:
            std::cout << "\n\nThanks for using this program!";
            break;
        default:
            cout << "Invalid option!";
            PauseAndClear();
        }
    } while (option != 0);

    return 0;
}


void AddPatient(PriorityQueue<Patient>& q)
{
    string name;
    int priority;

    cout << "Please enter a name: ";
    cin >> name;
    
    do {
        cout << "Please enter a number between 1 and 5: ";
        cin >> priority;
    } while (priority < 1 || priority > 5);

    q.Enqueue(Patient(name, priority));
}

void CallPatient(PriorityQueue<Patient>& q)
{
    if (q.IsEmpty()) {
        std::cout << "No Items Left In Queue!";
        return;
    }
    else if (q.IsFull()) {
        std::cout << "No Room Left In Queue!";
        return;
    }
    Patient p; 
    q.Dequeue(p);

    cout << "Name: " << p.getName() << "\nPriority: " << p.getPriority();
}

void DisplayMenu()
{
    cout << "---Patient Program---\n\n"
        << "1. Add Patient\n"
        << "2. Call Next Patient\n"
        << "3. Print Queue\n"
        << "0. Exit\nEnter Choice: ";
}

void PauseAndClear()
{
    std::cout << "\n\n";
    std::system("Pause");
    std::system("CLS");
}

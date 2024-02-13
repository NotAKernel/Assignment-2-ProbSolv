#include "PATIENT_H.h"
#include "HEAP_H.h"
#include "Heap.cpp"

using namespace std;

void SortList(Heap<int>& heap, Patient list[], int size);
void CallPatient(Heap<int>& heap, Patient list[], int& size);
void PrintList(Patient list[], int size);
void AddPatient(string& name, int& priority);
void DisplayMenu();

int main()
{
    string name;
    int priority;

    int arr[100];
    Heap<int> pHeap(arr);
    Patient pList[100];

    int size = 5;
    pList[0] = Patient("Dave", 3);
    pList[1] = Patient("Earl", 4);
    pList[2] = Patient("Geoff", 5);
    pList[3] = Patient("John", 5);
    pList[4] = Patient("Yup", 1);

    SortList(pHeap, pList, size);

    int option;

    do {
        DisplayMenu();
        cin >> option;

        switch (option) {
        case 1:
            AddPatient(name, priority);
            pList[size] = Patient(name, priority);
            size++;
            SortList(pHeap, pList, size);
            break;
        case 2:
            CallPatient(pHeap, pList, size);
            break;
        case 3:
            PrintList(pList, size);
            break;
        case 0:
            break;
        default:
            cout << "Invalid option!";
        }
    } while (option != 0);

    return 0;
}

void SortList(Heap<int>& heap, Patient list[], int size)
{
    for (int i = heap.numElements; i < size; i++) {
        heap.Insert(list[i].getPriority());
    }

    for (int i = size - 1; i >= 0; i--) {
        int priority = heap.Remove();
        for (int j = 0; j < size; j++) {
            if (list[j].getPriority() == priority) {
                Patient temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

void CallPatient(Heap<int>& heap, Patient list[], int& size)
{
    if (size == 0) {
        cout << "No patients in list\n";
    }
    else {
        heap.Remove();
        size--;
        cout << list[size].getName() << endl;
    }

}

void PrintList(Patient list[], int size)
{
    for (int i = size - 1; i >= 0; i--) {
        cout << "Name: " << list[i].getName() << "\nPriority: " << list[i].getPriority() << "\n\n";
    }
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

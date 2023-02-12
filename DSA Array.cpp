#include <iostream>

using namespace std;

const int MAX_SIZE = 100;
int arr[MAX_SIZE];
int size = 0;

void addValue(int value) {
    if (size == MAX_SIZE) {
        cout << "Array is full." << endl;
        return;
    }
    arr[size++] = value;
    cout << "Value added successfully." << endl;
}

void deleteValue(int value) {
    int pos = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "Value not found in the array." << endl;
        return;
    }
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "Value deleted successfully." << endl;
}

void insertValue(int value, int pos) {
    if (pos < 0 || pos > size) {
        cout << "Invalid position." << endl;
        return;
    }
    for (int i = size - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = value;
    size++;
    cout << "Value inserted successfully." << endl;
}

void printArray() {
    cout << "Array: [ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

int main() {
    int choice, value, pos;

    while (true) {
        cout << "1. Add value to array" << endl;
        cout << "2. Delete value from array" << endl;
        cout << "3. Insert value in array" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            	system("cls");
                cout << "Enter the value to be added: ";
                cin >> value;
                addValue(value);
                break;
            case 2:
            	system("cls");
                cout << "Enter the value to be deleted: ";
                cin >> value;
                deleteValue(value);
                break;
            case 3:
            	system("cls");
                cout << "Enter the value to be inserted: ";
                cin >> value;
                cout << "Enter the position to insert the value: ";
                cin >> pos;
                insertValue(value, pos);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice." << endl;
                break;
        }

        printArray();
    }

    return 0;
}

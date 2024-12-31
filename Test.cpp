#include <iostream>
#include <vector>
using namespace std;

class Employee {
private:
    int id;
    string name;
    string position;

public:
    Employee() {}

    Employee(int id, string name, string position) {
        this->id = id;
        this->name = name;
        this->position = position;
    }

    void setId(int id) {
        this->id = id;
    }

    int getId() {
        return this->id;
    }

    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return this->name;
    }

    void setPosition(string position) {
        this->position = position;
    }

    string getPosition() {
        return this->position;
    }

    void inputEmployeeInfo() {
        cout << "[+] Insert ID: ";
        cin >> id;
        cin.ignore(); // Ignore the newline character after the ID
        cout << "[+] Insert name: ";
        getline(cin, name);
        cout << "[+] Insert position: ";
        getline(cin, position);
    }

    void getEmployeeInfo() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Position: " << position << endl;
    }
};

int main() {
    vector<Employee> allEmployees;
    int option;

    do {
        cout << "================== SYSTEM OF THE COMPANY ==================" << endl;
        cout << "1. INPUT" << endl;
        cout << "2. OUTPUT" << endl;
        cout << "3. UPDATE" << endl;
        cout << "4. DELETE" << endl;
        cout << "5. EXIT" << endl;
        cout << "[+] INSERT OPTION: ";
        cin >> option;

        switch (option) {
        case 1: { // Add new employee
            Employee emp;
            emp.inputEmployeeInfo();
            allEmployees.push_back(emp);
            break;
        }
        case 2: { // Display all employees
            if (allEmployees.empty()) {
                cout << "[!] No employees found." << endl;
            } else {
                for (size_t i = 0; i < allEmployees.size(); i++) {
                    cout << "Employee " << i + 1 << ":" << endl;
                    allEmployees[i].getEmployeeInfo();
                    cout << "-----------------------------" << endl;
                }
            }
            break;
        }
        case 3: { // Update an employee
            int id;
            cout << "[+] INPUT ID TO UPDATE: ";
            cin >> id;
            bool found = false;
            for (size_t i = 0; i < allEmployees.size(); i++) {
                if (allEmployees[i].getId() == id) {
                    cout << "[+] Employee found. Update details:" << endl;
                    allEmployees[i].inputEmployeeInfo();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "[!] Employee with ID " << id << " not found." << endl;
            }
            break;
        }
        case 4: { // Delete an employee
            int id;
            cout << "[+] INPUT ID TO DELETE: ";
            cin >> id;
            bool found = false;
            for (size_t i = 0; i < allEmployees.size(); i++) {
                if (allEmployees[i].getId() == id) {
                    allEmployees.erase(allEmployees.begin() + i);
                    cout << "[+] Employee with ID " << id << " deleted." << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "[!] Employee with ID " << id << " not found." << endl;
            }
            break;
        }
        case 5: { // Exit
            cout << "Exiting system..." << endl;
            break;
        }
        default:
            cout << "[!] Invalid option. Please try again." << endl;
        }

    } while (option != 5);

    return 0;
}
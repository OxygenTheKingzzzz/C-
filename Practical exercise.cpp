#include<iostream>
#include<vector>
using namespace std;
class Employee{
    private:
    int id;
    string name;
    string position;
    public:
    Employee(){}
    Employee(int id,string name, string position){
        this->id=id;
        this->name=name;
        this->position=position;
    }
     void setId(int id){
        this->id=id;
    }
    int getId(){
        return this->id=id;
    }
    void setName(string name){
        this->name=name;
    }
    string getName(){
        return this->name=name;
    }
    void setPosition(string position){
        this->position=position;
    }
    string getPosition(){
        return this->position=position;
    }
    void inputEmployeeInfo(){
        cout<<"[+]Insert ID: "<<endl;
        cin>>id;
        cout<<"[+]Insert name: "<<endl;
        cin.ignore();
        getline(cin,name);
        cout<<"[+]Insert Position"<<endl;
        cin.ignore();
        getline(cin,position);
    }
    void getEmployeeInfo(){
        cout<<"ID:"<<id<<endl;
        cout<<"Name:"<<name<<endl;
        cout<<"Position: "<<position;
    }
    };
    int main(){
    vector<Employee> allEmployees;
    int id,n;
    string name;
    string position;
    int option;
    do{
        cout<<"==================SYSTEM OF THE COMPANY=================="<<endl;
        cout<<"1.INPUT"<<endl;
        cout<<"2.OUTPUT"<<endl;
        cout<<"3.UPDATE"<<endl;
        cout<<"4.DELETE"<<endl;
        cout<<"5.EXIT"<<endl;
        cout<<"[+]INSERT OPTION:"<<endl;
        cin>>option;
        switch(option){
            case 1:{
           Employee emp;
            emp.inputEmployeeInfo();
            allEmployees.push_back(emp);
            break;
             };
            case 2:{
            if (allEmployees.empty()) {
                cout << "[!] No employees found." << endl;
            } else {
                for (int i = 0; i < allEmployees.size(); i++) {
                    cout << "Employee " << i + 1 << ":" << endl;
                    allEmployees[i].getEmployeeInfo();
                    cout << "-----------------------------" << endl;
                }
            }
            break;
            }
            case 3:{
           cout<<"[+]INPUT ID TO UPDATE:"<<endl;
           cin>>id;
           for(int i=0;i<allEmployees.size();i++){
            cout<<"Employee found."<<endl;
            allEmployees[i].inputEmployeeInfo();
            break;
           }
        }
    case 4:{
        int id;
        cout<<"[+]INPUT ID TO DELETE:";
        cin>>id;
        for(int i=0;i<allEmployees.size();i++){
            if(allEmployees[i].getId()==id){
                allEmployees.erase(allEmployees.begin()+i);
                cout<<"DELETED SUCESSFULLY.";
                break;
            }
        }
    }
    case 5:{
        cout<<"EXITING..."<<endl;
        break;
    }
        }
    } while(option !=5);
        return 0;
    }
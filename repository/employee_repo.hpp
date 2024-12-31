#include<iostream>
#include<vector>
#include"../service/employee_ser.hpp"
using namespace std;
int id;
string name;
string position;
vector<Employee> getAllEmployees(){
return employeeRepositories;
}
Employee addEmployeeById(int id){
    for(Employee &E : employeeRepositories){
        if(E.getId()==id){
            cout<<"Employee Info:"<<E.getEmployeeInfo()<<endl;
            return E;
        }
    }
}   

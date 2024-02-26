#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Student {
public:
	Student( ) { }
    //TODO: design constructor
    Student(string first_name,string last_name,string dormitory,string ID){
        this->first_name = first_name;
        this->last_name = last_name;
        this->dormitory = dormitory;
        this->ID = ID;
    }
	string generate_address(){
    	//TODO: generate the output address
        return string ("1001 University Road, Hsinchu, Taiwan 300, ROC, dorm ")+ dormitory + ", " + "(" +ID +") "+first_name+" "+last_name;
    }

private:
	string first_name;
    string last_name;
	string dormitory;
	string ID;
};


int main() {
  	Student mStudent;
    //TODO: Read input from STDIN
    string first_name;
    string last_name;
    string dormitory;
    string ID;

    cin>>first_name>>last_name>>dormitory>>ID;
    mStudent = Student(first_name,last_name,dormitory,ID);
  	cout << mStudent.generate_address() << endl;
    return 0;
}

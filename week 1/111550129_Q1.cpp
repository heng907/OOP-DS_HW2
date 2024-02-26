#include <iostream>
#include <string>

using namespace std;

class Student {
private:
	string name;
	string studentID;
	int score;
public:
	Student(){}
	Student(string name, string studentID, int score){
		//TODO
        this->name=name;
        this->studentID=studentID;
        this->score=score;
    }
	string getName(){
		//TODO
		return name;
	}
	string getStudentID(){
		//TODO
		return studentID;
	}
	int getScore(){
		//TODO
		return score;
	}
};

int main() {
	string name;
	string studentID;
	int score;
	Student mStudent;

	cin >> name >> studentID >> score;
	mStudent = Student(name, studentID, score);
	cout << mStudent.getName() << "'s studentID is " << mStudent.getStudentID()
	<< " and score is " << mStudent.getScore() << "." << endl;

	return 0;
}

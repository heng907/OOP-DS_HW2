#include <vector>
#include <iostream>
using namespace std;

class Object{
public:
    virtual void response() = 0;

    virtual ~Object() = default;
};

class IceMonster : public Object{
	//add constructor or functions if you need
	void response () override {
        cout << "fire attack"<<endl;
	}
};

class FireMonster : public Object{
	//add constructor or functions if you need
	void response () override{
        cout << "ice attack" << endl;
	}
};

class Treasure : public Object{
	//add constructor or functions if you need
	void response() override{
        cout << "ya"<<endl;
	}
};


class Room{
public:
  	//add anything if you need
    Room *up_room;
    Room *down_room;
    Room *left_room;
    Room *right_room;
    int index;
    Object *o;
    //add constructor or functions if you need
    Room (int _index = -1) :  index (_index) , up_room (nullptr), down_room (nullptr), left_room (nullptr), right_room (nullptr), o (nullptr){
    }

    void setRoom (char type , Room *u , Room *d , Room *l , Room *r){
        this ->up_room = u ;
        this ->down_room = d ;
        this ->left_room = l ;
        this ->right_room = r ;

        if(type == 'e'){
            o = nullptr;
        }
        else if(type == 'i') {
            o = new IceMonster;
        }
        else if (type == 't') {
            o = new Treasure;
        }
        else if (type == 'f'){
            o = new FireMonster;
        }
    }
    ~Room() {
        delete o;
    }
};

 void visitRoom (Room* r) {

        if (r == nullptr){
            cout << -1 <<endl;
            return ;
        }

        cout << r ->index ;

        if(r->o == nullptr){
            cout << endl;
        }
        else {
            r -> o -> response() ;
        }

        delete r->o;
        r->o =nullptr;
    }

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int m , n ;
    cin >> m>>n ;

    vector<Room*> rooms(m + 1);
    rooms[0] = nullptr;
    for(int i = 1; i <= m; i++) {
        rooms[i] = new Room(i - 1);
    }

    char type, move;
    int up, down, left, right;

    for(int i = 1; i <= m; i++) {
        cin >> type >> up >> down >> left >> right;
        rooms[i]->setRoom(type, rooms[up + 1], rooms[down + 1], rooms[left + 1], rooms[right + 1]);
    }

    Room* curr = rooms[1];
    visitRoom(curr);
    for(int i = 0; i < n ; i++) {
        cin >> move;
        switch(move) {
            case 'u':
                visitRoom(curr->up_room);
                if(curr->up_room) curr = curr->up_room;
                break;
            case 'd':
                visitRoom(curr->down_room);
                if(curr->down_room) curr = curr->down_room;
                break;
            case 'l':
                visitRoom(curr->left_room);
                if(curr->left_room) curr = curr->left_room;
                break;
            case 'r':
                visitRoom(curr->right_room);
                if(curr->right_room) curr = curr->right_room;
                break;
        }
    }

    return 0;
}

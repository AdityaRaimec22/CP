#include<iostream>
using namespace std;

class Hero{

    private:
    int size = 1;

    public:
    int health;

    Hero(int health){
        this->health = health;
        cout << "health of ramesh is: " << health << endl;;
    }

    int getSize(){
        return size;
    }

    void setSize(int s){
        size = s;
    }

};

int main(){

    Hero ramesh(10);

    cout << "size of ramesh is: " << ramesh.getSize() << endl;

    ramesh.setSize(50);

    cout << "size of ramesh is: " << ramesh.getSize() << endl;

    return 0;
}
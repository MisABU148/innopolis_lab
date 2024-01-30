//
// Created by Maria on 30.01.2024.
//
#include <iostream>

using namespace std;

class Box {
    unsigned int length, width, height;
public:
    Box() {
        length = 0;
        width = 0;
        height = 0;
    }
    Box(int l, int w, int h) {
        length = l;
        width = w;
        height = h;
    }
    Box(Box& b) {
        length = b.length;
        width = b.width;
        height = b.height;
    }
    unsigned getVolume() {
        return height*width*length;
    } // returns the volume of the box.
    void scale(unsigned scaleValue) {
        length *= scaleValue;
        width *= scaleValue;
        height *= scaleValue;
    } // multiply each side of the box with scaleValue.
    bool isBigger(Box& other){
        if (getVolume() > other.getVolume())
            return true;
        return false;
    } // this box is larger than the other (you decide what the type should be)
    bool isSmaller(Box& other) {
        if (getVolume() < other.getVolume())
            return true;
        return false;
    } // this box is smaller than the other (you decide what the type should be)
    bool equal(Box& other) {
        int count_eqal = 0;
        if (length == other.length || length == other.width || length == other.height)
            count_eqal++;
        if (width == other.length || width == other.width || width == other.height)
            count_eqal++;
        if (height == other.length || height == other.width || height == other.height)
            count_eqal++;
        if (count_eqal == 3)
            return true;
        return false;
    } // returns true if the sides of two boxes are the same (they may be shuffled), false otherwise
};

class Cube {

};

int main() {
    Box box1;
    Box box2(1, 2, 3);
    Box box3(box2);
    Box box4 = box3;
    cout<<box4.getVolume()<<endl;
    box1 = box2;
    box1.scale(3);
    box3.scale(5);
    cout<<box3.isSmaller(box1)<<endl;
    cout<<box2.equal(box4);
}
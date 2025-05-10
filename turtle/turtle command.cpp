#include <iostream>
#include "tutel.h"

std::vector<int> x = {};
std::vector<int> y = {};
std::vector<int> col = {};

int main(){
    int i = 1;
    display(50,25,7,x,y,col,x.size());
    home();
    forward(10);
    right(1);
    back(5);
    left(2);
    back(5);
    setpos(0,0);
    while (i < 4){
        pencolor(i);
        forward(13);
        i += 1;
    }
    setX(0);
    setY(24);
    while (i < 7){
        forward(13);
        pencolor(i);
        i += 1;
    }
}
#include <iostream>
#include "tutel.h"

std::vector<int> x = {};
std::vector<int> y = {};
std::vector<int> col = {};

// exemple : the spiral
int main(){
  int f = 1;
  int times = 10;
  display(50,25,3,x,y,col,x.size());
  home();
  while (times > 0){
    forward(f);
    right(2);
    f += 1;
    times -=1;
  }
}

//show of all functions and colors for bg and pen
int main(){
    display(50,25,3,x,y,col,x.size());
    home();
    forward(10);
    right(1);
    back(5);
    left(2);
    back(5);
    right(1);
    setpos(0,0);
    pencolor(5);
    forward(50);
    setX(0);
    setY(24);
    forward(50);
    pencolor(0);
    home();
    right(4);
    int pc = 0;
    int i = 7;
    while (i > 0){
        forward(1);
        pc +=1;
        pencolor(pc);
        i -= 1;
    }
    i = 7;
    pc = 0;
    while (i > 0){
        display(50,25,pc,x,y,col,x.size());
        i -= 1;
        pc += 1;
    }
}

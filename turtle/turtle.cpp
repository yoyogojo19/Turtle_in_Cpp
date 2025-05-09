#include <iostream>
#include <vector>
#include "tutel.h"

int HomeX = 0;
int HomeY = 0;
int length = x.size();
int tl_or = 0;
int tlX = 0;
int tlY = 0;
int bgcol = 7;
int pencol = 0;
int lar = 0;
int hau = 0;
bool goback = false;

void display(int l,int h,int bgc,std::vector<int> dx,std::vector<int> dy,std::vector<int> dc,int lon){
    std::string screen = "";
    HomeX = l/2;
    HomeY = h/2;
    lar = l;
    hau = h;
    bgcol = bgc;
    for(int y = 0; y < h; y++){
        std::string line = "";
        for (int x = 0; x < l; x++){
            std::string cha = "";
            for (int i = 0; i < lon; i++){
                if (x == dx.at(i) && y == dy.at(i)){
                    switch (dc.at(i)){
                        case 0:
                            cha = "\033[0m  ";
                            break;
                        case 1:
                            cha = "\033[41m  \033[0m";
                            break;
                        case 2:
                            cha = "\033[42m  \033[0m";
                            break;
                        case 3:
                            cha = "\033[43m  \033[0m";
                            break;
                        case 4:
                            cha = "\033[44m  \033[0m";
                            break;
                        case 5:
                            cha = "\033[45m  \033[0m";
                            break;
                        case 6:
                            cha = "\033[46m  \033[0m";
                            break;
                        case 7:
                            cha = "\033[47m  \033[0m";
                            break;
                    }
                    break;
                }
            }
            if (cha == ""){
                switch (bgc){
                    case 0:
                        cha = "\033[0m  ";
                        break;
                    case 1:
                        cha = "\033[41m  \033[0m";
                        break;
                    case 2:
                        cha = "\033[42m  \033[0m";
                        break;
                    case 3:
                        cha = "\033[43m  \033[0m";
                        break;
                    case 4:
                        cha = "\033[44m  \033[0m";
                        break;
                    case 5:
                        cha = "\033[45m  \033[0m";
                        break;
                    case 6:
                        cha = "\033[46m  \033[0m";
                        break;
                    case 7:
                        cha = "\033[47m  \033[0m";
                        break;
                }
            }
            line += cha;            
        }
        screen += line + "\n";
    }
    std::cout<<screen<<"\n";
}

void update(){
    std::cout<<"\033[2J";
    display(lar,hau,bgcol,x,y,col,length);
}

void forward(int pixels){
    for(int j = 0; j < pixels; j++){
        x.push_back(tlX);
        y.push_back(tlY);
        col.push_back(pencol);
        switch (tl_or){
            case 0:
                tlX += 1;
                break;
            case 45:
                tlX += 1;
                tlY -= 1;
                break;
            case 90:
                tlY -= 1;
                break;
            case 135:
                tlY -= 1;
                tlX -= 1;
                break;
            case 180:
                tlX -= 1;
                break;
            case 225:
                tlX -= 1;
                tlY += 1;
                break;
            case 270:
                tlY += 1;
                break;
            case 315:
                tlX += 1;
                tlY += 1;
                break;
        }
    }
    length = x.size();
    if (goback == false){
        update();
    }
}

void right(int deg){
    if (deg > 8){
        deg = 8;
    }
    tl_or -= deg*45;
    if (tl_or < 0){
        tl_or += 360;
    }
    if (goback == false){
        update();
    }
}

void left(int deg){
    if (deg > 8){
        deg = 8;
    }
    tl_or += deg*45;
    if (tl_or > 360){
        tl_or -= 360;
    }
    if (goback == false){
        update();
    }
}

void back(int pixels){
    goback = true;
    right(4);
    forward(pixels);
    left(4);
    goback = false;
    update();
}

void pencolor(int color){
    pencol = color;
}

void setX(int X){
    tlX = X;
    update();
}

void setY(int Y){
    tlY = Y;
    update();
}

void setpos(int X,int Y){
    tlX = X;
    tlY = Y;
    update();
}

void home(){
    tlX = HomeX;
    tlY = HomeY;
    update();
}

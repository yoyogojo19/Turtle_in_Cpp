#include <vector>

extern std::vector<int> x;
extern std::vector<int> y;
extern std::vector<int> col;

void display(int l,int h,int bgc,std::vector<int> dx,std::vector<int> dy,std::vector<int> dc,int lon);

void update();

void forward(int pixels);

void right(int deg);

void left(int deg);

void back(int pixels);

void pencolor(int color);

void setX(int X);

void setY(int Y);

void setpos(int X,int Y);

void home();
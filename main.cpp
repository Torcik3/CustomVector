#include <iostream>
#include <vector>
#include "Vector.h"

class Panda {
public:
    int z;
    double y;
    std::string x;

public:
    Panda() {}
    Panda(int z, double y, std::string x): z(z), y(y), x(x) {}
};


int main() {

double a = 5;
std::vector <double> b;
b.push_back(a);
std::cout << b.size() << std::endl;
std::cout << b[0]<<std::endl;

Vector<int> v;
v.PushBack(2);
    std::cout<<v[0]<<std::endl;


    Vector<Panda> p;
    p.EmplaceBack(1,2.3,"lody");
std::cout<<p[0].x;

    std::cout << "Rozmiar przed: " << p.Size() << std::endl;
p.PopBack();
    std::cout << "Rozmiar po: " << p.Size() << std::endl;
    return 0;
}
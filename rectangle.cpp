#include "Figure.h"

double rectangle::Perimeter_this() const { // ok
    return 2*(a+b);
}
void rectangle::extractParams(const std::string& s) //ok
{
    std::string::size_type i = 0, j = 0;
    while(!(isdigit(s[i])))
        ++i;
    j = i;
    do {
        ++j;
    } while((isdigit(s[j])));
    a = atof(s.substr(i,j-i).c_str());
    b = atof(s.substr(j).c_str());
    perim = Perimeter();
}

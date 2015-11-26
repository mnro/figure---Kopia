#include "Figure.h"

double circle::Perimeter_this() const { // ok
    return 2*pi*r;
}

void circle::extractParams(const std::string& s) // ok
{
   std::string::size_type i = 0;
    while(!(isdigit(s[i])))
        ++i;
    r = atof(s.substr(i).c_str());
    perim = Perimeter();
}

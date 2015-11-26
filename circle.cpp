#include "Figure.h"

double circle::Perimeter_this() const {
    return 2*pi*r;
}

void circle::extractParams(const std::string& s)
{
   std::string::size_type i = 0;
    while(!(isdigit(s[i])))
        ++i;
    r = atof(s.substr(i).c_str());
    perim = Perimeter();
}

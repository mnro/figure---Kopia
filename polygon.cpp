#include "Figure.h"

double polygon::Perimeter_this() const {
    const_iterator it1 = coordinates_X.begin();
    const_iterator it2 = coordinates_Y.begin();
    double result = 0;
    for(; it1+1 != coordinates_X.end(); ++it1, ++it2)
       result += sqrt( pow(*(it1+1)-*it1,2) + pow(*(it2+1)-*it2,2) );

    // one last time. link the last point with the first point
    result += sqrt( pow(*(it1)-*(coordinates_X.begin()),2) + pow(*(it2)-*(coordinates_Y.begin()),2) );
    return result;
}
void polygon::extractParams(const std::string& s)
{
    std::string::size_type i=0;
    double d;
    while( !(isdigit(s[i])) )
            ++i;
    std::istringstream params(s.substr(i));
    i = 0;
    while(params >> d) {
        if(i%2) coordinates_Y.push_back(d);
        else coordinates_X.push_back(d);
        ++i;
    }
    if(i<2 || i%2) throw std::invalid_argument("incorrect structure. Won't be read");
    perim = Perimeter();
}

#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED

#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <sstream>
#include <stdexcept>

class Figure {

public:
    typedef std::vector<std::unique_ptr<Figure>> vec_figure_t;

    /* extracts parameters from the string and set private variables */
    virtual void extractParams(const std::string& ) = 0;

    /* returns local private perimeter of the object, calculated in extractParams() */
    virtual double retPerimeter() = 0;

    virtual ~Figure() {}

    /* accessor for testing */
    virtual void print_param() const = 0;


private:
    /* calculates the perimeter of the object */
    virtual double Perimeter() const = 0;
};


class circle : public Figure {
public:

    circle() : r(0) {}
    void extractParams(const std::string &);
    double retPerimeter() { return perim; }
    /* accessor for testing */
    void print_param() const { std::cout << r << std::endl;}

private:
    double r;
    const double pi = 3.14;
    double perim;
    double Perimeter() const {
        return Perimeter_this();
    }
    double Perimeter_this() const;

};

class rectangle : public Figure
{
public:

    rectangle() : a(0), b(0) {}
    void extractParams(const std::string &);
    double retPerimeter() { return perim; }
    /* accessor for testing */
    void print_param() const { std::cout << a << " " << b << std::endl;}

private:
    double a,b;
    double perim;
    double Perimeter() const {
        return Perimeter_this();
    }
    double Perimeter_this() const;

};

class polygon : public Figure
{
    public:
    typedef std::vector<double>::const_iterator const_iterator;
    polygon() {}

    void extractParams(const std::string &);
    double retPerimeter() { return perim; }
    /* accessor for testing */
    void print_param() const {
        const_iterator it1 = coordinates_X.begin();
        const_iterator it2 = coordinates_Y.begin();
        while(it1 != coordinates_X.end())
            std::cout << *it1++<< " " << *it2++ << std::endl;
    }

private:
    std::vector<double> coordinates_X;
    std::vector<double> coordinates_Y;
    double perim;
    double Perimeter() const {
        return Perimeter_this();
    }
    double Perimeter_this() const;

};

#endif // FIGURE_H_INCLUDED

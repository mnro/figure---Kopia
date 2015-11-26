#include <iostream>
#include <fstream>
#include "Figure.h"

using namespace std;

/* identify the figure based on deliver string. Compares this string with known figures */
int identifyFigure(const string& s);

double Figure::totalPerimeter = 0;

int main()
{
    Figure::vec_figure_t vec_figures;
    while(1) {
        ifstream fig_file("figures.txt");

        if(!fig_file) {
            cout<< "no figures.txt in the directory" << endl;
            return -1;
        }

        string tmp;
        while(getline(fig_file,tmp)) {
            auto error_flag = 0;
            auto id = identifyFigure(tmp);
            if(id==0) {
                unique_ptr<Figure> ptr(new circle);
                ptr->extractParams(tmp);
                vec_figures.push_back( move(ptr) );
    //            vec_figures.push_back(ptr); // zle
            } else if(id==1) {
                unique_ptr<Figure> ptr(new rectangle);
                ptr->extractParams(tmp);
                vec_figures.push_back( move(ptr) );
            } else if(id==2) {
                unique_ptr<Figure> ptr(new polygon);
                try {
                ptr->extractParams(tmp);
                } catch(invalid_argument err) {
                    cerr << "Error: one of the polygons has " << err.what() <<endl;
                    error_flag = 1;
                }
                if(!error_flag)vec_figures.push_back( move(ptr));
            } else return -1;
        }
        fig_file.close();
        while(1) {
            auto choice = 0;
            cout << "what would you like to do?" << endl << endl <<
                    "1- print the total Perimeter of all figures in the figures.txt" << endl << endl <<
                    "2- print the average perimeter of a figure in the figures.txt" << endl << endl <<
                    "3- I've made some changes in the file. Re-read." << endl << endl <<
                    "-1- exit the program" << endl <<
                    "Your choice:\t";
            while( !(cin >> choice)) {
                cin.clear();
                cin.ignore(10,'\n');
            }
        cout << endl;
        if(choice == -1) return 0;
        if(choice == 1) cout << vec_figures[0]->Perimeter(vec_figures) << endl;
        if(choice == 2) cout << vec_figures[0]->Perimeter(vec_figures, vec_figures.size()) << endl;
        if(choice == 3) {
            vec_figures[0]->setTotalPerimeterToZero();
            vec_figures.clear(); // guess unique_ptrs will destroy allocated objects as well
            break;
        }
        }
    }
}


int identifyFigure(const string& s)
{
    static const string figTypes[] = {"circle", "rectangle", "polygon"};
//    if( search( s.begin(),s.end(), figTypes[0].begin(), figTypes[0].end() ) == s.begin()) return 0;
//    else if( search( s.begin(),s.end(), figTypes[1].begin(), figTypes[1].end() ) == s.begin()) return 1;
//    else if( fsearch( s.begin(),s.end(), figTypes[2].begin(), figTypes[2].end() ) == s.begin()) return 2;
    if( s.compare(0, figTypes[0].length(), figTypes[0]) == 0) return 0;
    else if( s.compare(0, figTypes[1].length(), figTypes[1]) == 0 ) return 1;
    else if( s.compare(0, figTypes[2].length(), figTypes[2]) == 0 ) return 2;
    else {
            cerr << "unidentified figure in the file";
            return -1;
    }
}


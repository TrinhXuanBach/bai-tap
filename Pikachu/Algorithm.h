#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<vector>
#include<string>
#include<math.h>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<SDL_ttf.h>
#include<sstream>
using namespace std;


class Algorithm
{
public:
    void Acurate_Locate(int &x, int &y);
    bool checkLineX( int &y1, int &y2, int &x, vector< vector<int> >&Matrix );
    bool checkLineY( int &x1, int &x2, int &y, vector< vector<int> >&Matrix );
    int checkRectX( SDL_Point& p1, SDL_Point& p2, vector< vector<int> >&Matrix );
    int checkRectY( SDL_Point& p1, SDL_Point& p2, vector< vector<int> >&Matrix );
    int checkMoreLineX( SDL_Point& p1, SDL_Point& p2, vector< vector<int> >&Matrix, int type, int &row, int &column);
    int checkMoreLineY( SDL_Point& p1, SDL_Point& p2, vector< vector<int> >&Matrix, int type, int &row, int &column);
    void printMatrix( vector< vector<int> >&Matrix, int &r, int &c);
    void UpgradeMatrix(SDL_Point &p1, SDL_Point &p2, vector< vector<int> >&Matrix);
    string ConvertString ( int &number, string& result );
};

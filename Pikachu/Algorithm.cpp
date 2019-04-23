#include"Algorithm.h"

void Algorithm::Acurate_Locate(int &x, int &y)
{
    x = x/50 ;
    y = y/50 ;
}
string Algorithm::ConvertString ( int &number, string& result )
{
    ostringstream convert;
    convert << number;
    result = convert.str();
    return result;
}
bool Algorithm::checkLineX( int &y1, int &y2, int &x, vector< vector<int> >&Matrix )
{
    int Ymin = min( y1, y2 );
    int Ymax = max( y1, y2 );
    for ( int i = Ymin + 1; i < Ymax; i++ )
    {
        if ( Matrix[x][i] > 0 )
        {
            return false;
        }
    }
    return true;
}
bool Algorithm::checkLineY( int &x1, int &x2, int &y, vector< vector<int> >&Matrix )
{
    int Xmin = min( x1, x2 );
    int Xmax = max( x1, x2 );
    for ( int i = Xmin + 1; i < Xmax; i++ )
    {
        if ( Matrix[i][y] > 0 )
        {
            return false;
        }
    }
    return true;
}
int Algorithm::checkRectX( SDL_Point& p1, SDL_Point& p2, vector< vector<int> >&Matrix )
{
    vector< vector<int> >M;
    M = Matrix;
   SDL_Point pMin = p1, pMax = p2;
    if ( p1.y > p2.y )
    {
        pMax = p1;
        pMin = p2;
    }
    for ( int i = pMin.y; i <= pMax.y ; i++ )
    {
        if ( i > pMin.y && Matrix[pMin.x][i] > 0 )
        {
            return -1;
        }
        if ( (( Matrix[pMax.x][i] == 0 )|| i == pMax.y )&& checkLineY(pMin.x, pMax.x, i, M) == true && checkLineX(i, pMax.y, pMax.x, M) == true)
        {
            return i;
        }
    }
    return -1;
}
int Algorithm::checkRectY( SDL_Point &p1, SDL_Point &p2, vector< vector<int> >&Matrix )
{
    vector< vector<int> >M;
    M = Matrix;
    SDL_Point pMin = p1, pMax = p2;
    if ( p1.x > p2.x )
    {
        pMax = p1;
        pMin = p2;
    }
    for ( int i = pMin.x; i <= pMax.x ; i++ )
    {
        if ( i > pMin.x && Matrix[i][pMin.y] > 0 )
        {
            return -1;
        }
        if ( (( Matrix[i][pMax.y] == 0 )|| i == pMax.x )&& checkLineX(pMin.y, pMax.y, i, M) == true&& checkLineY(i, pMax.x, pMax.y, M) == true )
        {
            return i;
        }
    }
    return -1;
}
int Algorithm::checkMoreLineX( SDL_Point &p1, SDL_Point &p2, vector< vector<int> >&Matrix, int type, int &row, int &column )
{
    vector< vector<int> >M;
    M = Matrix;
    SDL_Point pMin = p1, pMax = p2;
    if ( p1.y > p2.y )
    {
        pMax = p1;
        pMin = p2;
    }
    if ( type == 1 )
    {
        int k = pMax.y + 1;
        while ( k <= (column - 1) )
        {
            if ( Matrix[pMin.x][k] == 0 && checkLineX(pMin.y, k, pMin.x, M)== true )
            {
                if ( Matrix[pMax.x][k] == 0 && checkLineY(pMin.x, pMax.x, k, M) == true )
                {
                    if ( checkLineX(k, pMax.y, pMax.x, M) == true )
                    {
                        return k;
                    }
                }
            }
            k = k + 1;
        }
    }
    else if ( type == -1 )
    {
        int k = pMin.y - 1 ;
        while ( k >= 0 )
        {
            if ( Matrix[pMin.x][k] == 0 && checkLineX(pMin.y, k, pMin.x, M)== true )
            {
                if ( Matrix[pMax.x][k] == 0 && checkLineY(pMin.x, pMax.x, k, M) == true )
                {
                    if ( checkLineX(k, pMax.y, pMax.x, M) == true )
                    {
                        return k;
                    }
                }
            }
            k = k - 1;
        }
    }
    return -1;
}
int Algorithm::checkMoreLineY( SDL_Point &p1, SDL_Point &p2, vector< vector<int> >&Matrix, int type, int &row, int &column)
{
    vector< vector<int> >M;
    M = Matrix;
    SDL_Point pMin = p1, pMax = p2;
    if ( p1.x > p2.x )
    {
        pMax = p1;
        pMin = p2;
    }
    if ( type == 1 )
    {
        int k = pMax.x + 1;
        while ( k <= (row - 1) )
        {
            if ( Matrix[k][pMin.y] == 0 && checkLineY(pMin.x, k, pMin.y, M)== true )
            {
                if ( Matrix[k][pMax.y] == 0 && checkLineX(pMin.y, pMax.y, k, M) == true )
                {
                    if ( checkLineY(k, pMax.x, pMax.y, M) == true )
                    {
                        return k;
                    }
                }
            }
            k = k + 1;
        }
    }
    else if ( type == -1 )
    {
        int k = pMin.x - 1 ;
        while ( k >= 0 )
        {
            if ( Matrix[k][pMin.y] == 0 && checkLineY(pMin.x, k, pMin.y, M)== true )
            {
                if ( Matrix[k][pMax.y] == 0 && checkLineX(pMin.y, pMax.y, k, M) == true )
                {
                    if ( checkLineY(k, pMax.x, pMax.y, M) == true )
                    {
                        return k;
                    }
                }
            }
            k = k - 1;
        }
    }
    return -1;
}
void Algorithm::printMatrix( vector< vector<int> >&Matrix, int &r, int &c)
{
    for ( int i = 0; i < r; i++ )
    {
        for ( int j = 0; j < c; j++ )
        {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void Algorithm::UpgradeMatrix(SDL_Point &p1, SDL_Point &p2, vector< vector<int> >&Matrix)
{
    Matrix[p1.x][p1.y] = 0;
    Matrix[p2.x][p2.y] = 0;
}

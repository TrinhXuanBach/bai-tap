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


class Graphic
{
public:
    vector< vector<int> >CreateMatrix(vector< vector<int> >&Matrix, int &r, int &c);
    bool init(SDL_Window* &gWindow,SDL_Renderer* &gRenderer, int &SCREEN_WIDTH, int &SCREEN_HEIGHT);
    void close(SDL_Texture* &gTexture, SDL_Renderer* &gRenderer, SDL_Window* &gWindow);
    SDL_Texture* loadTexture( string path, SDL_Renderer* &gRenderer, SDL_Texture* &gTexture );
    SDL_Texture* loadText( string path, TTF_Font* &gFont, SDL_Renderer* &gRenderer, SDL_Texture* &gTexture, SDL_Color &TextColor );
    void load_Number(SDL_Renderer* &gRenderer, SDL_Texture* &gTexture);
    void RenderPicture(vector< vector<int> >&Matrix, SDL_Renderer* &gRenderer, SDL_Texture* &gTexture, int &SCREEN_WIDTH, int &SCREEN_HEIGHT);
    void DrawLine(SDL_Point &p1, SDL_Point &p2, SDL_Renderer* &gRenderer, int &SCREEN_WIDTH, int &SCREEN_HEIGHT);
    void DrawX(SDL_Point &p1, SDL_Point &p2, int &test, SDL_Renderer* &gRenderer, int &SCREEN_WIDTH, int &SCREEN_HEIGHT );
    void DrawY(SDL_Point &p1, SDL_Point &p2, int &test, SDL_Renderer* &gRenderer, int &SCREEN_WIDTH, int &SCREEN_HEIGHT);
    void RenderWin(SDL_Renderer* &gRenderer, SDL_Texture* &gTexture, int &SCREEN_WIDTH, int &SCREEN_HEIGHT);
    void RenderLose(string &result, TTF_Font* &gFont, SDL_Renderer* &gRenderer, SDL_Texture* &gTexture, SDL_Color &TextColor, int &SCREEN_WIDTH, int &SCREEN_HEIGHT);
};

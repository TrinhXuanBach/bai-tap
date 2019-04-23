#include"Graphic.h"
#include"Algorithm.h"
using namespace std;

enum KeyPressSurfaces
{
	KEY_PRESS_TEXTURE_A,
	KEY_PRESS_TEXTURE_R,
	KEY_PRESS_TEXTURE_Q
};
int SCREEN_WIDTH = 600;
int SCREEN_HEIGHT =  400;
int row = 8;
int column = 12;

vector< vector<int> >Matrix(row, vector<int>(column));
SDL_Window* gWindow = NULL;
SDL_Texture* gTexture = NULL;
SDL_Texture* Screen_Texture = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Texture* Text = NULL;
SDL_Color TextColor= { 0, 0 ,0 };
TTF_Font* gFont = NULL;

int main(int argc, char*argv[])
{
    Graphic b;
    Algorithm y;
    b.CreateMatrix(Matrix, row, column);
    b.init(gWindow, gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    gFont = TTF_OpenFont("./Font/VHTIMEI.TTF", 28);
    b.loadTexture("./picture/start.png", gRenderer, gTexture);
    SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
    SDL_RenderPresent(gRenderer);
    SDL_Event e;
    int start = 0;
    int _x, _y;
    int case_1 = -1, case_2 = -1;
    int endgame = 30;
    int score = 0;
    bool play = true;
    bool quit = false;
    bool restart = false;
    bool test = false;
    Uint32 startTime;
    Uint32 x;
    SDL_Point p1, p2, p_Middle;
    while(!quit)
    {
        if ( start == 1 )
        {
            x = SDL_GetTicks() - startTime;
            cout << x << endl;
            if (x >= 60000 && endgame != 0)
            {
                string result;
                y.ConvertString(score, result);
                b.RenderLose(result, gFont, gRenderer, gTexture, TextColor, SCREEN_WIDTH, SCREEN_HEIGHT);
                restart = true;
            }
        }
        while(SDL_PollEvent(&e) != 0)
        {
            if ( e.type == SDL_QUIT )
            {
                quit = true;
            }
            if ( e.type == SDL_KEYDOWN )
                switch (e.key.keysym.sym)
                {
                case SDLK_a:
                    b.load_Number(gRenderer, gTexture);
                    b.RenderPicture(Matrix, gRenderer, gTexture, SCREEN_WIDTH, SCREEN_HEIGHT);
                    SDL_RenderPresent(gRenderer);
                    startTime = SDL_GetTicks();
                    start = 1;
                    break;
                case SDLK_r:
                if ( restart == true)
                {
                    endgame = 30;
                    case_1 = -1, case_2 = -1;
                    play = true;
                    test = false;
                    b.CreateMatrix(Matrix, row, column);
                    b.RenderPicture(Matrix, gRenderer, gTexture, SCREEN_WIDTH, SCREEN_HEIGHT);
                    SDL_RenderPresent(gRenderer);
                    start = 1;
                    startTime = SDL_GetTicks();
                }
                    break;
                case SDLK_q:
                    b.close(gTexture, gRenderer, gWindow);
                    break;
                }
            if (e.type == SDL_MOUSEBUTTONDOWN )
            {
                SDL_GetMouseState(&_x, &_y);
                play = !play;
                p_Middle.x = 0;
                p_Middle.y = 0;
                cout << _x << " " << _y << endl;
                p_Middle.x = _y;
                p_Middle.y = _x;
                y.Acurate_Locate(p_Middle.x, p_Middle.y);
                if (play == false)
                {
                    p1.x = p_Middle.x;
                    p1.y = p_Middle.y;
                }else
                {
                    p2.x = p_Middle.x;
                    p2.y = p_Middle.y;
                    if ( Matrix[p1.x][p1.y] == Matrix[p2.x][p2.y] && ( Matrix[p1.x][p1.y] != 0 ) && (p1.x != p2.x || p1.y != p2.y) )
                    {
                        if (y.checkLineX(p1.y, p2.y, p2.x, Matrix) == true && p1.x == p2.x)
                        {
                            cout << "1" << endl;
                            test = true;
                            score = score + 10;
                            endgame = endgame - 1;
                            y.UpgradeMatrix(p1, p2, Matrix);
                            y.printMatrix(Matrix, row, column);
                        }
                        else if (y.checkLineY(p1.x, p2.x, p2.y, Matrix) == true && p1.y == p2.y)
                        {
                            cout << "2" << endl;
                            test = true;
                            score = score + 10;
                            endgame = endgame - 1;
                            y.UpgradeMatrix(p1, p2, Matrix);
                            y.printMatrix(Matrix, row, column);
                        }
                        else if (y.checkRectX(p1, p2,  Matrix) != -1 )
                        {
                            cout << "3" << endl;
                            endgame = endgame - 1;
                            score = score + 10;
                            case_1 = y.checkRectX(p1, p2,  Matrix);
                            y.UpgradeMatrix(p1, p2, Matrix);
                            y.printMatrix(Matrix, row, column);
                        }
                        else if (y.checkRectY(p1, p2,  Matrix) != -1 )
                        {
                            cout << "4" << endl;
                            endgame = endgame - 1;
                            score = score + 10;
                            case_2 = y.checkRectY(p1, p2,  Matrix);
                            y.UpgradeMatrix(p1, p2, Matrix);
                            y.printMatrix(Matrix, row, column);
                        }
                        else if (y.checkMoreLineX(p1, p2,  Matrix, 1, row, column) != -1 )
                        {
                            cout << "5" << endl;
                            endgame = endgame - 1;
                            score = score + 10;
                            case_1 = y.checkMoreLineX(p1, p2,  Matrix, 1, row, column);
                            y.UpgradeMatrix(p1, p2, Matrix);
                            y.printMatrix(Matrix, row, column);
                        }
                        else if (y.checkMoreLineX(p1, p2,  Matrix, -1, row, column) != -1 )
                        {
                            cout << "6" << endl;
                            endgame = endgame - 1;
                            score = score + 10;
                            case_1 = y.checkMoreLineX(p1, p2,  Matrix, -1, row, column);
                            y.UpgradeMatrix(p1, p2, Matrix);
                            y.printMatrix(Matrix, row, column);
                        }
                        else if (y.checkMoreLineY(p1, p2,  Matrix, 1, row, column) != -1)
                        {
                            cout << "7" << endl;
                            endgame = endgame - 1;
                            score = score + 10;
                            case_2 = y.checkMoreLineY(p1, p2,  Matrix, 1, row, column);
                            y.UpgradeMatrix(p1, p2, Matrix);
                            y.printMatrix(Matrix, row, column);
                        }
                        else if (y.checkMoreLineY(p1, p2,  Matrix, -1, row, column) != -1)
                        {
                            cout << "8" << endl;
                            endgame = endgame - 1;
                            score = score + 10;
                            case_2 = y.checkMoreLineY(p1, p2,  Matrix, -1, row, column);
                            y.UpgradeMatrix(p1, p2, Matrix);


                            y.printMatrix(Matrix, row, column);
                        }
                    }
                    if ( test == true )
                    {
                        b.DrawLine(p1, p2, gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT);
                        test = false;
                        SDL_RenderPresent(gRenderer);
                        SDL_Delay(100);
                        b.RenderPicture(Matrix, gRenderer, gTexture, SCREEN_WIDTH, SCREEN_HEIGHT);
                        SDL_RenderPresent(gRenderer);
                    }else if (case_1 != -1)
                    {
                        b.DrawX(p1, p2, case_1, gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT);
                        case_1 = -1;
                        SDL_RenderPresent(gRenderer);
                        SDL_Delay(100);
                        b.RenderPicture(Matrix, gRenderer, gTexture, SCREEN_WIDTH, SCREEN_HEIGHT);
                        SDL_RenderPresent(gRenderer);
                    }else if (case_2 != -1)
                    {
                        b.DrawY(p1, p2, case_2, gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT);
                        case_2 = -1;
                        SDL_RenderPresent(gRenderer);
                        SDL_Delay(100);
                        b.RenderPicture(Matrix, gRenderer, gTexture, SCREEN_WIDTH, SCREEN_HEIGHT);
                        SDL_RenderPresent(gRenderer);
                    }
                    if ( endgame == 0 )
                    {
                        b.RenderWin(gRenderer, gTexture, SCREEN_WIDTH, SCREEN_HEIGHT);
                        restart = true;
                    }
                }
            }
        }
    }
    b.close(gTexture, gRenderer, gWindow);
    return 0;
}

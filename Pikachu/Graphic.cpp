#include "Graphic.h"

vector< vector<int> > Graphic::CreateMatrix(vector< vector<int> >&Matrix, int &r, int &c )
{
    ifstream infile;
    infile.open("./Matrix/Matrix.txt");
    for ( int i = 0; i < r; i++ )
        for ( int j = 0; j < c; j++ )
            infile >> Matrix[i][j];
    infile.close();
    return Matrix;
}

bool Graphic::init(SDL_Window* &gWindow, SDL_Renderer* &gRenderer, int &SCREEN_WIDTH, int &SCREEN_HEIGHT )
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "PIKACHU", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

				 //Initialize SDL_ttf
				if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
					success = false;
				}
			}
		}
	}
	return success;
}

SDL_Texture* Graphic::loadTexture( string path, SDL_Renderer* &gRenderer, SDL_Texture* &gTexture )
{
    SDL_Surface* loadSurface = IMG_Load( path.c_str() );
    if ( loadSurface == NULL )
    {
        cout << SDL_GetError() << "0";
    }
    else
    {
        gTexture = SDL_CreateTextureFromSurface(gRenderer, loadSurface);
        if ( gTexture == NULL )
        {
            cout << SDL_GetError() << "1";
        }
        else
        {
            SDL_FreeSurface( loadSurface );
        }
    }
    return gTexture;
}

SDL_Texture* Graphic::loadText( string path, TTF_Font* &gFont, SDL_Renderer* &gRenderer, SDL_Texture* &gTexture, SDL_Color &TextColor)
{
    SDL_Surface* loadSurface = TTF_RenderText_Solid( gFont, path.c_str(), TextColor );
    if ( loadSurface == NULL )
    {
        cout << SDL_GetError();
    }
    else
    {
        gTexture = SDL_CreateTextureFromSurface( gRenderer, loadSurface );
        if ( gTexture == NULL )
        {
            cout << SDL_GetError();
        }
        else
        {
            SDL_FreeSurface( loadSurface );
        }
    }
    return gTexture;
}

void Graphic::load_Number(SDL_Renderer* &gRenderer, SDL_Texture* &gTexture)
{
    SDL_RenderClear(gRenderer);
    gTexture = loadTexture("./picture/s3.png", gRenderer, gTexture);
    SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
    SDL_RenderPresent(gRenderer);
    SDL_Delay(1000);
    SDL_RenderClear(gRenderer);
    gTexture = loadTexture("./picture/s2.png", gRenderer, gTexture);
    SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
    SDL_RenderPresent(gRenderer);
    SDL_Delay(1000);
    SDL_RenderClear(gRenderer);
    gTexture = loadTexture("./picture/s1.png", gRenderer, gTexture);
    SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
    SDL_RenderPresent(gRenderer);
    SDL_Delay(1000);
}
void Graphic::RenderPicture(vector< vector<int> >&Matrix, SDL_Renderer* &gRenderer, SDL_Texture* &gTexture, int &SCREEN_WIDTH, int &SCREEN_HEIGHT)
{
    SDL_RenderClear(gRenderer);
    gTexture = loadTexture("./picture/3.png", gRenderer, gTexture );
    SDL_Rect topLeftViewport;
    topLeftViewport.x = 0 ;
    topLeftViewport.y = 0 ;
    topLeftViewport.w = SCREEN_WIDTH;
    topLeftViewport.h = SCREEN_HEIGHT;
    SDL_RenderSetViewport( gRenderer, &topLeftViewport );
    SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
    vector<string>List(30);
    List[0] = "./picture/icon1.png";
    List[1] = "./picture/icon2.png";
    List[2] = "./picture/icon3.png";
    List[3] = "./picture/icon4.png";
    List[4] = "./picture/icon5.png";
    List[5] = "./picture/icon6.png";
    List[6] = "./picture/icon7.png";
    List[7] = "./picture/icon8.png";
    List[8] = "./picture/icon9.png";
    List[9] = "./picture/icon10.png";
    List[10] = "./picture/icon11.png";
    List[11] = "./picture/icon12.png";
    List[12] = "./picture/icon13.png";
    List[13] = "./picture/icon14.png";
    List[14] = "./picture/icon15.png";
    List[15] = "./picture/icon16.png";
    List[16] = "./picture/icon17.png";
    List[17] = "./picture/icon18.png";
    List[18] = "./picture/icon19.png";
    List[19] = "./picture/icon20.png";
    List[20] = "./picture/icon21.png";
    List[21] = "./picture/icon22.png";
    List[22] = "./picture/icon23.png";
    List[23] = "./picture/icon24.png";
    List[24] = "./picture/icon25.png";
    List[25] = "./picture/icon26.png";
    List[26] = "./picture/icon27.png";
    List[27] = "./picture/icon28.png";
    List[28] = "./picture/icon29.png";
    List[29] = "./picture/icon30.png";
    int width = 50, height = 50 ;
    for ( int i = 1; i <= 6; i++ )
    {
        for ( int j = 1; j <= 10; j++ )
        {
            if ( Matrix[i][j] != 0 )
            {
                int potion = Matrix[i][j];
                int locationX = 0, locationY = 0;
                gTexture = loadTexture(List[potion - 1], gRenderer, gTexture);
                SDL_Rect topLeftViewport;
                locationX = locationX + 50*j;
                locationY = locationY + 50*i;
                topLeftViewport.x = locationX ;
                topLeftViewport.y = locationY;
                topLeftViewport.w = width;
                topLeftViewport.h = height;
                SDL_RenderSetViewport( gRenderer, &topLeftViewport );
                SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
            }
        }
    }
}
void Graphic::DrawLine(SDL_Point &p1, SDL_Point &p2, SDL_Renderer* &gRenderer, int &SCREEN_WIDTH, int &SCREEN_HEIGHT)
{
    int x1, y1, x2, y2;
    x1 = p1.y;
    y1 = p1.x;
    y2 = p2.x;
    x2 = p2.y;
    SDL_Rect topLeftViewport;
    topLeftViewport.x = 0;
    topLeftViewport.y = 0;
    topLeftViewport.w = SCREEN_WIDTH;
    topLeftViewport.h = SCREEN_HEIGHT;
    SDL_RenderSetViewport( gRenderer, &topLeftViewport );
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0);
    SDL_RenderDrawLine(gRenderer, 50*x1 + 25 , 50*y1 + 25 , 50*x2 + 25 , 50*y2 + 25);
}
void Graphic::DrawX(SDL_Point &p1, SDL_Point &p2, int &test, SDL_Renderer* &gRenderer, int &SCREEN_WIDTH, int &SCREEN_HEIGHT )
{
    SDL_Rect topLeftViewport;
    topLeftViewport.x = 0;
    topLeftViewport.y = 0;
    topLeftViewport.w = SCREEN_WIDTH;
    topLeftViewport.h = SCREEN_HEIGHT;
    SDL_RenderSetViewport( gRenderer, &topLeftViewport );
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0);
    SDL_Point new_p1 = {p1.y,p1.x}, new_p2 = {p2.y, p2.x};
    SDL_RenderDrawLine(gRenderer, new_p1.x*50+25, new_p1.y*50+25, test*50+25, new_p1.y*50+25 );
    SDL_RenderDrawLine(gRenderer, test*50+25, new_p1.y*50+25, test*50+25, new_p2.y*50+25);
    SDL_RenderDrawLine(gRenderer, test*50+25, new_p2.y*50+25, new_p2.x*50+25, new_p2.y*50+25);
}
void Graphic::DrawY(SDL_Point &p1, SDL_Point &p2, int &test, SDL_Renderer* &gRenderer, int &SCREEN_WIDTH, int &SCREEN_HEIGHT)
{
    SDL_Rect topLeftViewport;
    topLeftViewport.x = 0;
    topLeftViewport.y = 0;
    topLeftViewport.w = SCREEN_WIDTH;
    topLeftViewport.h = SCREEN_HEIGHT;
    SDL_RenderSetViewport( gRenderer, &topLeftViewport );
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0);
    SDL_Point new_p1 = {p1.y,p1.x}, new_p2 = {p2.y, p2.x};
    SDL_RenderDrawLine(gRenderer, new_p1.x*50+25, new_p1.y*50+25, new_p1.x*50+25, test*50+25 );
    SDL_RenderDrawLine(gRenderer, new_p1.x*50+25, test*50+25, new_p2.x*50+25, test*50+25);
    SDL_RenderDrawLine(gRenderer, new_p2.x*50+25, test*50+25, new_p2.x*50+25, new_p2.y*50+25);
}
void Graphic::RenderWin(SDL_Renderer* &gRenderer, SDL_Texture* &gTexture, int &SCREEN_WIDTH, int &SCREEN_HEIGHT)
{
    SDL_RenderClear(gRenderer);
    gTexture = loadTexture("./picture/end.png", gRenderer, gTexture);
    SDL_Rect topLeftViewport;
    topLeftViewport.x = 0 ;
    topLeftViewport.y = 0 ;
    topLeftViewport.w = SCREEN_WIDTH;
    topLeftViewport.h = SCREEN_HEIGHT;
    SDL_RenderSetViewport( gRenderer, &topLeftViewport );
    SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
    SDL_RenderPresent(gRenderer);
}
void Graphic::RenderLose(string &result, TTF_Font* &gFont, SDL_Renderer* &gRenderer, SDL_Texture* &gTexture, SDL_Color &TextColor, int &SCREEN_WIDTH, int &SCREEN_HEIGHT)
{
    SDL_RenderClear(gRenderer);
    gTexture = loadTexture("./picture/Lose.png", gRenderer, gTexture);
    SDL_Rect topLeftViewport;
    topLeftViewport.x = 0 ;
    topLeftViewport.y = 0 ;
    topLeftViewport.w = SCREEN_WIDTH;
    topLeftViewport.h = SCREEN_HEIGHT;
    SDL_RenderSetViewport( gRenderer, &topLeftViewport );
    SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
    topLeftViewport.x = 267;
    topLeftViewport.y = 260;
    topLeftViewport.w = 50;
    topLeftViewport.h = 50;
    SDL_RenderSetViewport( gRenderer, &topLeftViewport );
    gTexture = loadText(result, gFont, gRenderer, gTexture, TextColor );
    SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
    SDL_RenderPresent(gRenderer);
}
void Graphic::close(SDL_Texture* &gTexture, SDL_Renderer* &gRenderer, SDL_Window* &gWindow)
{
    SDL_DestroyTexture( gTexture );
    gTexture = NULL;
    SDL_DestroyRenderer( gRenderer );
    gRenderer = NULL;
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    IMG_Quit();
    SDL_Quit();
}


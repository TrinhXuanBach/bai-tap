#include<iostream>
#include<string>
#include<string.h>
using namespace std;


char* concat(const char* m1, const char* m2)
{
    int x1 = strlen(m1);
    int x2 = strlen(m2);
    char *kq = new char[x1 + x2];
    strcpy(kq, m1);
    strcat(kq, m2);
    return kq;
}
int main()
{
   char mang1[] = "Hello";
   char mang2[] = "World";
   cout << concat( mang1, mang2 );
   //delete concat(mang1, mang2);
}

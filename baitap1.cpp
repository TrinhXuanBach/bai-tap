
#include <iostream>

using namespace std;

int main(){
    int a[3];
    char b[3];
    cout << "Dia chi 3 phan tu mang a:";
    for(int i=0; i<3; i++)
        cout << &a[i] <<" ";
    /*
    Dia chi cua 3 phan tu mang a duoc viet duoi dang hexa
    Moi dia chi cach nhau 4 bit
    */
    cout << endl;
    cout << "Dia chi 3 phan tu mang b:";
    for(int i=0; i<3; i++)
        cout << int(&b[i]) <<" ";
    /*
    Dia chi cua 3 phan tu mang b duoc viet duoi dang so
    Moi dia chi cach nhau 1 don vi
    */
}

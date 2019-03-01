#include<iostream>

using namespace std;

long factorial(long x) {

cout << x <<" " <<  "at: " << &x << endl;
if (x > 1)

return (x * factorial(x-1));

else

return 1;
}
// địa chỉ được biểu diễn dưới dạng hexa
// mỗi phần cách nhau 20 byte -> mỗi stack frame là 20 byte
int main()
{
    long x;
    cin >> x;
    factorial(x);
    return 0;
}

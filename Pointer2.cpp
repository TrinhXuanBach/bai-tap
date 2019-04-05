#include<iostream>

using namespace std;

int main()
{
    int* p = new int;
    int* p2 = p;
    *p = 10;
    delete p;
    *p2 = 100;

    cout << *p2;
    delete p2;
    // giải phóng bộ nhớ p quá sớm khi con trỏ p2 đang trỏ tới vùng bộ nhớ p, vì vậy p2 đang trỏ đến vùng bộ nhớ không xác định.
    // lỗi ở câu lệnh "cout << *p2 ";
}

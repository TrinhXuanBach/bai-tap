#include<iostream>
using namespace std;


int main()
{
   int x = 4;
   int *p = new int;
   p = &x;
   delete p;
   cout << x;
   cout << &x;
   // chương trình bị lỗi "has stopped working"
   /* vì con trỏ p đang trỏ tới địa chỉ của biến x bị giải phóng sớm
   nên vùng nhớ chứa địa chỉ của biến x bị mất -> vùng nhớ x sẽ không tồn tại
   nên khi chúng ta in ra x hay &x thì sẽ dẫn đến lỗi khi truy cập vùng nhớ không tồn tại*/
}

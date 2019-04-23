// bài nay em chạy trên hackkerrank đúng 8/10 test, 2 test bị timeout
#include<iostream>
#include<vector>
using namespace std;
void sherlock(vector<int>dayso, int sum)
{

    if ( sum - dayso[dayso.size()-1] == 0 )
    {
        cout << "YES";
        return;
    }
    else
    {


        for ( int i = 0; i < dayso.size() - 1 ; i++ )
        {
            int tong = 0;
            for ( int j = i + 1; j < dayso.size(); j++ )
            {
                tong = tong + dayso[j];
            }
            if (tong == sum - tong - dayso[i])
            {
                cout << "YES";
                return ;
            }
        }
    }
    cout << "NO";
    return ;
}
int main()
{
    int test, tong, so;
    cin >> test;
    for ( int i = 0; i < test; i++ )
    {
        cin >> tong;
        vector<int>dayso;
        int sum = 0;
        for ( int i = 0; i < tong; i++ )
        {
            cin >> so;
            sum = sum + so;
            dayso.push_back(so);
        }
        sherlock(dayso, sum);
        cout << endl;
    }

}


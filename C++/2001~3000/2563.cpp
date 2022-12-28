// 2563번 BOJ

#include <iostream>
using namespace std;

int main()
{
    int max = 100;

    int area[max + 1][max + 1] = {0,};

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;

        for (int a = x; a < x + 10; a++)
        {
            for (int b = y; b < y + 10; b++)
            {
                area[a][b] = 1;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < max + 1; i++)
    {
        for (int j = 0; j < max + 1; j++)
        {
            if(area[i][j] == 1){
                result += 1;
            }
        }
    }
    cout << result;
}
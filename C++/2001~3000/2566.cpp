// 2566번 BOJ

#include <iostream>
using namespace std;

int main()
{
    int N = 9;

    int array[N][N];
    int row = 0, column = 0, max = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> array[i][j];

            if (max < array[i][j])
            {
                max = array[i][j];
                row = i;
                column = j;
            }
        }
    }

    row = row + 1;
    column = column + 1;
    cout << max << endl << row << ' ' << column;
}

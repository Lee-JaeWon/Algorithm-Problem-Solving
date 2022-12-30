// 1978번 BOJ

#include <iostream>
using namespace std;

bool prime_num(int value);

int main()
{

    // 첫 줄 입력 : 개수
    int N;
    cin >> N;

    // 두번째 줄 입력 : 1000이하의 값(자연수)
    int val[N] = {
        0,
    };

    // 소수 판별
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> val[i];

        if (prime_num(val[i]))
        {
            result += 1;
        }
    }

    cout << result;
}

bool prime_num(int value)
{
    if (value < 2){ // 1은 소수가 아니다.
        return false;
    }
    for (int i = 2; i < value; i++) // 주어진 값부터 그 값 전까지 모두 나누기
    {
        if (value % i == 0)
        {
            return false;
        }
    }
    return true;
}
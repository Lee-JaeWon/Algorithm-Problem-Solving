// 10816번 BOJ

#include <iostream>
#include <map>
using namespace std;

// map으로 풀이 -> 시간초과 아슬아슬
int main()
{
    // 해당 구문 추가 안할 시 시간 초과남
    // 있어도 아슬아슬하다.
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    map<int, int> m1;
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        m1[num]++;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> num;
        cout << m1[num] << ' ';
    }

    return 0;
}
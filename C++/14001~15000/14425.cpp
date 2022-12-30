// 14425번 BOJ
// 자료구조 문제? --> 이 문제에서는 map contatiner 사용

#include <iostream>
#include <map>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    std::map<string, bool> m; // key, value structure
    string str;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        m.insert(pair<string, bool>(str, true));
    }

    int result = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> str;
        if (m[str] == true) // map container, m의 [str]키가 true면?
           result++; // True
    }

    cout << result;
}
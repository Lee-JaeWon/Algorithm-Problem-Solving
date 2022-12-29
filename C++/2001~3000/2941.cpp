// 2941번 BOJ

// 목록에 없으면 한 글자

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // 주어진 알파벳
    std::string ori[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    // 문자열 입력
    std::string str1;
    cin >> str1;

    // 문자열 총 길이
    size_t total_len = str1.length();

    // 순서대로 찾으면서 지우는 방식으로
    size_t temp_len = 0;
    std::string buf = "#";
    
    for (int i = 0; i < 8; i++)
    {
        while (1)
        {
            size_t nPos = str1.find(ori[i]);

            if (nPos == string::npos) // 찾고자 하는 문자열이 없다면
            {
                break;
            }
            str1.replace(nPos, ori[i].length(), buf);
        }
    }

    cout << str1.length();
}
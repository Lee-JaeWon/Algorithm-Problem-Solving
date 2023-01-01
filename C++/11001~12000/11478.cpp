#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int len = str.length();

    string temp;
    map<string,bool> m;
    for (int i = 1; i <= len; i++)
    {
        for (int j = 0; j <= len - i; j++)
        {
            temp = str.substr(j, i);
            m.insert(pair<string, bool>(temp, true));
        }
    }

    // map 특성 -> 이미 존재하는 key면 insert하지 않음. 그래서 map 사용해봄.
    int map_size = m.size();
    cout << map_size;
}
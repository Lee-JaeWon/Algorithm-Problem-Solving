#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int N = 8;
    int pre, cur;
    std::cin >> cur;
    pre = cur;

    int flag_ascending = 1;
    int flag_descending = 1;

    for (int i = 1; i < N; i++)
    {
        std::cin >> cur;
        if (cur - pre == 1)
        {
            flag_ascending++;
        }
        if (cur - pre == -1)
        {
            flag_descending++;
        }
        pre = cur;
    }
    if (flag_ascending == 8)
    {
        std::cout << "ascending";
    }
    else if (flag_descending == 8)
    {
        std::cout << "descending";
    }
    else
    {
        std::cout << "mixed";
    }

    return 0;
}
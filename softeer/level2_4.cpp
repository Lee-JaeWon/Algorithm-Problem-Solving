#include <iostream>

using namespace std;

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

int main(int argc, char **argv)
{
    fastio;

    int N;
    std::cin >> N;

    int temp = 2;

    for (int i = 1; i <= N; i++)
    {
        temp = (temp - 1) + temp;
    }
    std::cout << temp * temp;

    return 0;
}
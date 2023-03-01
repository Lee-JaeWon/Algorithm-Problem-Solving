#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    int M, N, K;
    std::cin >> M >> N >> K;

    int temp;

    int key[M];
    std::string key_s;
    for (int i = 0; i < M; i++)
    {
        std::cin >> key[i];
        key_s += std::to_string(key[i]);
    }

    int ori[N];
    std::string ori_s;
    for (int i = 0; i < N; i++)
    {
        std::cin >> ori[i];
        ori_s += std::to_string(ori[i]);
    }

    if (ori_s.find(key_s) != string::npos)
    {
        std::cout << "secret";
    }
    else
    {
        std::cout << "normal";
    }

    return 0;
}
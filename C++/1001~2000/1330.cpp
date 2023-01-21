#include <iostream>

int main(void)
{

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int A, B;
    std::cin >> A >> B;

    if (A > B)
    {
        std::cout << '>';
    }
    else if (A < B)
    {
        std::cout << '<';
    }
    else if (A == B)
    {
        std::cout << "==";
    }

    return 0;
}
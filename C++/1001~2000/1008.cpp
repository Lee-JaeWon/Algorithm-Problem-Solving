#include <iostream>

using namespace std;

int main(void)
{

    double A, B;
    std::cin >> A >> B;

    std::cout.precision(12);
    std::cout << fixed;
    std::cout << A / B;

    return 0;
}
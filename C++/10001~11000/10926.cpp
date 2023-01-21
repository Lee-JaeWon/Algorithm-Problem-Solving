#include <iostream>
#include <string>

int main(void)
{

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string str1;
    std::string str2 = "??!";

    std::cin >> str1;
    std::cout << str1 + str2;

    return 0;
}
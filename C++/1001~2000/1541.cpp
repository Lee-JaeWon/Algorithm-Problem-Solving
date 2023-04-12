#include <iostream>
#include <string>
#include <queue>
#include <vector>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

int main(int argc, char **argv)
{
    fastio;

    // input
    std::string str;
    std::cin >> str;

    bool isMinus = false;
    std::string num;
    int res = 0;
    for (int i = 0; i < str.size() + 1; i++)
    {
        if(str[i] == '-' || str[i] == '+' || i == str.size())
        {
            if(isMinus){
                res -= std::stoi(num);
                num = "";
            }
            else{
                res += std::stoi(num);
                num = "";
            }
        }
        else{
            num += str[i];
            // std::cout << num << "e\n";
        }

        if(str[i] == '-'){
            isMinus = true;
        }
    }
    std::cout << res;

    return 0;
}
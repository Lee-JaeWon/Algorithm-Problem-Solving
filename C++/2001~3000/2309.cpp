#include <iostream>
#include <vector>
#include <algorithm>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define TOT 9

int main(void)
{
    fastio;

    int n;
    std::vector<int> vec;
    int sum = 0;
    for (int i = 0; i < TOT; i++)
    {
        std::cin >> n;
        sum += n;
        vec.push_back(n);
    }
    std::sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size() - 1; i++)
    {
        for (int j = i + 1; j < vec.size(); j++)
        {
            if ((sum - (vec[i] + vec[j])) == 100)
            {
                for (int k = 0; k < vec.size(); k++)
                {
                    if (k != i && k != j)
                    {
                        std::cout << vec[k] << "\n";
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}
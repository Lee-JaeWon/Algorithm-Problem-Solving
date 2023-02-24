#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    std::string time_1, time_2;

    int N = 5;
    int result_hour = 0;
    int result_min = 0;
    for (int i = 0; i < N; i++)
    {
        std::cin >> time_1 >> time_2;

        int hour1 = stoi(time_1.substr(0, 2));
        int min1 = stoi(time_1.substr(3, 2));

        int hour2 = stoi(time_2.substr(0, 2));
        int min2 = stoi(time_2.substr(3, 2));

        result_hour += (hour2 - hour1) * 60;
        if (min1 > min2)
        {
            result_min += 60 - (min1 - min2);
            result_hour -= 60;
        }
        else if (min1 <= min2)
        {
            result_min += (min2 - min1);
        }
    }
    std::cout << result_hour + result_min;

    return 0;
}
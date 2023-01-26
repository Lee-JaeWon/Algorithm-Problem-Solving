#include <iostream>
#include <cmath>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

using namespace std;

int main(void)
{
    fastio;

    int T;
    std::cin >> T;

    int x1, y1, r1;
    int x2, y2, r2;

    int ans = 0, cond1, cond2;
    for (int i = 0; i < T; i++)
    {
        std::cin >> x1 >> y1 >> r1;
        std::cin >> x2 >> y2 >> r2;

        ans = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
        cond1 = (r1 - r2) * (r1 - r2);
        cond2 = (r1 + r2) * (r1 + r2);

        if (ans == 0)
        {
            if (cond1 == 0)
                cout << "-1" << '\n';
            else
                cout << "0" << '\n';
        }
        else if (ans == cond1 || ans == cond2)
            cout << "1" << '\n';
        else if (cond1 < ans && ans < cond2)
            cout << "2" << '\n';
        else
            cout << "0" << '\n';
    }

    return 0;
}
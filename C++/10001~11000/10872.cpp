#include <iostream>

using namespace std;

int main(){

    int num;
    int total = 1;
    cin >> num;
    if (num < 0 && num > 12)
        return 0;
    if (num == 0)
        total == 1;
    else{
        for (int i = 1; i <= num; i++){
            total *= i;
        }
    }
    cout << total; 
}
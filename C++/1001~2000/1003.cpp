#include <iostream>
using namespace std;

int main() {
	int test_case;
	cin >> test_case;

	int* fibonacci_tbl = new int[41];
	fibonacci_tbl[0] = 0; fibonacci_tbl[1] = 1;

	for (int i = 2; i < 41; i++) {
		fibonacci_tbl[i] = fibonacci_tbl[i - 1] + fibonacci_tbl[i - 2];
	}

	for (int i = 0; i < test_case; i++) {
		int num;
		cin >> num;

		if (num == 0)
			cout << "1 0" << endl;
		else
			cout << fibonacci_tbl[num - 1] << " " << fibonacci_tbl[num] << endl;
	}

	delete[] fibonacci_tbl;
}
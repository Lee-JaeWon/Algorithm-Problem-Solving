//2447
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>
#include <math.h>

void Allspot(char(*spot)[1000], int);
void Holespot(char(*spot)[1000], int, int);
void Space(char(*spot)[1000], int, int, int);

int main(void) {

	int num;

	char spot[1000][1000];
	scanf("%d", &num);

	if (num % 3 != 0) {
		printf("Error!\n\n");
		return 0;
	}
	Allspot(spot, num);
	Holespot(spot, num / 3, 0);

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			printf("%c", spot[i][j]);
		}
		printf("\n");
	}

	return 0;
}

// n*n 점 찍기
void Allspot(char(*spot)[1000], int num) { // 2차원 배열, 입력
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			spot[i][j] = '*';
}

// 좌표 찾기
void Holespot(char(*spot)[1000], int n, int cnt) { // 2차원 배열, 입력/3, count

	if (n > 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				Space(spot, (int)pow(3, cnt) + i * (int)pow(3, cnt + 1), (int)pow(3, cnt) + j * (int)pow(3, cnt + 1), cnt);
			}
		}
		Holespot(spot, n / 3, cnt + 1);
	}
}

//공백 삽입
void Space(char(*spot)[1000], int x, int y, int cnt) {  // 2차원 배열, x, y, count
	for (int i = x; i < x + (int)pow(3, cnt); i++) {
		for (int j = y; j < y + (int)pow(3, cnt); j++) {
			spot[i][j] = ' ';
		}
	}
}
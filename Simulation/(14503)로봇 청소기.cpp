/*
문제
로봇 청소기가 주어졌을 때, 청소하는 영역의 개수를 구하는 프로그램을 작성하시오.

로봇 청소기가 있는 장소는 N×M 크기의 직사각형으로 나타낼 수 있으며, 1×1크기의 정사각형 칸으로 나누어져 있다.
각각의 칸은 벽 또는 빈 칸이다.
청소기는 바라보는 방향이 있으며, 이 방향은 동, 서, 남, 북중 하나이다.
지도의 각 칸은 (r, c)로 나타낼 수 있고, r은 북쪽으로부터 떨어진 칸의 개수, c는 서쪽으로 부터 떨어진 칸의 개수이다.

로봇 청소기는 다음과 같이 작동한다.

현재 위치를 청소한다.
현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
로봇 청소기는 이미 청소되어있는 칸을 또 청소하지 않으며, 벽을 통과할 수 없다.

입력
첫째 줄에 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 50)

둘째 줄에 로봇 청소기가 있는 칸의 좌표 (r, c)와 바라보는 방향 d가 주어진다.
d가 0인 경우에는 북쪽을, 1인 경우에는 동쪽을, 2인 경우에는 남쪽을, 3인 경우에는 서쪽을 바라보고 있는 것이다.

셋째 줄부터 N개의 줄에 장소의 상태가 북쪽부터 남쪽 순서대로, 각 줄은 서쪽부터 동쪽 순서대로 주어진다.
빈 칸은 0, 벽은 1로 주어진다. 장소의 모든 외곽은 벽이다.

로봇 청소기가 있는 칸의 상태는 항상 빈 칸이다.

출력
로봇 청소기가 청소하는 칸의 개수를 출력한다.

예제 입력 1
3 3
1 1 0
1 1 1
1 0 1
1 1 1

예제 출력 1
1

예제 입력 2
11 10
7 4 0
1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 1 1 1 1 0 1
1 0 0 1 1 0 0 0 0 1
1 0 1 1 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1

예제 출력 2
57
*/

#include <stdio.h>
#include <iostream>

#pragma warning(disable:4996)

using namespace std;

int main() {
	int n, m;
	int r, c, d, x, y;
	int coord[50][50];
	int cnt = 0, roundCnt = 0;

	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &d);
	x = c;
	y = n - r - 1;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &coord[i][j]);
		}
	}

	coord[x][y] = 1;
	cnt++;
	printf("(%d, %d)", x, y);
	while (true) {
		if (roundCnt == 4) {
			if (d == 0) {
				if (y - 1 >= 0 && coord[x][y - 1] != 1) {
					y--;
					roundCnt = 0;
				}
				else {
					break;
				}
			}
			else if (d == 1) {
				if (x - 1 >= 0 && coord[x - 1][y] != 1) {
					x--;
					roundCnt = 0;
				}
				else {
					break;
				}
			}
			else if (d == 2) {
				if (y + 1 < n && coord[x][y + 1] != 1) {
					y++;
					roundCnt = 0;
				}
				else {
					break;
				}
			}
			else if (d == 3) {
				if (x + 1 < m && coord[x + 1][y] != 1) {
					x++;
					roundCnt = 0;
				}
				else {
					break;
				}
			}
		}

		if (d == 0) {
			if (x - 1 >= 0) {
				if (coord[x - 1][y] == 0) {
					d = 3;
					x--;
					coord[x][y] = -1;
					cnt++;
					printf("(%d, %d)", x, y);
				}
				else {
					d = 3;
					roundCnt++;
				}
			}
			else {
				d = 3;
				roundCnt++;
			}
		}
		else if (d == 1) {
			if (y + 1 < n) {
				if (coord[x][y + 1] == 0) {
					d = 0;
					y++;
					coord[x][y] = -1;
					printf("(%d, %d)", x, y);
					cnt++;
				}
				else {
					d = 0;
					roundCnt++;
				}
			}
			else {
				d = 0;
				roundCnt++;
			}
		}
		else if (d == 2) {
			if (x + 1 < m) {
				if (coord[x + 1][y] == 0) {
					d = 1;
					x++;
					coord[x][y] = -1;
					printf("(%d, %d)", x, y);
					cnt++;
				}
				else {
					d = 1;
					roundCnt++;
				}
			}
			else {
				d = 1;
				roundCnt++;
			}
		}
		else if (d == 3) {
			if (y - 1 >= 0) {
				if (coord[x][y - 1] == 0) {
					d = 2;
					y--;
					coord[x][y - 1] = -1;
					printf("(%d, %d)", x, y);
					cnt++;
				}
				else {
					d = 2;
					roundCnt++;
				}
			}
			else {
				d = 2;
				roundCnt++;
			}
		}
	}

	printf("%d", cnt);

	return 0;
}
/*
문제
길이가 L(1≤L≤1,000,000,000)인 막대기 위에 N(1≤N≤100,000)마리의 개미들이 서로 다른 위치에 살고 있다.
개미들은 크기가 매우 작기 때문에 이 문제에서는 개미가 크기가 없는 점이라고 생각하자.
각각의 개미의 위치는 x좌표로 표시되며, 좌표값은 0보다 크고 L보다 작은 값으로 표현된다.

각각의 개미는 왼쪽, 혹은 오른쪽으로 움직이고 있다.
모든 개미들은 똑같은 속도로, 1초에 한 칸씩 움직인다.
개미들이 움직이는 도중에 서로 부딪히는 경우가 생길 수도 있다.
두 마리의 개미가 서로 부딪혔을 때, 두 마리의 개미는 모두 즉시 방향을 바꾸어 다시 움직이게 된다.

개미들이 이동하다가 0인 위치나 L인 위치에 도달하게 되면, 그 개미는 막대기 아래로 떨어지게 된다.
개미들의 초기상태가 주어졌을 때, 가장 마지막에 떨어지는 개미와 그 개미가 떨어지는 시각을 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 두 정수 N, L이 주어진다.
다음 N개의 줄에는 각 개미의 초기 위치가 주어진다.
초기 위치가 양수로 주어지는 경우는 그 값이 그 개미의 위치가 되며, 그 개미는 오른쪽으로 움직이고 있다.
초기 위치가 음수로 주어지는 경우에는 그 절댓값이 그 개미의 위치가 되며, 그 개미는 왼쪽으로 움직이고 있다.
예를 들어 3이 주어지는 경우에는 3인 위치에서 오른쪽으로 움직이고 있고, -7인 경우에는 7인 위치에서 왼쪽으로 움직이고 있다.

출력
첫째 줄에 두 정수 i, t를 출력한다.
i는 가장 마지막에 떨어지는 개미의 번호이다.
개미의 번호는 입력에서 주어지는 순서대로 1, 2, …, N이다.
t는 가장 마지막에 떨어지는 개미가 바닥에 떨어지는 시간이다.
가장 마지막에 떨어지는 개미가 여러 마리인 경우는 없다고 가정한다.

예제 입력 1
2 5
4
-3

예제 출력 1
2 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <algorithm>
#pragma warning(disable: 4996)

using namespace std;

int main() {

	int n, l;
	map<int, int> ants; // key pair array로 바꾸자
	map<int, int>::iterator it;
	int lastTime = 0, d, leftCnt = 0, rightCnt = 0, cnt = 0;
	
	scanf("%d %d", &n, &l);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &ants[i]);
	}

	for (it = ants.begin(); it != ants.end(); it++) {
		printf("%d %d\n", it->first, it->second);
	}

	for (int i = 1; i <= n; i++) {
		if (ants[i] > 0) { // 개미가 오른쪽 방향일 떄
			if (l - ants[i] > lastTime) {
				lastTime = l - ants[i]; // 떨어지는데 걸리는 시간은 (l - ants[i]) 초
				d = 1; // 마지막 개미 오른쪽 방향으로 저장
			}

			rightCnt++; // 오른쪽 방향 개미 증가
		}

		else {
			if (ants[i] > lastTime) { // 개미가 왼쪽 방향일 때
				lastTime = -ants[i]; // 떨어지는데 걸리는 시간은 (-ants[i]) 초
				ants[i] = -ants[i];
				d = -1; // 마지막 개미 왼쪽 방향으로 저장
			}

			leftCnt++; // 왼쪽 방향 개미 증가
		}
	}

	if (d == 1) { // 마지막에 떨어지는 개미가 오른쪽 방향이면
		printf("%d %d", ants[n-rightCnt], lastTime);
	}
	else { // 마지막에 떨어지는 개미가 왼쪽 방향이면
		printf("%d %d", ants[leftCnt], lastTime);
	}

	return 0;
}
/*
문제
상근이는 우주선을 타고 인간이 거주할 수 있는 행성을 찾고 있다.
마침내, 전 세계 최초로 인간이 거주할 수 있는 행성을 찾았다.
이 행성은 정글, 바다, 얼음이 뒤얽힌 행성이다.
상근이는 이 행성에서 거주 할 수 있는 구역의 지도를 만들어 지구로 보냈다.

상근이가 보내온 지도는 가로 Ncm, 세로 Mcm 직사각형 모양이다.
지도는 1cm 크기의 정사각형으로 나누어져 있고, 각 구역의 지형이 알파벳으로 표시되어 있다.
지형은 정글, 바다, 얼음 중 하나이며, 정글은 J, 바다는 O, 얼음은 I로 표시되어 있다.

지구에 있는 정인이는 조사 대상 영역을 K개 만들었다.
이때, 각 영역에 정글, 바다, 얼음이 각각 몇 개씩 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 지도의 크기 M과 N이 주어진다. (1 ≤ M, N ≤ 1000)
둘째 줄에 정인이가 만든 조사 대상 영역의 개수 K가 주어진다. (1 ≤ K ≤ 100000)
셋째 줄부터 M개 줄에는 상근이가 보낸 지도의 내용이 주어진다.
다음 K개 줄에는 조사 대상 영역의 정보가 주어진다.
정보는 네 정수 a b c d로 이루어져 있다.
구역은 직사각형 모양 이며, 왼쪽 위 모서리의 좌표가 (a, b) 오른쪽 아래 모서리의 좌표가 (c, d)이다.

출력
각 조사 대상 영역에 포함되어 있는 정글, 바다, 얼음의 수를 공백으로 구분해 한 줄에 한 정보씩 출력한다.

예제 입력 1
4 7
4
JIOJOIJ
IOJOIJO
JOIJOOI
OOJJIJO
3 5 4 7
2 2 3 6
2 2 2 2
1 1 4 7

예제 출력 1
1 3 2
3 5 2
0 1 0
10 11 7
*/

#include <stdio.h>
#include <iostream>

#pragma warning(disable: 4996)

using namespace std;

int main() {

	char arr[1000][1000];
	int n, m, k;
	int a, b, c, d;
	int jCnt = 0, oCnt = 0, iCnt = 0;

	scanf("%d %d", &n, &m);
	scanf("%d", &k);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);


		for (int p = a - 1; p < c; p++) {
			for (int q = b - 1; q < d; q++) {
				if (arr[p][q] == 'J') {
					jCnt++;
				}
				else if (arr[p][q] == 'O') {
					oCnt++;
				}
				else if (arr[p][q] == 'I') {
					iCnt++;
				}
			}
		}
		printf("%d %d %d", jCnt, oCnt, iCnt);
		
		jCnt = 0;
		oCnt = 0;
		iCnt = 0;
	}

	return 0;
}
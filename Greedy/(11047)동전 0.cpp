/*
문제
준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.

동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)

둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다. (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)

출력
첫째 줄에 K원을 만드는데 필요한 동전 개수의 최솟값을 출력한다.

예제 입력 1
10 4200
1
5
10
50
100
500
1000
5000
10000
50000

예제 출력 1
6


예제 입력 2
10 4790
1
5
10
50
100
500
1000
5000
10000
50000

예제 출력 2
12
*/

#include <iostream>

#pragma warning(disable:4996)

using namespace std;

int main() {

	int n, k, pos, once=0, cnt=0; // pos : k값에서 빼줄 수 있는 가장 큰 금액의 동전 index, cnt : 필요한 동전 개수 count한 값
	int coin[10]; // 주어지는 동전의 종류

	cin >> n;
	cin >> k;

	pos = n; // pos에 가장 큰 금액의 동전 index를 저장

	for (int i = 0; i < n; i++) { // 동전 입력

		cin >> coin[i];

		if (k < coin[i] && once ==0) { // k값 보다 금액이 큰 동전이 있다면, k값 보다 그것보다 금액이 한 단계 낮은 동전의 index 저장 
			pos = i;
			once = 1;
		}
	}

	pos -= 1;

	while (k != 0) { // k값이 0이 될 때까지

		cnt += k / coin[pos]; // k값에서 빼줄 수 있는 가장 큰 금액을 빼줄 때, 몇 번 빼주는지 count 값 저장
		k = k - coin[pos] * (k / coin[pos]); // k값에서 빼줄 수 있는 가장 큰 금액을 빼줌

		while (coin[pos] > k) { // 그 다음으로 빼줄 수 있는 가장 큰 금액의 동전 탐색

			pos--;
		}
	}

	cout << cnt;

	return 0;
}
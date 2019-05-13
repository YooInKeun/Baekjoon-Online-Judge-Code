/*
문제
오늘은 2007년 1월 1일 월요일이다. 그렇다면 2007년 x월 y일은 무슨 요일일까? 이를 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 빈 칸을 사이에 두고 x(1≤x≤12)와 y(1≤y≤31)이 주어진다. 참고로 2007년에는 1, 3, 5, 7, 8, 10, 12월은 31일까지, 4, 6, 9, 11월은 30일까지, 2월은 28일까지 있다.

출력
첫째 줄에 x월 y일이 무슨 요일인지에 따라 SUN, MON, TUE, WED, THU, FRI, SAT중 하나를 출력한다.

예제 입력 1
1 1
예제 출력 1
MON
예제 입력 2
3 14
예제 출력 2
WED
예제 입력 3
9 2
예제 출력 3
SUN
예제 입력 4
12 25
예제 출력 4
TUE
*/

#include <iostream>

#pragma warning(disable:4996)

using namespace std;

int main() {

	int m[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, month, day, sum = 0, result;

	scanf("%d", &month);
	scanf("%d", &day);


	for (int i = 0; i < month - 1; i++) {

		if (month == 1) {

			break;
		}

		sum += m[i];
	}

	sum += day;

	result = sum % 7;

	if (result == 0) {

		printf("SUN");
	}

	else if (result == 1) {

		printf("MON");
	}

	else if (result == 2) {

		printf("TUE");
	}

	else if (result == 3) {

		printf("WED");
	}

	else if (result == 4) {

		printf("THU");
	}

	else if (result == 5) {

		printf("FRI");
	}

	else if (result == 6) {

		printf("SAT");
	}

	return 0;
}
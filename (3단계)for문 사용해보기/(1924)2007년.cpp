/*
����
������ 2007�� 1�� 1�� �������̴�. �׷��ٸ� 2007�� x�� y���� ���� �����ϱ�? �̸� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �� ĭ�� ���̿� �ΰ� x(1��x��12)�� y(1��y��31)�� �־�����. ����� 2007�⿡�� 1, 3, 5, 7, 8, 10, 12���� 31�ϱ���, 4, 6, 9, 11���� 30�ϱ���, 2���� 28�ϱ��� �ִ�.

���
ù° �ٿ� x�� y���� ���� ���������� ���� SUN, MON, TUE, WED, THU, FRI, SAT�� �ϳ��� ����Ѵ�.

���� �Է� 1
1 1
���� ��� 1
MON
���� �Է� 2
3 14
���� ��� 2
WED
���� �Է� 3
9 2
���� ��� 3
SUN
���� �Է� 4
12 25
���� ��� 4
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
/*
����
1���� N������ ���� �̾ ���� ������ ���� ���ο� �ϳ��� ���� ���� �� �ִ�.

1234567891011121314151617181920212223...

�̷��� ������� ���ο� ���� �� �ڸ� ���ϱ�? �� ���� �ڸ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N(1��N��100,000,000)�� �־�����.

���
ù° �ٿ� ���ο� ���� �ڸ����� ����Ѵ�.

���� �Է� 1
120
���� ��� 1
252
*/

#include <stdio.h>
#pragma warning(disable:4996)

using namespace std;

int main() {

	int n, cnt, divider, check;
	cnt = 0;
	divider = 10;
	check = 1;
	
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		if (i / divider > 0) {
			divider *= 10;
			check++;
		}
		cnt += check;
	}

	printf("%d", cnt);

	return 0;
}
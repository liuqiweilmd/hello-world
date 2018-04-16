#include <iostream>
#include <cstdio>
#include <cmath>
#define maxn 10005
int num[maxn];
int tmp[maxn];
void change(int head, int rear, int len) {
	if (len>2) {
		int newlen = len / 2;
		//将变换后内容存放在tmp中
		for (int i = head, j = 0; i <= rear; i++) {
			if (i % 2 == 0)
				tmp[j++] = num[i];
			else
				tmp[newlen + j - 1] = num[i];
		}
		//将tmp复制给num
		for (int i = head, j = 0; i <= rear; i++, j++) {
			num[i] = tmp[j];
		}
		change(head, newlen - 1, newlen);//左边
		change(newlen, rear, newlen);//右边
	}
	else
		return;
}
int main() {
	int n;
	int k;
	int len;
	while (scanf("%d", &n) != EOF) {
		scanf("%d", &k);
		len = pow(2, k);
		for (int i = 0; i<len; i++) {
			scanf("%d", &num[i]);
		}
		change(0, len - 1, len);
		for (int i = 0; i<len; i++) {
			printf("%d", num[i]);
			if (i != len - 1)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}

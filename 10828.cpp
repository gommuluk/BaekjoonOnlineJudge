#include <cstdio>

int main() {
	
	int N, num = 0;
	char q[10];
	int stk[10000], top = -1; // stack

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", q);
		if (q[0] == 'p') {
			if (q[1] == 'u') {
				scanf("%d", &num);
				stk[++top] = num;
			}
			else if (q[1] == 'o') {
				if (top == -1) printf("-1 \n");
				else printf("%d \n", stk[top--]);
			}
		}
		else if (q[0] == 's') {
			printf("%d \n", top + 1);
		}
		else if (q[0] == 'e') {
			top == -1 ? printf("1 \n") : printf("0 \n");
		}
		else if (q[0] == 't') {
			if (top == -1) printf("-1 \n");
			else printf("%d \n", stk[top]);
		}
	}

	return 0;
}
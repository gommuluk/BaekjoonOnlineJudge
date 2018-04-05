#include <cstdio>

int queue[10010], front = -1, back = -1, N;

int main() {

	char q[10];
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", q);
		if (q[0] == 'p') {
			if (q[1] == 'u') {
				int tmp;
				scanf("%d", &tmp);
				queue[++back] = tmp;
				if (front == -1) ++front;
			}
			else if (q[1] == 'o') {
				if (front == -1 || front == back + 1) printf("-1\n");
				else printf("%d\n", queue[front++]);
			}
		}
		else if (q[0] == 's') {
			if (front == -1) printf("0\n");
			else printf("%d\n", back - front + 1);
		}
		else if (q[0] == 'e') {
			if (front == -1 || front == back + 1) printf("1\n");
			else printf("0\n");
		}
		else if (q[0] == 'f') {
			if (front == -1 || front == back + 1) printf("-1\n");
			else printf("%d\n", queue[front]);
		}
		else if (q[0] == 'b') {
			if (front == -1 || front == back + 1) printf("-1\n");
			else printf("%d\n", queue[back]);
		}
	}
	return 0;
}
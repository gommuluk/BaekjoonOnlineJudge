#include <cstdio>

int N;
int matrix[111][111];
bool visit[111];

int DFS(int from, int to) {
	int result = 0;
	
	visit[from] = true;
	for (int i = 1; i <= N; i++) {
		if (matrix[from][i] && !visit[i] && !result) {
			if (matrix[i][to]) return 1;
			else result = DFS(i, to);
		}
	}
	
	return result;
}

int main() {

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (matrix[i][j]) printf("%d ", 1);
			else {
				printf("%d ", DFS(i, j));
				for (int k = 0; k <= N; k++) visit[k] = 0;
			}
		}
		printf("\n");
	}

	return 0;
}

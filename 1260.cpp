#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int N, M, V, a, b;
bool matrix[1010][1010];
bool visit_d[1010], visit_b[1010];

void DFS(int num) {
	printf("%d ", num);
	visit_d[num] = 1;

	for (int i = 1; i <= N; i++) {
		if (matrix[num][i] && !visit_d[i]) {
			DFS(i);
		}
	}
}

void BFS(int num) {
	queue<int> q;
	int next;

	q.push(num);
	visit_b[num] = 1;

	while (!q.empty()) {
		next = q.front();
		printf("%d ", next);
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (matrix[next][i] && !visit_b[i]) {
				q.push(i);
				visit_b[i] = 1;
			}
		}
	}
}

int main() {

	scanf("%d %d %d", &N, &M, &V);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		matrix[a][b] = matrix[b][a] = 1;
	}

	DFS(V);
	printf("\n");
	BFS(V);

	return 0;
}
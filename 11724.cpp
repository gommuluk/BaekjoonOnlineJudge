/*
https://www.acmicpc.net/problem/11724
*/

#include <cstdio>
#include <queue>
using namespace std;

int N, M;
bool matrix[1010][1010], visit[1010];

int main() {

	int a, b, start, next, result = 0;
	queue<int> q;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		matrix[a][b] = matrix[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		start = i;
		
		if (!visit[start]) {
			q.push(start);
			visit[start] = true;
		
			while (!q.empty()) {
				next = q.front();
				q.pop();

				for (int i = 1; i <= N; i++) {
					if (matrix[next][i] && !visit[i]) {
						q.push(i);
						visit[i] = true;
					}
				}
			}
			result++;
		}
	}


	
	
	printf("%d\n", result);

	return 0;
}

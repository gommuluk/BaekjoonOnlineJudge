#include <cstdio>
#include <queue>
using namespace std;

queue <int> q;
bool visit[100001];
int level[100001];

void get_node(int prev, int num) {
	q.push(num);
	visit[num] = true;
	level[num] = level[prev] + 1;
}

int main() {

	int N, K, next;
	scanf("%d %d", &N, &K);

	q.push(N);
	visit[N] = true;
	level[N] = 1;

	while (!q.empty()) {
		next = q.front();
		q.pop();

		if (next == K) break;
		
		if (next * 2 <= 100000 && !visit[next * 2]) get_node(next, next * 2);
		if (next + 1 <= 100000 && !visit[next + 1]) get_node(next, next + 1);
		if (next - 1 >= 0 && !visit[next - 1]) get_node(next, next - 1);
	}

	printf("%d\n", level[K] - 1);
	return 0;
}
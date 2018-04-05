#include <cstdio>
#include <queue>
using namespace std;

class Pos {
public:
	int x;
	int y;

	Pos(int x, int y) {
		this->x = x;
		this->y = y;
	}

	Pos() {}
};

char matrix[110][110];
queue<Pos> q;
bool visit[110][110];
int level[110][110];
Pos now;

void get_node(Pos next, Pos prev) {
	q.push(Pos(next.x, next.y));
	visit[next.x][next.y] = true;
	level[next.x][next.y] = level[prev.x][prev.y] + 1;
}

int main() {

	int N, M;
	scanf("%d %d", &N, &M); scanf("%*c");
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%c", &matrix[i][j]);
		}
		scanf("%*c");
	}

	q.push(Pos(1, 1));
	visit[1][1] = true;

	while (!q.empty()) {
		now = q.front();
		if (now.x == N && now.y == M) break;
		q.pop();

		if (now.x - 1 > 0 && !visit[now.x - 1][now.y] && matrix[now.x - 1][now.y] == '1') get_node(Pos(now.x - 1, now.y), now);
		if (now.x + 1 <= 100 && !visit[now.x + 1][now.y] && matrix[now.x + 1][now.y] == '1') get_node(Pos(now.x + 1, now.y), now);
		if (now.y - 1 > 0 && !visit[now.x][now.y - 1] && matrix[now.x][now.y - 1] == '1') get_node(Pos(now.x, now.y - 1), now);
		if (now.y + 1 <= 100 && !visit[now.x][now.y + 1] && matrix[now.x][now.y + 1] == '1') get_node(Pos(now.x, now.y + 1), now);
	}

	printf("%d\n", level[now.x][now.y] + 1);
	return 0;
}
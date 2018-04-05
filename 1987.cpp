#include <cstdio>
using namespace std;

char matrix[25][25];
bool visit[25][25];
bool alphabet[25];
int R, C, cnt, max_cnt;

void DFS(int x, int y) {
	visit[x][y] = true;
	int ch = matrix[x][y] - 'A';
	alphabet[ch] = true;
	cnt++;
	
	if (x - 1 > 0 && !visit[x - 1][y] && !alphabet[matrix[x - 1][y] - 'A']) DFS(x - 1, y);
	if (x + 1 <= R && !visit[x + 1][y] && !alphabet[matrix[x + 1][y] - 'A']) DFS(x + 1, y);
	if (y - 1 > 0 && !visit[x][y - 1] && !alphabet[matrix[x][y - 1] - 'A']) DFS(x, y - 1);
	if (y + 1 <= C && !visit[x][y + 1] && !alphabet[matrix[x][y + 1] - 'A']) DFS(x, y + 1);

	if (max_cnt < cnt) max_cnt = cnt;
	cnt--;

	visit[x][y] = false;
	alphabet[ch] = false;
}

bool cmp(const int &a, const int &b) {
	return a > b;
}

int main() {

	scanf("%d %d", &R, &C); scanf("%*c");
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf("%c", &matrix[i][j]);
		}
		scanf("%*c");
	}

	DFS(1, 1);
		
	printf("%d\n", max_cnt);
	return 0;
}
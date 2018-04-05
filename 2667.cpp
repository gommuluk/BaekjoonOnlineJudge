#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;


int N, total = 0;
int matrix[30][30], num_apt[30];
bool visit[30][30];

int DFS(int x, int y) {
	int num = 0;

	visit[x][y] = true;
	num++;

	//위 아래 좌 우 
	if (x - 1 > 0 && !visit[x - 1][y] && matrix[x - 1][y]) num +=DFS(x - 1, y);
	if (x + 1 <= N && !visit[x + 1][y] && matrix[x + 1][y]) num += DFS(x + 1, y);
	if (y - 1 > 0 && !visit[x][y - 1] && matrix[x][y - 1]) num += DFS(x, y - 1);
	if (y + 1 <= N && !visit[x][y + 1] && matrix[x][y + 1]) num += DFS(x, y + 1);

	return num;
}

int main() {

	char tmp;
	scanf("%d", &N); scanf("%*c");

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%c", &tmp);
			matrix[i][j] = tmp - '0';
		}
		scanf("%*c");
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visit[i][j] && matrix[i][j]) {
				num_apt[total++] = DFS(i, j);
			}
		}
	}

	sort(num_apt, num_apt + total);
	printf("%d\n", total);
	for (int i = 0; i < total; i++) {
		printf("%d\n", num_apt[i]);
	}
		
	return 0;
}
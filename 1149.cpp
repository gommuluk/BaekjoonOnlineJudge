#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

	int cost[1000][3], N;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	}
	
	for (int i = 1; i < N; i++) {
		cost[i][0] += min(cost[i - 1][1], cost[i - 1][2]);
		cost[i][1] += min(cost[i - 1][0], cost[i - 1][2]);
		cost[i][2] += min(cost[i - 1][0], cost[i - 1][1]);
	}

	printf("%d  \n", min({ cost[N - 1][0], cost[N - 1][1], cost[N - 1][2] }));

	return 0;
}
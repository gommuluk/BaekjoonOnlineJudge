#include <iostream>
#include <cstdio>
#include <queue>

using namespace std; 

int main() {
	int N, x;
	priority_queue<int> pq;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		if (x) pq.push((-1)*x);
		else if (!x && !pq.empty()) {
			printf("%d\n", (-1)*(pq.top()));
			pq.pop();
		}
		else printf("0\n");
	}
	
	return 0;
}
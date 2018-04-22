/*
10815번 [숫자 카드]
https://www.acmicpc.net/problem/10815
*/

#include <cstdio>

bool card[2][10000000] = { 0, };
int main() {
	
	int N, M, tmp;
	

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		
		scanf("%d", &tmp);
		if (tmp < 0) card[0][(-1)*tmp] = 1;
		else card[1][tmp] = 1;
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		
		scanf("%d", &tmp);
		if (tmp < 0) printf("%d ", card[0][(-1)*tmp]);
		else printf("%d ", card[1][tmp]);
	}


	return 0;
}
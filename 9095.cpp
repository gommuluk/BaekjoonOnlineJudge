#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int n, result[15] = { 0,1,2,4, }, tmp;

	scanf("%d", &n);

	for (int i = 4; i < 11; i++) {
		result[i] = result[i - 3] + result[i - 2] + result[i - 1];
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		printf("%d\n", result[tmp]);
	}

	return 0;
}
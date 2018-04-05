#include <cstdio>

char pipe[100001] = { 0, };
int raser[100000] = { 0, }, len = 0, end = 0, result = 0;

int main() {
	
	scanf("%s", pipe); 
	for (len = 1; pipe[len] != '\0'; len++) {
		if (pipe[len] == ')') {
			if (pipe[len - 1] == '(') { // raser
				raser[len] = 2;
			}
			else if (pipe[len - 1] == ')') { // end of pipe
				raser[len] = 1;
			}
		}
	}

	for (int i = 0; i < len; i++) {
		if (raser[i] == 2) {
			result += (--end);
		}
		else if (raser[i] == 1) {
			result++;
			end--;
		}
		else {
			end++;
		}
	}
	
	printf("%d \n", result);

	return 0;
}
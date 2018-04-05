#include <cstdio>
#include <cstring>


int main() {

	char L[15], R[15];
	int eight = 0;
	scanf("%s %s", L, R);

	if (!strcmp(L, R)) {
		for (int i = 0; i < strlen(L); i++) {
			if (L[i] == '8') eight++;
		}
	}
	else {
		if(strlen(L) != strlen(R)) eight = 0;
		else {
			for (int i = 0; i < strlen(L); i++) {
				if (L[i] == '8' && R[i] == '8') eight++;
				else if (L[i] != R[i]) break;
			}
			
		}
	}

	printf("%d\n", eight);

	return 0;
}
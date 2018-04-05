#include <cstdio>
#include <stack>

using namespace std;

int main() {
	int T, i, j;
	char enter, par;
	
	scanf("%d", &T); scanf("%c", &enter);
	for (i = 0; i < T; i++) {
		stack<char> st;
		
		for (j = 0;  scanf("%c",&par) && par != '\n'; j++) {

			if (par == '(')
				st.push(par);
			else {
				if (!st.empty() && st.top() == '(') st.pop();
				else {
					j = 0;
					while (scanf("%c", &par) && par != '\n');
					break;
				}
			}
		}
		if (j && st.empty()) printf("YES \n");
		else printf("NO \n");
		
	}

	return 0;
}
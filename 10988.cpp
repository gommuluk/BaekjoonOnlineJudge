#include <iostream>
#include <string>

using namespace std;

int main() {
	string pal;
	getline(cin, pal);

	int len = pal.length(), result = 1;

	for (int i = 0; i <= len/2; i++) {
		if (pal[i] != pal[len - 1 - i]) {
			result = 0;
			break;
		}
	}

	cout << result << "\n";

	return 0;
}
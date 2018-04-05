#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std; 

int main() {

	string str;
	vector<string> v;

	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		v.push_back(str.substr(i));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}


	return 0;
}
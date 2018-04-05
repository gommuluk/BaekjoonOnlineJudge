#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Pos {
public:
	int x, y;

	Pos(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

bool cmp(const Pos &a, const Pos &b) {
	if (a.x != b.x) return a.x < b.x;
	else return a.y < b.y;
}

int main() {

	int N, x, y;
	vector<Pos> pos;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		pos.push_back(Pos(x, y));
	}

	sort(pos.begin(), pos.end(), cmp);
	
	for (int i = 0; i < pos.size(); i++) {
		printf("%d %d\n", pos[i].x, pos[i].y);
	}

	return 0;
}
#include <iostream>
#include <queue>
using namespace std;

/*
	F층으로 이루어진 고층
	G층은 스타링크가 있는곳
	S층은 강호의 현재 위치
	U버트은 위로 U층 만큼 이동
	D버튼은 아래로 D층 만큼 이동
*/
queue<pair<int, int>>	q;
bool visited[1000001];
int S, G, F, U, D; 

bool range(int floor) {
	return 1<=floor && floor <= F;
}

int bfs() {
	q.push({S, 0});
	while (!q.empty()) {
		int up, down, cnt;

		up = down = q.front().first;
		cnt = q.front().second;
		q.pop();
		if (up == G)
			return cnt;
		
		up += U;
		down -= D;
		if (range(up) && visited[up] == false) {
			q.push({up, cnt+1});
			visited[up] = true;
		}
		if (range(down) && visited[down] == false) {
			q.push({down, cnt+1});
			visited[down] = true;
		}
	}
	return -1;
}

int	main(void) {
	int temp;
	cin >> F >> S >> G >> U >> D;
	temp = bfs();
	if (temp != -1)
		cout << temp << endl;
	else
		cout << "use the stairs" << endl;
	return 0;
}
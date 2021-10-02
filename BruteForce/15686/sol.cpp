#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int		N, M;
int		MIN = INT_MAX;
int		grid[50][50];
vector<pair<int, int>>	house, chicken;
bool	visited[13];

int		distance(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void	dfs(int idx, int select) {
	if (select == M) {
		int	temp = 0;
		for (int i=0;i<house.size();++i) {
			int	dist = INT_MAX;
			for (int j=0;j<chicken.size();++j)
				if (visited[j])
					dist = min(dist, distance(house[i], chicken[j]));
			temp += dist;
		}
		MIN = min(MIN, temp);
	}

	if (idx == chicken.size())
		return;

	visited[idx] = true;
	dfs(idx + 1, select + 1);
	visited[idx] = false;
	dfs(idx + 1, select);
}

int		main(void) {
	cin >> N >> M;
	for (int i=0;i<N;++i)
		for (int j=0;j<N;++j) {
			cin >> grid[i][j];
			if (grid[i][j] == 1)
				house.push_back({i, j});
			else if (grid[i][j] == 2)
				chicken.push_back({i, j});
		}
	dfs(0, 0);
	cout << MIN << endl;
	return (0);
}
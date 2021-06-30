#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool		compare(pair<int, int> a, pair<int, int> b) {
	if (a.second > b.second)
		return true;
	return false;
}

vector<int> solution(vector<int> answers) {
	vector<pair<int, int>>	idiot;
	vector<int>				answer;

	int 		one[5] = {1, 2, 3, 4, 5};
	int 		two[8] = {2, 1, 2, 3, 2, 4, 2, 5};
	int 		three[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
	for (int i=1;i<=3;i++)
		idiot.push_back({i, 0});
	for (int i=0;i<answers.size();++i) {
		if (one[i % 5] == answers[i])
			++idiot[0].second;
		if (two[i % 8] == answers[i])
			++idiot[1].second;
		if (three[i % 10] == answers[i])
			++idiot[2].second;
	}
	sort(idiot.begin(), idiot.end(), compare);
	for (int i=0;i<idiot.size();++i) {
		if (answer.empty())
			answer.push_back(idiot[i].first);
		else {
			if (idiot[i-1].second != idiot[i].second)
				break;
			else
				answer.push_back(idiot[i].first);
		}
	}
	return answer;
}
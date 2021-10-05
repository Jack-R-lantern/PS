#include <iostream>
using namespace std;

int		T, H, W, N;

int		main(void) {
	cin >> T;
	while (T--) {
		int room;
		cin >> H >> W >> N;
		if(N%H)
			room = 100*(N%H) + N/H+1;
		else
			room = 100*H + N/H;
		cout << room << '\n';
	}
	return (0);
}
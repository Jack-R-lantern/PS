#include <iostream>
using   namespace   std;

int     main(void) {
    int		cnt;
	int		i, j;

    cin >> cnt;
	i = 0;
	while (i <  2 * cnt - 1) {
		j = 0;
		while (j++ < abs(cnt - i - 1))
			cout << ' ';
		if (i < cnt)
			while (j++ <= cnt + i)
				cout << '*';
		else
			while (j++ < 2 * cnt - i % cnt - 1)
				cout << '*';
		cout << endl;
		i++;
	}
	return (0);
}
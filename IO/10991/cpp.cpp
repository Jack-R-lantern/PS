#include <iostream>
using   namespace   std;

int     main(void) {
    int     cnt;
    int     i, j;

    cin >> cnt;
    i = 0;
    while (i < cnt) {
        j = 0;
        while (j++ < cnt - i - 1)
            cout << ' ';
        j = 0;
        while (j <= 2 * i + 1) {
            if (j % 2 == 0)
                cout << '*';
            else
                cout << ' ';
            j++;
        }
        cout << endl;
        i++;
    }
    return (0);
}
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
        while (j++ <= cnt)
            cout << '*';
        cout << endl;
        i++;
    }
    i = cnt - 2;
    while (i >= 0) {
        j = 0;
        while (j++ < cnt -i - 1)
            cout << ' ';
        while (j++ <= cnt)
            cout << '*';
        cout << endl;
        i--;
    }
}
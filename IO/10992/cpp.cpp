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
        if (i != cnt - 1) {
            while (j++ <= cnt + i) {
                if (j - 1 == cnt + i || j - 2 == cnt - i -1)
                    cout << '*';
                else
                    cout << ' '; 
            }
        }
        else
            while (j++ <= 2 * cnt - 1)
                cout << '*';
        cout << endl;
        i++;
    }
}
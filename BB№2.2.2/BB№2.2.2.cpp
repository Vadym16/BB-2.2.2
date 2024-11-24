#include <iostream>

using namespace std;

bool magic(int a[100][100], int n, int m);

int main()
{
    setlocale(LC_ALL, "ukr");

    int n, m, arr[100][100];

    cout << "Введіть розмірність матриці (nxm) "; cin >> n >> m;
    cout << "Введіть елементи матриці";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    if(n==m and magic(arr, n, m)) {
        cout << "Дана матриція є магічним квадратом" << endl;
    } else  cout << "Дана матриція не є магічним квадратом" << endl;

}

bool magic(int a[100][100], int n, int m) {
    int sumd1 = 0, sumd2 = 0, msum=0;

    for (int i = 0; i < n; i++) {
        msum += a[0][i];
    }

    for (int i = 0; i < n; i++) {
        int sumv = 0, sumg = 0;
        for (int j = 0; j < m; j++) {
            sumv += a[i][j];
            sumg += a[j][i];
        }
        if (sumv != msum and sumg != msum) return false;
      
    }

    for (int i = 0; i < n; i++) {
        sumd1 += a[i][i];
        sumd2 += a[i][n-i-1];
    }

    if (sumd1 != msum and sumd2 != msum) return false;

    return true;

}
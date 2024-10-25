#include <iostream>
#include <vector>
using namespace std;
int n;
int a[100][100];
int ans[50][50];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int value;
bool valid(int x, int y) {
    return ((a[x][y] == 0 || a[x][y] == 2) && x >= 0 && x < n && y >= 0 && y < n);
}
void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void solve(int r, int c, int diamonds) {
    if (r == n - 1 && c == n - 1) {
        if (diamonds > value) {
            value = diamonds;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    ans[i][j] = a[i][j];
                }
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        int x = r + dx[i];
        int y = c + dy[i];
        if (valid(x, y)) {
            int check = (a[x][y] == 2) ? 1 : 0;
            a[x][y] = 3;  
            solve(x, y, diamonds + check);
            a[x][y] = (check == 1) ? 2 : 0;  
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
                ans[i][j] = 0;  
            }
        }
        value = -100;  
        a[0][0] = 3;   
        solve(0, 0, 0);
        cout << "Maximum diamonds collected: " << value << endl;
        cout << "Path traversed: " << endl;
        print();
    }
    return 0;
}

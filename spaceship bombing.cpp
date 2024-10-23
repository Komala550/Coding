#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <sstream>  
#include <iomanip> // For std::setw and std::setfill

using namespace std;

int n;
int arr[15][5];
unordered_map<string, int> umap; // Memoization using unordered_map

// Helper function to create a unique key for the unordered_map
string createKey(int x, int y, bool check, int index) {
    // x is represented by 2 digits, y, check, and index are each represented by 1 digit
    stringstream ss;
    ss << setw(2) << setfill('0') << x   // 2 digits for x
       << y                               // 1 digit for y
       << check                           // 1 digit for check (true/false -> 1/0)
       << index;                          // 1 digit for index
    return ss.str();
}

// Recursive function with memoization using unordered_map
int solve(int x, int y, bool check, int index) {
    // Base case: out of bounds or bomb effect has expired on an enemy
    if (x < 0 || (arr[x][y] == 2 && index >= 5)) {
        return 0;
    }

    // Create a unique key for the current state
    string key = createKey(x, y, check, index);

    // If the state has already been computed, return the cached result
    if (umap.find(key) != umap.end()) {
        return umap[key];
    }

    int ans = INT_MIN;
    int next[3][2] = {{-1, -1}, {-1, 0}, {-1, 1}}; // Possible moves: up-left, up, up-right

    // Explore all 3 directions
    for (int i = 0; i < 3; i++) {
        int dx = x + next[i][0];
        int dy = y + next[i][1];
        int p = 0;

        if (dx >= 0 && dx < n && dy >= 0 && dy < 5) {
            if (arr[dx][dy] == 1 && check == false) {
                p = 1 + solve(dx, dy, false, index);
            } else if (arr[dx][dy] == 1 && check == true) {
                p = 1 + solve(dx, dy, true, index + 1);
            } else if (arr[dx][dy] == 2 && check == false) {
                p = solve(dx, dy, true, index + 1);  // Use bomb
            } else if (arr[dx][dy] == 2 && check == true) {
                p = solve(dx, dy, true, index + 1);  // Bomb already used
            } else if (arr[dx][dy] == 0 && check == false) {
                p = solve(dx, dy, check, index);     // Empty cell
            } else if (arr[dx][dy] == 0 && check == true) {
                p = solve(dx, dy, check, index + 1); // Empty cell, bomb used
            }
        }
        ans = max(ans, p);  // Take the maximum result from all 3 directions
    }

    // Memoize the result for the current state using the unique key
    umap[key] = ans;
    return ans;
}

int main() {
    int t;
    cin >> t;

    for (int m = 1; m <= t; ++m) {
        cin >> n;

        // Initialize grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> arr[i][j];
            }
        }

        // Clear the unordered_map for memoization before solving each test case
        umap.clear();

        // Start solving from the middle of the last row (n-1, 2)
        cout << "#" << m << " " << solve(n, 2, false, 0) << endl;
    }

    return 0;
}

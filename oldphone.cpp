#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;

int ans;

void getMinSteps(int target, unordered_map<int, int> &output, int cur_level, vector<int> &workingNumber, int o, vector<int> &signs) {
    if (workingNumber.empty()) return;

    for (int i = 0; i < workingNumber.size(); i++) {
        int cur_ele = workingNumber[i];
        workingNumber.erase(workingNumber.begin() + i);
        unordered_map<int, int> new_output;
        new_output[cur_ele] = 1;

        for (auto &entry : output) {
            int val = entry.first;
            int level = entry.second;

            // Addition
            if (signs[0] == 1) {
                int newAdd = cur_ele + val;
                int newFreq = level + 3;
                if (new_output.find(newAdd) == new_output.end() || new_output[newAdd] > newFreq) {
                    new_output[newAdd] = newFreq;
                }
                if (newAdd == target && newFreq <= o) {
                    ans = min(ans, newFreq);
                }
            }

            // Subtraction
            if (signs[1] == 1) {
                int newAdd = abs(cur_ele - val);
                int newFreq = level + 3;
                if (new_output.find(newAdd) == new_output.end() || new_output[newAdd] > newFreq) {
                    new_output[newAdd] = newFreq;
                }
                if (newAdd == target && newFreq <= o) {
                    ans = min(ans, newFreq);
                }
            }

            // Multiplication
            if (signs[2] == 1) {
                int newAdd = cur_ele * val;
                int newFreq = level + 3;
                if (new_output.find(newAdd) == new_output.end() || new_output[newAdd] > newFreq) {
                    new_output[newAdd] = newFreq;
                }
                if (newAdd == target && newFreq <= o) {
                    ans = min(ans, newFreq);
                }
            }

            // Division
            if (signs[3] == 1 && val != 0 && cur_ele % val == 0) {
                int newAdd = cur_ele / val;
                int newFreq = level + 3;
                if (new_output.find(newAdd) == new_output.end() || new_output[newAdd] > newFreq) {
                    new_output[newAdd] = newFreq;
                }
                if (newAdd == target && newFreq <= o) {
                    ans = min(ans, newFreq);
                }
            }

            // Concatenation
            string one = to_string(cur_ele);
            string two = to_string(val);
            int concat1 = stoi(one + two);
            int newFreq = level + 1;
            if (new_output.find(concat1) == new_output.end() || new_output[concat1] > newFreq) {
                new_output[concat1] = newFreq;
            }
            if (concat1 == target && newFreq <= o) {
                ans = min(ans, newFreq);
            }

            int concat2 = stoi(two + one);
            if (new_output.find(concat2) == new_output.end() || new_output[concat2] > newFreq) {
                new_output[concat2] = newFreq;
            }
            if (concat2 == target && newFreq <= o) {
                ans = min(ans, newFreq);
            }
        }

        for (auto &entry : output) {
            int val = entry.first;
            int level = entry.second;
            if (new_output.find(val) == new_output.end() || new_output[val] > level) {
                new_output[val] = level;
            }
        }

        getMinSteps(target, new_output, cur_level + 1, workingNumber, o, signs);
        workingNumber.insert(workingNumber.begin() + i, cur_ele);
    }
}

int main() {
    int t;
    cin >> t;
    int count = 0;

    while (t--) {
        ans = INT_MAX;
        int n, m, o;
        cin >> n >> m >> o;

        vector<int> workingNumber(n);
        for (int i = 0; i < n; i++) {
            cin >> workingNumber[i];
        }

        vector<int> signs(4, 0);
        for (int i = 0; i < m; i++) {
            int num;
            cin >> num;
            signs[num - 1] = 1;
        }

        int target;
        cin >> target;

        unordered_map<int, int> output;
        getMinSteps(target, output, 1, workingNumber, o, signs);
        count++;
        cout << "#" << count << ": " << ans << endl;
    }
    return 0;
}

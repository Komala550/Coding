/*
There is an island surrounded by oil mines. You will be given n companies and m oil mines having values.
You have to distribute the mines to "n" companies in fair manner. Remember the companies can have oil 
mines adjacent to each other and not in between of each others.After distributing them compute the 
difference of oil mines from the company getting highest and company getting lowest. This number 
should be minimum.(then only the distribution can be termed as fair).

Input 
2 
2 4 
6 13 10 2 
2 4 
6 10 13 2 

output 
5 
1
*/
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int companies, mines, ANS;
void calculateOilMines(int i, vector<int> oilMines,vector<bool> &visited,int minV, int maxV, int sum,int nodes, int &ANS){
    // Base Case
    if(visited[i]){
        int newMin = min(sum, minV);
        int newMax = max(sum, maxV);

        if(nodes == companies - 1){
            ANS = min(ANS, newMax - newMin);
        }
        return;
    }

    // Main Case
    visited[i] = 1;
    int j = (i + 1) % mines;

    calculateOilMines(j, oilMines, visited, minV, maxV, sum + oilMines[i], nodes, ANS);

    int newMin = min(sum, minV);
    int newMax = max(sum, maxV);

    calculateOilMines(j, oilMines, visited, newMin, newMax, oilMines[i], nodes + 1, ANS);

    visited[i] = 0;
    return;
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
		cin >> companies >> mines;
		vector<int> oilMines(mines,0);
		vector<bool> visited(mines,false);
		for(int i=0; i<mines; i++){
            cin >> oilMines[i];
        }
        ANS = INT_MAX;    
        for(int i=0; i<mines; i++)
            calculateOilMines(i, oilMines, visited, INT_MAX, INT_MIN, 0, 0, ANS);  

		cout << ANS <<endl;		
	}
	return 0;
}

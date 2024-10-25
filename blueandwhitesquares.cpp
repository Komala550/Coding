#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
const int maxn = 129;
int white = 0, blue = 0;

bool checkSame(bool arr[maxn][maxn], int sti, int stj, int size)
{
	bool color = arr[sti][stj];
	for(int i = sti; i < sti + size; i++){
		for(int j = stj; j < stj + size; j++){
			if(arr[i][j] != color){
				return false;
			}
		}
	}
	return true;
}

void solve(bool arr[maxn][maxn], int size, int sti, int stj)
{
	bool same = checkSame(arr, sti, stj, size);
	
	if(!same){
		solve(arr, size / 2, sti, stj);
		solve(arr, size / 2, sti + size/2, stj);
		solve(arr, size / 2, sti, stj + size/2);
		solve(arr, size / 2, sti + size/2, stj + size/2);
	}
	else{
		(arr[sti][stj]) ? ++blue : ++white ;
	}
}

int main()
{
	int test ;
	cin >> test ;
	for(int l = 1; l <= test; l++){
		white = 0;
		blue = 0;
		int size ;
		cin >> size;
		bool arr[maxn][maxn];
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				cin >> arr[i][j] ;
			}
		}
		solve(arr, size, 0, 0);
		cout << "Case #" << l << endl;
		cout << white << " " << blue << endl;
	}
	return 0;
}
// optimized approach using prefix sum of matrix

#include <iostream>
using namespace std;
const int maxn = 129;
int white = 0, blue = 0;
void solve(int arr[maxn][maxn], int size, int si,int sj)
{
    if( size == 0)
    return;
    int sum = arr[size + si - 1][size + sj - 1];
    if(sj - 1 >= 0)
    sum -= arr[size + si - 1][sj - 1];
    if(si - 1 >= 0)
    sum -= arr[si - 1][sj + size - 1];
    if( si - 1 >= 0 && sj - 1 >= 0)
    sum += arr[si - 1][sj - 1];
    if(si == 4 && sj == 1)
    cout<<sum<<endl;
    if(sum == 0)
    {
       // cout<<si<<"white"<<sj<<" "<<size<<" "<<white<<endl;
        white++;
        return;
    }
    if(sum == size * size)
    {
     //cout<<si<<"blue"<<sj<<" "<<size<<" "<<blue<<endl;
     blue++;
     return;
    }
    solve(arr, size / 2, si, sj);
    solve(arr, size / 2,  si + size/2, sj);
    solve(arr, size / 2, si, sj + size/2);
    solve(arr, size / 2, si + size / 2, sj + size / 2);
}
int main() {
    int test ;
	cin >> test ;
	for(int l = 1; l <= test; l++){
		white = 0;
		blue = 0;
		int size ;
		cin >> size;
		int arr[maxn][maxn];
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
                int a;
                cin>>a;
                if( i == 0 && j == 0)
                 arr[i][j] = a;
                else if( i == 0)
                arr[i][j] = a + arr[i][j - 1];
                else if( j == 0)
                arr[i][j] = a + arr[i - 1][j];
                else
                arr[i][j] = a + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
			}
		}
		solve(arr, size, 0, 0);
		cout << "Case #" << l << endl;
		cout << white << " " << blue << endl;
	}
	return 0;
}

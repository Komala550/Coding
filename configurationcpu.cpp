#include<iostream>

using namespace std;

#define rep(i,a,n) for(int i =a; i < n; i++)
#define repe(i,a,n) for(int i =a; i <= n; i++)

int D,E,F,d,e;
int config;
int answer = 0;

struct configuration
{
    int D,E,F,SPi;
};
configuration m[9];

void solve(int index, int counta, int D, int E, int F, int cost )
{

    if(index >= config || counta == 3)
    {
        cost += D*d + E*e;
        if(cost > answer)
            answer = cost;
        return;
    }
    solve(index + 1, counta, D,E,F,cost);

    int i = 1;

    while(true)
    {
        if( D - m[index].D*i >= 0 && E - m[index].E*i >=0 && F - m[index].F*i >= 0 )
        {
            solve(index+1,counta+1,D- m[index].D *i,E - m[index].E *i,F- m[index].F*i, cost+ m[index].SPi * i);
            ++i;
        }
        else
        {
            break;
        }
    }
    return;

}

int main()
{
    int t;
    cin >> t;
    repe(_cases,1,t)
    {

        answer = 0;
        cin >> D >> E >> F >> d >> e;

        cin >> config;

        rep(i,0,config)
        {
            cin >> m[i].D >> m[i].E >> m[i].F >> m[i].SPi;
        }
        solve(0,0,D,E,F,0);
        cout << "Case #"<<_cases << "\n" << answer <<"\n";

    }

    return 0;
}

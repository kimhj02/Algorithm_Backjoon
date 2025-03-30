#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int N, P, min_cost = 2147483647;
int country[10001];
int parent[10001];
typedef struct edge{
    int x;
    int y;
    int cost;
}edge;
vector<edge> connect;

bool cmp(edge a, edge b){
    if(a.cost < b.cost) return true;
    else return false;
}

void reset_parent(){
    for(int i = 1; i <= N; i++) parent[i] = i;
}

void Union(int x, int y){
    if(x < y) parent[x] = y;
    else parent[y] = x;
}

int Find(int x){
    if(x == parent[x]) return x;
    else return parent[x] = Find(parent[x]);
}

void solve(){
    reset_parent();
    sort(connect.begin(), connect.end(), cmp);
    int cost = 0;
    for(int i = 0; i < connect.size(); i++){
        int x = Find(connect[i].x);
        int y = Find(connect[i].y);
        if(x != y){
            Union(x, y);
            cost += connect[i].cost;
        }
    }
    cout << cost + min_cost;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> P;
    for(int i = 1; i <= N; i++){
        cin >> country[i];
        min_cost = min(min_cost , country[i]);
    }
    for(int i = 1; i <= P; i++){
        int x, y, cost;
        cin >> x >> y >> cost;
        cost += cost + country[x] + country[y];
        connect.push_back({x, y, cost});
    }
    solve();
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define INF 2147483647

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int city_num, road_num;
    cin >> city_num >> road_num;

    vector<vector<pair<int, int>>> graph(city_num + 1);
    vector<int> dist(city_num + 1, INF);
    vector<int> prev(city_num + 1, -1);  // 이전 도시 저장

    for (int i = 0; i < road_num; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        graph[start].push_back({cost, end});
    }

    int start, end;
    cin >> start >> end;

    // 다익스트라 알고리즘
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;//우선순위 큐
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cur_cost = pq.top().first;
        int cur_city = pq.top().second;
        pq.pop();

        if (cur_cost > dist[cur_city]) continue;

        for (auto& next : graph[cur_city]) {
            int next_cost = next.first;
            int next_city = next.second;

            if (dist[next_city] > cur_cost + next_cost) {
                dist[next_city] = cur_cost + next_cost;
                prev[next_city] = cur_city;  // 경로 저장
                pq.push({dist[next_city], next_city});
            }
        }
    }

    // 최소 비용 출력
    cout << dist[end] << endl;

    // 경로 복원 (스택 사용)
    stack<int> path;
    int cur = end;
    while (cur != -1) {
        path.push(cur);
        cur = prev[cur];
    }

    // 경로 개수 출력
    cout << path.size() << endl;

    // 경로 출력
    while (!path.empty()) {
        cout << path.top() << ' ';
        path.pop();
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 2147483647

int city_num, road_num, X; //입력 값
vector<vector<pair<int, int>>> graph, reverse_graph;

//다익스트라
vector<int> dijkstra(int start, const vector<vector<pair<int, int>>>& d_gragh) {

    vector<int> dist(city_num + 1, INF); //거리를 초기에는 무제한으로 초기화, x에서 인덱스까지의 최단 거리 저장
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //최소 힙

    dist[start] = 0; //시작 거리는 0으로 초기화
    pq.push({0, start}); //시작 정점 큐에 넣기

    while (!pq.empty()) {
        // 우선순위 큐에서 현재까지의 거리가 가장 짧은 노드를 꺼냄
        int cur_dist = pq.top().first;   // 현재 거리
        int cur_node = pq.top().second;  // 현재 노드
        pq.pop(); // 꺼낸 노드를 큐에서 제거

        // 이미 더 짧은 거리로 방문한 적이 있다면 건너뜀
        if (cur_dist > dist[cur_node]) continue;

        // 현재 노드와 연결된 모든 인접 노드 탐색
        for (int i = 0; i < d_gragh[cur_node].size(); i++) {
            int next_node = d_gragh[cur_node][i].first;   // 다음 노드
            int weight = d_gragh[cur_node][i].second;     // 간선 가중치
            int next_dist = cur_dist + weight;      // 다음 노드까지의 거리 계산

            // 더 짧은 거리로 갈 수 있다면 거리 갱신
            if (next_dist < dist[next_node]) {
                dist[next_node] = next_dist;
                pq.push(make_pair(next_dist, next_node)); // 큐에 삽입
            }
        }
    }

    return dist;
}

int main() {
    cin >> city_num >> road_num >> X;

    graph.resize(city_num + 1); //사이즈 조절
    reverse_graph.resize(city_num + 1); //사이즈 조절

    for (int i = 0; i < road_num; i++) { //입력
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});          // 정방향 그래프
        reverse_graph[v].push_back({u, w});  // 역방향 그래프
    }
    //정방향 역방향 둘 다 거리를 계산해야 함
    vector<int> from_x = dijkstra(X, graph);        // 정방향 거리 벡터 반환
    vector<int> to_x = dijkstra(X, reverse_graph);  // 역방향 거리 벡터 반환

    int max_time = 0; //두 개의 합이 가장 큰 학생을 찾아보자
    for (int i = 1; i <= city_num; i++) {
        int total_time = from_x[i] + to_x[i];
        if (total_time < INF)
            max_time = max(max_time, total_time);
    }

    cout << max_time << endl;
    return 0;
}

//두번 다익스트라를 사용해야 함
//1번째는 갈 때, 2번째는 올 떄
//그렇다면 정방향 그래프와 역방향 그래프를 가지고 있어야 함
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int edge_num = 0, vertex_num = 0;
    vector<vector<pair<int, int>>> list; // 인접 리스트 (정점, 가중치)
    cin >> vertex_num >> edge_num;

    list.assign(vertex_num + 1, vector<pair<int, int>>()); //정점은 1부터 시작

    for (int i = 0; i < edge_num; i++) {
        int start, end, weight;
        cin >> start >> end >> weight;
        list[start].push_back({end, weight}); //양방향 연결
        list[end].push_back({start, weight}); //양방향 연결
    }

    int start, end;
    cin >> start >> end;

    // 다익스트라 알고리즘 시작
    vector<int> dist(vertex_num + 1, 1e9); // 거리를 무한대로 초기화
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // 최소 힙 (거리, 노드)
    dist[start] = 0;
    pq.push({0, start}); // 시작

    while (!pq.empty()) { //큐가 빌때까지
        int edge = pq.top().first; //정점
        int cost = pq.top().second; //가중치
        pq.pop();

        if (dist[cost] < edge) continue; //현재 가중치보다 크다면 넘어감

        for (auto next : list[cost]) {
            int next_node = next.first;
            int weight = next.second;

            if (dist[next_node] > dist[cost] + weight) { //작다면 업데이트
                dist[next_node] = dist[cost] + weight;
                pq.push({dist[next_node], next_node}); //큐에 push
            }
        }
    }

    cout << dist[end] << endl;
    return 0;
}
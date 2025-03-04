#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321; // 충분히 큰 수

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));

    // 자기 자신과의 거리는 0 플로이드-워셜을 사용하기 위함
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    // 친구 관계 입력 (-1 -1이 나오기 전까지)
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        dist[a][b] = 1;
        dist[b][a] = 1; //양방향 연결
    }

    // 플로이드-워셜 알고리즘: 모든 정점 쌍 최단 거리 계산
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) //k를 거쳐 연결이 가능하다면
                    dist[i][j] = dist[i][k] + dist[k][j]; //연결
            }
        }
    }

    // 각 사람의 점수: 다른 모든 사람과 연결되는데 필요한 최소 친구 관계 중 최대값
    vector<int> score(n+1, 0); //각 사람당 점수 계산용 벡터
    int min_score = INF; //최소값을 큰 수로 설정

    for (int i = 1; i <= n; i++) {
        int max_distance = 0; //가장 긴 거리를 구하자, 그 거리의 최종 점수임
        for (int j = 1; j <= n; j++) {
            max_distance = max(max_distance, dist[i][j]); // 가장 긴 친구 관계 찾기
        }
        score[i] = max_distance; //가장 긴 거리가 점수임
        min_score = min(min_score, max_distance); // 최소 점수 찾기
    }

    // 회장 후보 찾기
    vector<int> candidates;
    for (int i = 1; i <= n; i++) {
        if (score[i] == min_score)
            candidates.push_back(i);
    }

    // 출력
    cout << min_score << " " << candidates.size() << endl;
    for (int x : candidates)
        cout << x << " ";
    cout << endl;

    return 0;
}
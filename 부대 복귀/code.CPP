#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    unordered_map<int, vector<int>> graph;
    for (auto& road : roads) {
        graph[road[0]].push_back(road[1]);
        graph[road[1]].push_back(road[0]);
    }
    
    vector<int> distances(n + 1, -1);
    queue<int> q;
    q.push(destination);
    distances[destination] = 0;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        for (int neighbor : graph[current]) {
            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[current] + 1;
                q.push(neighbor);
            }
        }
    }
    
    vector<int> result;
    for (int source : sources) {
        result.push_back(distances[source]);
    }
    
    return result;
}

int main() {
    // 첫 번째 테스트 케이스
    int n1 = 3;
    vector<vector<int>> roads1 = {{1, 2}, {2, 3}};
    vector<int> sources1 = {2, 3};
    int destination1 = 1;
    vector<int> result1 = solution(n1, roads1, sources1, destination1);
    cout << "Test 1 Results:" << endl;
    for (int time : result1) {
        cout << time << " ";
    }
    cout << endl;
    
    // 두 번째 테스트 케이스
    int n2 = 5;
    vector<vector<int>> roads2 = {{1, 2}, {1, 4}, {2, 4}, {2, 5}, {4, 5}};
    vector<int> sources2 = {1, 3, 5};
    int destination2 = 5;
    vector<int> result2 = solution(n2, roads2, sources2, destination2);
    cout << "Test 2 Results:" << endl;
    for (int time : result2) {
        cout << time << " ";
    }
    cout << endl;

    return 0;
}

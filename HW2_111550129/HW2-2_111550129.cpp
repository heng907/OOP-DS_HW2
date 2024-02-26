#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct edge {
    int dest;
    int width;
    int t_truck;
    int t_car;
    int t_bike;
};

int shortestTime(vector<vector<edge>>& graph, int startCity, int endCity, int s_truck, int s_car, int s_bike) {
    int n = graph.size();
    vector<int> distance(n, INT_MAX);
    vector<bool> visited(n, 0);
    distance[startCity] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, startCity});

    while (!pq.empty()) {
        int currentCity = pq.top().second;
        pq.pop();

        if (visited[currentCity]) {
            continue;
        }

        visited[currentCity] = true;

        for (const edge& _edge : graph[currentCity]) {
            int neighborCity = _edge.dest;
            int roadWidth = _edge.width;
            int truckTime = _edge.t_truck;
            int carTime = _edge.t_car;
            int bikeTime = _edge.t_bike;

            int costTime = 0;
            int roadweight = 0;

            if (roadWidth >= s_truck) {
                costTime = truckTime;
                roadweight = s_truck;
            } else if (roadWidth >= s_car) {
                costTime = carTime;
                roadweight = s_car;
            } else if (roadWidth >= s_bike) {
                costTime = bikeTime;
                roadweight = s_bike;
            } else {
                continue;
            }
            int newDistance = distance[currentCity] + costTime;
            if (newDistance < distance[neighborCity]) {
                distance[neighborCity] = newDistance;
                pq.push({newDistance, neighborCity});
            }
        }
    }
    return distance[endCity];
}

int main() {
    int n,m;
    cin >> n >> m;

    vector<vector<edge>> graph(n);
    for (int i = 0; i < m; i++) {
        int startCity, endCity, width, t_truck, t_car, t_bike;
        cin >> startCity >> endCity >> width >> t_truck >> t_car >> t_bike;
        startCity--;
        endCity--;
        graph[startCity].push_back({endCity, width, t_truck, t_car, t_bike});
        graph[endCity].push_back({startCity, width, t_truck, t_car, t_bike});
    }

    int s_truck, s_car, s_bike;
    cin >> s_truck >> s_car >> s_bike;
    int p;
    cin >>p;

    while (p--) {
        int startCity, endCity;
        cin >> startCity >> endCity;

        startCity--;
        endCity--;

        int ans = shortestTime(graph, startCity, endCity, s_truck, s_car, s_bike);
        cout << ans << endl;
    }

    return 0;
}

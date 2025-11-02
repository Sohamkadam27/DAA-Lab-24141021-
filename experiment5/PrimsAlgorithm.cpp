#include <iostream>

using namespace std;

#define INF 9999999

int main() {
    int cost[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int visited[5] = {0};
    int n = 5;
    int edges = 0;

    visited[0] = 1;

    cout << "Edge : Weight" << endl;

    while (edges < n - 1) {
        int min = INF, a = -1, b = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j]) { 
                        if (cost[i][j] < min) {
                            min = cost[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }
            }
        }

        cout << a << " - " << b << " : " << min << endl;

        visited[b] = 1;
        edges++;
    }

    return 0;
}
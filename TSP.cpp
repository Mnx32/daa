#include <iostream>
#include <limits.h>
using namespace std;

int calculateBound(int currentCost, int** adjMatrix, bool* visited, int currentCity, int N) {
    int bound = currentCost;
    int minOutgoing = INT_MAX;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            minOutgoing = min(minOutgoing, adjMatrix[currentCity][i]);
        }
    }

    return bound + minOutgoing;
}

void tspBranchAndBound(int** adjMatrix, int* bestPath, int& minCost, int N) {
    int* currentPath = new int[N];
    bool* visited = new bool[N]();
    int currentCost = 0;

    currentPath[0] = 0;
    visited[0] = true;

    auto explorePaths = [&](int level, int currentCity, auto& explorePaths) -> void {
        if (level == N - 1) {
            int tourCost = currentCost + adjMatrix[currentCity][0];

            if (tourCost < minCost) {
                minCost = tourCost;
                for (int i = 0; i < N; i++) {
                    bestPath[i] = currentPath[i];
                }
            }
            return;
        }

        for (int nextCity = 0; nextCity < N; nextCity++) {
            if (!visited[nextCity]) {
                int costWithNextCity = currentCost + adjMatrix[currentCity][nextCity];
                int bound = calculateBound(costWithNextCity, adjMatrix, visited, nextCity, N);

                if (bound < minCost) {
                    visited[nextCity] = true;
                    currentPath[level + 1] = nextCity;
                    currentCost = costWithNextCity;

                    explorePaths(level + 1, nextCity, explorePaths);

                    visited[nextCity] = false;
                    currentCost -= adjMatrix[currentCity][nextCity];
                }
            }
        }
    };

    explorePaths(0, 0, explorePaths);
    delete[] currentPath;
    delete[] visited;
}

int main() {
    int N;
    cout << "Enter the number of cities: ";
    cin >> N;

    int** adjMatrix = new int*[N];
    for (int i = 0; i < N; i++) {
        adjMatrix[i] = new int[N];
    }

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    int* bestPath = new int[N];
    int minCost = INT_MAX;

    tspBranchAndBound(adjMatrix, bestPath, minCost, N);

    cout << "Minimum cost of the tour: " << minCost << endl;
    cout << "Optimal path: ";
    for (int i = 0; i < N; i++) {
        cout << bestPath[i];
        if (i < N - 1) cout << " -> ";
    }
    cout << " -> 0" << endl;

    for (int i = 0; i < N; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
    delete[] bestPath;

    return 0;
}



#include <iostream>
using namespace std;

const int MAX_NODES = 50;

static int m, n;
static int c = 0;
static int count = 0;
int g[MAX_NODES][MAX_NODES];
int x[MAX_NODES];        

void nextValue(int k);
void GraphColoring(int k);
int maxDegree();

int main() {
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "\nEnter Adjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    int maxDeg = maxDegree();
    cout << "The maximum degree among all vertices is: " << maxDeg << endl;

    m = maxDeg + 1;
    cout << "Total number of colors allowed: " << m << endl;

    cout << "\nPossible Solutions are:\n";
    for (int i = 1; i <= m; i++) {
        if (c == 1) {
            break;
        }
        GraphColoring(0); 
    }

    cout << "The total number of solutions is " << count << endl;
    return 0;
}

void GraphColoring(int k) {
    while (true) {
        nextValue(k);
        if (x[k] == 0) {
            return;
        }

        if (k == n - 1) {
            c = 1;
            count++;
            cout << "Solution " << count << ": " << endl;
            for (int i = 0; i < n; i++) {
                cout << "Vertex " << i + 1 << " --->  Color " << x[i] << endl;
            }
            cout << endl;
        } 
        else {
            GraphColoring(k + 1);
        }
    }
}

void nextValue(int k) {
    while (true) {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0) {
            return;
        }
        bool conflict = false;
        for (int j = 0; j < n; j++) {
            if (g[k][j] == 1 && x[k] == x[j]) {
                conflict = true;
                break;
            }
        }
        if (!conflict) {
            return;
        }
    }
}


int maxDegree() {
    int maxDeg = 0;
    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (int j = 0; j < n; j++) {
            if (g[i][j] == 1) {
                degree++;
            }
        }
        if (degree > maxDeg) {
            maxDeg = degree;
        }
    }
    return maxDeg;
}

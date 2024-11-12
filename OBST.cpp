#include <iostream>
#include <cstring>
#define max 20

using namespace std; 

int main() {

    int i, j, k, n, min_cost, r[max][max];
	float p[max], q[max], w[max][max], c[max][max];
	
    cout << "Enter total number of nodes: ";
    cin >> n;

    cout << "\nEnter successful probabilities:\n";
    for (i = 1; i <= n; i++) {
        cin >> p[i];
    }
    
    cout << "\nEnter unsuccessful probabilities::\n";
    for (i = 0; i <= n; i++) {
        cin >> q[i];
    }

    for (i = 0; i <= n; i++) {
        c[i][i] = 0;  
        r[i][i] = 0;  
        w[i][i] = q[i];
    }

    for (i = 0; i < n; i++) {
        w[i][i + 1] = p[i + 1] + q[i] + q[i + 1];
        c[i][i + 1] = w[i][i + 1];
        r[i][i + 1] = i + 1;  
    }

    w[n][n] = q[n];
    c[n][n] = 0;
    r[n][n] = 0;

    for (int m = 2; m <= n; m++) {
        for (i = 0; i <= n - m; i++) {
            j = i + m;
            w[i][j] = w[i][j - 1] + p[j] + q[j];  
            c[i][j] = 99999;
            for (k = i + 1; k <= j; k++) {
                float cost = c[i][k - 1] + c[k][j] + w[i][j];
                if (cost < c[i][j]) {
                    c[i][j] = cost;  
                    r[i][j] = k;     
                }
            }
        }
    }
    cout << "\n\n";
    for (i = 0; i <= n; i++) {
        for (j = i; j <= n; j++) {
            cout << "w[" << i << "][" << j << "] = " << w[i][j] << "\n";
            cout << "c[" << i << "][" << j << "] = " << c[i][j] << "\n";
            cout << "r[" << i << "][" << j << "] = " << r[i][j] << "\n";
        }
        cout << "\n";
    }
    cout << "\nThe cost of OBST is: " << c[0][n] << "\n";

    return 0;
}

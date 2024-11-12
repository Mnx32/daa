#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int W;  
    int n;  

    cout << "Enter capacity (W): ";
    cin >> W;

    cout << "Enter number of items (n): ";
    cin >> n;

    int weights[n];
    int values[n];

    cout << "Enter the weights: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter the profits: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    int arr[n + 1][W + 1];

    
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                arr[i][w] = 0;
            }
        }
    }

    
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                arr[i][w] = max(arr[i-1][w], values[i-1] + arr[i-1][w-weights[i-1]]);
            } else {
                arr[i][w] = arr[i-1][w];
            }
        }
    }

    int maxValue = arr[n][W];
    int x[n];  

    
    int w = W;
    for (int i = n; i > 0; i--) {
        if (arr[i][w] != arr[i-1][w]) {  
            x[i-1] = 1;
            w -= weights[i-1];  
        } else {  
            x[i-1] = 0;
        }
    }

    
    cout << "\nDP Table:\n";
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            cout << arr[i][w] << "\t";
        }
        cout << endl;
    }

    
    cout << "\nSelected items (x):\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": " << (x[i] == 1 ? "Included" : "Not included") << " (x[" << i << "] = " << x[i] << ")\n";
    }

   
    int finalProfit = 0;
    for (int i = 0; i < n; i++) {
        finalProfit += values[i] * x[i];
    }

    cout << "\nMaximum Profit: " << maxValue << endl;
    cout << "Calculated Profit: " << finalProfit << endl;

    return 0;
}

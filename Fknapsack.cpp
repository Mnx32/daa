#include <iostream>
using namespace std;

int main () {
    int n;
    cout << "Enter total number of objects: ";
    cin >> n;
    float p[n], w[n];
    cout << "Enter weight and profits:\n";
    for (int i=0; i<n; i++) {
        cout << "Object : " << (i+1) << ": " << endl;
        cout << "Profit: ";
        cin >> p[i];
        cout << "Weight: ";
        cin >> w[i];
    }
    float m;
    cout << "Enter maximum capacity of knapsack: ";
    cin >> m;
    float piwi[n];
    for (int i=0; i<n; i++) {
        piwi[i] = p[i] / w[i];
    }
    cout << "\nStep 01:\nObject\tProfit\tWeight\tPi/Wi\n";
    for (int i=0; i<n; i++) {
        cout << (i+1) << "\t" << p[i] << "\t" << w[i] << "\t" << piwi[i] << endl;
    }
    for (int i=0; i<n; i++) {
        for (int j=(i+1); j<n; j++) {
            if (piwi[i] < piwi[j]) {
                float temp1 = piwi[i];
                float temp2 = p[i];
                float temp3 = w[i];
                piwi[i] = piwi[j];
                p[i] = p[j];
                w[i] = w[j];
                piwi[j] = temp1;
                p[j] = temp2;
                w[j] = temp3;
            }
        }
    }
    cout << "\nStep 02 (Arrange in Decreasing Order)\nObject\tProfit\tWeight\tPi/Wi\n";
    for (int i=0; i<n; i++) {
        cout << (i+1) << "\t" << p[i] << "\t" << w[i] << "\t" << piwi[i] << endl;
    }
    float x[n], u[n];
    for (int i=0; i<n; i++) {
        x[i] = 0.0;
        u[i] = m;
    }
    int i=0;
    for (i=0; i<n; i++) {
        if (w[i] > m) {
            break;
        }
        x[i] = 1.0;
        m = m - (w[i] * x[i]);
        u[i] = m;
    }
    if (i < n) {
        x[i] = m / w[i];
        
    }
    float profit=0.0;
    cout << "Printing all data:\nObject\tPi\tWi\tXi\tMi\tProfit\n";
    for (int i=0; i<n; i++) {  
        cout << (i+1) << "\t" << p[i] << "\t" << w[i] << "\t" << x[i] << "\t" << u[i] << "\t" << p[i]*x[i] << endl;
        profit = profit + (p[i] * x[i]);
    }
    cout << "Maximum profit is: " << profit << endl;
    return 0;
}

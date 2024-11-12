#include <iostream>
#include <cmath>

using namespace std;

const int MAX_N = 20; 
int x[MAX_N]; 
int count = 0; 

bool place(int k, int i) {
    
    for (int j = 1; j < k; ++j) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

void NQueen(int k, int n) {
    for (int i = 1; i <= n; ++i) {
        if (place(k, i)) {
            x[k] = i; 
            if (k == n) {
                
                cout << "Solution " << ++count << ": ";
                for (int j = 1; j <= n; ++j) {
                    cout << x[j] << " ";
                }
                cout << endl;
            } 
            else {
                NQueen(k + 1, n); 
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter total number of queens: ";
    cin >> n;

    NQueen(1, n); 
    cout << "Total possibilities: " << count << endl;

    return 0;
}

// Algorithm

/* 

algorithm place (k, i) {
    
    // Return true if a queen can be placed in kth row and ith column.
    // Otherwise it returns false.
    
    // x[] is a global array whose first k = 1 values have been set to absolute Abs(r)
    // Returns the Abs(r)
    
    for j:=1 to k-1 do
        if ((x[j] == i) || (Abs(x[j]-i) == Abs(j-k))) 
            returns false;
    return true;
}

Algorithm NQueen (k, n) {
    
    // Using backtracking, this procedure prints all possible placements of N Queen 
    // on an N*N chessboard so that they are non-attacking
    
    for i:=1 to n {
        if place(k, i) {
            x[k] = i;
            if (k == n) {
                write(x[1:n]);
            }
            else 
                NQueen(k+1, n);
        }
    }
}
*/

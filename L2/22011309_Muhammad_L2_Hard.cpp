/*
id: 22011309
name: Adam Haris
group: G1
lab: L3 (Hard) - Find a specific pair in Matrix
https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/
*/

#include <iostream>
#include <climits>
using namespace std;

#define N 5

int main() {
    int mat[N][N] = {
        { 10, -5, 3, 2, 7 },
        { -8, 12, -6, 4, 1 },
        { 5, -3, 15, 0, -2 },
        { 6, 8, -9, 11, 13 },
        { -4, 7, 2, -7, 9 }
    };

    int maxValue = INT_MIN;

    for (int a = 0; a < N - 1; a++) {
        for (int b = 0; b < N - 1; b++) {
            for (int d = a + 1; d < N; d++) {
                for (int e = b + 1; e < N; e++) {
                    int current = mat[d][e] - mat[a][b];
                    if (current > maxValue)
                        maxValue = current;
                }
            }
        }
    }

    cout << "Maximum Value is " << maxValue << endl;
    return 0;
}



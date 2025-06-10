/*
id: 22011309
name: Adam Haris
group: G1
lab: L2 (Easy) - Sort a Matrix in all way increasing order
https://www.geeksforgeeks.org/sort-matrix-way-increasing-order/
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    const int N = 3;
    int arr[N][N] = {
        {1, 0, 3},
        {2, 5, 6},
        {9, 4, 8}
    };

    int* ptr = (int*)arr;
    sort(ptr, ptr + N * N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int MATRIX_SIZE = 10000;

void runrow_major_traversal(vector<vector<int>>& v) {
    auto start = std::chrono::high_resolution_clock::now();
    long long sum = 0; // Upgraded to prevent future overflows
    
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            sum += v[i][j];
        }
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    
    // Fixed label to [Row-Major]
    std::cout << "[Row-Major] Execution Time: " << duration.count() << " ms | Checksum: " << sum << "\n";
}

void runcolumn_major_traversal(vector<vector<int>>& v) {
    long long sum = 0; // Upgraded to prevent future overflows
    auto start = std::chrono::high_resolution_clock::now();
    
    for(int j = 0; j < MATRIX_SIZE; j++) {
        for(int i = 0; i < MATRIX_SIZE; i++) {
            sum += v[i][j];
        }
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    
    std::cout << "[Column-Major] Execution Time: " << duration.count() << " ms | Checksum: " << sum << "\n";
}

int main() {
    cout << "Starting memory traversal hardware benchmarks..." << endl;
    vector<vector<int>> v(MATRIX_SIZE, vector<int>(MATRIX_SIZE, 1));
    
    runrow_major_traversal(v);
    runcolumn_major_traversal(v);
    
    return 0;
}

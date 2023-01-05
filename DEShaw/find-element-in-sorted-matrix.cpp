#include <iostream>

using namespace std;

bool isElementInMatrix(int element, int matrix[][3], int n, int m) {
    int i = 0;
    int j = m - 1;
    while(i < n && j >= 0) {
        if(matrix[i][j] == element) return true;
        else if(matrix[i][j] > element) --j;
        else ++i;
    }
    return false;
}

int main() {
    int element = 4;
    int matrix[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    int n = 4, m = 3;
    
    if(isElementInMatrix(element,matrix,n,m)) cout << "Found" << endl;
    else cout << "Not Found" << endl;
    
    return 0;
}


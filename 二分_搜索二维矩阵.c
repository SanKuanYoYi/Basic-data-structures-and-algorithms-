bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize,
                  int target) {

    int row = 0;
    
    while (row < matrixSize) {

        int col_left = 0;
        int col_right = *matrixColSize - 1;

        while (col_left <= col_right) {
            int col_mid = col_left + (col_right - col_left) / 2;

            if (matrix[row][col_mid] == target) {
                return true;
            } else if (matrix[row][col_mid] < target) {
                col_left = col_mid + 1;
            } else {
                col_right = col_mid - 1;
            }
        }
        row++;
    }
    return false;
}

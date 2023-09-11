
/**Adding two sparse matrices A[k][3] and B[k][3]*/
#include <stdio.h>

int main() {
    int k;
    printf("Enter the number of non-zero elements in the matrices A and B: ");
    scanf("%d", &k);

    int A[k][3], B[k][3], C[k][3]; 
    
    printf("Enter the elements of matrix A (row, column, value):\n");
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
    }

    printf("Enter the elements of matrix B (row, column, value):\n");
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &B[i][0], &B[i][1], &B[i][2]);
    }

    
    for (int i = 0; i < k; i++) {
        C[i][0] = A[i][0];
        C[i][1] = A[i][1];
        C[i][2] = A[i][2] + B[i][2]; 
    }

    printf("Resultant matrix C (row, column, value):\n");
    for (int i = 0; i < k; i++) {
        printf("%d %d %d\n", C[i][0], C[i][1], C[i][2]);
    }

    return 0;
}

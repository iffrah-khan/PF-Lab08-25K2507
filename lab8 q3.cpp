#include <stdio.h>
int main() 
{
    int r1, r2, c1, c2;
    int i, j, k;

    printf("========= MATRIX MULTIPLICATION =========\n\n");

    // taking input for dimensions of martrices
    printf("Enter number of rows for Matrix 1 (max 3): ");
    scanf("%d", &r1);
    printf("Enter number of columns for Matrix 1 (max 3): ");
    scanf("%d", &c1);
    printf("Enter number of rows for Matrix 2 (max 3): ");
    scanf("%d", &r2);
    printf("Enter number of columns for Matrix 2 (max 3): ");
    scanf("%d", &c2);

    // checkin if they are valid for multiplication
    while (c1 != r2) {
        printf("\n Invalid dimensions! Columns of Matrix 1 must equal Rows of Matrix 2.\n");
        printf("Please re-enter dimensions:\n");
        printf("Rows for Matrix 1: "); scanf("%d", &r1);
        printf("Columns for Matrix 1: "); scanf("%d", &c1);
        printf("Rows for Matrix 2: "); scanf("%d", &r2);
        printf("Columns for Matrix 2: "); scanf("%d", &c2);
    }

    int arr1[r1][c1], arr2[r2][c2], M[r1][c2];

    // taking input for matrix 1
    printf("\nEnter elements for Matrix 1:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("arr1[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &arr1[i][j]);
        }
    }

    // taking input for matrix 2
    printf("\nEnter elements for Matrix 2:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            printf("arr2[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &arr2[i][j]);
        }
    }
    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++)
            M[i][j] = 0;

    // matrix multiplication
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            for (k = 0; k < c1; k++) {
                M[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    // displaying all matrices
    printf("\nMatrix 1:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++)
            printf("%4d", arr1[i][j]);
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++)
            printf("%4d", arr2[i][j]);
        printf("\n");
    }

    printf("\n------ Resultant Matrix (A x B) ------\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++)
            printf("%4d", M[i][j]);
        printf("\n");
    }

    return 0;
}


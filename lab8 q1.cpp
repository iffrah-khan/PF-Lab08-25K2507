#include <stdio.h>
int main() 
{
    int arr[3][3], cofactor[3][3], adj[3][3];
    float inverse[3][3];
    int det = 0;
    int i, j;

    printf("Enter elements for a 3x3 matrix:\n\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nYour Matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
    
    printf("\n========= MATRIX ANALYSIS =========\n");
    printf("\n----- Transpose -----\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%4d", arr[j][i]);
        }
        printf("\n");
    }

    // determinant calculation
    for (i = 0; i < 3; i++) {
        det += arr[0][i] * (arr[1][(i + 1) % 3] * arr[2][(i + 2) % 3]
                          - arr[1][(i + 2) % 3] * arr[2][(i + 1) % 3]);
    }
    printf("\nDeterminant: %d\n", det);

    printf("\n----- Cofactor Matrix -----\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cofactor[i][j] = ((arr[(i + 1) % 3][(j + 1) % 3] * arr[(i + 2) % 3][(j + 2) % 3])
                             - (arr[(i + 1) % 3][(j + 2) % 3] * arr[(i + 2) % 3][(j + 1) % 3]));

            if ((i + j) % 2 != 0)
                cofactor[i][j] = -cofactor[i][j];

            printf("%4d", cofactor[i][j]);
        }
        printf("\n");
    }

    printf("\n----- Adjoint Matrix -----\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            adj[i][j] = cofactor[j][i];
            printf("%4d", adj[i][j]);
        }
        printf("\n");
    }

    if (det != 0) {
        printf("\n----- Inverse Matrix -----\n");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                inverse[i][j] = (float)adj[i][j] / det;
                printf("%8.2f", inverse[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nError! Determinant is zero — inverse cannot be found.\n");
    }

    return 0;
}


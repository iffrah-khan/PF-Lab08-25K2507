#include <stdio.h>
int main() 
{
    int rows, columns;
    printf("Enter number of rows (up to 5): ");
    scanf("%d", &rows);
    printf("Enter number of columns (up to 5): ");
    scanf("%d", &columns);

    int arr[5][5];
    printf("\n--- Enter elements of Matrix ---\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nMatrix :\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }

    int square = (rows == columns);
    int zero = 1, identity = 1, diagonal = 1, scalar = 1;
    int upper = 1, lower = 1, symmetric = 1, skew = 1;
    int determinant = 0, idempotent = 1, nilpotent = 1;

    // check for zero matrix
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if (arr[i][j] != 0) zero = 0;

    if (square) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (i != j && arr[i][j] != 0)
                    diagonal = 0;

                if ((i == j && arr[i][j] != 1) || (i != j && arr[i][j] != 0))
                    identity = 0;

                if (i > j && arr[i][j] != 0)
                    upper = 0;

                if (i < j && arr[i][j] != 0)
                    lower = 0;
            }
        }

        // check for scalar matrix
        if (diagonal) {
            int val = arr[0][0];
            for (int i = 0; i < rows; i++)
                if (arr[i][i] != val)
                    scalar = 0;
        } else scalar = 0;

        // check for symmetric and skew symmetric matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (arr[i][j] != arr[j][i])
                    symmetric = 0;
                if (arr[i][j] != -arr[j][i])
                    skew = 0;
            }
        }

        // calculating determinant (for 2x2 and 3x3 matrix)
        if (rows == 2)
            determinant = arr[0][0]*arr[1][1] - arr[0][1]*arr[1][0];
        else if (rows == 3)
            determinant = arr[0][0]*(arr[1][1]*arr[2][2]-arr[1][2]*arr[2][1])
                        - arr[0][1]*(arr[1][0]*arr[2][2]-arr[1][2]*arr[2][0])
                        + arr[0][2]*(arr[1][0]*arr[2][1]-arr[1][1]*arr[2][0]);
        else if (rows > 3)
            printf("\n(Determinant not calculated for matrices larger than 3x3)\n");

        // check for idempotent matrix
        int b[5][5] = {0};
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                for (int k = 0; k < columns; k++)
                    b[i][j] += arr[i][k] * arr[k][j];

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                if (b[i][j] != arr[i][j])
                    idempotent = 0;

        // check for nilpotent matrix
        nilpotent = 1;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                if (b[i][j] != 0)
                    nilpotent = 0;
    } else {
        diagonal = scalar = identity = upper = lower = symmetric = skew = idempotent = nilpotent = 0;
    }

    printf("\n--- MATRIX TYPE ANALYSIS ---\n\n");

    if (square) printf("1. Square Matrix\n");
    else printf("2. Rectangular Matrix\n");

    if (zero) printf("3. Zero Matrix\n");
    if (identity) printf("4. Identity Matrix\n");
    if (diagonal && !identity && !scalar) printf("5. Diagonal Matrix\n");
    if (scalar) printf("6. Scalar Matrix\n");
    if (upper) printf("7. Upper Triangular Matrix\n");
    if (lower) printf("8. Lower Triangular Matrix\n");
    if (symmetric) printf("9. Symmetric Matrix\n");
    if (skew) printf("10. Skew-Symmetric Matrix\n");

    if (square && rows <= 3) {
        if (determinant == 0)
            printf("11. Singular Matrix\n");
        else
            printf("11. Non-Singular Matrix (Det = %d)\n", determinant);
    }

    if (rows == 1) printf("13. Row Matrix\n");
    if (columns == 1) printf("14. Column Matrix\n");
    if (zero) printf("15. Null Matrix\n");
    if (idempotent) printf("16. Idempotent Matrix\n");
    if (nilpotent) printf("17. Nilpotent Matrix (A^2 = 0)\n");

    
    return 0;
}


#include <stdio.h>

int areLayersSame(int a[3][3][3], int l1, int l2) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (a[l1][i][j] != a[l2][i][j])
                return 0;
    return 1;
}

int main() 
{
    int matrix[3][3][3];
    char choice;

    printf("Do you want to enter matrix values manually? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        for (int layer = 0; layer < 3; layer++) {
            printf("\n--- Enter values for Layer %d ---\n", layer + 1);
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++) {
                    printf("Layer %d [%d][%d]: ", layer + 1, i + 1, j + 1);
                    scanf("%d", &matrix[layer][i][j]);
                }
        }
    } else {
        // default matrix
        int temp[3][3][3] = {
            { {9,8,7}, {6,5,4}, {3,2,1} },
            { {1,2,3}, {4,5,6}, {7,8,9} },
            { {9,8,7}, {6,5,4}, {3,2,1} }
        };
        for (int l = 0; l < 3; l++)
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    matrix[l][i][j] = temp[l][i][j];
    }

    printf("\n--- 3D MATRIX LAYERS ---\n");
    for (int layer = 0; layer < 3; layer++) {
        printf("\nLayer %d:\n", layer + 1);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                printf("%d\t", matrix[layer][i][j]);
            printf("\n");
        }
    }

    printf("\n--- LAYER COMPARISON RESULTS ---\n\n");

    int same12 = areLayersSame(matrix, 0, 1);
    int same13 = areLayersSame(matrix, 0, 2);
    int same23 = areLayersSame(matrix, 1, 2);

    printf("Layer 1 and Layer 2 are %s\n", same12 ? "IDENTICAL " : "DISTINCT ");
    printf("Layer 1 and Layer 3 are %s\n", same13 ? "IDENTICAL " : "DISTINCT ");
    printf("Layer 2 and Layer 3 are %s\n", same23 ? "IDENTICAL " : "DISTINCT ");

    return 0;
}


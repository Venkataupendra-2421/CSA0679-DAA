#include <stdio.h>
#include <stdlib.h>

// Function to calculate the binomial coefficient using dynamic programming
unsigned long long binomialCoeff(int n, int k) {
    unsigned long long C[n + 1][k + 1];

    // Calculate the binomial coefficient for each value of n and k
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= (i < k ? i : k); j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    return C[n][k];
}

int main() {
    int n, k;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the value of k: ");
    scanf("%d", &k);

    unsigned long long result = binomialCoeff(n, k);

    printf("Binomial Coefficient C(%d, %d) = %llu\n", n, k, result);

    return 0;
}


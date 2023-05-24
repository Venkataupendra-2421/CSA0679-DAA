#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_KEYS 100

// Function to calculate the sum of frequencies from i to j
int sumOfFreq(int freq[], int i, int j) {
    int sum = 0;
    for (int k = i; k <= j; k++)
        sum += freq[k];
    return sum;
}

// Function to calculate the cost of optimal BST using dynamic programming
int optCost(int keys[], int freq[], int n) {
    int cost[n][n];

    // For a single key, the cost is equal to the frequency
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    // Fill the cost matrix in a bottom-up manner
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        sumOfFreq(freq, i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    int keys[MAX_KEYS];
    int freq[MAX_KEYS];
    int n;

    printf("Enter the number of keys (maximum %d): ", MAX_KEYS);
    scanf("%d", &n);

    printf("Enter the keys:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    printf("Enter the frequencies:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    int cost = optCost(keys, freq, n);
    printf("Cost of the Optimal Binary Search Tree: %d\n", cost);

    return 0;
}


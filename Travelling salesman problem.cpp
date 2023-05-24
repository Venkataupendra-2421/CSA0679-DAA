#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

int numCities;
int graph[MAX_CITIES][MAX_CITIES];

int tspDP(int mask, int pos) {
    if (mask == (1 << numCities) - 1) {
        // All cities have been visited, return to starting city
        return graph[pos][0];
    }

    int minCost = INT_MAX;

    for (int city = 0; city < numCities; city++) {
        // Check if the city is not visited
        if ((mask & (1 << city)) == 0) {
            int newMask = mask | (1 << city);
            int newCost = graph[pos][city] + tspDP(newMask, city);
            if (newCost < minCost) {
                minCost = newCost;
            }
        }
    }

    return minCost;
}

int main() {
    printf("Enter the number of cities (maximum %d): ", MAX_CITIES);
    scanf("%d", &numCities);

    printf("Enter the cost matrix:\n");

    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int startCity = 0; // Starting city is assumed to be 0
    int initialMask = 1; // Bit mask for the starting city

    int minCost = tspDP(initialMask, startCity);

    printf("Minimum cost: %d\n", minCost);

    return 0;
}


#include <stdio.h>

#define MAX_ITEMS 100

// Structure to represent an item
struct Item {
    int weight;
    int value;
};

// Function to perform knapsack using a greedy approach
void knapsack_greedy(int n, int capacity, struct Item items[]) {
    int i, j;
    double value_per_weight[MAX_ITEMS];
    double total_value = 0.0;
    int total_weight = 0;

    // Calculate the value per unit weight of each item
    for (i = 0; i < n; i++) {
        value_per_weight[i] = (double) items[i].value / items[i].weight;
    }

    // Sort the items by their value per unit weight
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (value_per_weight[i] < value_per_weight[j]) {
                double temp = value_per_weight[i];
                value_per_weight[i] = value_per_weight[j];
                value_per_weight[j] = temp;

                int temp_weight = items[i].weight;
                items[i].weight = items[j].weight;
                items[j].weight = temp_weight;

                int temp_value = items[i].value;
                items[i].value = items[j].value;
                items[j].value = temp_value;
            }
        }
    }

    // Fill the knapsack with items
    for (i = 0; i < n && total_weight < capacity; i++) {
        int weight = items[i].weight;
        int value = items[i].value;

        if (total_weight + weight <= capacity) {
            total_weight += weight;
            total_value += value;
            printf("Selected item with weight %d and value %d\n", weight, value);
        } else {
            // Fractional part of the item can be added
            double fraction = (double) (capacity - total_weight) / weight;
            total_weight += weight * fraction;
            total_value += value * fraction;
            printf("Selected fractional part of item with weight %d and value %d\n", weight, value);
        }
    }

    printf("Total weight: %d\n", total_weight);
    printf("Total value: %.2f\n", total_value);
}

int main() {
    struct Item items[MAX_ITEMS];
    int n, capacity, i;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("Enter the weight and value of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d%d", &items[i].weight, &items[i].value);
    }

    knapsack_greedy(n, capacity, items);

    return 0;
}


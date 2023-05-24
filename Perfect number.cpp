#include <stdio.h>

// Function to check if a number is perfect
int isPerfectNumber(int num) {
    int sum = 0;
    
    // Iterate from 1 to num/2
    for (int i = 1; i <= num / 2; i++) {
        // If i is a divisor of num, add it to sum
        if (num % i == 0) {
            sum += i;
        }
    }
    
    // Check if sum is equal to num
    if (sum == num) {
        return 1;  // The number is perfect
    } else {
        return 0;  // The number is not perfect
    }
}

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (isPerfectNumber(num)) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is not a perfect number.\n", num);
    }
    
    return 0;
}


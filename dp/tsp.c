#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define INF 1000000

int C[MAX][MAX]; // Cost matrix
int n; // Number of cities

// Function to find the minimum cost for visiting cities in D[] starting from city i
int cost(int i, int D[], int dSize, int visited[], int path[], int index) {
    if (dSize == 0) {
        // Base case: if there are no more cities to visit, return the cost to go back to the start city (1)
        path[index] = 1; // Add city 1 to the tour path
        return C[i][1]; // Return the cost to go back to the start city
    }

    int minCost = INF;  // Start with a very high cost
    int bestCity = -1;  // To track the city that leads to the minimum cost

    // Loop over all cities in the remaining set D
    for (int k = 0; k < dSize; k++) {
        int j = D[k];  // The next city to visit

        // Skip cities that have already been visited
        if (visited[j]) continue;

        // Mark the city as visited
        visited[j] = 1;

        // Store the city in the path
        path[index] = j;

        // Create a new set D' without city j (D - {j})
        int newD[MAX], newIndex = 0;
        for (int m = 0; m < dSize; m++) {
            if (m != k) {
                newD[newIndex++] = D[m];
            }
        }

        // Recursively calculate the cost to visit city j and then the remaining cities in newD
        int newCost = C[i][j] + cost(j, newD, dSize - 1, visited, path, index + 1);

        // Update the minimum cost and store the best city visited
        if (newCost < minCost) {
            minCost = newCost;
            bestCity = j;
        }

        // Unmark the city as visited for other recursive paths
        visited[j] = 0;
    }

    return minCost;
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    // Step 1: Cost Matrix Construction
    printf("Enter cost matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                C[i][j] = 0; // Cost of traveling from a city to itself is 0
            else {
                printf("Enter cost from %d to %d: ", i, j);
                scanf("%d", &C[i][j]);
            }
        }
    }

    // Step 2: Optimal Cost Initialization
    int D[MAX]; // Array to store the set of cities remaining to visit
    int dSize = 0;
    for (int i = 1; i <= n; i++) {
        if (i != 1) {
            D[dSize++] = i; // Set of cities to visit (excluding city 1)
        }
    }

    // Step 3: Initialize visited array to track the visited cities
    int visited[MAX] = {0}; // Initially no cities are visited
    visited[1] = 1; // Mark city 1 as visited

    // Step 4: Path array to store the best tour sequence
    int path[MAX];

    int minTour = cost(1, D, dSize, visited, path, 1); // Start from city 1

    // Print the minimum tour cost
    printf("Minimum tour cost: %d\n", minTour);

    // Print the tour sequence from the path array
    printf("Best tour sequence: 1 -> ");
    for (int i = n - 1; i >= 1; i--) {
        printf("%d -> ", path[i]);
    }
    printf("1\n");

    return 0;
}

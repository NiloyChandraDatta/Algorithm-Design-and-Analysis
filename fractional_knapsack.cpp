#include<bits/stdc++.h>
using namespace std;

// Item structure holds profit and weight
struct Item 
{
    int profit, weight;
    
    Item(int profit, int weight) 
    {
        this->profit = profit;
        this->weight = weight;
    }
};

// Compare function to sort items by profit/weight ratio
static bool cmp(struct Item a, struct Item b) 
{
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}

// Function to solve fractional knapsack problem
double fractionalKnapsack(int W, struct Item arr[], int N) 
{
    sort(arr, arr + N, cmp); // Sort items by ratio
    double finalvalue = 0.0; // Total profit
    
    for (int i = 0; i < N; i++) 
    {
        // If item can be fully added
        if (arr[i].weight <= W) 
        {
            W -= arr[i].weight;
            finalvalue += arr[i].profit;
        }
        // Add fractional part if item can't be fully added
        else 
        {
            finalvalue += arr[i].profit * ((double)W / (double)arr[i].weight);
            break;
        }
    }
    return finalvalue; // Return final profit
}

// Main function
int main() 
{
    int W = 50; // Knapsack capacity
    Item arr[] = {{ 60, 10 }, { 100, 20 }, { 120, 30 }}; // Items
    int N = sizeof(arr) / sizeof(arr[0]); // Number of items
    
    // Call the function and print the result
    cout << fractionalKnapsack(W, arr, N);
    return 0;
}

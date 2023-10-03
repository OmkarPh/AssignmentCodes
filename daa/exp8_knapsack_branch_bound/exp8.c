#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct {
    int weight;
    int value;
} Item;

typedef struct {
    int level;
    int value;
    int weight;
    int bound;
} Node;

int n, capacity;
Item items[N];
Node queue[N];
int front = 0, rear = 0;
int max_profit = 0;

void enqueue(Node node) {
    queue[rear++] = node;
}

Node dequeue() {
    return queue[front++];
}

int bound(Node node) {
    if (node.weight > capacity) {
        return 0;
    }
    int profit_bound = node.value;
    int j = node.level + 1;
    int total_weight = node.weight;
    while (j < n && total_weight + items[j].weight <= capacity) {
        total_weight += items[j].weight;
        profit_bound += items[j].value;
        j++;
    }
    if (j < n) {
        profit_bound += (capacity - total_weight) * (items[j].value / (double) items[j].weight);
    }
    return profit_bound;
}

void knapsack() {
    Node root = {0, 0, 0, 0};
    root.bound = bound(root);
    enqueue(root);
    while (front != rear) {
        Node node = dequeue();
        if (node.bound > max_profit) {
            Node left = {node.level + 1, node.value + items[node.level].value, node.weight + items[node.level].weight, 0};
            left.bound = bound(left);
            if (left.weight <= capacity && left.bound > max_profit) {
                max_profit = left.value;
            }
            if (left.bound > max_profit) {
                enqueue(left);
            }
            Node right = {node.level + 1, node.value, node.weight, 0};
            right.bound = bound(right);
            if (right.weight <= capacity && right.bound > max_profit) {
                max_profit = right.value;
            }
            if (right.bound > max_profit) {
                enqueue(right);
            }
        }
    }
}



int main() {
  /*
  Testcase
6
12
3 7
5 4
2 6
4 3
5 3
7 6

Max profit - 17
  */
    printf("Enter the no. of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    knapsack();

    printf("Maximum profit: %d\n", max_profit);
    return 0;
}

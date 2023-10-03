#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_RESOURCES 5

int available[MAX_RESOURCES];
int allocation[MAX_RESOURCES];
int max[MAX_RESOURCES];
int need[MAX_RESOURCES];

pthread_mutex_t mutex;

int safe_state = 1;
int safe_sequence[MAX_RESOURCES];
int num_safe = 0;

void print_arrays()
{
  printf("Allocation:\n");
  for (int i = 0; i < MAX_RESOURCES; i++)
  {
    printf("%d ", allocation[i]);
  }
  printf("\n");

  printf("Max:\n");
  for (int i = 0; i < MAX_RESOURCES; i++)
  {
    printf("%d ", max[i]);
  }
  printf("\n");

  printf("Available:\n");
  for (int i = 0; i < MAX_RESOURCES; i++)
  {
    printf("%d ", available[i]);
  }
  printf("\n");

  printf("Need:\n");
  for (int i = 0; i < MAX_RESOURCES; i++)
  {
    printf("%d ", need[i]);
  }
  printf("\n");
}

int is_safe(int request[])
{
  int work[MAX_RESOURCES];
  int finish[MAX_RESOURCES];

  // Initialize work and finish arrays
  for (int i = 0; i < MAX_RESOURCES; i++)
  {
    work[i] = available[i] - request[i];
    finish[i] = 0;
  }

  // Check if the request is less than or equal to need
  for (int i = 0; i < MAX_RESOURCES; i++)
  {
    if (request[i] > need[i])
    {
      return 0;
    }
  }

  // Check if the request can be granted without leaving the system in an unsafe state
  int num_finished = 0;
  while (num_finished < MAX_RESOURCES)
  {
    int found = 0;
    for (int i = 0; i < MAX_RESOURCES; i++)
    {
      if (!finish[i] && need[i] <= work)
      {
        // Grant the resources to the process
        for (int j = 0; j < MAX_RESOURCES; j++)
        {
          work[j] += allocation[i * MAX_RESOURCES + j];
        }

        finish[i] = 1;
        safe_sequence[num_finished] = i;
        num_finished++;
        found = 1;
      }
    }
    if (!found)
    {
      return 0;
    }
  }
  return 1;
}

void request_resources(int request[])
{
  pthread_mutex_lock(&mutex);

  // Check if the request can be granted immediately
  if (is_safe(request))
  {
    for (int i = 0; i < MAX_RESOURCES; i++)
    {
      available[i] -= request[i];
      allocation[i] += request[i];
      need[i] -= request[i];
    }
    printf("Request granted.\n");
    print_arrays();
  }
  else
  {
    printf("Request denied.\n");
  }

  pthread_mutex_unlock(&mutex);
}

void release_resources(int release[])
{
  pthread_mutex_lock(&mutex);

  // Release the resources
  for (int i = 0; i < MAX_RESOURCES; i++)
  {
    available[i] += release[i];
    allocation[i] -= release[i];
    need[i] += release[i];
  }
  printf("Resources released.\n");
  print_arrays();

  pthread_mutex_unlock(&mutex);
}

int main()
{
  // Initialize mutex
  pthread_mutex_init(&mutex, NULL);

  // Get allocation and available from user
  printf("Enter allocation:\n");
  for (int i = 0; i < MAX_RESOURCES; i++)
  {
    scanf("%d", &allocation[i]);
  }

  printf("Enter available:\n");
  for (int i = 0; i < MAX_RESOURCES; i++)
  {
    scanf("%d", &available[i]);
  }

  // Calculate need
  for (int i = 0; i < MAX_RESOURCES; i++)
  {
    need[i] = max[i] - allocation[i];
  }

  // Print arrays
  print_arrays();

  // Find safe sequence
  int work[MAX_RESOURCES];
  int finish[MAX_RESOURCES];
  int num_finished = 0;
  while (num_finished < MAX_RESOURCES)
  {
    int found = 0;
    for (int i = 0; i < MAX_RESOURCES; i++)
    {
      if (!finish[i] && need[i] <= available)
      {
        // Grant the resources to the process
        for (int j = 0; j < MAX_RESOURCES; j++)
        {
          available[j] += allocation[i * MAX_RESOURCES + j];
        }

        finish[i] = 1;
        safe_sequence[num_finished] = i;
        num_finished++;
        found = 1;
      }
    }
    if (!found)
    {
      safe_state = 0;
      break;
    }
  }

  // Print safe sequence and safe state
  printf("Safe sequence: ");
  if (safe_state)
  {
    for (int i = 0; i < MAX_RESOURCES; i++)
    {
      printf("%d ", safe_sequence[i]);
    }
    printf("\nFederation is in a safe state.\n");
  }
  else
  {
    printf("No safe sequence exists.\nFederation is in an unsafe state.\n");
  }

  // Create customer thread to request resources
  pthread_t customer_thread;
  int request[MAX_RESOURCES];
  printf("Enter request:\n");
  for (int i = 0; i < MAX_RESOURCES; i++)
  {
    scanf("%d", &request[i]);
  }
  pthread_create(&customer_thread, NULL, request_resources, request);

  // Wait for customer thread to finish
  pthread_join(customer_thread, NULL);

  // Release resources
  release_resources(allocation);

  // Destroy mutex
  pthread_mutex_destroy(&mutex);

  return 0;
}



// Output
/*
Enter allocation:
0 1 0 1
2 0 0 1
2 0 3 2
1 2 2 1
Enter max:
0 2 1 2
3 0 0 1
3 0 3 3
1 3 5 2
Enter available:
1 0 2 0
Allocation:
0 1 0 1
2 0 0 1
2 0 3 2
1 2 2 1
Max:
0 2 1 2
3 0 0 1
3 0 3 3
1 3 5 2
Need:
0 1 1 1
1 0 0 0
1 0 0 1
0 1 3 1
Safe sequence: 1 3 0 2
Federation is in a safe state.
Enter request:
0 0 1 0
Request can be granted immediately.
*/
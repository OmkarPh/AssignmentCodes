#include <stdio.h>
#include "semaphore.h"
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#include <fcntl.h>
#include <sys/stat.h>

int main()
{
  key_t key;
  int *arr;
  int shmid;
  key = ftok("shared_mem_prog", 0);

  sem_t *semaphore;
  semaphore = sem_open("testsemaphore", 0);

  if (semaphore == SEM_FAILED)
  {
    perror("sem_open");
    exit(1);
  }

  shmid = shmget(key, 41 * sizeof(int), IPC_CREAT | 0666);

  if (shmid == -1)
  {
    perror("shmget");
    exit(1);
  }

  arr = (int *)shmat(shmid, NULL, 0);

  if (arr == (int *)-1)
  {
    perror("shmat");
    exit(1);
  }

  // printf("Value of array:%d",arr[40]);
  while (1)
  {
    // printf("before sem_wait\n");
    sem_wait(semaphore);
    // printf("after sem_wait\n");

    int count = arr[40];
    if (count >= 39)
    {
      sem_post(semaphore);
      break;
    }
    int val = rand() % 100;
    arr[count + 1] = val;
    arr[40] = count + 1;
    printf("\nIndex:%d,Value:%d", count + 1, val);
    sem_post(semaphore);
    sleep(1);

    if (count == 39)
      break;
  }

  shmdt(arr);
  return 0;
}
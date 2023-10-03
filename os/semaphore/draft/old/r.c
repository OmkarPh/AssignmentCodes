#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <semaphore.h>

int main()
{
  key_t key;
  int *arr;
  int shmid;
  key = ftok("shared_mem_prog", 0);

  sem_t *semaphore;
  semaphore = sem_open("testsemaphore", O_CREAT, S_IRUSR | S_IWUSR, 0);

  if (semaphore == SEM_FAILED)
  {
    perror("sem_open");
    exit(1);
  }

  sem_init(semaphore, 1, 1);
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

  arr[40] = -1;

  int ch;
  printf("\nShared Memory and Semaphores initialized");
  printf("\nEnter 1 to continue:");
  scanf("%d", &ch);

  // sorting the array

  for (int i = 0; i < 40; i++)
  {
    for (int j = i; j < 40; j++)
    {
      if (arr[i] > arr[j])
      {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
      }
    }
  }

  if (ch == 1)
  {
    for (int i = 0; i < 41; i++)
    {
      printf("\narr[%d]=%d", i, arr[i]);
    }
  }

  shmdt(arr);
  sem_destroy(semaphore);
  sem_close(semaphore);
  sem_unlink("testsemaphore");
  return 0;
}
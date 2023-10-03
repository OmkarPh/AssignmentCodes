
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define FILLED 0
#define Ready 1
#define NotReady -1

struct memory
{
   char buff[100];
   int status, pid1, pid2;
};

struct memory *shmptr;

// handler function to print message received from user1

void receiver(int signum)
{
   if (signum == SIGUSR2)
   {
      printf("Got > ");
      puts(shmptr->buff);
   }
}

// main function

int main()
{
   int pid = getpid();
   int shmid;
   int key = 12345;

   shmid = shmget(key, sizeof(struct memory), IPC_CREAT | 0666);

   shmptr = (struct memory *)shmat(shmid, NULL, 0);

   shmptr->pid2 = pid;

   shmptr->status = NotReady;

   signal(SIGUSR2, receiver);

   while (1)
   {
      sleep(1);

      printf("Enter your message: ");
      fgets(shmptr->buff, 100, stdin);
      shmptr->status = Ready;

      kill(shmptr->pid1, SIGUSR1);

      while (shmptr->status == Ready)
         continue;
   }

   shmdt((void *)shmptr);
   return 0;
}

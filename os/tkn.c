#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
  char *file = argv[1];
  char *cmd = argv[2];
  int fd;
  struct flock lock;
  memset(&lock, 0, sizeof(lock));
  lock.l_pid = getpid();
  if (strcmp(cmd, "r") == 0)
  {
    
    fd = open(file, O_RDONLY);
    printf("Locked the file in share mode !\n");
    lock.l_type = F_RDLCK;
    fcntl(fd, F_SETLK, &lock);
    char buff[100];
    int fsize = lseek(fd, 0, SEEK_END);
    // printf("%d is file size\n", fsize);
    lseek(fd, 0, SEEK_SET);
    printf("File text : \n");
    read(fd, buff, fsize);
    printf("%s", buff);
    getchar();
    printf("\nUnlocked the file !");
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
  }
  else
  {
    fd = open(file, O_TRUNC | O_WRONLY);
    lock.l_type = F_WRLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1)
    {
      printf("\nCan't lock this file, Already locked by other process, wait till it's released ... \n");
    }
    while (fcntl(fd, F_SETLK, &lock) == -1)
    {
    }
    printf("Locked file in exclusive mode !\n");
    char *buff = (char *)malloc(sizeof(char) * 1024);
    int i = 0;
    while ((buff[i] = getchar()) != 10)
    {
      // write(fd,buff+i,1);
      i++;
    }
    // optional
    int a = getpid();
    char result[20];
    sprintf(result, "%d", a);
    strcat(buff, result);
    int len = strlen(buff);
    write(fd, buff, len);
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Unlocked !!\n");
    close(fd);
  }
  return 0;
}
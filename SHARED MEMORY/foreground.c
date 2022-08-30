/*
Develop programs to implement the following system. The system consists of a foreground process and a background process. Both share an array of integers. 
The foreground process accepts integers through the terminal and appends each integer to the shared array.
The background process keeps the shared array sorted in ascending order after each addition. 
When the last element is also placed in its correct position, the foreground process displays the shared array on the terminal.
*/

#include<stdio.h>
#include<semaphore.h>
#include <stdlib.h>
#include<unistd.h>
#include <fcntl.h> 
#include <sys/mman.h>
#include<sys/stat.h>

struct data
{
 int a[20]; 
  sem_t mutex;
}*d;

int main(){
  int x=0,i,n,size,item;
  int fd=shm_open("/shared",O_CREAT|O_RDWR,0777);
  ftruncate(fd,sizeof(struct data));
  d=mmap(NULL,sizeof(struct data),PROT_WRITE|PROT_READ,MAP_SHARED,fd,0);
  sem_init(&(d->mutex),10,1);
  printf("Enter number of items:");
  scanf("%d",&n);
  for(i=0;i<=n;i++){
    if(x==n)
      {
        sleep(5);
      for(int p=0;p<5;p++)
     {
        printf("  %d  ",d->a[p]);
     } 
        exit(0);
      }
    else{
      printf("\nEnter an item");
      scanf("%d",&item);
      sem_wait(&(d->mutex));
      d->a[x]=item;
      x++;
      sem_post(&(d->mutex));
  }
  }
 }
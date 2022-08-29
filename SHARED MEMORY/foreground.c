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
 int buffer[10];
 int a[20]; 
  sem_t full,empty,mutex;
}*d;

int main(){
  int x,index=0,item,i,n,size;
  int fd=shm_open("/shared",O_CREAT|O_RDWR,0777);
  ftruncate(fd,sizeof(struct data));
  d=mmap(NULL,sizeof(struct data),PROT_WRITE|PROT_READ,MAP_SHARED,fd,0);
  sem_init(&(d->mutex),10,1);
  sem_init(&(d->full),10,0);
  sem_init(&(d->empty),10,5);
  
  
  printf("Enter number of items:");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    sem_getvalue(&(d->full),&x);
    
    if(x==5)
      {
      sleep(10);
      for(int p=0;p<5;p++)
     {
        printf("  %d  ",d->a[p]);
     } 
        printf("\nBuffer full\n"); 
        exit(0);
      }
    else{
      printf("\nEnter an item");
      scanf("%d",&item);
      sleep(15);
      sem_wait(&(d->mutex));
      sem_wait(&(d->empty));
      d->buffer[index] = item;
     index=(index+1)%5;
      sem_post(&(d->full));
      sem_post(&(d->mutex));
  }
 
  }
 }
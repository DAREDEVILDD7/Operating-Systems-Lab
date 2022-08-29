#include<stdio.h>
#include<semaphore.h>
#include <stdlib.h>
#include<unistd.h>
#include <fcntl.h> 
#include <sys/mman.h>
#include<sys/stat.h>

#define n 5

int s=0;
 int j;
struct data
{
 int buffer[10];
 int a[20]; 
  sem_t full,empty,mutex;
}*d;

void inssort(int dt)
{
 if(d->a[j]>=dt)
 {
    for (j = s - 1; (j >=0 && d->a[j] > dt); j--)
    {
        d->a[j + 1] = d->a[j];
    }
  //  printf("\n%d\n",j);
            d->a[j+1] = dt;
   }
 else
 d->a[s]=dt;

/* for(int p=0;p<=s;p++)
 {
  printf("  %d  ",d->a[p]);
 }
 */
}

int main(){
  int x,out=0,item,index=0,i;
  int fd=shm_open("/shared",O_RDWR,0777);
  d=mmap(NULL,sizeof(struct data),PROT_WRITE|PROT_READ,MAP_SHARED,fd,0);
  for(i=0;i<n;i++){
    sem_getvalue(&(d->empty),&x);
    
    if(x==5)
      {printf("Buffer empty\n");
        exit(0);}
    else{
     sleep(2);
      sem_wait(&(d->mutex));
      sem_wait(&(d->full));
      item=d->buffer[index] ;
      printf("Item consumed:%d\n",item);
           index=(index+1)%5;
     if(s==0)
     {
       d->a[s]=item;
              s++;
     }
     else
     {
     
      inssort(item);
      s++;
     }

      sem_post(&(d->mutex));
      sem_post(&(d->empty));
    }
  }
}
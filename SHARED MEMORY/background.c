#include<stdio.h>
#include<semaphore.h>
#include <stdlib.h>
#include<unistd.h>
#include <fcntl.h> 
#include <sys/mman.h>
#include<sys/stat.h>

#define n 5

int s=0;
struct data
{
 int a[20]; 
  sem_t mutex;
}*d;

void inssort(int dt)
{
int j=s-1;
 if(d->a[j]>=dt)
 {
    for (j = s - 1; (j >=0 && d->a[j] > dt); j--)
    {
        d->a[j + 1] = d->a[j];
    }
            d->a[j+1] = dt;
   }
 else
 d->a[s]=dt;

}

int main(){
  int out=0,data,x=0,i;
  int fd=shm_open("/shared",O_RDWR,0777);
  d=mmap(NULL,sizeof(struct data),PROT_WRITE|PROT_READ,MAP_SHARED,fd,0);
  for(i=0;i<n;i++){
      sem_wait(&(d->mutex));
      data=d->a[x] ;
      printf("Item Inserted:%d\n",data);
           x++;
     if(s==0)
     {
       d->a[s]=data;
              s++;
     }
     else
     {
      inssort(data);
      s++;
     }
      sem_post(&(d->mutex));

    sleep(5);
  }
}
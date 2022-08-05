//fcfs
/*
#include<stdio.h>
#include<string.h>
struct process1
{
  char name1[20];
  int at1,tt1,bt1,wt1,ct1,status1;
}p1[20],temp1;
struct done1
{
  char name1[20];
  int st1,ct1;
}d1[20];
void main()
{
  int i1,j1,n1,num1,idle1=0;
  float avwt1=0;
  float avtt1=0;
  printf("ENTER THE NUMBER OF PROCESSES : ");
  scanf("%d",&n1);
  for(i1=0;i1<n1;i1++)                         //Input process details
  {
    printf("\nENTER DETAILS OF PROCESS %d",i1+1);
    printf("\nPROCESS NAME : ");
    scanf(" %s",p1[i1].name1);
    printf("ARRIVAL TIME : ");
    scanf("%d",&p1[i1].at1);
    printf("BURST TIME : ");
    scanf("%d",&p1[i1].bt1);
    p1[i1].status1 = 0;
  }
  for(i1=0;i1<n1;i1++)                       //Sorting based on at
  {
    for(j1=0;j1<n1-i1-1;j1++)
    {
      if(p1[j1].at1 > p1[j1+1].at1)
      {
        temp1 = p1[j1];
        p1[j1] = p1[j1+1];
        p1[j1+1] = temp1;
      }
    }
  }
  for(i1=0,j1=0,num1=0;j1<n1;)              //Calculations
  {
    if(p1[j1].at1<=i1 && p1[j1].status1==0)
    {
      if(idle1==1)
      {
        d1[num1].ct1=i1;
        num1++;
        idle1 = 0;
      }
      strcpy(d1[num1].name1,p1[j1].name1);
      d1[num1].st1 = i1;
      d1[num1].ct1 = i1 + p1[j1].bt1;
      p1[j1].wt1 = d1[num1].st1 - p1[j1].at1;
      p1[j1].tt1 = p1[j1].wt1 + p1[j1].bt1;
      p1[j1].ct1 = d1[num1].ct1;
      i1 = d1[num1].ct1;
      p1[j1].status1 = 1;
      j1++;
      num1++;
    }
    else if(idle1 == 0)
    {
      strcpy(d1[num1].name1,"Idle");
      d1[num1].st1 = i1;
      i1++;
      idle1 = 1;
    }
    else
    {
      i1++;
    }
  }
  printf("\nPROCESS NAME\tCOMPLETION TIME (ms)\tWAITING TIME (ms)\tTURNAROUND TIME (ms)\n");
  for(int i1=0;i1<n1;i1++)
  {
    printf("    %s\t\t\t%d\t\t\t%d\t\t\t%d\n",p1[i1].name1,p1[i1].ct1,p1[i1].wt1,p1[i1].tt1);
    avwt1+=p1[i1].wt1;
    avtt1+=p1[i1].tt1;
  }
  printf("\n\nGANTT CHART ");
  printf("\n----------------------------------------------------------\n");
      for(i1=0;i1<num1;i1++)
      {
          printf("|");
          printf("   %s\t",d1[i1].name1);
       }
       printf(" |");
       printf("\n----------------------------------------------------------\n");
       for(i1=0;i1<num1;i1++)
       {
          printf("%d\t",d1[i1].st1);
       }
       printf("%d\t",d1[num1-1].ct1);
  printf("\n\nAVERAGE WAITING TIME : %f",(avwt1/n1));
  printf("\nAVERAGE TURNAROUND TIME : %f\n",(avtt1/n1));
}

*/


























//priority

#include<stdio.h>
#include<string.h>
struct process2
{
  char name2[20];
  int at2,tt2,bt2,wt2,status2,ct2,pr2;
}p2[20],temp2;
struct done2
{
  char name2[20];
  int st2,ct2;
}d2[20];
void main()
{
  int n2,i2,j2,ls2,min2,fnd2,num2,idle2;
  float twt2=0.0,ttt2=0.0;
  printf("ENTER THE NUMBER OF PROCESSES : ");
  scanf("%d",&n2);
  for(i2=0;i2<n2;i2++)                         //Input process details
  {
    printf("\nENTER DETAILS OF PROCESS %d",i2+1);
    printf("\nPROCESS NAME : ");
    scanf(" %s",p2[i2].name2);
    printf("ARRIVAL TIME : ");
    scanf("%d",&p2[i2].at2);
    printf("BURST TIME : ");
    scanf("%d",&p2[i2].bt2);
    printf("PRIORITY : ");
    scanf("%d",&p2[i2].pr2);
    p2[i2].status2 = 0;
  }
  for(i2=0,ls2=0,num2=0,idle2=0;ls2<n2;)
  {
    for(j2=0,fnd2=0;j2<n2;j2++)
    {
      if(i2>=p2[j2].at2 && p2[j2].status2==0)
      {
        if(fnd2==0)
        {
          min2 = j2;
          fnd2 = 1;
        }
        else if((p2[min2].pr2>p2[j2].pr2)||(p2[min2].pr2==p2[j2].pr2 && p2[min2].at2>p2[j2].at2))
        {
          min2 = j2;
        }
      }
    }
    if(idle2==0 && fnd2==0)
    {
      strcpy(d2[num2].name2,"Idle");
      d2[num2].st2 = i2;
      i2++;
      idle2 = 1;
    }
    else if(fnd2==1)
    {
      if(idle2==1)
      {
        d2[num2].ct2 = i2;
        num2++;
        idle2 = 0;
      }
      strcpy(d2[num2].name2,p2[min2].name2);
      p2[min2].status2 =1;
      d2[num2].st2 = i2;
      d2[num2].ct2 = i2 + p2[min2].bt2;
      i2 = d2[num2].ct2;
      p2[min2].ct2 = d2[num2].ct2;
      p2[min2].tt2 = p2[min2].ct2 - p2[min2].at2;
      p2[min2].wt2 = p2[min2].tt2 - p2[min2].bt2;
      num2++;
      ls2++;
    }
    else
    {
      i2++;
    }
  }
  printf("\nPROCESS NAME\tCOMPLETION TIME (ms)\tWAITING TIME (ms)\tTURNAROUND TIME (ms)\n\n");
  for(i2=0;i2<n2;i2++)
  {
    printf("    %s\t\t\t%d\t\t\t%d\t\t\t%d\n",p2[i2].name2,p2[i2].ct2,p2[i2].wt2,p2[i2].tt2);
    twt2+=p2[i2].wt2;
    ttt2+=p2[i2].tt2;
  }
  printf("\n\nGANTT CHART ");
  printf("\n\t--------------------------------------------------------------------\n\t");
  for(i2=0;i2<num2;i2++)
  {
    printf("|");
    printf("%s\t",d2[i2].name2);
  }
  printf(" |");
  printf("\n\t--------------------------------------------------------------------\n\t");
  for(i2=0;i2<num2;i2++)
  {
      printf("%d\t",d2[i2].st2);
  }
  printf("%d\t\n",d2[num2-1].ct2);
  printf("\nAVERAGE WAITING TIME : %f",(twt2/n2));
  printf("\nAVERAGE TURNAROUND TIME : %f\n",(ttt2/n2));
}




















//sjf



#include<stdio.h>
#include<string.h>
struct process3
{
  char name3[20];
  int at3,tt3,bt3,wt3,status3,ct3;
}p3[20],temp3;
struct done3
{
  char name3[20];
  int st3,ct3;
}d3[20];
void main()
{
  int n3,i3,j3,ls3,min3,fnd3,num3,idle3;
  float twt3=0.0,ttt3=0.0;
  printf("ENTER THE NUMBER OF PROCESSES : ");
  scanf("%d",&n3);
  for(i3=0;i3<n3;i3++)                         //Input process details
  {
    printf("\nENTER DETAILS OF PROCESS %d",i3+1);
    printf("\nPROCESS NAME : ");
    scanf(" %s",p3[i3].name3);
    printf("ARRIVAL TIME : ");
    scanf("%d",&p3[i3].at3);
    printf("BURST TIME : ");
    scanf("%d",&p3[i3].bt3);
    p3[i3].status3 = 0;
  }
  for(i3=0,ls3=0,num3=0,idle3=0;ls3<n3;)
  {
    for(j3=0,fnd3=0;j3<n3;j3++)
    {
      if(i3>=p3[j3].at3 && p3[j3].status3==0)
      {
        if(fnd3==0)
        {
          min3 = j3;
          fnd3 = 1;
        }
        else if(fnd3!=0 && p3[min3].bt3>p3[j3].bt3)
        {
          min3 = j3;
        }
      }
    }
    if(idle3==0 && fnd3==0)
    {
      strcpy(d3[num3].name3,"Idle");
      d3[num3].st3 = i3;
      i3++;
      idle3 = 1;
    }
    else if(fnd3==1)
    {
      if(idle3==1)
      {
        d3[num3].ct3 = i3;
        num3++;
        idle3 = 0;
      }
      strcpy(d3[num3].name3,p3[min3].name3);
      p3[min3].status3 =1;
      d3[num3].st3 = i3;
      d3[num3].ct3 = i3 + p3[min3].bt3;
      i3 = d3[num3].ct3;
      p3[min3].ct3 = d3[num3].ct3;
      p3[min3].tt3 = p3[min3].ct3 - p3[min3].at3;
      p3[min3].wt3 = p3[min3].tt3 - p3[min3].bt3;
      num3++;
      ls3++;
    }
    else
    {
      i3++;
    }
  }
  printf("\nPROCESS NAME\tCOMPLETION TIME (ms)\tWAITING TIME (ms)\tTURNAROUND TIME (ms)\n\n");
  for(i3=0;i3<n3;i3++)
  {
    printf("    %s\t\t\t%d\t\t\t%d\t\t\t%d\n",p3[i3].name3,p3[i3].ct3,p3[i3].wt3,p3[i3].tt3);
    twt3+=p3[i3].wt3;
    ttt3+=p3[i3].tt3;
  }
  printf("\n\nGANTT CHART ");
  printf("\n\t--------------------------------------------------------------------\n\t");
  for(i3=0;i3<num3;i3++)
  {
    printf("|");
    printf("%s\t",d3[i3].name3);
  }
  printf(" |");
  printf("\n\t--------------------------------------------------------------------\n\t");
  for(i3=0;i3<num3;i3++)
  {
      printf("%d\t",d3[i3].st3);
  }
  printf("%d\t\n",d3[num3-1].ct3);
  printf("\nAVERAGE WAITING TIME : %f",(twt3/n3));
  printf("\nAVERAGE TURNAROUND TIME : %f\n",(ttt3/n3));
}

















//roundrobin


#include <stdio.h>
#include <string.h>
int q4[100],front=-1,rear=-1;
struct process4
{
  char name4[20];
  int at4,tt4,bt4,wt4,status4,left4,ct4;
}p4[20],temp4;
struct done4
{
  char name4[20];
  int st4,ct4;
}d4[20];
void enqueue(int j4)
{
  if(front==-1 && rear==-1)
  {
    front++;
  }
  rear++;
  q4[rear] = j4;
}
int dequeue()
{
  int item4;
  item4 = q4[front];
  if(front == rear)
  {
    front = -1;
    rear = -1;
  }
  else
  {
    front++;
  }
  return(item4);
}
void main()
{
  int n4,i4,j4,idle4=0,k4,num4,ls4,t4;
  float avwt4=0,avtt4=0;
  printf("ENTER THE NUMBER OF PROCESSES : ");
  scanf("%d",&n4);
  for(i4=0;i4<n4;i4++)                         //Input process details
  {
    printf("\nENTER DETAILS OF PROCESS %d",i4+1);
    printf("\nPROCESS NAME : ");
    scanf(" %s",p4[i4].name4);
    printf("ARRIVAL TIME : ");
    scanf("%d",&p4[i4].at4);
    printf("BURST TIME : ");
    scanf("%d",&p4[i4].bt4);
    p4[i4].left4 = p4[i4].bt4;
    p4[i4].status4 = 0;
  }
  printf("\nENTER THE TIME QUANTUM : ");
  scanf("%d",&t4);

  for(i4=0,num4=0,ls4=0;ls4<n4;)
  {
    for(j4=0;j4<n4;j4++)
    {
      if(p4[j4].status4==0 && p4[j4].at4<=i4)
      {
        enqueue(j4);
        p4[j4].status4 = 1;
      }
    }
    if(idle4==0 && front == -1)
    {
      strcpy(d4[num4].name4,"Idle");
      d4[num4].st4 = i4;
      idle4 = 1;
      i4++;
    }
    else if(front!=-1)
    {
      if(idle4==1)
      {
        d4[num4].ct4 = i4;
        idle4 = 0;
        num4++;
      }
      k4 = dequeue();
      d4[num4].st4 = i4;
      strcpy(d4[num4].name4,p4[k4].name4);
      if(p4[k4].left4<=t4)
      {
        d4[num4].ct4 = i4+p4[k4].left4;
        p4[k4].ct4 = d4[num4].ct4;
        i4 = d4[num4].ct4;
        p4[k4].tt4 = i4 - p4[k4].at4;
        p4[k4].wt4 = p4[k4].tt4 - p4[k4].bt4;
        p4[k4].status4 = 2;
        ls4++;
        num4++;
      }
      else if(p4[k4].left4>t4)
      {
        d4[num4].ct4 = i4+t4;
        i4 = d4[num4].ct4;
        p4[k4].left4 = p4[k4].left4-t4;
        num4++;
        for(j4=0;j4<n4;j4++)
        {
          if(p4[j4].status4==0 && p4[j4].at4<=i4)
          {
            enqueue(j4);
            p4[j4].status4 = 1;
          }
        }
        enqueue(k4);
      }
    }
    else
    {
      i4++;
    }
  }

  printf("\nPROCESS NAME\tCOMPLETION TIME (ms)\tWAITING TIME (ms)\tTURNAROUND TIME (ms)\n\n");
  for(i4=0;i4<n4;i4++)
  {
    printf("    %s\t\t\t%d\t\t\t%d\t\t\t%d\n",p4[i4].name4,p4[i4].ct4,p4[i4].wt4,p4[i4].tt4);
    avwt4+=p4[i4].wt4;
    avtt4+=p4[i4].tt4;
  }
  printf("\n\nGANTT CHART ");
  printf("\n\t--------------------------------------------------------------------------\n\t");
  for(i4=0;i4<num4;i4++)
  {
    printf("|");
    printf("%s\t",d4[i4].name4);
  }
  printf(" |");
  printf("\n\t--------------------------------------------------------------------------\n\t");
  for(i4=0;i4<num4;i4++)
  {
      printf("%d\t",d4[i4].st4);
  }
  printf("%d\t",d4[num4-1].ct4);
  printf("\n\nAVERAGE WAITING TIME : %f",(avwt4/n4));
  printf("\nAVERAGE TURNAROUND TIME : %f\n",(avtt4/n4));
}

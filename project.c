#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
  char process[10][5],temp[5];
  int i,j,burst_time[10],waiting_time[10],total_waiting_time=0,priority[10],temp1,no_of_process;
  float average_waiting_time;
 printf("enter no of processes:");
 scanf("%d",&no_of_process);
  for(i=0;i<no_of_process;i++)
  {
  printf("enter process%d name:",i+1);
 scanf("%s",&process[i][0]);
  printf("enter process time:");
 scanf("%d",&burst_time[i]);
  printf("enter priority:");
 scanf("%d",&priority[i]);
  }
 for(i=0;i<no_of_process-1;i++)
 {
 for(j=i+1;j<no_of_process;j++)
 {
   if(priority[i]>priority[j])
 {
   temp1=priority[i];
 priority[i]=priority[j];
  priority[j]=temp1;
  temp1=burst_time[i];
  burst_time[i]=burst_time[j];
  burst_time[j]=temp1;
 strcpy(temp,process[i]);
 strcpy(process[i],process[j]);
  strcpy(process[j],temp);
  }
  }
  }
 waiting_time[0]=0;
  for(i=1;i<no_of_process;i++)
  {
   waiting_time[i]=waiting_time[i-1]+burst_time[i-1];
   total_waiting_time=total_waiting_time+waiting_time[i];
   }   
average_waiting_time=(float)total_waiting_time/no_of_process;   
printf("p_name\t p_time\t priority\t w_time\n");
for(i=0;i<no_of_process;i++)  
{
   printf(" %s\t %d\t %d\t\t %d\t\n" ,process[i],burst_time[i],priority[i],waiting_time[i]);
   }
  printf("total waiting time=%d\n avg waiting time=%f",total_waiting_time,average_waiting_time);
  getch();
   }
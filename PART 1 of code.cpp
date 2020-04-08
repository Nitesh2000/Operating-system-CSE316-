#include<stdio.h> 
#include<conio.h>

void rr(int no,int REMT[10],int Cur_t,int arT[10], int bsT[10]);

main() 
{
	int PROC_NO,j,no,CurT,REM_PROC,INDICATOR,TIME_QUANTUM,wait,TUT,arT[10],bsT[10],REMT[10],x=1;
	INDICATOR = 0;
	wait = 0;
	TUT = 0;

	printf("\n\n***Name- NITESH KUMAR SAO***\n"); 
	printf("\n\n***Roll No.-01***\n");
	printf("***Reg. No.- 11803482***\n\n");
	printf("***Enter number of processes***\n"); 
	scanf("%d",&no);
	REM_PROC = no;
	
	printf("\nEnter the arrival time and burst time of the processes\n");
	for(PROC_NO = 0;PROC_NO < no;PROC_NO++) 
	{
		printf("\nProcess P%d\n",PROC_NO+1);
		printf("Arrival time = "); 
		scanf("%d",&arT[PROC_NO]);
		printf("Burst time = "); 
		scanf("%d",&bsT[PROC_NO]); 
		REMT[PROC_NO]=bsT[PROC_NO]; 
	} 
	printf("The details of time quantum are as follows:\n");
	printf("The time quantum for first round is 3.\n"); 

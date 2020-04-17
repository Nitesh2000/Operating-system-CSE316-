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
	TIME_QUANTUM=3;
	CurT=0;
	for(PROC_NO=0;REM_PROC!=0;) 
	{
		if(REMT[PROC_NO]<=TIME_QUANTUM && REMT[PROC_NO]>0)
		{ 
			CurT+=REMT[PROC_NO]; 
			REMT[PROC_NO]=0; 
			INDICATOR=1; 
		} 
		else if(REMT[PROC_NO]>0)
		{ 
			REMT[PROC_NO]-=TIME_QUANTUM; 
			CurT+=TIME_QUANTUM; 
		} 
		if(REMT[PROC_NO]==0 && INDICATOR==1)			
		{ printf("%d",PROC_NO);
			REM_PROC--;				
			printf("P %d",PROC_NO+1); 
			printf("\t\t\t%d",CurT-arT[PROC_NO]);
			printf("\t\t\t%d\n",CurT-bsT[PROC_NO]-arT[PROC_NO]);
			wait+=CurT-arT[PROC_NO]-bsT[PROC_NO]; 
			TUT+=CurT-arT[PROC_NO]; 
			INDICATOR=0; 
                       
		} 
		if(PROC_NO==no-1){
			x++;
			if(x==2){
				PROC_NO=0;
				TIME_QUANTUM=6;
				
				printf("The time quantum for second round is 6. \n");
			}
			else{
				break;
			}
		}
		else if(CurT >= arT[PROC_NO+1]){
			PROC_NO++;
		}
		else{
			PROC_NO=0;
		}
	}
	
	rr(no,REMT,CurT,arT,bsT);
	
	return 0;
}


void rr(int no,int REMT[10],int Cur_t,int arT[10], int bsT[10]){
	
	float avg_wait,avg_TUT;
    int i,j,n=no,temp,btime[20],PROC_NO[20],w_time[20],TUT_t[20],total=0,loc;
    
    printf("Third round with least burst time.\n");
    
    for(i=0;i<n;i++)
    {
        btime[i]=REMT[i];
        w_time[i]=Cur_t-arT[i]-btime[i];
		PROC_NO[i]=i+1;
    }
	
    for(i=0;i<n;i++)
    {
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(btime[j]<btime[loc]){
            	loc=j;
            }
        }
        temp=btime[i];
        btime[i]=btime[loc];
        btime[loc]=temp;
        temp=PROC_NO[i];
        PROC_NO[i]=PROC_NO[loc];
        PROC_NO[loc]=temp;
    }
	
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++){
        	w_time[i]+=btime[j];
        }
        total+=w_time[i];
    }

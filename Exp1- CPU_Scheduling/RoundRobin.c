#include<stdio.h>
#include<stdlib.h>
  

void findWaitingTime(int pid[], int n, int bt[], int wt[], int quantum){
	int bt_bal[n]; 
	int i, flag;
	for (i = 0 ; i < n ; i++) 
		bt_bal[i] =  bt[i]; 

	int t = 0; 
   
	while (1){ 
		flag = 1;
		for (i = 0 ; i < n; i++){
			if (bt_bal[i] > 0){
				flag = 0;
				if (bt_bal[i] > quantum){
					t += quantum;
					bt_bal[i] -= quantum; 
				}

				else{
					t = t + bt_bal[i];
					wt[i] = t - bt[i]; 
					bt_bal[i] = 0; 
				}
			} 
		}
	if (flag == 1) 
		break; 
	}
}
  

void findTurnAroundTime(int pid[], int n, int bt[], int wt[], int tat[]){ 
	int i;
	for (i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
	} 
  

void findavgTime(int pid[], int n, int bt[], int quantum){
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	findWaitingTime(pid, n, bt, wt, quantum);
	findTurnAroundTime(pid, n, bt, wt, tat); 

	printf("PID\tBT\tWT\tTT");

	int i;
	for (i=0; i<n; i++){
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i];
		printf("\n% d\t %d\t %d\t %d\n",i+1,bt[i],wt[i],tat[i]);
	} 
 
	printf("\nAverage waiting time =%.2f\n",(float)total_wt / (float)n);
	printf("Average turn around time =%.2f\n",(float)total_tat / (float)n);
	} 


void main(){ 

	int i;
	int j;
	int pid[10];
	FILE *fp;
	char btt[10],prr[10], file[20];
	int bt[10];
	int n;
	char str[100];
	printf("\n Enter File Name : ");
	scanf("%s", file);
	fp = fopen("test2.txt","r");
	if(fp == NULL){
		printf("\nError in file opening");
	}

	fgets(str,2,fp);
	n = atoi(str);
	for (i = 0; i < n; i++) {
		fscanf(fp,"%s :  %s",prr,btt);
		pid[i] = atoi(prr);
		bt[i] = atoi(btt);
	}

	//for (i = 0; i < n; i++) {
	//	printf("\nP%d  %d\n",pid[i],bt[i]);
	//}

	fclose(fp);
 
	int quantum = 2; 
	findavgTime(pid, n, bt, quantum); 
} 


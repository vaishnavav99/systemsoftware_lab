
#include <stdio.h>
#include <stdlib.h>

int *safe;


int test(int p, int nr, int request[nr], int need[][nr], int available[nr]){
	int j;
	for(j=0; j<nr ;j++){
		if(request[j] > need[p][j]){
			printf("\n Request Exceeds Claim.");
			printf("\n Request Rejected.\n");
			return 0;
		}
	}
	for(j=0;j<nr;j++){
		if(request[j] > available[j]){
			printf("\n Resources unavailable.");
			printf("\n Try Later.\n");
			return 0;
		}
	}
	
	return 1;
}

void safety_alg(int np, int nr,int allocated[][nr], int need[][nr], int available[nr]){
	int i, j, work[nr], finish[np], streak = 0;
	int k=0,order[np];
	
	
	
	for(i=0;i<np;i++){
		order[i] = -1;
		finish[i] = 0;
	}
	for(j=0;j<nr;j++) work[j] = available[j];
	
	i=0;
	while(streak<np){
		if(i==np)i=0;
		
		if(finish[i] == 0){
			int exist = 1;
			for(j=0;j<nr;j++){
				if(need[ i ][ j ] > work[ j ]) exist = 0;
			}
			if(exist  == 1){
				streak = 0;
				for(j=0;j<nr;j++) work[j] += allocated[i][j];
				finish[i] = 1;
				order[k] = i;
				k++;
			}
			else streak++;
		}
		else streak++;
		i++;
	}
	
	safe = (int *)malloc(sizeof(int)*np);
	
	printf("\n");
	for(i=0;i<np;i++)
		*(safe+i) = order[i];
}



void main(){
	//i,j - Looping variables
	//n - No. of resources
	//p - No. of processes
	int i, j, n, p;
	//t - Variable to test resource allocation
	int t;
	
	
	printf("\t\tBANKER\'S ALGORITHM\n");
	
	printf("\n Enter the number of resource types: ");
	scanf("%d",&n);
	printf(" Enter the number of processes: ");
	scanf("%d", &p);
	

	int avail[n], max[p][n], alloc[p][n], need[p][n];
	int pid,req[n];
	
	
	printf("\n\n Enter process details :");
	printf("\n INput Format = ");
	for(j=0;j<n;j++)
		printf(" R%d",j);
	printf("\n");
	
	
	for(i=0;i<p;i++){
		printf("\n PID: %d",i);
		printf("\n Allocation: ");
		for(j=0;j<n;j++) 
			scanf("%d",&alloc[i][j]);
		
		printf(" Max Need: ");
		for(j=0;j<n;j++) 
			scanf("%d",&max[i][j]);
	}
	
	
	printf("\n Enter available resources: ");
	for(j=0;j<n;j++) 
		scanf("%d",&avail[j]);
	
	
	for(i=0; i<p; i++){
		for(j=0; j<n; j++) 
			need[i][j] = max[i][j]-alloc[i][j];
	}
	
	
	printf("\n\n Enter request");
	printf("\n Process ID: ");
	scanf("%d",&pid);
	printf(" Resource request: ");
	for(j=0;j<n;j++) 
		scanf("%d",&req[j]);
	 
	
	t = test(pid, n, req, need, avail);
	
	
	printf("Processes Are...\n");
	printf("Process ID \t Allocation \t Max \t Need");
	for(i=0;i<p;i++){
		printf("\n P%d ", i);
		printf("\t");
		for(j=0;j<n;j++){
			printf(" %d", alloc[i][j]);
		}
		printf("\t");
		for(j=0;j<n;j++){
			printf(" %d", max[i][j]);
		}
		printf("\t");
		for(j=0;j<n;j++){
			printf(" %d", need[i][j]);
		}
		printf("\n");
	}
	printf("\n");

		
		
	if(t==1){
		for(j=0;j<n;j++){
		
			avail[j] -= req[j];
			alloc[pid][j] += req[j];
			need[pid][j] -= req[j];
		}
		printf("Processes Are...\n");
	printf("PID \t Alloc \t Max \t Need");
	for(i=0;i<p;i++){
		printf("\n P%d ", i);
		printf("\t");
		for(j=0;j<n;j++){
			printf(" %d", alloc[i][j]);
		}
		printf("\t");
		for(j=0;j<n;j++){
			printf(" %d", max[i][j]);
		}
		printf("\t");
		for(j=0;j<n;j++){
			printf(" %d", need[i][j]);
		}
		printf("\n");
	}
	printf("\n");

		
		//Running safety algorithm
		safety_alg(p, n, alloc, need, avail);
			if(*(safe+(p-1)) == -1){
			printf("\n System is not safe\n Request not accepted\n");
			
			avail[j] += req[j];
			alloc[pid][j] -= req[j];
			need[pid][j] += req[j];
		}
		else{
			printf("\n System is safe\n Request accepted\n");
			printf(" Safe sequence:");
			for(i=0;i<p;i++)printf(" %d", *(safe+i));
			printf("\n");
			
			
		}
	}
}

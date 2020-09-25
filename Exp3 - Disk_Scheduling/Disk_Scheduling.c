#include<stdio.h>
#include<stdlib.h>

void main(){
	int i,j,sum=0,size, flag = 0, ip, seek, seektot = 0, flagm = 0;
	int data[50];
	int hpos, hposinit, temp, max, hloc, choice, dir;
	int backup[3];
	
	for(j=0; j<50; j++){
		data[j] = -1;
	}
	
	printf("\nEnter the current head position : ");
	scanf("%d", &hpos);
	
	hposinit = hpos;
	
	printf("\n Input the Data Positions : ");
	printf("\n Cylinder size is 1000. You can enter a maximum of 50 requests. Enter 9999 to stop inputting... \n");
	i = 0;
	while(flag == 0 && i<=50){
		flag = 0;
		scanf("%d", &ip);
		
		if(ip == 9999){
			flag = 1;
			break;
		}
		
		if(ip>1000){
			printf("\n The Value is larger than the Disk Size. Please enter a different Value... \n");
			continue;
		}
		
		data[i] = ip;
		i++;
	}
	
	size = 0;
	for(j=0; j<50; j++){
		if(data[j] != -1)
			size++;
	}
	
	backup[0] = hpos;
	backup[1] = hposinit;
	backup[2] = size;
	
	while(flagm == 0){

		hpos = backup[0];
		hposinit = backup[1];
		size = backup[2];
		
		seektot = 0;
		seek = 0;

		printf("\n\n_____---MENU---_____\n\n");
		printf(" 1. FCFS \n 2. SCAN \n 3. CSCAN");
		printf("\n Enter Your Choice : ");
		scanf("%d", &choice);
	
		switch(choice){
			case 1 :
				printf("\n FCFS Scheduling....\n");
				
				for(i=0; i<size; i++){
					if(data[i] <= hpos){
						seek = hpos - data[i];
					}
					else if(hpos <= data[i]){
						seek = data[i] - hpos;
					}

					seektot = seektot + seek;
					hpos = data[i];
				}
				
				for(i=0;i<size;i++){
					if(i==size-1)
						printf("%d",data[i]);
					else
						printf("%d-->",data[i]);
				}
					
				printf("\n Seek Completed. The Final Head position is %d...", hpos);
				printf("\n\n Total Head Movement = %d \n\n", seektot);
			
				break;
			
			case 2 :
				printf("\n SCAN Scheduling....\n");
				
				printf("\n Disk Head Movement to Left(0) or Right(1) ? : ");
				scanf("%d", &dir);
				if(dir!=0 && dir!= 1){
					printf("Invalid Direction!!");
					break;
				}
				
				data[size]=hpos;
				size++;
	
				for(i=0;i<size;i++){
					for(j=i;j<size;j++){
						if(data[i]>data[j]){
							temp=data[i];
							data[i]=data[j];
							data[j]=temp;
						}
					}
				}
	
				max=data[size];
				for(i=0;i<size;i++){
					if(hpos==data[i]){
						hloc=i;
						break;
					}
				}

				if(dir ==0){
					for(i=hloc;i>=0;i--){
						printf("%d -->",data[i]);
					}
	
					printf("0 -->");
					for(i=hloc+1;i<size;i++){
						if(i==size-1)
							printf("%d",data[i]);
						else
							printf("%d-->",data[i]);
						seek = data[i];
					}
	
					seektot = hposinit + seek;
				}
				
				if(dir ==1){
					for(i=hloc;i<size;i++){
						printf("%d -->",data[i]);
					}
	
					printf("1000 -->");
					for(i=hloc-1;i>=0;i--){
						if(i==0)
							printf("%d",data[i]);
						else
							printf("%d-->",data[i]);
						seek = 1000 - data[i];
					}
	
					seektot = hposinit + seek;
				}
				
				printf("\n Seek Completed. The Final Head position is %d...", seek);
				printf("\n\n Total Head Movement = %d \n\n", seektot);
			
				break;
			
			case 3:
				printf("\n CSCAN Scheduling....\n");
				
				printf("\n Disk Head Movement to Left(0) or Right(1) ? : ");
				scanf("%d", &dir);
				if(dir!=0 && dir!= 1){
					printf("Invalid Direction!!");
					break;
				}
				
				data[size]=hpos;
				size++;
	
				for(i=0;i<size;i++){
					for(j=i;j<size;j++){
						if(data[i]>data[j]){
							temp=data[i];
							data[i]=data[j];
							data[j]=temp;
						}
					}
				}
	
				max=data[size];
				for(i=0;i<size;i++){
					if(hpos==data[i]){
						hloc=i;
						break;
					}
				}
	
				if(dir == 0){
					for(i=hloc;i>=0;i--){
						printf("%d -->",data[i]);
					}
	
					printf("1000 -->");
					for(i=size-1;i>hloc;i--){
						if(i==hloc+1)
							printf("%d",data[i]);
						else
							printf("%d-->",data[i]);
						seek = data[i];
					}
	
					seektot =hposinit + (1000-seek);
					
				}
				
				if(dir == 1){
					for(i=hloc;i<size;i++){
						printf("%d -->",data[i]);
					}
	
					printf("0 -->");
					for(i=0;i<hloc;i++){
						if(i==hloc-1)
							printf("%d",data[i]);
						else
							printf("%d-->",data[i]);
						seek = data[i];
					}
	
					seektot =hposinit + (1000-seek);
					
				}
				
				printf("\n Seek Completed. The Final Head position is %d...", seek);
				printf("\n\n Total Head Movement = %d \n\n", seektot);
			
				break;
		}
		
		printf("\n Do You want to check another Scheduling?  (0 = Yes/ 1 = No): ");
		scanf("%d", &flagm);
	}
}

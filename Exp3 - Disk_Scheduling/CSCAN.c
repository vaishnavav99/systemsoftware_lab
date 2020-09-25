#include<stdio.h>
#include<stdlib.h>


void main(){
	int i,j,sum=0,size, flag = 0, ip, seek, seektot;
	int data[50];
	int hpos, hposinit, temp, max, hloc;
	
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
	printf("\n Seek Completed. The Final Head position is %d...", seek);
	printf("\n\n Total Head Movement = %d \n\n", seektot);
}

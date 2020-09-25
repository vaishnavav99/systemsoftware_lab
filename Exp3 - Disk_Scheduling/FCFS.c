#include<stdio.h>
#include<stdlib.h>

void main(){
	int hposinit, hpos, data[50], exec[50], ip, seektot=0, seek;
	int size, i, j, flag = 0;
	
	printf("\nEnter the current head position : ");
	scanf("%d", &hpos);
	
	hposinit = hpos;
	
	for(j=0; j<50; j++){
		data[j] = -1;
	}
	
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
	
	for(i=0; i<size; i++){
		if(data[i] <= hpos){
			seek = hpos - data[i];
		}
		else if(hpos <= data[i]){
			seek = data[i] - hpos;
		}
		
		exec[i] = data[i]
		
		seektot = seektot + seek;
		
		hpos = data[i];
	}
	
	printf("\n Seek Completed. The Final Head position is %d...", hpos);
	printf("\n\n Total Head Movement = %d \n\n", seektot);
}

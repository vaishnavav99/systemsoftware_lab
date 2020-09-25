#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct{
	char dir_name[10];
	char file_name[10][10];
	int count;
}dir[10];


void main(){
	int i,choice,dir_count,k, flag = 0;
	char file[30], dr[30];
	dir_count=0;
	while(flag == 0){
		flag = 0;
		printf("\n\n_____---MENU---_____\n");
		printf(" 1. Create Directory \n 2. Create File \n 3. Delete File \n 4. Search File \n 5. Display \n 6. Exit ");
		printf(" \n Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: 
				printf("\n Enter Directory Name : ");
				scanf("%s", dr);
				for(i=0;i<dir_count;i++){
					if(strcmp(dr,dir[i].dir_name)==0){
						printf("\nDirectory %s already exists",dr);
						break;
					}
				}
				if(i==dir_count){
					strcpy(dir[dir_count].dir_name,dr);
					dir[dir_count].count=0;
					dir_count++;
					printf("Directory created");
				}
				break;
			case 2: 
				printf("\n To which Directory? : ");
				scanf("%s",dr);
				for(i=0;i<dir_count;i++){
					if(strcmp(dr,dir[i].dir_name)==0){
						printf("\n Enter File Name : ");
						scanf("%s",file);
						for(k=0;k<dir[i].count;k++){
							if(strcmp(file,dir[i].file_name[k])==0){
 							 	printf("\n File %s already exists.",file);
  								goto bp1;
 							}
						}
						if(k==dir[i].count){
							strcpy(dir[i].file_name[dir[i].count],file);
							dir[i].count++;
							printf("File created");
							goto bp1;
						}
					}
				}
				if(i==dir_count){
					printf("Directory %s not found",dr);
				}
				bp1: break;
			case 3: 
				printf("\nFrom WHich Directory? : ");
				scanf("%s",dr);
				for(i=0;i<dir_count;i++){
					if(strcmp(dr,dir[i].dir_name)==0){
						printf("Enter Name of File to Delete : ");
						scanf("%s",file);
						for(k=0;k<dir[i].count;k++){
							if(strcmp(file, dir[i].file_name[k])==0){
								printf("File %s Deleted Successfully.",file);
								dir[i].count--;
								strcpy(dir[i].file_name[k],dir[i].file_name[dir[i].count]);
								goto bp2;
							}
						}
						printf("File %s not found",file);
						goto bp2;
						}
					}
					printf("Directory %s not found",dr);
					bp2: break;
				case 4: 
					printf("\n In which Directory? : ");
					scanf("%s",dr);
					for(i=0;i<dir_count;i++){	
						if(strcmp(dr,dir[i].dir_name)==0){
							printf("Enter Name of File to search : ");
							scanf("%s",file);
							for(k=0;k<dir[i].count;k++){
								if(strcmp(file, dir[i].file_name[k])==0){
									printf("File %s Found at location %d",file,i);
									goto bp3;
								}
							}
						printf("File %s not found",file);
						goto bp3;
						}
					}
					printf("Directory %s not found",dr);
					bp3: break;
				case 5: 
					if(dir_count==0)
						printf("\n There are No Directories present ");
					else{
						printf("\n Directory : \tFiles : ");
						for(i=0;i<dir_count;i++){
							printf("\n%s\t\t",dir[i].dir_name);
							for(k=0;k<dir[i].count;k++)
								printf("\t%s",dir[i].file_name[k]);
						}
					}
					break;
				case 6:
					printf("\n--Exited--");
					exit(0);
				default:
					printf("\n Invalid Input\n");
			}
	}
}

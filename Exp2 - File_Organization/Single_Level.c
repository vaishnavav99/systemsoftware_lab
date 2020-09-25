#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct directory{
	char dir_name[20];
	char file_name[15][25];
	int count;
} dir;

void main(){
	int i, j, n, flag = 0, flagd = 0, flags = 0, choice;
	dir.count = 0;
	char file[25];
	
	printf("\n Enter the Name of Directory : ");
	scanf("%s", dir.dir_name);
	printf("\n --Directory Name Set--");
	
	while(flag==0){
		flag = 0;
		flagd = 0;
		flags = 0;
		printf("\n_____---MENU---_____\n");
		printf(" 1. Add File \n 2. Delete File \n 3. View Files \n 4. Search \n 5. Exit \n");
		printf("Enter you Choice : ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1 :
				printf("\n Enter New File Name : ");
				scanf("%s", dir.file_name[dir.count]);
				//dir.file_name[dir.count] = file;
				dir.count++;
				printf("\n --File Added Successfully--");
				break;
			case 2 :
				printf("\n Enter File Name to Delete : ");
				scanf("%s", file);
				for(i=0; i<dir.count; i++){
					if(strcmp(file, dir.file_name[i]) == 0){
						for(j=i; j<dir.count; j++){
							if(j == dir.count){
								strcpy(dir.file_name[j] ," ");
							}
							strcpy(dir.file_name[j] , dir.file_name[j+1]);
						}
						printf("\n File %s has been deleted.", file);
						dir.count--;
						flagd = 1;
					}
				}
				if(flagd == 0){
						printf("\n File %s not Found.", file);
					}
				break;
			case 3 : 
				if(dir.count == 0){
					printf("\n Directory is Empty ");
				}
				else{
					printf("\n The Files in the Directory %s are : ", dir.dir_name);
					for(i=0; i<dir.count; i++){
						printf("\n %s", dir.file_name[i]);
					}
				}
				break;
			case 4 : 
				printf("\n Enter File Name to Search for : ");
				scanf("%s", file);
				flags = 0;
				for(i=0; i<dir.count; i++){
					if(strcmp(file, dir.file_name[i]) == 0){
						printf("\n File %s has been Found at location %d", file, i);
						flags = 1;
					}
				}
				if(flags == 0){
						printf("\n File %s not Found in the directory", file);
					}
				break;
			case 5 : 
				printf("\n Exit");
				flag = 1;
				break;
			default : 
				printf("\n Invalid Choice");
		}
	}
}

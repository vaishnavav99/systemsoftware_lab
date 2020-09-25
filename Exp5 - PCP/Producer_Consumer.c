

#include<stdio.h>
#include<stdlib.h>
int s, x, sel;
int mutex=1, buffer[6];
int empty=6, full=0;


int wait(int s){
	return --s;
	}
		
int signal(int s){
	return ++s;
	}
		
void produce(){
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	printf("\nEnter Value:");
	scanf("%d",&buffer[x]);
	printf("\nProducer produces %d \n",buffer[x]);
	x++;
	mutex=signal(mutex);
	}

void consume(){
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	
	printf("\nConsumer consume %d\n",buffer[x-1]);
	x--;
	mutex=signal(mutex);
	}
		
		
void main()
{	printf("\t\tPRODUCER CONSUMER PROBLEM\n");
	do{
			printf(" 1. Produce\n 2. Consume \n 3. Exit\n");
			printf("Enter your choice : ");
			scanf("%d",&sel);
			switch(sel)
			{
				case 1:
					if(mutex==1 && empty!=0)
						produce();
					else 
						printf("\n ERROR : Can't Produce - Buffer Full\n\n");
					break;
					
				case 2:
					if(mutex==1 && full>0)
						consume();
					else 
						printf("\n ERROR : Nothing to Consume - Buffer Empty\n\n");
					break;
					
				default :
					if(sel!=3)
						printf("\n ERROR : Please Enter a Valid Option \n\n");
			}
		}while(sel!=3);
}
		
		

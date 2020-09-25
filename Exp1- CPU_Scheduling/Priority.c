#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int AT[50], BT[50], ET[50], WT[50], TT[50], Pid[50], Prio[50];;


int Convert(char X[10]){
	int temp = 0, i, size = 0, tmp = 1;

	for(i=0; i<10; i++){
		if(X[i] != 'a')
			size ++;
	}

	for(i=size-1; i>=0; i--){
		temp = temp + ((X[i] - '0') * tmp);
		tmp = tmp*10;	
	}

	return temp;
}

void fileRead(int at[50], int bt[50], int pid[50]){
	char A[10], B[10], P[10];
	char a, b, c, d;
	int x = 0, i, j=0;
	int temparr[50];
	FILE *fp;
	char file[30];
	int index = 0;

	printf("Enter File Name : ");
	scanf("%s", file);

	fp = fopen("demo.txt", "r");

	fseek(fp, 0, 0);

	

	for(i=0; i<3; i++){

		for(x=0; x<10; x++){
			A[x] = 'a';
			B[x] = 'a';
			P[x] = 'a';
		}
		x=0;

		for(j=0; j<5; j++){
			a = getc(fp);
			if(a == ',')
				break;
			if(a == EOF)
				break;
			P[j] = a;
			//fseek(fp, 1, SEEK_CUR);
			}    

		pid[index] = Convert(P);
		//fseek(fp, 1, SEEK_CUR);

		for(j=0; j<5; j++){
			b = getc(fp);
			if(b == ',')
				break;
			if(b == EOF)
				break;
			A[j] = b;
			//fseek(fp, 1, SEEK_CUR);
		}

		at[index] = Convert(A);
		//fseek(fp, 1, SEEK_CUR);

		for(j=0; j<5; j++){
			c = getc(fp);
			printf("\n c = %c", c);
			if(c == '|')
				break;
			if(c == EOF)
				break;
			B[j] = c;
			//fseek(fp, 1, SEEK_CUR);
		}

		printf("\n%s \n", B);
		bt[index] = Convert(B);
		//fseek(fp, 1, SEEK_CUR);

		index++;
	}
}

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void sort( int at[50], int bt[50], int pid[50], int prio[50], int size){
	int i, j;
	for (i=0; i<size; i++){
		for(j=0; j<i; j++){
			if(at[j] < at[j+1]){
				swap(&prio[j], &prio[j+1]);
				swap(&at[j], &at[j+1]);
				swap(&bt[j], &bt[j+1]);
				swap(&pid[j], &pid[j+1]);
			}
			if(at[j] == at[j+1]){
				if(prio[j] < prio[j+1]){
					swap(&prio[j], &prio[j+1]);
					swap(&at[j], &at[j+1]);
					swap(&bt[j], &bt[j+1]);
					swap(&pid[j], &pid[j+1]);
			}
			}
		}
	}
}

void main(){
	int i,j,size = 0;

	fileRead(AT, BT, Pid);

	for(i=0; i<50; i++){
		if(AT[i]!= '\0')
			size++;
	}

	sort(AT, BT, Pid, Prio, size);

	ET[0] = 0;
	TT[0] = BT[0];
	WT[0] = 0;

	for(i=0; i<size; i++){
		if( i!=0)		
			ET[i] = ET[i-1] + BT[i-1];

		if(ET[i]-AT[i] <= 0)
			continue;
		else
			WT[i] = ET[i] - AT[i];

		TT[i] = WT[i] + BT[i];
	}

	printf("PID \t AT \t BT \t TT \t WT");
	for(j=0; j<=size; j++){
		printf("\n %d", Pid[j]);
		printf(" \t %d", AT[j]);
		printf(" \t %d", BT[j]);
		printf(" \t %d", TT[j]);
		printf(" \t %d", WT[j]);
	}
	printf("\n");
}

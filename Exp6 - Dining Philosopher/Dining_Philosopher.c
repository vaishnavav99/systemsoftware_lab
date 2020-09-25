
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum + 4) % N
#define RIGHT (phnum + 1) % N

int state[N];
int phil[N] = { 0, 1, 2, 3, 4 };

sem_t mutex;
sem_t S[N];

void test(int phnum){ 
	if (state[phnum] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
		//Current Eating State
		state[phnum] = EATING;
		sleep(2);
		
		printf("Philosopher %d takes Chopsticks %d and %d\n", phnum + 1, LEFT + 1, phnum + 1); 
		printf("Philosopher %d is Eating\n", phnum + 1); 

		// sem_post(&S[phnum]) has no effect
		// during take_chopstick
		// used to wake up hungry philosophers
		// during put_chopstick
		sem_post(&S[phnum]);
		} 
	}

// Picks Up the Chopsticks
void take_chopstick(int phnum){ 

	sem_wait(&mutex); 
	//Hungry State 
	state[phnum] = HUNGRY; 
	printf("Philosopher %d is Hungry\n", phnum + 1); 
	//Eat if Neighbours aren't Eating
	test(phnum); 
	sem_post(&mutex); 
	//If Eat not possible, wait for signal
	sem_wait(&S[phnum]); 
	sleep(1); 
	} 

//Puts down the chopsticks 
void put_chopstick(int phnum){ 

	sem_wait(&mutex); 
	//Thinking State 
	state[phnum] = THINKING; 
	printf("Philosopher %d putting chopstick %d and %d down\n", 
	phnum + 1, LEFT + 1, phnum + 1); 
	printf("Philosopher %d is thinking\n", phnum + 1); 
	test(LEFT); 
	test(RIGHT); 
	sem_post(&mutex); 
	}
  
void* philospher(void* num){ 
	while (1) { 
		int* i = num;
		sleep(1);
		take_chopstick(*i); 
		sleep(0); 
		put_chopstick(*i); 
		}
	}

int main(){
	int i; 
	pthread_t thread_id[N]; 
	//Semaphore Initialization
	sem_init(&mutex, 0, 1); 
	
	for (i = 0; i < N; i++)
		sem_init(&S[i], 0, 0); 

	for (i = 0; i < N; i++){ 
		//Create Philosophers 
		pthread_create(&thread_id[i], NMonday 11 November 2019 03:53:59 PM IST ULL, philospher, &phil[i]); 
		printf("Philosopher %d is thinking\n", i + 1); 
	} 

	for (i = 0; i < N; i++)
		pthread_join(thread_id[i], NULL); 
} 


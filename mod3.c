#define _CRT_SECURE_NO_WARNINGS
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 5
typedef struct
{
	int c_no;
	int p_id;
	int p;
	int time;
}process;
pthread_mutex_t mutex;
process s[5];
void *run(void *t)
{
	pthread_mutex_lock(&mutex);
	int p = *(int*)t;
	for (int i = 0; i < s[p].time; i++) {
		printf("%d", s[p].p_id);
	}
	printf("\n");
	pthread_mutex_unlock(&mutex);
	pthread_exit(0);
};
void sort(process *p, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (p[i].p < p[j].p) {
				process a;
				a = p[i];
				p[i] = p[j];
				p[j] = a;
			}
		}
	}
}
int main() {
	
	for (int i = 0; i < 5; i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		s[i].c_no = a;
		s[i].p_id = b;
		s[i].p = c;
		s[i].time = d;
	}//xianchengchi
	sort(s, 5);
	pthread_t tid[NUM_THREADS];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	int p_id[5];
	for (int i = 0; i < NUM_THREADS; i++) {
		p_id[i] = 4 - i;
	}
	for (int i = 0; i < NUM_THREADS; i++) {
		int *t = p_id + i;
		pthread_create(&tid, &attr, run,(void*)t);
	}
	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_join(tid[i], NULL);
	}
}

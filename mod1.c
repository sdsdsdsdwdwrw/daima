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
process s[5];
void run(int w)
{
	s[w].c_no;
	printf("id=%d,youxiandu=%d\n", s[w].p_id, s[w].p);
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
	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_create(&tid, &attr, run, i);
	}
	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_join(tid[i], NULL);
	}
}

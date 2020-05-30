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
	FILE *fp;
	fp = fopen("output", "a");
	int p = *(int*)t;
	for (int i = 0; i < s[p].time; i++) {
		int o = s[p].p_id;
		fprintf(fp, "%d\t", o);
		//printf("%d\t", s[p].p_id);
	}
	fprintf(fp, "\n");
	fclose(fp);
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
void sort2(process *p, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (p[i].time < p[j].time) {
				process a;
				a = p[i];
				p[i] = p[j];
				p[j] = a;
			}
		}
	}
}
int main() {
	FILE *fp2;
	fp2 = fopen("input", "r");
	for (int i = 0; i < 5; i++) {
		int a, b, c, d;
		fscanf(fp2, "%d%d%d%d", &a, &b, &c, &d);
		//scanf("%d%d%d%d", &a, &b, &c, &d);
		s[i].c_no = a;
		s[i].p_id = b;
		s[i].p = c;
		s[i].time = d;
	}//xianchengchi
	fclose(fp2);
	int youxian = 0;
	process you[5];
	for (int i = 0; i < 5; i++) {

		if (s[i].c_no == 1) {
			you[youxian] = s[i];
			youxian++;
		}
	}
	sort(you, youxian);
	int zuiduan = 0;
	process zui[5];
	for (int i = 0; i < 5; i++) {
		if (s[i].c_no == 2) {
			zui[zuiduan] = s[i];
			zuiduan++;
		}
	}
	sort2(zui, zuiduan);

	for (int i = 0; i < youxian; i++) {
		s[i] = you[i];
	}
	int jj = 0;
	for (int i = youxian; i < 5; i++) {

		s[i] = zui[jj];
		jj++;
	}
	//sort(s, 5);
	pthread_t tid[NUM_THREADS];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	int p_id[5];
	for (int i = 0; i < NUM_THREADS; i++) {
		p_id[i] = 4 - i;
	}
	for (int i = 0; i < NUM_THREADS; i++) {
		int *t = p_id + i;
		pthread_create(&tid[i], &attr, run, (void*)t);
	}
	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_join(tid[i], NULL);
	}
}

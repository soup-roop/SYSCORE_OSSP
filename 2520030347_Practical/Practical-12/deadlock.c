#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock1;
pthread_mutex_t lock2;

void *thread1_function(void *arg) {
    pthread_mutex_lock(&lock1);

    printf("Thread 1 acquired Lock 1\n");

    sleep(1);

    printf("Thread 1 waiting for Lock 2\n");

    pthread_mutex_lock(&lock2);

    printf("Thread 1 acquired Lock 2\n");

    pthread_mutex_unlock(&lock2);
    pthread_mutex_unlock(&lock1);

    return NULL;
}

void *thread2_function(void *arg) {
    pthread_mutex_lock(&lock2);

    printf("Thread 2 acquired Lock 2\n");

    sleep(1);

    printf("Thread 2 waiting for Lock 1\n");

    pthread_mutex_lock(&lock1);

    printf("Thread 2 acquired Lock 1\n");

    pthread_mutex_unlock(&lock1);
    pthread_mutex_unlock(&lock2);

    return NULL;
}

int main() {
    pthread_t thread1;
    pthread_t thread2;

    pthread_mutex_init(&lock1, NULL);
    pthread_mutex_init(&lock2, NULL);

    pthread_create(&thread1, NULL, thread1_function, NULL);
    pthread_create(&thread2, NULL, thread2_function, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&lock1);
    pthread_mutex_destroy(&lock2);

    return 0;
}

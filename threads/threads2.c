#include <stdio.h>
#include <pthread.h>
/* Para trabajar con hilos, al compilar usar: -pthread */

// para crear un hilo:
// int pthread_create(	pthread_t *thread,            		>>> puntero al hilo
// 						const pthread_attr_t *attr,       	>>> atributos del hilo, NULL por defecto 
// 						void *(*start_routine) (void *),  	>>> función que ejecutara el hilo
// 						void *arg);                       	>>> argumento adicional, NULL si no pasamos nada

// esperar que termine el hilo:
// int pthread_join(	pthread_t thread, 					>>> el hilo
// 						void **retval);						>>> copia el 'exit status' del hilo, NULL por defecto

void	*routine(void *data)
{
	int *counter;
    int i;

    i = 0;
	counter = (int*)data;
	while (i < 10000)
	{
		*counter = *counter + 1;
		//printf("%d ", *counter);
        i++;
	}
	return (NULL); 
}

int main(void)
{
	int			count;
	pthread_t	thread1;
	pthread_t	thread2;

	count = 0;
	pthread_create(&thread1, NULL, routine, &count);
	pthread_create(&thread2, NULL, routine, &count);
	printf("antes del join: %d\n", count);
	pthread_join(thread1, NULL); 
	pthread_join(thread2, NULL); 
	printf("final: %d\n", count); 
    // tenemos dos hilos que suman en el mismo contador, la rutina itera 10000 vecessobre la variable count
    // pero casi nunca tendremos un resultado de 20000, comienzan a leer y escribr su operación antes de que el otro hilo termine
    // es necesario crear un mutex para protejer el acceso a la variable y que solo pueda acceder un hilo a la vez
	return (0); 
}
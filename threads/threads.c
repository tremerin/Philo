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

	counter = (int*)data;
	printf("%d\n", *counter);
	while (*counter < 100)
	{
		*counter = *counter + 1;
		printf("%d ", *counter);
	}
	return (NULL);  // debe retornar NULL 
}

int main(void)
{
	int			count;
	pthread_t	thread;

	count = 20;
	pthread_create(&thread, NULL, routine, &count);
	printf("antes del join: %d\n", count);
	pthread_join(thread, NULL); //para que main no termine hasta que termine el hilo
	printf("final: %d\n", count);
	return (0);
}
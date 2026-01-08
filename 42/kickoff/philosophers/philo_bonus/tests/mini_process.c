#include <fcntl.h> // For O_CREAT
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define N 5
#define SEM_NAME "/log_semaphore"

void	safe_print(sem_t *sem, int id, const char *msg)
{
	sem_wait(sem); // Decrement
	printf("Philo %d %s\n", id, msg);
	sem_post(sem); // Increment
}

void	philo_process(int id, sem_t *sem)
{
	safe_print(sem, id, "is thinking");
	usleep(100000);
	safe_print(sem, id, "is eating");
	usleep(100000);
	safe_print(sem, id, "is sleeping");
	exit(0);
}

int	main(void)
{
	sem_t	*sem;
	pid_t	pid;

	sem = sem_open(SEM_NAME, O_CREAT | O_EXCL, 0644, 1);
	if (sem == SEM_FAILED)
	{
		perror("sem_open failed");
		exit(1);
	}
	for (int i = 0; i < N; i++)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("fork failed");
			exit(1);
		}
		if (pid == 0)
		{
			// Child process
			philo_process(i + 1, sem);
		}
	}
	for (int i = 0; i < N; i++)
		wait(NULL); // wait for all child processes
	sem_close(sem);
	sem_unlink(SEM_NAME); // clean up the named semaphore
	return (0);
}

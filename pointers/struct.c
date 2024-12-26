typedef struct s_user
{
	char	name[25];
	int		age;
}			t_user;

int	main(void)
{
	struct s_user	person1;
	t_user			person2;

	person1.age = 20;
	person2.age = 10;
}

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnum(int n)
{
	ft_putchar('0' + n);
}

void ft_print_array(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putnum(arr[i]);
		if (i < size - 1)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		i++;
	}
}

void ft_print_comb(int *arr, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putnum(arr[i]);
		i++;
	}
	if (arr[0] != 10 - n)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void ft_generate_comb(int *arr, int n, int index, int start)
{
	int num;

	if (index == n)
	{
		// ft_print_array(arr, n);
		ft_print_comb(arr, n);

		return;
	}

	num = start;
	while (num < 10)
	{
		arr[index] = num;
		ft_generate_comb(arr, n, index + 1, num + 1);
		num++;
	}
}

void ft_print_combn(int n)
{
	int arr[n];
	ft_generate_comb(arr, n, 0, 0);
}

int main()
{
	int n = 2;
	ft_print_combn(n);
	return (0);
}
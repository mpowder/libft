#include "libc.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c[10];
	int		i;

	i = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n *= -1;
			write(fd, "-", 1);
		}
		while (n / 10 != 0)
		{
			c[i++] = n % 10 + '0';
			n /= 10;
		}
		c[i] = n + '0';
		while (i >= 0)
			write(fd, &c[i--], 1);
	}
}

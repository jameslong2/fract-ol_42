#include "fractol.h"

int	numlen(const char *n)
{
	int	i;

	i = 0;
	while (*(n + i) >= '0' && *(n + i) <= '9')
		i++;
	return (i);
}

char	*skip(const char *str)
{
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	return (str);
}

static double	recursive_d(double div, const char *num)
{
	if (*(num + 1) >= '0' && *(num + 1) <= '9')
	{
		return ((*(num) - '0') * div + recursive_d(div / 10, num + 1));
	}
	else
	{
		return ((*(num) - '0')*div);
	}
}

double	double_part(const char *str)
{
	double	result;

	str = skip(str);
	if (*str == '-' && numlen(str + 1) != 0)
	{
		while (*(str + 1) == '0' && numlen(str + 1) - 1 > 0)
			str++;
		result = -recursive_d(0.1, str + 1);
	}
	else if (*str == '+' && numlen(str + 1) != 0)
	{
		while (*(str + 1) == '0' && numlen(str + 1) > 0)
			str++;
		result = recursive_d(0.1, str + 1);
	}
	else if (*str >= '0' && *str <= '9')
	{
		while (*(str) == '0' && numlen(str) - 1 > 0)
			str++;
		result = recursive_d(0.1, str);
	}
	else
		result = 0;
	return (result);
}
#include "fractol.h"

static int	power(int n, int e)
{
	int	f;

	f = 1;
	while (e > 0)
	{
		f = f * n;
		e--;
	}
	return (f);
}

static char *after_point(const char *str)
{
    char *s;
    
    s = (char *)str;
    while (*s != 0 && *s != '.')
        s++;
    return (s);
}

static int	recursive(int div, const char *num)
{
	if (div > 1)
	{
		return ((*(num) - '0') * div + recursive(div / 10, num + 1));
	}
	else
	{
		return (*(num) - '0');
	}
}

double	ft_atod(const char *str)
{
	double	result;

	str = skip(str);
	if (*str == '-' && numlen(str + 1) != 0)
	{
		while (*(str + 1) == '0' && numlen(str + 1) - 1 > 0)
			str++;
		result = -(recursive(power(10, numlen(str + 1) - 1), str + 1)+double_part(after_point(str)+1));
	}
	else if (*str == '+' && numlen(str + 1) != 0)
	{
		while (*(str + 1) == '0' && numlen(str + 1) > 0)
			str++;
		result = recursive(power(10, numlen(str + 1) - 1), str + 1)+double_part(after_point(str)+1);
	}
	else if (*str >= '0' && *str <= '9')
	{
		while (*(str) == '0' && numlen(str) - 1 > 0)
			str++;
		result = recursive(power(10, numlen(str) - 1), str)+double_part(after_point(str)+1);
	}
	else
		result = 0;
	return (result);
}
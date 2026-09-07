
#include "push_swap.h"
#include <limits.h>

static int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	ps_atoi(const char *s, int *value)
{
	int sign;
	ssize_t result;

	sign = 1;
	result = 0;
	if (!s || *s == '\0')
		return (0);
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s)
	{
		if (!ps_isdigit(*s))
			return (0);
		result = result * 10 + (*s - '0');
		if (sign == 1 && result > INT_MAX)
			return (0);
		if (sign == -1 && -result < INT_MIN)
			return (0);
		s++;
	}
	*value = (int)(result * sign);
	return (1);
}
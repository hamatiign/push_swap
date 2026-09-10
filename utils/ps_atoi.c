#include "../push_swap.h"
#include <limits.h>

int	ps_atoi(const char *s, int *value)
{
	int sign;
long long result;

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
  if(*s == '\0') return (0);
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

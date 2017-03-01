#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	ft_bzero(const void *addr, size_t size)
{
	char	*ptr = (char*)addr;
	while (size--)
		*ptr++ = '\0';
}

char	*ft_strdup(char *str)
{
	int		len = ft_strlen(str);
	int		i;
	char	*new;

	if (!(new = (char*)malloc(sizeof(*new) * (len + 1))))
		return (NULL);
	ft_bzero(new, len + 1);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}

int		ft_size_base(int nb, int base)
{
	int		i;

	i = 1;
	nb = (nb < 0) ? nb * -1 : nb;
	while (nb >= base)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

int		calc_len(int nb, int base)
{
	int	len = ft_size_base(nb, base);

	if (base == 10 && nb < 0)
		len++;
	return (len);
}

void	putnbr_in_str(int nb, int base, char **str)
{
	char	base_str[] = "0123456789ABCDEF";

	if (nb < 0)
	{
		nb *= -1;
		if (base == 10)
		{
			**str = '-';
			(*str)++;
		}
	}
	if (nb > base - 1)
	{
		putnbr_in_str(nb / base, base, str);
		putnbr_in_str(nb % base, base, str);
	}
	else
	{
		**str = *(base_str + nb);
		(*str)++;
	}
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	char	*tmp;
	int		len = calc_len(value, base);

	if (base < 2 || base > 16)
		return (NULL);
	else if (value == -2147483648 && base == 10)
		str = ft_strdup("-2147483648");
	else
	{
		if (!(str = (char*)malloc(sizeof(*str) * len + 1)))
			return (NULL);
		ft_bzero(str, len + 1);
		tmp = str;
		putnbr_in_str(value, base, &tmp);
	}
	return (str);
}

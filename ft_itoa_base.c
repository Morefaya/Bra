#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	len;

	if (!str)
		return ;
	len = ft_strlen(str);
	write(1, str, len);
}

void	ft_bzero(const void *addr, size_t size)
{
	char	*ptr = (char*)addr;
	while (size--)
		*ptr = '\0';
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

	i = 0;
	nb = (nb < 0) ? nb * -1 : nb;
	while (nb >= base)
	{
		nb /= base;
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

void	putnbr_in_str(int nb, char **str)
{
	char	base_str[] = "0123456789";

	/*if (nb == -2147483648)
	{
		//write(1, "-2147483648", 11);
		return ;
	}*/
	if (nb < 0)
	{
		nb *= -1;
		//write(1, "-", 1);
		**str = '-';
		(*str)++;
	}
	if (nb > 9)
	{
		putnbr_in_str(nb / 10, str);
		putnbr_in_str(nb % 10, str);
	}
	else
	{
		//write(1, base + nb, 1);
		**str = *(base_str + nb);
		(*str)++;
	}
}

void	putnbr_hex_str(int nb, int base, char **str)
{
	char	base_str[] = "0123456789ABCDEF";

	if (nb > base - 1)
	{
		putnbr_hex_str(nb / base, base, str);
		putnbr_hex_str(nb % base, base, str);
	}
	else
	{
		**str = *(base_str + nb);
		(*str)++;
	}
}

char	*ft_itoa_base(int nb, int base)
{
	char	*str;
	char	*tmp;
	int		len = calc_len(nb, base);
	
	if (nb == -2147483648 && base == 10)
		str = ft_strdup("-2147483648");
	else
	{
		if (!(str = (char*)malloc(sizeof(*str) * len + 1)))
			return (NULL);
		tmp = str;
		if (base == 10)
		{
			putnbr_in_str(nb, &tmp);
		//	write(1, "\n@\n", 3);
		}
		else
		{
			putnbr_hex_str(nb, base, &tmp);
		//	write(1, "\n#\n", 3);
		}
	}
	return (str);
}

int	main(void)
{
	int		nb = 2147483647;
	int		base = 16;
	char	*str;

	str = ft_itoa_base(nb, base);
	ft_putstr(str);
	return (0);
}

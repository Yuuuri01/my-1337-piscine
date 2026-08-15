/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 16:40:35 by hamossai          #+#    #+#             */
/*   Updated: 2026/07/25 16:18:46 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] <= 32 || base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	nb;
	int			len_base;

	if (!valid_base(base))
		return ;
	nb = nbr;
	len_base = ft_strlen(base);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= len_base)
		ft_putnbr_base(nb / len_base, base);
	write(1, &(base[nb % len_base]), 1);
}
int main()
{
	ft_putnbr_base(255, "0123456789abcdefghizx");
	write(1, "\n", 1);
	ft_putnbr_base(255, "01");
	write(1, "\n", 1);
	ft_putnbr_base(255, "poneyvif");
	write(1, "\n", 1);
	ft_putnbr_base(42, "01");
	write(1, "\n", 1);
	ft_putnbr_base(-2147483648, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(2, "0123456789abcdefdkd");
	write(1, "\n", 1);
	ft_putnbr_base(10, "01234567890");
	write(1, "\n", 1);
	ft_putnbr_base(10, "0123456789+");
	write(1, "\n", 1);
	ft_putnbr_base(-10, "01");
}

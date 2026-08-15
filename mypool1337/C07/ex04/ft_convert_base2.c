/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 23:23:05 by hamossai          #+#    #+#             */
/*   Updated: 2026/07/28 18:28:44 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valid_base(char *base)
{
	int	i;
	int	j;

	if (!base)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == 45 || base[i] == 43 || base[i] <= 32)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	get_position(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	get_len_nbr(long tmp, int len, int sign)
{
	int	size;
    
	if (tmp == 0)
		return (1);
	size = 0;
	if (sign == 1)
		size++;
	while (tmp)
	{
		size++;
		tmp /= len;
	}
	return (size);
}

int	ft_atoi(char *str, int len, char *base)
{
	int	res;
	int	sign;
	int	position;

	while (*str && (*str == 32 || (*str >= 9 && *str <= 13)))
		str++;
	sign = 1;
	while (*str && (*str == 45 || *str == 43))
	{
		if (*str == 45)
			sign = -sign;
		str++;
	}
	res = 0;
	while (*str)
	{
		position = get_position(*str, base);
		if (position != -1)
			res = res * len + position;
		else
			return (res * sign);
		str++;
	}
	return (res * sign);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 23:26:08 by hamossai          #+#    #+#             */
/*   Updated: 2026/07/27 23:26:10 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi(char *str, int len, char *base);
int		get_len_nbr(int nb, int len, int sign);
int		valid_base(char *base);
int		get_position(char c, char *base);
int		ft_strlen(char *str);


int get_number(int *sign, char *nbr, char *base_from, char *base_to)
{
    long nb;
    int tmp;
    int nb_size;
    int len_from;
    int len_to;

    len_from = valid_base(base_from);
    len_to = valid_base(base_to);
    if(!len_from || !len_to)
        *sign = -1;
    
    nb = ft_atoi(nbr, len_from, base_from);
    if(nb < 0)
    {
        *sign = 1;
        nb = -nb;
    }
    return (nb);
}
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*s_nb;
	long		nb;
	int		i;
	int		len_nbr;
    int sign;
	
	
    sign = 0;
    nb = get_number(&sign, nbr, base_from, base_to);
    if(sign == -1)
        return NULL;
    
    len_nbr = get_len_nbr(nb, ft_strlen(base_to), sign);
    s_nb = malloc((len_nbr + 1) * sizeof(char));
	if (!s_nb)
		return (NULL);
	if (nb == 0)
	{
		s_nb[0] = '0';
		s_nb[1] = '\0';
		return (s_nb);
	}
	if (sign)
		s_nb[0] = '-';
	s_nb[len_nbr] = '\0';
	i = len_nbr - 1;
    len_nbr = ft_strlen(base_to);
	while (nb)
	{
		s_nb[i--] = base_to[nb % len_nbr];
		nb /= len_nbr;
	}
	return (s_nb);
}

#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;
	// char	*s3;
	// char	*s4;

	s1 = ft_convert_base("-26", "0123456789", "0123456789ABCDEF");
	s2 = ft_convert_base("10000000", "010", "0123456789");
	// s3 = ft_convert_base("1111011", "01", "0123456789");
	// s4 = ft_convert_base("1111", "01", "0123456789");
	printf("%s\n", s1);
	printf("%s\n", s2);
	// printf("%s\n", s2);
	// printf("%s\n", s4);
	free(s1);
	free(s2);
	// free(s3);
	// free(s4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 21:26:19 by hamossai          #+#    #+#             */
/*   Updated: 2026/07/25 21:35:58 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	len;
	int	i;

	if (ac >= 2)
	{
		i = 1;
		len = 0;
		while (av[i])
		{
			len = 0;
			while (av[i] && av[i][len])
				len++;
			write(1, av[i], len);
			write(1, "\n", 1);
			i++;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 23:16:57 by hamossai          #+#    #+#             */
/*   Updated: 2026/07/25 23:22:17 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*send;
	char	*tab;

	len = 0;
	while (*(src + len))
		len++;
	tab = malloc((len + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	send = tab;
	while (*src)
		*tab++ = *src++;
	*tab = '\0';
	return (send);
}

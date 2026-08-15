/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 11:56:38 by hamossai          #+#    #+#             */
/*   Updated: 2026/07/22 17:36:36 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	sr_len;
	unsigned int	de_len;
	unsigned int	i;

	sr_len = ft_strlen(src);
	de_len = ft_strlen(dest);
	if (size <= de_len)
		return (size + sr_len);
	i = 0;
	while (src[i] && (i + de_len < size - 1))
	{
		dest[i + de_len] = src[i];
		i++;
	}
	dest[i + de_len] = '\0';
	return (sr_len + de_len);
}
/*
# include <stdio.h>
int main()
{
	char dst[10] = "";
	printf("%d\n", ft_strlcat(dst, "", sizeof(dst)));
}
*/

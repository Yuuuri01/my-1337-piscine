/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:22:40 by hamossai          #+#    #+#             */
/*   Updated: 2026/07/27 00:23:55 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	get_len(char **strs, char *sep, int size)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	len += (ft_strlen(sep) * (size - 1));
	return (len);
}

char	*empty(void)
{
	char	*empty;

	empty = malloc(sizeof(char));
	*empty = '\0';
	return (empty);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	char	*str;
	int		index;
	int		k;

	if (size == 0)
		return (empty());
	str = malloc((get_len(strs, sep, size) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	index = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			str[index++] = strs[i][j++];
		i++;
		k = 0;
		while (i != size && sep[k])
			str[index++] = sep[k++];
	}
	str[index] = '\0';
	return (str);
}
// # include <stdio.h>
// int main(void)
// {
//     char *str[] = {"hello", "world", "again"};
//     char *sep = "XV";
//     char *result;
//     int i = 0;

//     result = ft_strjoin(3, str, sep);
//  	   while (result[i])
//     {
//         printf("%c", result[i]);
//         i++;
//     }
//     free(result);
// }
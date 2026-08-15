/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 22:05:14 by hamossai          #+#    #+#             */
/*   Updated: 2026/07/22 21:30:09 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
/*
# include <stdio.h>
int main()
{
    printf("Test 2 (s2 shorter): %d\n", ft_strncmp("helloworld", "hello", 50));
    printf("Test 3 (s1 shorter): %d\n", ft_strncmp("hello", "helloworld", 50));
    printf("Test 4 (diff before n): %d\n", ft_strncmp("hello", "hallo", 5));
    printf("Test 5 (n=0): %d\n", ft_strncmp("abc", "def", 0));
    printf("Test 6 (identical, large n): %d\n", ft_strncmp("test", "test", 10));
    printf("Test 7 (empty strings): %d\n", ft_strncmp("", "", 5));
    printf("Test 8 (one empty): %d\n", ft_strncmp("", "a", 5));
    printf("Test 9 (null term check): %d\n", ft_strncmp("abc", "abc\0def", 10));

    return (0);
}
*/

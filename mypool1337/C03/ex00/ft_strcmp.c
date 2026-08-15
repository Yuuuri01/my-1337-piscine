/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 21:31:03 by hamossai          #+#    #+#             */
/*   Updated: 2026/07/22 13:37:02 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
/*
int main()
{
	printf("%d\n", ft_strcmp("helloworld", "hello"));

	printf("%d\n", ft_strcmp("hell", "hel"));

	printf("%d\n", ft_strcmp("hello", "hello"));

	printf("%d\n", ft_strcmp("ABC", "AB"));
}*/

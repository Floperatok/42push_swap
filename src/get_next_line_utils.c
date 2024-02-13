/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:21:14 by nsalles           #+#    #+#             */
/*   Updated: 2024/02/13 17:06:53 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
 *	Combines the string s1 and the string s2 together into one string.
 *	Memory for the new string is obtained with malloc(3), and can be freed
 *	with free(3).
 *	ARGUMENTS:
 *		char const *s1	: The first string, will be at the begginning of
							the final string.
		char const *s2	: The second string, will be at the end of
							the final string.
	RETURN VALUE:
		char *	: The first and the second string joined together.
	IMPORTANT NOTE : in this specific strjoin, s1 is freed.
*/
char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	lens1;
	size_t	lens2;
	size_t	i;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!res)
		return (free(s1), NULL);
	i = -1;
	while (s1 && ++i < lens1)
		res[i] = s1[i];
	i--;
	while (s2 && ++i < lens1 + lens2)
		res[i] = s2[i - lens1];
	res[i] = '\0';
	free(s1);
	return (res);
}

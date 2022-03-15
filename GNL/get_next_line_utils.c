/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:57:31 by romvan-d          #+#    #+#             */
/*   Updated: 2022/03/15 18:45:22 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>
size_t ft_strlen(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		return (i);
	}
	return (0);
}

/*prefix is the prefix string, suffix is the suffix string
Il faudra surement free pour pas quelle ne garde de valeur
donc surement prefix, wip*/

// char *ft_strjoin(char *prefix, char *suffix)
// {
// 	char *cat_str;
// 	size_t i;
// 	size_t j;

// 	i = 0;
// 	j = 0;
// 	if (!prefix || !suffix)
// 		return (NULL);
// 	cat_str = malloc(sizeof(*cat_str) * (ft_strlen(prefix) + ft_strlen(suffix) + 1));
// 	if (!cat_str)
// 		return (NULL);
// 	while (prefix[i] && i < ft_strlen(cat_str) - 1)
// 	{
// 		cat_str[i] = prefix[i];
// 		i++;
// 	}
// 	while (suffix[j] && j < ft_strlen(cat_str) - 1)
// 	{
// 		cat_str[i] = suffix[j];
// 		j++;
// 	}
// 	cat_str[j] = '\0';
// 	free(prefix); // leak a chaque appel de join sans le free (cest moche)
// 	return (cat_str);
// }

char	*ft_strjoin(char *s1, char *s2)
{
	// printf("%s \n, %s\n", s1 , s2);
	char	*cat_str;

	if (!s1 && s2)
		return (strdup(s2));
	if (s1 && !s2)
		return (strdup(s1));	
	cat_str = malloc(sizeof(*cat_str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!cat_str)
		return (NULL);
	strlcpy(cat_str, s1, ft_strlen(s1) + 1);
	strlcat(cat_str, s2, ft_strlen(s2) + ft_strlen(s1) + 1);
	free(s1);
	return (cat_str);
}

int ft_strchr(char *str, int c)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == c)
				return (1);
			i++;
		}
	}
	return (0);
}

char	*ft_handle_pre_endl(char *str, size_t len)
{
	int i;
	char *stored;

	i = 0;
	stored = malloc(sizeof(*stored) * (ft_strlen(str) - len + 1));
	if (!stored)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		stored[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		stored[i] = '\n';
		i++;
	}
	stored[i] = '\0';
	return (stored);
}

void	ft_handle_post_endl(char *str, char*buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n') 
		i++;
	if (str[i] == '\n')
		i++;
	while (str[i])
	{
		buff[j] = str[i];
		j++;
		i++;
	}
	buff[j] = '\0';
}

// #include <stdio.h>

// int main(void)
// {
// 	char str[] = "salut les \n   copains";
// 	printf("%s\n", ft_handle_post_endl(str));
// }


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:56:51 by romvan-d          #+#    #+#             */
/*   Updated: 2022/03/15 18:45:39 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

void	*ft_bzero(void *str, size_t len)
{
	int				i;
	unsigned char	*ptr;

	ptr = (unsigned char *) str;
	i = 0;
	while (len > 0)
	{
		ptr[i] = 0;
		i++;
		len --;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char		*remainder;
	char		*line;
	int			i;

	if (fd == -1 || BUFFER_SIZE < 0)
		return (NULL);
	i = BUFFER_SIZE;
	remainder = ft_strjoin(NULL, buffer); // equivalent a un strdup
	while (i == BUFFER_SIZE && ft_strchr(buffer, '\n') == 0)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		i = read(fd, buffer, BUFFER_SIZE);
		remainder = ft_strjoin(remainder, buffer);
	}
	ft_handle_post_endl(remainder, buffer);
	if (!remainder[0] && i != BUFFER_SIZE)
		line = NULL;
	else
		line = ft_handle_pre_endl(remainder, ft_strlen(buffer));
	free(remainder);
	return (line);
}

// int main(void)
// {
// 	int	s;
// 	char *str;
	
// 	s = open("blabla.txt", O_RDONLY);
// 	while((str = get_next_line(s)))
// 	{
// 		printf("%s", str);
// 	}
// 	return (0);
// }
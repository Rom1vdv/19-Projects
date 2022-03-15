/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:55:18 by romvan-d          #+#    #+#             */
/*   Updated: 2022/03/15 17:26:51 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

char 	*ft_strjoin(char *prefix, char *suffix);
int		ft_strchr(char *str, int c);
size_t	ft_strlen(char *s);
void	ft_handle_post_endl(char *str, char*buff);
char	*ft_handle_pre_endl(char *str, size_t len);
char	*get_next_line(int fd);

#endif
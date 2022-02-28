/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:53:33 by romvan-d          #+#    #+#             */
/*   Updated: 2022/02/28 19:24:30 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_check_charset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_arguments(char conv, va_list args)
{
	char *base;
	
	if (conv == 'd' || conv == 'i' || conv == 'u')
		// appelle putnbr
		ft_putnbr_base(args, "0123456789", 10);
		// return (ft_nbrlen(args, 10));
	if (conv == 's')
		ft_putstr();
		return (ft_strlen());
	if (conv == 'c' || '%')
		ft_putchar();
	if (conv == 'x')
	
	if (conv == 'X')

	if (conv == 'p')
		//faut write le Ox dabord
		ft_putnbr_base()
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list args;
	
	if (!str)
		return (NULL);
	va_start(args, str);
	i = 0;
	while(str[i])
	{
		if (str[i] == '%' && )
			return ;// do something, il faut regarder le char juste apres le % 
		else
			ft_putstr(str);
			return (ft_strlen(str));
			
			
		
	}
	va_end(args);
	return(ft_strlen(str));
}

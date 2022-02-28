/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_treatments_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:55:12 by romvan-d          #+#    #+#             */
/*   Updated: 2022/02/28 17:31:27 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/* ********************************** */
/* Evaluate the length of a number nb */
/* in a base b and return the length  */
/* ********************************** */

int	ft_nbrlen(int nb, int base)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		count++;
	while (nb)
	{
		nb = nb / base;
		count++;
	}
	return (count);
}

/* *********************************** */
/* Display the number nb in the base b */
/* *********************************** */

void	ft_putnbr_base(long long int nb, char *base, int radix)
{

	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= radix)
	{
		ft_putnbr_base(nb / radix, base, radix);
		ft_putnbr_base(nb % radix, base, radix);
	}
	if (nb < radix)
		ft_putchar(base[nb]);
}

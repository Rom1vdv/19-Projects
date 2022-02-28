/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:57:27 by romvan-d          #+#    #+#             */
/*   Updated: 2022/02/28 17:30:54 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
	char *base_dec;
	char *base_hex;
	char *base_capshex;
	unsigned int	i;

	i = -3;
	base_dec = "0123456789";
	base_hex = "0123456789abcdef";
	base_capshex = "0123456789ABCDEF";
	ft_putnbr_base(i, base_dec, 10);
}
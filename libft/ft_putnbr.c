/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchabala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 09:43:46 by kchabala          #+#    #+#             */
/*   Updated: 2018/06/01 09:49:57 by kchabala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	unsigned int mnb;

	if (nb < 0)
	{
		ft_putchar('-');
		mnb = -nb;
	}
	else
		mnb = nb;
	if (mnb >= 10)
	{
		ft_putnbr(mnb / 10);
		ft_putnbr(mnb % 10);
	}
	else if (mnb < 10)
	{
		ft_putchar(mnb + '0');
	}
}

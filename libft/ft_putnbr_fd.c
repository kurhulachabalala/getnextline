/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchabala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:29:11 by kchabala          #+#    #+#             */
/*   Updated: 2018/06/01 11:33:52 by kchabala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int mnb;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		mnb = -nb;
	}
	else
		mnb = nb;
	if (mnb >= 10)
	{
		ft_putnbr_fd(mnb / 10, fd);
		ft_putnbr_fd(mnb % 10, fd);
	}
	else if (mnb < 10)
	{
		ft_putchar_fd(mnb + '0', fd);
	}
}

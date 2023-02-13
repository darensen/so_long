/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:18:10 by dsenatus          #+#    #+#             */
/*   Updated: 2022/12/15 14:00:59 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 0 && nb <= 9)
		i += ft_putchar(nb + 48);
	else if (nb < 0)
	{
		i += ft_putchar('-');
		nb = nb * -1;
		i += ft_putuint(nb);
	}
	else if (nb > 0)
	{
		i += ft_putuint(nb / 10);
		i += ft_putuint(nb % 10);
	}
	return (i);
}

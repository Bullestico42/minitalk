/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:31:52 by apiscopo          #+#    #+#             */
/*   Updated: 2025/01/17 09:12:28 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putnbr(int n)
{
	char	c;
	int		count;

	c = 0;
	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		count += ft_putc('-');
		n = -n;
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
	}
	c = (n % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}
/*
	Converti un nombre en base 10 et l'affiche sur la sortie standard.
*/

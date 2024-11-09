/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:22:37 by jcologne          #+#    #+#             */
/*   Updated: 2024/11/09 10:59:06 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void put_digits(int n)
{
	if (n >= 10)
		put_digits(n / 10);
	put_char((n % 10) + 48);
}

int	put_num(int n)
{
	long	num;
	int		len;

	num = n;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	len = num_len(n);
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
		len++;
	}
	put_digits (n);
	return (len);
}

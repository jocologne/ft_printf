/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:22:37 by jcologne          #+#    #+#             */
/*   Updated: 2024/11/08 08:40:30 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_len(int n)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	put_num(int n)
{
	char		*str;
	int			len;
	long		num;
	int			sign;

	num = n;
	sign = (num < 0);
	if (sign)
		num = -num;
	len = num_len(num) + sign;
	str = (char *)malloc(len + 1);
	str[len] = '\0';
	while (len-- > sign)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	if (sign)
		str[0] = '-';
	return (put_str(str));
}

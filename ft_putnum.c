/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:22:37 by jcologne          #+#    #+#             */
/*   Updated: 2024/11/10 06:05:33 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_num(int n)
{
	int		len;

	len = 0;
	if (n == -2147483648)
		return (put_str("-2147483648"));
	if (n < 0)
	{
		len += put_char('-');
		n = -n;
	}
	if (n >= 10)
		len += put_num(n / 10);
	len += put_char((n % 10) + 48);
	return (len);
}

/*int main(void)
{
	int num = 101;
	int a = put_num(num);
	printf("\n");
	int b = printf("%d", num);
	printf("\n");
	printf("meu_%d org_%d\n", a, b);

}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 06:09:06 by jcologne          #+#    #+#             */
/*   Updated: 2024/11/10 08:01:16 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexa_char(int d, char c)
{
	char	*hexachars_l;
	char	*hexachars_u;

	hexachars_l = "0123456789abcdef";
	hexachars_u = "0123456789ABCDEF";
	if (c == 'x')
		put_char(hexachars_l[d]);
	if (c == 'X')
		put_char(hexachars_u[d]);
	return (1);
}

int	put_hexa(unsigned long n, char c)
{
	int		len;

	len = 0;
	if (n >= 16)
		len += put_hexa(n / 16, c);
	len += hexa_char(n % 16, c);
	return (len);
}

int	put_pnt(unsigned long pnt)
{
	int	len;

	len = 0;
	len += put_str("0x");
	len += put_hexa(pnt, 'x');
	return (len);
}

/*int main(void)
{
	int num = 424253;
	int a = put_hexa(num, 'x');
	printf("\n");
	int b = printf("%x", num);
	printf("\n");
	printf("meu_%d org_%d\n", a, b);
	int c = printf("%p", &num);
	printf("\n");
	int d = put_pnt(&num);
	printf("\n");
	printf("meu_%d org_%d\n", d, c);
}*/
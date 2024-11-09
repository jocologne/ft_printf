/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:46:02 by jcologne          #+#    #+#             */
/*   Updated: 2024/11/08 10:53:13 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	type(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == '%')
		len += put_char('%');
	if (c == 'c')
		len += put_char(va_arg(args, int));
	if (c == 's')
		len += put_str(va_arg(args, char *));
	if (c == 'i' || c == 'd')
		len += put_num(va_arg(args, int));
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	int		i;
	va_list	args_list;

	i = 0;
	len = 0;
	va_start(args_list, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += type(s[i + 1], args_list);
			i++;
		}
		else
			len += put_char(s[i]);
		i++;
	}
	va_end(args_list);
	return (len);
}

int main(void)
{
	int a = ft_printf("1234 %% %c %s %i %d", 'A', "BC", -2, 333);
	printf("\n");
	int b =    printf("1234 %% %c %s %i %d", 'A', "BC", -2, 333);
	printf("\n%d %d", a, b);
}
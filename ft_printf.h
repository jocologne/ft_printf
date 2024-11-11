/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 06:48:30 by jcologne          #+#    #+#             */
/*   Updated: 2024/11/11 13:33:35 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//REMOVER LIBS DE TESTE
# include <stdarg.h>
# include <unistd.h>

int	put_char(char c);
int	put_str(char *str);
int	put_int(int n);
int	ft_printf(const char *s, ...);
int	put_hexa(unsigned long n, char c);
int	put_pnt(unsigned long pnt);
int	put_uns(unsigned int n);

#endif
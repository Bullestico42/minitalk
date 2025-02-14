/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:18:02 by apiscopo          #+#    #+#             */
/*   Updated: 2025/01/22 21:18:54 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
ssize_t	ft_putc(char c);
ssize_t	ft_putnbr(int n);
ssize_t	ft_putstr(char *str);
ssize_t	ft_putptr(void *ptr);
ssize_t	ft_putun(unsigned int n);
ssize_t	ft_puthex(unsigned int n, int index);
ssize_t	convert(const char *str, va_list *args);

#endif
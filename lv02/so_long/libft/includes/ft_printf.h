/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:04:08 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/09 15:20:14 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		dispatch_format(char specifier, va_list args);
int		handle_format(const char *format, va_list args, int *index);
int		print_char(char c);
int		print_str(const char *s);
int		print_int(int n);
int		print_unsigned(unsigned int un);
int		print_hex(unsigned int xn, int uppercase);
int		print_pointer(void *p);
char	*ft_utoa(unsigned int un);

#endif

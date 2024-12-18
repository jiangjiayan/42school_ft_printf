/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjiayan <jiayanjiangfr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:24:57 by jjiayan           #+#    #+#             */
/*   Updated: 2024/12/03 12:36:39 by jjiayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

static size_t	i_digits(int n)
{
	size_t	digits;

	digits = 0;
	if (n <= 0)
		digits += 1;
	while (n != 0)
	{
		n /= 10;
		digits += 1;
	}
	return (digits);
}

static void	put_int(int n)
{
	static char	digits[] = "0123456789";

	if (n > 9)
		put_int(n / 10);
	write(STDOUT_FILENO, &digits[n % 10], 1);
}

int	print_int(int n)
{
	int	len;

	if (n == INT_MIN)
		return ((write(STDOUT_FILENO, "-2147483648", 11)));
	len = i_digits(n);
	if (n < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		n *= -1;
	}
	put_int(n);
	return (len);
}

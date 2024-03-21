/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:34:35 by diahmed           #+#    #+#             */
/*   Updated: 2023/11/12 15:33:44 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digitcount(int n)
{
	int	cnt;

	cnt = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		cnt++;
	}
	cnt++;
	return (cnt);
}

char	*ft_itoa(int n)
	{
	char	*str;
	int		sign;
	int		len;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	len = digitcount(n) + sign;
	str = malloc ((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (sign)
		str[0] = '-';
	while (len >= sign)
	{
		str[len--] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}

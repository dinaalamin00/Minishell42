/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:23:40 by diahmed           #+#    #+#             */
/*   Updated: 2024/05/05 11:56:15 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	checksign(char c, int *i, int *sign)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
			*sign *= -1;
		(*i)++;
	}
}

int	ft_atoi(const char *nptr)
{
	int			sign;
	long		result;
	int			i;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	checksign(nptr[i], &i, &sign);
	while (ft_isdigit(nptr[i]) && nptr[i])
	{
		if ((nptr[i] - '0' > (LONG_MAX % 10) && (result == (LONG_MAX / 10)))
			|| result > (LONG_MAX / 10))
		{
			if (sign == 1)
				return (-1);
			if (sign == -1)
				return (0);
		}
		result = result * 10 + nptr[i] - 48;
		i++;
	}
	return (result * sign);
}

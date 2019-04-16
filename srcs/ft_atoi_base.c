/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:28:53 by ceugene           #+#    #+#             */
/*   Updated: 2019/04/16 15:41:49 by ceugene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_atoi_base(const char *str, int base)
{
	int				s;
	unsigned int	result;
	int				levier;

	if (base == 10)
		return (ft_atoi(str));
	s = 0;
	result = 0;
	levier = 1;
	while (str != NULL && (str[s] == '\f' || str[s] == '\n' || str[s] == ' '
		|| str[s] == '\t' || str[s] == '\r' || str[s] == '\v'))
		s++;
	if (str[s] == '-' && str != NULL)
		levier = -1;
	if (str[s] == '-' || (str[s] == '+' && str != NULL))
		s++;
	while (str != NULL && str[s] >= '0' && (str[s] <= '9'))
	{
		result = result * 10;
		result = result + str[s] - '0';
		s++;
	}
	return ((int)result * levier);
}

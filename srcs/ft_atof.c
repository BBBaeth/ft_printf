/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:19:09 by ceugene           #+#    #+#             */
/*   Updated: 2019/04/16 15:19:11 by ceugene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

float		ft_atof(const char *str)
{
	int		s;
	int		virgule;
	float	result;
	int		levier;

	s = 0;
	result = 0;
	levier = 1;
	virgule = 0;
	while (str[s] == '\f' || str[s] == '\n' || str[s] == ' '
		|| str[s] == '\t' || str[s] == '\r' || str[s] == '\v')
		s++;
	if (str[s] == '-')
		levier = -1;
	if (str[s] == '-' || str[s] == '+')
		s++;
	while (str[s] >= '0' && str[s] <= '9')
	{
		result = result * 10 + (str[s++] - '0');
		if (str[s] == '.')
			virgule = s++;
	}
	while (virgule != 0 && ft_isdigit(str[++virgule]))
		levier = levier * 10;
	return (result / levier);
}

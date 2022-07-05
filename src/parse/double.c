/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   double.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/30 11:35:50 by mjoosten      #+#    #+#                 */
/*   Updated: 2022/07/05 10:58:00 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "program.h"

#define ERR_INCORRECT_DOUBLE "double incorrectly formatted"

char	*double_err_check(char *str)
{
	size_t	i;

	i = 0;
	if (!ft_isdigit(str[i]) && str[i] != '-')
		rt_error(str, ERR_INCORRECT_DOUBLE);
	i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '\0')
		return (str);
	if (str[i] != '.')
		rt_error(str, ERR_INCORRECT_DOUBLE);
	i++;
	if (!ft_isdigit(str[i]))
		rt_error(str, ERR_INCORRECT_DOUBLE);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		rt_error(str, ERR_INCORRECT_DOUBLE);
	return (str);
}

double	atod(char *str)
{
	double	int_part;
	double	double_part;
	int		sign;
	int		len;
	int		i;

	i = 0;
	sign = 1;
	int_part = 0;
	double_part = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		int_part = 10 * int_part + (str[i++] - '0');
	if (!str[i])
		return (int_part * sign);
	i++;
	len = ft_strlen(str);
	while (len-- > i)
		double_part = double_part / 10 + (double)(str[len] - '0') / 10;
	return ((int_part + double_part) * sign);
}

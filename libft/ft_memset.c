/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 23:45:34 by ecunniet          #+#    #+#             */
/*   Updated: 2016/11/06 13:38:21 by ecunniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		((unsigned char*)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

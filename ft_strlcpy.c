/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcosio <mcosio@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 20:48:56 by mcosio          #+#    #+#             */
/*   Updated: 2026/10/28 17:34:52 by mcosio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	src_length;

	src_length = ft_strlen(src);
	if (dstsize == 0)
		return (src_length);
	index = 0;
	while (src[index] != '\0' && index < dstsize - 1)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (src_length);
}

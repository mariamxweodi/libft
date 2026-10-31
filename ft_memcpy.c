/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcosio <mcosio@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 20:48:13 by mcosio          #+#    #+#             */
/*   Updated: 2026/10/28 17:35:57 by mcosio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;
	size_t				index;

	if (!dest && !src)
		return (NULL);
	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	index = 0;
	while (index < n)
	{
		dest_ptr[index] = src_ptr[index];
		index++;
	}
	return (dest);
}

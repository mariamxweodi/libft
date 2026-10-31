/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcosio <mcosio@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 20:48:31 by mcosio          #+#    #+#             */
/*   Updated: 2026/10/28 17:34:13 by mcosio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;

	if (!dest && !src)
		return (NULL);
	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	if (dest_ptr < src_ptr)
		ft_memcpy(dest_ptr, src_ptr, n);
	else
	{
		while (n > 0)
		{
			dest_ptr[n - 1] = src_ptr[n - 1];
			n--;
		}
	}
	return (dest);
}

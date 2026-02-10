/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 21:09:54 by jezambra          #+#    #+#             */
/*   Updated: 2026/02/09 22:46:08 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;
	
	i = 0;
	if(!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup_gnl(char *s)
{
	char	*str;
	int	i;

	if (!s)
		return (NULL);
	str = malloc(ft_strlen_gnl(s) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

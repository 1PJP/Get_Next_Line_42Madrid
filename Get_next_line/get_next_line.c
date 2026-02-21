/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 21:09:29 by jezambra          #+#    #+#             */
/*   Updated: 2026/02/21 21:08:56 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_gnl	gnl;
	char			*buffer;
	char			*temp;
	int				byread;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!gnl.stash)
	{
		gnl.stash = ft_strdup_gnl("");
		if (!gnl.stash)
			return (NULL);
	}
	/* else if (gnl.stash[0] == '\0')
	{
		free(gnl.stash);
		gnl.stash = NULL;
		return (NULL);
	} */
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(gnl.stash), gnl.stash = NULL, NULL);
	byread = 1;
	while (!ft_strchr_gnl(gnl.stash, '\n') && byread > 0)
	{
		byread = read(fd, buffer, BUFFER_SIZE);
		if (byread == -1)
			return (free(buffer), free(gnl.stash), gnl.stash = NULL, NULL);
		if (byread == 0 && (!gnl.stash || gnl.stash[0] == '\0'))
			return (free(buffer), free(gnl.stash), gnl.stash = NULL, NULL);
		buffer[byread] = '\0';
		temp = gnl.stash;
		gnl.stash = ft_strjoin_gnl(gnl.stash, buffer);
		free(temp);
		if (!gnl.stash)
			{
			free(buffer);
			gnl.stash = NULL;
			return (NULL);
			}
	}
	free(buffer);
//	if (!gnl.stash || gnl.stash[0] == '\0')
//	{
//		free(gnl.stash);
//		gnl.stash = NULL;
//		return (NULL);
//	}
	return (ft_get_line(&gnl));
}

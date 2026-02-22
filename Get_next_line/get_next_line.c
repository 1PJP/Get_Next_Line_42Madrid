/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 21:09:29 by jezambra          #+#    #+#             */
/*   Updated: 2026/02/22 14:55:27 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_and_stash(int fd, t_gnl *gnl)
{
	char	*buffer;
	char	*temp;
	int		byread;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	byread = 1;
	while (!ft_strchr_gnl(gnl->stash, '\n') && byread > 0)
	{
		byread = read(fd, buffer, BUFFER_SIZE);
		if (byread <= 0)
			break ;
		buffer[byread] = '\0';
		temp = gnl->stash;
		gnl->stash = ft_strjoin_gnl(temp, buffer);
		free(temp);
		if (!gnl->stash)
			return (free(buffer), -1);
	}
	free(buffer);
	return (byread);
}

char	*get_next_line(int fd)
{
	static t_gnl	gnl;
	int				status;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!gnl.stash)
	{
		gnl.stash = ft_strdup_gnl("");
		if (!gnl.stash)
			return (NULL);
	}
	status = read_and_stash(fd, &gnl);
	if (status == -1 || (status == 0 && (!gnl.stash || !gnl.stash[0])))
		return (free(gnl.stash), gnl.stash = NULL, NULL);
	return (ft_get_line(&gnl));
}

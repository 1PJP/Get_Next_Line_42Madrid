/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 22:02:45 by jezambra          #+#    #+#             */
/*   Updated: 2026/02/16 23:11:05 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line_stack(int fd)
{
	static t_gnl	gnl;
	char buffer[BUFFER_SIZE + 1];// guardamos todo lo que leemos antes de pasarlo al stash
	char	*temp;
	ssize_t	byread;//cunatos bytes vamos a leer

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!gnl.stash)
		gnl.stash = ft_strdup_gnl("");
	byread = 1;
	while (!ft_strchr_gnl(gnl.stash, '\n') && byread > 0)// mietras no haya un salto de linea sigue leyendo
	{
		byread = read(fd, buffer, BUFFER_SIZE);
		if (byread == -1)
			return (NULL);
		buffer[byread] = '\0';
		temp = gnl.stash;// guardamos stash viejo
		gnl.stash = ft_strjoin_gnl(gnl.stash, buffer);// concatenamos lo leido al stash
		free(temp);// ahora si liberamos el stash viejo
	}
	if	(!gnl.stash || gnl.stash[0] == '\0')
		return (NULL);//si el stash no exite o esta vacio
	return (get_line(&gnl));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 22:30:14 by jezambra          #+#    #+#             */
/*   Updated: 2026/02/16 23:03:05 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line_ptr(int fd)
{
	static t_gnl	*gnl;
	char	*buff;//temporal que solo guarda lo leido, luego lo pasa a stash
	ssize_t	byread;//cunatos bytes vamos a leer
	char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!gnl)
	{
		gnl = malloc(sizeof(t_gnl));
		if(!gnl)
			return (NULL);
		gnl->stash = NULL;
	}
	if (!gnl->stash)
	{
		gnl->stash = ft_strdup_gnl("");
		if (!gnl->stash)
		{
			free(buff);
			return (NULL);
		}
	}
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
		byread = 1;
	while (!ft_strchr_gnl(gnl->stash, '\n') && byread > 0)
	{
		byread = read(fd, buff, BUFFER_SIZE);
		if (byread == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[byread] = '\0';
		temp = ft_strjoin_gnl(gnl->stash, buff);
		if (!temp)
		{
			free(buff);
			free(gnl->stash);
			return (NULL);
		}
		free(gnl->stash);
		gnl->stash = temp;
	}
	free(buff);
	if (!gnl->stash || gnl->stash[0] == '\0')
		return (NULL);
	return (get_line(gnl));
}
/*version experimental, para acceder mediante puntero forma como las listas
enlazadas en esta version manejamos mas punteros, si no hacemos una reserva
de memoria con malloc lo que tendriamos seria una persistencia de puntero
pero no para la memeoria del sruct por eso aqui tenemos que hacer un malloc
para crear memora y automaticamente al ser static se vuelve persistente
y usamos el operador -> paraapuntar y acceder a la lista un poco mas 
compleja pero es una comparacion*/
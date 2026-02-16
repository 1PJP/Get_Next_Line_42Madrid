/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 21:09:29 by jezambra          #+#    #+#             */
/*   Updated: 2026/02/16 22:38:11 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_gnl	gnl;
	char	*buffer;//temporal que solo guarda lo leido, luego lo pasa a stash
	char	*temp;
	ssize_t	byread;//cunatos bytes vamos a leer

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!gnl.stash)
		gnl.stash = ft_strdup_gnl("");
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	byread = 1;
	while (!ft_strchr_gnl(gnl.stash, '\n') && byread > 0)
	{
		byread = read(fd, buffer, BUFFER_SIZE);
		if (byread == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byread] = '\0';
		temp = gnl.stash;
		gnl.stash = ft_strjoin_gnl(gnl.stash, buffer);
		free(temp);
		if (!gnl.stash)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	if (!gnl.stash || gnl.stash[0] == '\0')
		return (NULL);
	return (get_line(&gnl));
}
/*funcion principal, accedemos de esta forma directo al struct ya que no
referenciamos ni desreferenciamos punteros, tenemos una variable static no puntero 
asi que no usamos -> si no '.', de esta forma accedemos directo al struct y trabajamos
en el heap no en el stack, aqui asiganosm memoria manualmente de igual forma la liberamos
aumenta el riesgo de leaks memory pero asi aprendemos manejarlo mejor*/
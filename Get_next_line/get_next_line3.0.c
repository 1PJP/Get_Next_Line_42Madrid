/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 22:02:45 by jezambra          #+#    #+#             */
/*   Updated: 2026/02/13 23:33:05 by jezambra         ###   ########.fr       */
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
		free(temp);// ahora si leberamos el stash viejo
	}
	if	(!gnl.stash || gnl.stash[0] == '\0')
		return (NULL);//si el stash no exite o esta vacio
	return (get_line(&gnl));
}
/*esta version la vamos hacer con la memoria en el stack, osea no
usamos free ya que el stack lo hace automaticamente, en teoria 
menos riesgos*/
int main(void)
{
	int fd;
	char *line;

	fd = open("prueba.txt", O_RDONLY);
	if (fd < 0)
		return 1;
	while ((line = get_next_line_stack(fd)) != NULL)
		free(line);
	close(fd);
	return 0;
}
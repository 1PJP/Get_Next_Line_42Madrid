/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 22:02:45 by jezambra          #+#    #+#             */
/*   Updated: 2026/02/10 22:06:43 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line_stack(int fd)
{
	static t_gnl	gnl;
	char buffer[BUFFER_SIZE + 1];// guardamos todo lo que leemos antes de pasarlo al stash
	int	i;
	ssize_t	byread;//cunatos bytes vamos a leer

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!gnl.stash)
		gnl.stash = ft_strdup_gnl("");
	byread = 1;
	while (byread > 0)
	{
		byread = read(fd, buffer, BUFFER_SIZE);
		if (byread == -1)
			return (NULL);
	}
	i = 0;
	//while (gnl.stash[i] && gnl.stash[i] != '\n')
	//	i++;
}
/*esta version la vamos hacer con la memoria en el stack, osea no
usamos free ya que el stack lo hace automaticamente, en teoria 
menos riesgos*/
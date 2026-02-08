/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 21:09:54 by jezambra          #+#    #+#             */
/*   Updated: 2026/02/08 21:09:33 by jezambra         ###   ########.fr       */
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
/*con este strlen decidimos cuanto vamos hacer crecer el stash para no hacer overflow
y lo reutilizamos dentro del codigo para ahorra lienas, tambien se le hizo una pequena 
modificacion ya que el stash inicia en NULL asi que para que no de error se le anadio 
una pequena condicion */

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
/*con esta funcion creamos una copia de stash por que al hacer free liberamos el 
stash pero ya tenemos una copia en memoria del stash con strdup, asi que no vamos 
a perder nada y podremos hacer free y guardar lo que vamos a leer, free para liberar
lo leido y strdup para hacr una copia de lo que no se a leido */
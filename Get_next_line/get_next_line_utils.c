/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 21:09:54 by jezambra          #+#    #+#             */
/*   Updated: 2026/02/21 21:08:55 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup_gnl(char *s)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	str = malloc(ft_strlen_gnl(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	i1;
	size_t	i2;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	i1 = 0;
	i2 = 0;
	s3 = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!s3)
		return (NULL);
	i1 = 0;
	i2 = 0;
	while (s1[i1])
	{
		s3[i1] = s1[i1];
		i1++;
	}
	while (s2[i2])
	{
		s3[i1 + i2] = s2[i2];
		i2++;
	}
	s3[i1 + i2] = '\0';
	return (s3);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	unsigned char	ch;
	int				i;

	if (!s)
		return (NULL);
	ch = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		i++;
	}
	if (ch == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_get_line(t_gnl *gnl)
{
	int		i;
	char	*line;
	char	*save;

	i = 0;
	while (gnl->stash[i] && gnl->stash[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
	{
		free(gnl->stash);
		gnl->stash = NULL;
		return(NULL);
	}
	i = 0;
	while (gnl->stash[i] && gnl->stash[i] != '\n')
	{
		line[i] = gnl->stash[i];
		i++;
	}
	if (gnl->stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	save = ft_strdup_gnl(gnl->stash + i);
	if (!save)
	return (free(line), free(gnl->stash), gnl->stash = NULL, NULL);
	free(gnl->stash);
	gnl->stash = save;
	if (!gnl->stash || gnl->stash[0] == '\0')
		return (free(gnl->stash), gnl->stash = NULL);
	return (line);
}

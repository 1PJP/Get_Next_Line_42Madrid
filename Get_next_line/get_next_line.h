/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 21:10:08 by jezambra          #+#    #+#             */
/*   Updated: 2026/02/10 22:07:12 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


typedef struct	s_gnl
{
	char	*stash;
}				t_gnl;

char	*get_next_line(int fd);
char	*get_next_line_ptr(int fd);
char	*get_next_line_stack(int fd);

char	*ft_strdup_gnl(char *s);
size_t	ft_strlen_gnl(char *s);


#endif
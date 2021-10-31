/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 13:09:16 by rvan-mee      #+#    #+#                 */
/*   Updated: 2021/10/31 15:09:01 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*remove_till_newline(char *str);
char	*merge_str(char *src, char *buffer);
char	*strcopy(char *src, char *dst);
int		ft_strlen(char *str);
char	*ft_calloc(int len);

#endif

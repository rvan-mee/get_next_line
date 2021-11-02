/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 13:09:08 by rvan-mee      #+#    #+#                 */
/*   Updated: 2021/11/02 17:09:59 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	memsetzero(char *str, ssize_t len)
{
	ssize_t	i;

	i = 0;
	while (i <= len)
	{
		str[i] = '\0';
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*merge_str(char *src, char *buffer)
{
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	newstr = ft_calloc(ft_strlen(buffer) + ft_strlen(src) + 1);
	if (!newstr)
	{
		free(src);
		return (NULL);
	}
	while (src[i] != '\0')
	{
		newstr[i] = src[i];
		i++;
	}
	while (buffer[j] != '\0')
	{
		newstr[i + j] = buffer[j];
		j++;
	}
	free(src);
	return (newstr);
}

char	*remove_helper(char *newstr, char *str)
{
	int	j;

	j = 0;
	while (str[j] != '\n' && str[j] != '\0')
	{
		newstr[j] = str[j];
		j++;
	}
	if (str[j] == '\n')
	{
		newstr[j] = '\n';
		j++;
	}
	newstr[j] = '\0';
	free(str);
	return (newstr);
}

char	*remove_till_newline(char *str)
{
	int		i;
	char	*newstr;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			i++;
			newstr = ft_calloc(i + 1);
			if (!newstr)
				return (NULL);
			newstr = remove_helper(newstr, str);
			return (newstr);
		}
		i++;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 13:09:08 by rvan-mee      #+#    #+#                 */
/*   Updated: 2021/10/31 16:41:35 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
//	printf(" ----------------- ft_strlen -----------------\n");
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*strcopy(char *src, char *dst)
{
//	printf(" ----------------- strcopy -----------------\n");
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*merge_str(char *src, char *buffer)
{
//	printf("------------------ MERGE_STR ------------------\n");
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	newstr = ft_calloc(ft_strlen(buffer) + ft_strlen(src) + 1);
	if (!newstr)
		return (NULL);
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
//	printf("   ----------------- free ------------------\n");
	free(src);
//	printf("   ----------------- free successfull ------\n");
	return (newstr);
}

char	*remove_till_newline(char *str)
{
//	printf("------------------ remove_till_newline --------\n");
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
//	printf("str contains: %s\n", str);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			i++;
			newstr = ft_calloc(ft_strlen(str + i) + 1);
			if (!newstr)
				return (NULL);
			while (j < i)
			{
				newstr[j] = str[j];
				j++;
			}
			newstr[j] = '\0';
//			printf("newstr contains: %s\n", newstr);
//			printf("   ----------------- free ------------------\n");
			free(str);
//			printf("   ----------------- free successfull ------\n");
			return (newstr);
		}
		i++;
	}
	return (str);
}

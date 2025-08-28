/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 23:06:00 by cgross-s          #+#    #+#             */
/*   Updated: 2025/08/27 20:35:10 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_countword(const char *input)
{
	int			word_count;
	int			inside_quotes;
	const char	*ch;

	word_count = 0;
	inside_quotes = 0;
	ch = input;
	while (*ch != '\0')
	{
		if (*ch == '\\' && *(ch + 1) != '\0')
			ch += 2;
		if (*ch == '"' || *ch == '\'')
			inside_quotes = !inside_quotes;
		else if (*ch == ' ' && !inside_quotes)
			word_count++;
		ch++;
	}
	if (!inside_quotes)
		word_count++;
	return (word_count);
}

int	array_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	*remove_backslashes(char *s)
{
	size_t	len;
	size_t	j;
	size_t	k;
	char	*result;

	len = 0;
	j = 0;
	k = 0;
	while (s[j])
	{
		if (s[j + k] == '\\' && s[j + k + 1] != '\0')
			k++;
		j++;
	}
	result = malloc(sizeof(char) * (ft_strlen(s) - k + 1));
	j = 0;
	len = 0;
	while (s[j])
	{
		if (s[j] == '\\' && s[j + 1] != '\0')
			j++;
		result[len++] = s[j++];
	}
	result[len] = '\0';
	return (result);
}

char	**remove_scape_symbol(char **s)
{
	char	**new_array;
	int		i;

	remove_spaces(s);
	if (!s[0])
		return (NULL);
	new_array = malloc(sizeof(char *) * (array_size(s) + 1));
	i = 0;
	while (i < (array_size(s)))
	{
		new_array[i] = remove_backslashes(s[i]);
		i++;
	}
	new_array[i] = NULL;
	return (new_array);
}

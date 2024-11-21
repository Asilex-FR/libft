/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:08:05 by ainthana          #+#    #+#             */
/*   Updated: 2024/11/21 16:56:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int  ft_count(char const *str, char c)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] != c)
        {
            j++;
            while (str[i] != c && str[i])
                i++;
            if (str[i] == '\0')
                return (j);
        }
        i++;
    }
    return (j);
}

static char *ft_putword(char const *s, size_t start, size_t end)
{
    char    *word;
    size_t  i;

    i = 0;
    if (!s)
        return (NULL);
    word = malloc(sizeof (char) * (end - start) + 1);
    if (!word)
        return (NULL);
    while (start < end)
    {
        word[i] = s[start];
        i++;
    }
    word[i] = '\0';
    return (word);
}

static char **ft_free_tab(char **tab)
{
    size_t  i;

    i = 0;
    while (tab && tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
    return (NULL);
}

char	**ft_split(char const *s, char c)
{
    char    **split;
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    split = malloc(sizeof (char *) * (ft_count(s, c) + 1 ));
    if (!s || !split)
        return (NULL);
    while (s[i])
    {
        split[j] = ft_putword(s, i, (ft_strlen(s) - 1));
        i++;
    }
    if (!split[i])
        return (ft_free_tab(split));
    split[j] = '\0';
    return (split);
}

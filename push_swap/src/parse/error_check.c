/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:48:32 by ilyas             #+#    #+#             */
/*   Updated: 2024/03/20 00:19:59 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int is_arg_empty(char *str)
{
    int i = 0;

    while (str[i] && str[i] == ' ')
        i++;
    if (str[i] == '\0')
        return (1);
    return (0);
}

int filter_one(int ac, char **av)
{
    int i;
    int j;
    int count_digit;

    count_digit = 0;
    i = 1;
    j = 0;

    while(i < ac)
    {
        if (is_arg_empty(av[i]))
            return (0);
        j = 0;
        count_digit = 0;
        if (!av[i][0])
            return (0);
        while(av[i][j])
        {
            if(av[i][j] != ' ' && av[i][j] != '\t' 
                && !is_sign(av[i][j])
                && !ft_isdigit(av[i][j]))
                    return (0);
            if (ft_isdigit(av[i][j]))
                count_digit = 1;
            j++;
        }
            i++;
    }
    return (1);
}

char **error_check(int ac, char **av)
{
    int i;
    char *tmp;
    char **arr_of_numbers;
    
    tmp = NULL;
    i = 1;
    if(!filter_one(ac, av))
        return (NULL);
    while(i < ac)
    {
        if (!is_arg_valid(av[i]))
            return (NULL);
        i++;
    }
    tmp = join_all(ac, av);
    if(!tmp)
        return (0);
    arr_of_numbers = ft_split(tmp, ' ');
    if (!arr_of_numbers)
    {
        free(tmp);
        return (NULL);
    }
    if (have_duplicates(arr_of_numbers))
    {
        free_double_array(arr_of_numbers);
        free(tmp);
        return (NULL);
    }
    free(tmp);
    return (arr_of_numbers);
}
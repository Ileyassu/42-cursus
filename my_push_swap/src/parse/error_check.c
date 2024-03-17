/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:48:32 by ilyas             #+#    #+#             */
/*   Updated: 2024/03/16 14:03:28 by ilyas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int filter_one(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while(i < ac)
    {
        j = 0;
        while(av[i][j])
        {
            if(av[i][j] != ' ' && av[i][j] != '\t' 
                && !is_sign(av[i][j])
                && !ft_isdigit(av[i][j]))
                    return (0);
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
    // int x = 0;
    // while (arr_of_numbers[x])
    // {
    //     printf("num = %s\n", arr_of_numbers[x]);
    //     x++;
    // }
    if (have_duplicates(arr_of_numbers))
    {
        free_double_array(arr_of_numbers);
        free(tmp);
        return (NULL);
    }
    return (arr_of_numbers);
}
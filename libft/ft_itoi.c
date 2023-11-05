/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:42:17 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/04 18:48:29 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char *checkIfZero(char *ptr)
{

            ptr = (char *)malloc(3);
            if(ptr == NULL)
                return (NULL);
            
            *ptr = '0'; //returni 0 ila nbr = 0
            return (ptr);
}
static void checkNegative(long long *nbr, int *isNeg_num)
{
        *nbr *= -1;
        *isNeg_num = 1;
}

char *ft_itoi(size_t n)
{
    size_t nbr;
    char *ptr;
    size_t temp;
    size_t len;
    size_t isNeg_num;

    isNeg_num = 0; //tracki sign
    len = 0;    //bach an7ssb length (malloc, last block)
    if(n == 0)  //check if n == 0
    {
        ptr = checkIfZero(ptr); //returni ptr = '0' ila nbr = 0
        return (ptr);
    }
    nbr = n;
    if(nbr < 0) //handli negative
        checkNegative(&nbr, &isNeg_num);
    temp = nbr;
    while(temp > 0) //bach n7ssbo length ou ndiro 
        temp /= 10;
        len++;
    ptr = (char *)malloc(len + 2);// + 2 3la 9ble negative ou '\0'
    if(ptr == NULL)
        return NULL;
    ptr += len +1; //pointiw l akhir block
    *ptr = '\0'; //htte lihh khrahh
    ptr--;
    while(nbr > 0) //an7tto numbers
    {
        //printf("%d\n", (int)nbr);
        ptr--;
        *ptr = (nbr % 10) + '0';
        nbr /= 10;
    }
    if(isNeg_num)//ila kane true Y3ni negative
    {
        ptr--;
        *ptr = '-';
    }
    return (ptr);
}
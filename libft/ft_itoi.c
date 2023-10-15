#include <stdlib.h>

char *ft_itoi(int n)
{
    long long nbr;
    char *ptr;
    int temp;
    int len;
    int isNeg_num;

    isNeg_num = 0; //tracki sign
    len = 0;    //hssbe length (malloc, last block)
    if(n == 0)  //first case if it's 0
    {
        ptr = (char *)malloc(2);
        if(ptr == NULL)
            return (NULL);
        
        *ptr = '0'; //returni 0 ila nbr = 0
        return ptr;
    }
    nbr = n;
    if(nbr < 0) //handli negative
    {
        nbr *= -1;
        isNeg_num = 1;
    }
    temp = nbr;
    while(temp > 0) //bach n7ssbo length ou ndiro 
    {               //malloc 3la hssab chhal mne ra9m kayne
        temp /= 10;
        len++;
    }
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
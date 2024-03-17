#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libraries/libraries.h"

typedef struct s_stack
{
    int value;
    int index;
    struct s_stack *next;
}   t_stack;

char **error_check(int ac, char **av);
char	**free_double_array(char **s);
int	have_duplicates(char **av);
int is_arg_valid(char *av);
int is_sign(char c);
char *join_all(int ac, char **av);
t_stack *add_to_stack(char **arr_of_num);
void free_list(t_stack *head);

#endif
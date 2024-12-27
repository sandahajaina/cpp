#include <iostream>
#include <cctype>

void    ft_print(char *str)
{
    std::cout << str;
}

void    to_uppercase(char *str)
{
    if (!str)
        return ;
    while (*str)
    {
        *str = std::toupper(*str);
        ++str;
    }
    
}

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        int i = 1;
        while (argv[i])
        {
            to_uppercase(argv[i]);
            ft_print(argv[i]);
            i++;
        }
        ft_print((char *)"\n");
        
    }
    return (0);
}
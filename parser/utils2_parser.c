int ft_thereis_c(char *str, char c)
{
    int i;

    i = 0;
    if (!str || !c)
        return (0);
    while (str[i] && str[i] != c)
        i++;
    if (str[i]  == c)
        return (1);
    return (0);
}

void    ft_get_real_value(char **linput)
{
    int i;
    int ix;

    i = 0;
    ix = 0;
    while (linput[ix])
    {
        while (linput[ix][i])
        {
            if (linput[ix][i] == 18)
                linput[ix][i] = ' ';
            if (linput[ix][i] == 19)
                linput[ix][i] = '|';
            i++;
        }
        i = 0;
        ix++;
    }
}
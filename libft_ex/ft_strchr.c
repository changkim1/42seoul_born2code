char    *strchr(const char *str, int c)
{
    int i;

    i = 0;
    if (str[i] == 0)
        return (0);
    while (str[i])
    {
        if (str[i] == (unsigned char)c)
        {
            return ((char *)&str[i]);
        }
        i++;
    }
    if (str[i] == (unsigned char)c)
    {
        return ((char *)&str[i]);
    }
    return (0);
}
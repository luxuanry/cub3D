#include "../../includes/cub3d.h"

int is_empty_line(char *line)
{
    while (*line)
    {
        if (*line != ' ' && *line != '\t' && *line != '\n')
            return (0);
        line++;
    }
    return (1);
}

int check_file_extension(char *filename, char *ext)
{
    int len;
    int ext_len;
    
    len = ft_strlen(filename);
    ext_len = ft_strlen(ext);
    
    if (len < ext_len)
        return (0);
    
    return (ft_strncmp(filename + len - ext_len, ext, ext_len) == 0);
}

void free_split(char **split)
{
    int i;
    
    if (!split)
        return;
    
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}
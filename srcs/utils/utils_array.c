#include "../../includes/cub3d.h"

static char *create_visited_row(int width)
{
    char    *row;
    int     j;
    
    row = malloc(sizeof(char) * width);
    if (!row)
        return (NULL);
    j = 0;
    while (j < width)
    {
        row[j] = 0;
        j++;
    }
    return (row);
}
char **create_visited_array(int height, int width)
{
    char    **visited;
    int     i;
    
    visited = malloc(sizeof(char *) * height);
    if (!visited)
        return (NULL);
    i = 0;
    while (i < height)
    {
        visited[i] = create_visited_row(width);
        if (!visited[i])
        {
            free_visited_array(visited, i);
            return (NULL);
        }
        i++;
    }
    return (visited);
}

void free_visited_array(char **visited, int height)
{
    int i;
    
    if (!visited)
        return;
    
    i = 0;
    while (i < height)
    {
        free(visited[i]);
        i++;
    }
    free(visited);
}

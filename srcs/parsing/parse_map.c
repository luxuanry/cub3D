#include "../../includes/cub3d.h"

/*
 * add_map_line - Add a line to the map grid
 * @line: Line to add
 * @data: Main data structure
 * 
 * Reallocates the map grid and adds the new line.
 * Returns 1 on success, 0 on failure.
 */
int add_map_line(char *line, t_data *data)
{
    char **new_grid;
    int i;
    int len;
    
    // Remove trailing newline
    len = ft_strlen(line);
    if (len > 0 && line[len - 1] == '\n')
        line[len - 1] = '\0';
    
    // Allocate new grid with one more line
    new_grid = malloc(sizeof(char *) * (data->map.height + 1));
    if (!new_grid)
        return (error_msg("Memory allocation failed"));
    
    // Copy existing lines
    i = 0;
    while (i < data->map.height)
    {
        new_grid[i] = data->map.grid[i];
        i++;
    }
    
    // Add new line
    new_grid[i] = ft_strdup(line);
    if (!new_grid[i])
    {
        free(new_grid);
        return (error_msg("Memory allocation failed"));
    }
    
    // Update width (take maximum width)
    len = ft_strlen(line);
    if (len > data->map.width)
        data->map.width = len;
    
    // Free old grid pointer (not the strings, they were copied)
    if (data->map.grid)
        free(data->map.grid);
    
    // Update map
    data->map.grid = new_grid;
    data->map.height++;
    
    return (1);
}

/*
 * parse_map_line - Parse a map line
 * @line: Line to parse
 * @data: Main data structure
 */
int parse_map_line(char *line, t_data *data)
{
    // Check if textures and colors are set
    if (data->tex_count != 4 || data->color_count != 3)
        return (error_msg("Map must come after textures and colors"));
    
    // Add line to map
    if (!add_map_line(line, data))
        return (0);
    
    return (1);
}

// int parse_file(char *filename, t_data *data)
// {
//     int fd;
//     char *line;
    
//     // Check file extension
//     if (!check_file_extension(filename, ".cub"))
//         return (error_msg("file must be .cub format"));
    
//     // Open file
//     fd = open(filename, O_RDONLY);
//     if (fd < 0)
//         return (error_msg("can not open file"));
    
//     // Initialize data
//     init_data(data);
    
//     // Read line by line
//     line = get_next_line(fd);
//     while (line != NULL)
//     {
//         if (!parse_line(line, data))
//         {
//             free(line);
//             close(fd);
//             get_next_line(-1); // Clean up GNL static buffer
//             return (0);
//         }
//         free(line);
//         line = get_next_line(fd);
//     }
    
//     close(fd);
//     get_next_line(-1); // Clean up GNL static buffer
    
//     // Validate all information
//     if (!validate_data(data))
//         return (0);
    
//     return (1);
// }

int parse_file(char *filename, t_data *data)
{
    int fd;
    char *line;
    
    // Initialize data FIRST (before any checks that might fail)
    init_data(data);
    
    // Check file extension
    if (!check_file_extension(filename, ".cub"))
        return (error_msg("file must be .cub format"));
    
    // Open file
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (error_msg("cannot open file"));
    
    // Read line by line
    line = get_next_line(fd);
    while (line != NULL)
    {
        if (!parse_line(line, data))
        {
            free(line);
            close(fd);
            get_next_line(-1); // Clean up GNL static buffer
            return (0);
        }
        free(line);
        line = get_next_line(fd);
    }
    
    close(fd);
    get_next_line(-1); // Clean up GNL static buffer
    
    // Validate all information
    if (!validate_data(data))
        return (0);
    
    return (1);
}
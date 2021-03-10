# get\_next\_line

_Get\_next\_line()_ is a function  which can read from a file descriptor one line at a time and store the result in dynamically allocated memory. The function is also able to read from multiple file descriptors at the same time.

## :rocket: Description

The get_next_line function has the following prototype:

```C
int get_next_line(int fd, char **line)
```

in which **fd** is the file descriptor to read from and **line** is the adress of a string (character pointer) which _get_next_line()_ will fill with the line read. The line variable is NULL-terminated.

### Return values
 - 1 if line is read
 - 0 at EOF (End Of File)
 - -1 when an error occurs.


>:warning: Dynamically allocated memory will be stored in **line**, so be sure to free the variable after each call to prevent memory leaks in your program.

## :scroll: Contents

The **src** folder contains the source files for the _get_next_line()_ function as explained above. The **extended_src** folder contains a _get_next_line()_ function which can read from multiple file descripters in one program.

## :joystick: Example Program

```C
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int     main(void)
{
    char    *line;
    int     fd;
    int     res;

    res = 1;
    fd = open("text.txt", O_RDONLY);
    line = NULL;
    while (res == 1)
    {
        res = get_next_line(&line);
        printf("%s\n", line);
        printf("res = %d\n\n", res);
        free(line);
        line = NULL;
    }
    close(fd);
    return (0);
}
```

This will read all lines in the text file "text.txt". 

## :blue_book: License
[MIT](https://opensource.org/licenses/MIT)


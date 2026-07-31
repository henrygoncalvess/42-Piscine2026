*This project has been created as part of the 42 curriculum by hegoncal.*

# get_next_line

## Description

**get_next_line** is a project developed as part of the 42 curriculum. The goal of this project is to create a function that reads a file descriptor line by line.

Calling this function in a loop will allow you to read the text available on the file descriptor one line at a time until the end of it. This project introduces the concept of static variables in C, which are essential to remember information between successive function calls.

The function prototype is:

```c
char *get_next_line(int fd);
```

## Instructions

To use `get_next_line` in your own project, simply include the header and compile your files with the `get_next_line` source files.

1. Clone the repository:
```sh
git clone <repository-url> get_next_line
cd get_next_line
```

2. Compile your project with the required source files and specify the `BUFFER_SIZE` as a compiler flag (e.g., `-D BUFFER_SIZE=42`):
```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 your_main.c get_next_line.c get_next_line_utils.c
```

*(If no `BUFFER_SIZE` is defined, the compiler flag can be omitted if your header defines a default value, but it's recommended to test with various buffer sizes).*

3. Include the header in your C file:
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Algorithm and Data Structure

The algorithm implemented in `get_next_line` revolves around reading chunks of data and accumulating them until a complete line (ending in a newlinere character `\n`) is formed.

### How it works:
1. **Static Stash**: A `static char *stash` variable is used to keep track of the characters that were read from the file descriptor but have not yet been returned as part of a complete line. The static keyword ensures the state of this variable persists across multiple calls to the function.

2. **Reading phase**: If the current `stash` does not contain a newline character, the function reads from the file descriptor in chunks of `BUFFER_SIZE` bytes. Each chunk is dynamically appended to the `stash` using string joining, until a newline character is encountered or the end of the file (EOF) is reached.

3. **Extraction**: Once a newline is found (or EOF is reached with remaining characters in the stash), the `extract_line` function creates a new string containing all characters up to and including the newline. This string is what will be returned to the caller.

4. **Updating the Stash**: The `get_remaining` function takes the characters that appear *after* the extracted newline and saves them back into the `stash` for the next function call.

### Justification:

- **String accumulation**: Using a single `char *` as a stash and dynamically allocating memory as we read chunk by chunk avoids complex linked lists or arbitrary size limits. It provides a simple and manageable way to handle potentially long lines.

- **Modularity**: The logic is broken down into helper functions (`read_to_stash`, `extract_line`, `get_remaining`), making each step testable, easier to debug, and strictly compliant with the Norm (e.g., max 25 lines per function).

- **Efficiency**: The function only reads from the file descriptor when absolutely necessary (i.e., when no newline is present in the stash), minimizing expensive `read` system calls.

## Resources

### Documentation and references
- [`man 2 read`](https://man7.org/linux/man-pages/man2/read.2.html) — the reference specification for the `read` system call.
- [`man 3 malloc`](https://man7.org/linux/man-pages/man3/malloc.3.html) / [`free`](https://man7.org/linux/man-pages/man3/free.3.html) — reference for dynamic memory allocation.
- 42's own `get_next_line` subject and Norm documentation.

### Use of AI

AI assistance was used in two scoped ways during this project:

- **Understanding concepts and man pages** — clarifying the expected behavior of standard functions like `read`, edge cases, memory management, and how to deal with varying buffer sizes.
- **Tests and review** — generating test cases and reviewing implementations for edge cases, memory leaks, and Norm compliance.

All function implementations were written and understood by the author; AI was used as a study and verification aid, not as a code generator.

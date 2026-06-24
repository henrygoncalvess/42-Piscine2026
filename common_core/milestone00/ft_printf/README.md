_This project has been created as part of the 42 curriculum by hegoncal._

# ft_printf

## Description

**ft_printf** is a reimplementation of the standard C library function
`printf`, developed as part of the 42 curriculum. The goal of the project is
to understand how variadic functions work in C, how format strings are
parsed, and how to build a small, reusable library from scratch without
relying on the standard library's own `printf` implementation.

The project delivers a static library, `libftprintf.a`, exposing a single
public function:

```c
int ft_printf(const char *format, ...);
```

`ft_printf` reads a format string, interprets the conversion specifiers it
contains, and prints the corresponding arguments to the standard output,
mimicking the behavior of the original `printf` for the subset of
conversions it supports.

## Instructions

Clone the repository and build the library with `make`:

```sh
git clone <repository-url> ft_printf
cd ft_printf
make
```

This produces the static library `libftprintf.a` in the project root.

Available Makefile rules:

| Rule          | Description                                       |
| ------------- | -------------------------------------------------- |
| `make`        | Build `libftprintf.a` (default `all` rule).         |
| `make clean`  | Remove the object (`.o`) files.                     |
| `make fclean` | Remove the object files **and** `libftprintf.a`.    |
| `make re`     | Rebuild everything from scratch.                    |

The library is compiled with `cc -Wall -Wextra -Werror`.

To use `ft_printf` in your own project, include the header and link the
library:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! You are %d years old.\n", "world", 42);
    return (0);
}
```

```sh
cc -Wall -Wextra -Werror your_file.c -L . -l ftprintf -o your_program
```

*The `-l` option is automatic. it searches for lib[name].a*

## Algorithm and Data Structure

`ft_printf` works as a single left-to-right scan of the format string:

1. **Literal characters** are written to standard output as-is.
2. When a `%` is encountered, the parser switches into **conversion mode**
   and reads the specifier that follows (e.g. `c`, `s`, `p`, `d`, `i`, `u`,
   `x`, `X`, `%`).
3. Each conversion is delegated to its own dedicated function, which reads
   the next argument from the `va_list` using the type appropriate for that
   conversion (`char`, `char *`, `void *`, `int`, `unsigned int`, ...) and
   writes the formatted output.
4. A running character counter accumulates the number of bytes written,
   which is returned at the end — matching the standard `printf` contract.

This design was chosen over a single monolithic function because:

- **One function per conversion** keeps each case small, testable in
  isolation, and easy to extend (adding a new specifier means adding one
  function and one dispatch entry, not touching existing logic).
- **Each conversion function reads exactly one argument** from the `va_list`
  and processes it independently, making the code straightforward to follow
  and debug.
- **A single left-to-right pass** through the format string is simple and
  efficient — no complex state machine or backtracking needed.

No dynamic data structure is required: the format string itself, combined
with the `va_list`, acts as the only "state" the algorithm needs to track.

## Resources

### Documentation and references

- [`man 3 printf`](https://man7.org/linux/man-pages/man3/printf.3.html) — the
  reference specification for the conversions and flags implemented.
- [`man 3 stdarg`](https://man7.org/linux/man-pages/man3/stdarg.3.html) —
  documentation on `va_list`, `va_start`, `va_arg`, and `va_end`.
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/) — general
  reference for pointers, variadic functions, and low-level I/O in C.
- 42's own `printf` subject and Norm documentation.

### Use of AI

AI assistance was used in two scoped ways during this project:

- **Understanding concepts and man pages** — clarifying the expected
  behavior of standard functions, edge cases, and how to read the C
  documentation.
- **Tests and review** — generating test cases and reviewing
  implementations for edge cases and Norm compliance.

All function implementations were written and understood by the author; AI
was used as a study and verification aid, not as a code generator.

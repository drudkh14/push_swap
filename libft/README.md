*This project has been created as part of the 42 curriculum by zbohdanc.*

# Description

The goal of this project *libft* is to code a library that
includes functions from the C standard library,
as well as other ones that are not included in the standard library and
functions for a data structure *linked list* in order to use this library
during the Core Curriculum.

# Instructions

- To use this library you should have either source files
with Makefile and header file *libft.h* or
compiled library *libft.a* and header file *libft.h*

- To compile library from source files you need to
run 'make'

- To use the library in your project just include
header file *libft.h* that contains prototypes
and structure description

- Don't forget to set compilation flags while compiling your source

**Part 1 - Libc functions**
*Use man <function-name> to see prototypes and manual*

Functions 'ft_isalpha', 'ft_isdigit', 'ft_isalnum', 'ft_isascii',
		  'ft_isprint' return:
- 1 if character matches the tested class
- 0 if character does not match

If "ft_calloc" gets as one of the arguments '0'
it returns a unique pointer value that can be successfully freed.

**Part 2 - Additional functions**
*See function prototypes for details*

* 'ft_substr' -- Returns a substring from an original string
* 'ft_strjoin' -- Returns new string that is contatenation of two strings
* 'ft_strtrim' -- Returns a new string trimmed from characters in the set
* 'ft_split' -- Returns an array of strings by splitting a string by delimeter
* 'ft_itoa' -- Returns a string represantation of an integer
* 'ft_striteri' -- Applies function passed to each character of a string
* 'ft_strmapi' -- Similar to 'ft_striteri', but returns processed string
* 'ft_putchar_fd' -- Outputs a character to a specifieed file descriptor
* 'ft_putstr_fd' -- Outputs a string to a specified file descriptor
* 'ft_putendl_fd' -- As 'ft_putstr_fd' but outputs a new lineat the end
* 'ft_putnbr_fd' -- Outputs a number to a specified file descriptor

**Part 3 -- Linked List**
*See function prototypes for details*

* 'ft_lstnew' -- Creates a new node
* 'ft_lstadd_front' -- Adds the given node at the beginning of the list
* 'ft_lstsize' -- Returns the number of nodes on the list
* 'ft_lstlast' -- Returns the last node of the list
* 'ft_lstadd_back' -- Adds the given node at the end of the list
* 'ft_lstdelone' -- Takes a node and frees its content with a specified function
					without freeing the next node
* 'ft_lstclear' -- Deletes and frees the list
* 'ft_lstiter' -- Iterates through the list and applies the given function
					to each node
* 'ft_lstmap' -- Iterates through the list and creates a new list
					with nodes created after application of the given function

# Resources
- The C Programming Language by K&R
- Head First C Griffiths
- Classmates
- Man page
- Google

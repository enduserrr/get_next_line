# GET_NEXT_LINE

## Project Overview

The Get Next Line project was about creating a function that enables the reading of a line ending with a newline character ('\n') from a file descriptor without prior knowledge of its size.

With this project, I was introduced to the concept of static variables in C programming and delved deeper into memory manipulation, both on the stack and the heap.

## Testing

I implemented the project following The Norm V4 and thoroughly tested it using Francinette (--strict) as well as my own tests, both of which the program successfully passed.

Note:
With Francinette using the --strict tests, two timeouts may occurre when processing giant files with small buffers. However, these issues did not surface during my own testing, even with larger files.

## Useful resources

- [get_next_line explained](https://www.youtube.com/watch?v=8E9siq7apUU)
- ["everything is a file"](https://www.youtube.com/watch?v=-gP58pozNuM)
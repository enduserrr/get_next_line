Get_Next_Line

The Get Next Line project involves creating a function that enables the reading of a line ending with a newline character ('\n') from a file descriptor without prior knowledge of its size.

Throughout this project, I was introduced to the concept of static variables in C programming and delved deeper into memory manipulation, both on the stack and the heap.

I implemented the project following The Norm V4 and thoroughly tested it using Francinette (--strict) as well as my own tests, both of which the program successfully passed.

Note:
With Francinette using the --strict tests, two timeouts may occurre when processing giant files with small buffers. However, these issues did not surface during my own testing, even with larger files.
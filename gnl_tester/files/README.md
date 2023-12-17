Copy the get_next_line files into gnl_tester directory.
COMPILE: cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

- `main_argv.c` to input the desired file descriptors as command-line arguments (one or more for the bonuses).
- `main_gn(0)` to test the standard input (`get_next_line(0)`), in this case, the keyboard.

- `fortnite_mega.txt` consists of the word "fortnite" with a new line after every ten words (file size: 9 MB).
- `fortnite_mega_oneline.txt` consists of the word "fortnite" on a single line (file size: 900 KB).
- The `generate_fortnite.py` script generates files of specified size. (to run: `python generate_fortnite.py`)
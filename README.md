*This project has been created as part of the 42 curriculum by etasci.*

# 🟢 GetNextLine - 42 Kocaeli 🇹🇷

## 📝 Description
get_next_line is a C function that reads a file line by line.

- Each call returns the next line from a file descriptor.
- Works with any file size and multiple calls.
- Handles edge cases such as empty files, long lines, and files without a trailing newline.

---

## Instructions

### Files to Submit
- get_next_line.c
- get_next_line_utils.c
- get_next_line.h

### Helper Functions
- ft_strlen
- ft_strchr
- ft_strjoin
- ft_substr
- ft_strdup

---

## 🛠️ Compilation

Compile with a defined BUFFER_SIZE:

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

---

## ▶️ How to Use

1. Open a file using open()
2. Call get_next_line(fd) repeatedly
3. Each call returns one line
4. When finished, the function returns NULL

---

## ⚙️ Algorithm

The function uses a static variable to store remaining data between function calls.

1. Read from the file descriptor into a buffer of size BUFFER_SIZE
2. Append the buffer to a static string
3. Check for a newline character (\n)
4. If found:
   - Extract the line to return
   - Keep the remaining part for the next call
5. If not found:
   - Continue reading and appending
6. When EOF is reached:
   - Return remaining data or NULL

This approach ensures efficient reading and correct behavior across multiple calls.

---

## 🧪 Edge Cases

- Empty file → returns NULL
- Single line → returns line, then NULL
- No newline at end → line is still returned
- Only newline characters → returns empty lines
- Very long lines → handled correctly regardless of BUFFER_SIZE

---

## 📚 Resources

- POSIX read() documentation
- Stack Overflow discussions on buffer handling
- 42 intra materials

---

## 📌 Notes

- Memory management is handled properly (no leaks)
- Code follows 42 Norminette rules
- Only mandatory part implemented (no bonus)

---

## 🤖 AI Usage

AI tools were used in a limited way during this project:

- Understanding general concepts (file reading, buffering)
- Validating logic and edge cases

All code and implementation were written and tested independently.

# Line Editor

A simple command-line text editor built in C++ using linked lists to store each line separately. This editor allows users to create, modify, and save text files using intuitive commands.

## Features

- **File Handling**: Open an existing file or create a new one via the command line.
- **Linked List Storage**: Each line is stored as a separate node, enabling efficient insertion and deletion.
- **Text Manipulation**:
  - Insert new lines at specific positions.
  - Delete single lines or ranges of lines.
  - List full text or specific line ranges.
- **Save & Exit**:
  - Save changes (`E` command).
  - Exit without saving (`Q` command).

### Commands

<details>
  <summary>Click to expand command list</summary>

| Command | Description |
|---------|------------|
| `I <n>` | Insert a line at position `n` |
| `I` | Insert before current line |
| `L` | List entire content |
| `L <n>` | List line `n` and move to next line |
| `L <m> <n>` | List range from `m` to `n` |
| `D <n>` | Delete line `n` |
| `D <m> <n>` | Delete range from `m` to `n` |
| `D` | Delete previous line |
| `E` | Save changes & exit |
| `Q` | Exit without saving |

</details>


## Usage

Once in the projects folder, run:
```sh
./edit.exe <filename>


# Console Text Editor

A basic file editor program written in C that allows users to view and edit text files.

## Usage

- **Usage Instructions:**
  - When prompted, enter the name of the file you want to edit.
  - If the file doesn't exist, it will be created. Otherwise, the existing content will be displayed.
  - To add new content, enter text followed by pressing `Enter`.
  - Press `Ctrl+D` to save the changes and exit the editor.

## Example

```bash
Enter the name of the file: example.txt
File content:
Hello, this is an example file.

Enter new content (Press Ctrl+D to save and exit):
This is new content.

File saved and editor closed.
```

## Notes

- The program automatically creates the file if it doesn't exist.
- The editor allows you to view the current content and append new content to the file.
- Press `Ctrl+D` to save the changes and close the editor.

Feel free to modify the code and customize the README to better fit your project or provide additional information.

## How to Run

To run this program:

1. Make sure you have a C compiler installed on your computer.
2. Copy the code into a file with a `.c` extension, for example, `TextEditor.c`.
3. Open a terminal or command prompt and navigate to the directory where your file is located.
4. Compile the program by entering: `gcc TextEditor.c -o TextEditor`
5. Run the compiled program: `./TextEditor`

Or you can run this program also using:

```bash
   make TextEditor
```

---

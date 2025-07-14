# 🖥️ Windows Shell in C++

A simple custom shell (command-line interpreter) built using C++ for Windows. This program allows you to execute Windows commands (like notepad, calc, dir, etc.) and supports a built-in `cd` command to change the working directory.

## ✨ Features

- Basic shell prompt: `mysh>`
- Built-in support for `cd` command
- Executes Windows programs using `CreateProcessA`
- Uses `SetCurrentDirectory` from Windows API
- Handles command parsing and argument separation

## 💻 Technologies Used

- C++
- Windows API: `windows.h`, `CreateProcessA`, `SetCurrentDirectory`
- Visual Studio / VS Code (with cl.exe or g++ compiler)

## 🧪 How to Compile

You must be on Windows with a C++ compiler that supports Windows API:

### Option 1: Using cl (Visual Studio)

1. Open the "Developer Command Prompt for Visual Studio"
2. Navigate to the folder containing `shell.cpp`
3. Run:


### Option 2: Using g++ (MinGW-w64)

1. Open Command Prompt
2. Navigate to the folder containing `shell.cpp`
3. Run:
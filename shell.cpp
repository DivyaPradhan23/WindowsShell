#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

void parseCommand(const string &input, string &command, string &args) {
    size_t spacePos = input.find(' ');
    if (spacePos != string::npos) {
        command = input.substr(0, spacePos);
        args = input.substr(spacePos + 1);
    } else {
        command = input;
        args = "";
    }
}

int main() {
    string input;

    while (true) {
        cout << "mysh> ";
        getline(cin, input);

        if (input.empty()) continue;
        if (input == "exit") break;

        string command, arguments;
        parseCommand(input, command, arguments);

        // Handle built-in 'cd'
        if (command == "cd") {
            if (!arguments.empty()) {
                if (!SetCurrentDirectory(arguments.c_str())) {
                    cerr << "cd failed: Invalid path\n";
                }
            } else {
                cerr << "cd: missing operand\n";
            }
            continue;
        }

        // Create the full command line string
        string cmdLine = command + " " + arguments;

        // Convert to LPSTR
        char cmdBuffer[1024];
        strncpy(cmdBuffer, cmdLine.c_str(), sizeof(cmdBuffer));
        cmdBuffer[sizeof(cmdBuffer) - 1] = '\0';

        STARTUPINFOA si = { sizeof(si) };
        PROCESS_INFORMATION pi;

        BOOL success = CreateProcessA(
            NULL,           // Application name
            cmdBuffer,      // Command line
            NULL, NULL,     // Process and thread attributes
            FALSE,          // Inherit handles
            0,              // Creation flags
            NULL,           // Environment
            NULL,           // Current directory
            &si, &pi        // Startup and process info
        );

        if (!success) {
            cerr << "Failed to execute command\n";
        } else {
            // Wait for the process to complete
            WaitForSingleObject(pi.hProcess, INFINITE);
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
        }
    }

    return 0;
}

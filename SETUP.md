# VS Code Setup Guide for Ubuntu

This guide will help you set up Visual Studio Code on Ubuntu for working with this repository.

## Prerequisites

- Ubuntu 18.04 or later
- Internet connection
- Terminal access

## Installing VS Code on Ubuntu

### Method 1: Using Snap (Recommended)

The easiest way to install VS Code on Ubuntu is through Snap:

```bash
sudo snap install --classic code
```

### Method 2: Using apt package manager

1. Update the package index and install dependencies:
```bash
sudo apt update
sudo apt install software-properties-common apt-transport-https wget
```

2. Import the Microsoft GPG key:
```bash
wget -q https://packages.microsoft.com/keys/microsoft.asc -O- | sudo apt-key add -
```

3. Enable the VS Code repository:
```bash
sudo add-apt-repository "deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main"
```

4. Install VS Code:
```bash
sudo apt update
sudo apt install code
```

### Method 3: Download .deb package

1. Download the .deb package from [VS Code website](https://code.visualstudio.com/Download)
2. Install using dpkg:
```bash
sudo dpkg -i code_*.deb
sudo apt-get install -f
```

## Setting Up the Development Environment

### 1. Clone the Repository

```bash
git clone https://github.com/shanur00/shanur00.github.io.git
cd shanur00.github.io
```

### 2. Open in VS Code

```bash
code .
```

### 3. Install Recommended Extensions

When you open the project, VS Code should prompt you to install recommended extensions. Click "Install All" to install them.

Alternatively, you can install them manually:

#### For C/C++ Development (DSA folder)
```bash
code --install-extension ms-vscode.cpptools
code --install-extension ms-vscode.cmake-tools
```

#### For Web Development (HTML/CSS/JavaScript)
```bash
code --install-extension dbaeumer.vscode-eslint
code --install-extension esbenp.prettier-vscode
code --install-extension formulahendry.auto-close-tag
code --install-extension formulahendry.auto-rename-tag
```

#### For React/JSX Development
```bash
code --install-extension dsznajder.es7-react-js-snippets
code --install-extension msjsdiag.vscode-react-native
```

#### Additional Helpful Extensions
```bash
code --install-extension ritwickdey.liveserver
code --install-extension ms-vscode.live-server
code --install-extension christian-kohler.path-intellisense
```

### 4. Install Required Compilers and Tools

#### For C/C++ Development
```bash
sudo apt update
sudo apt install build-essential gdb
```

Verify installation:
```bash
gcc --version
g++ --version
gdb --version
```

#### For Web Development
No additional tools are required for basic HTML/CSS/JavaScript development. However, for a better development experience:

```bash
# Install Node.js and npm (optional, for advanced tooling)
sudo apt install nodejs npm
```

## Compiling and Running Code

### C/C++ Files (in dsa/ folder)

#### Compile a C file:
```bash
gcc dsa/reverseLinkedList.c -o reverseLinkedList
./reverseLinkedList
```

#### Compile a C++ file:
```bash
g++ dsa/ipToDecimal.cpp -o ipToDecimal
./ipToDecimal
```

#### Compile with debugging information:
```bash
gcc -g dsa/reverseLinkedList.c -o reverseLinkedList
gdb ./reverseLinkedList
```

### HTML Files

For HTML files, you can:

1. **Use Live Server extension**: Right-click on an HTML file and select "Open with Live Server"
2. **Open in browser**: Right-click on an HTML file and select "Open in Default Browser"
3. **Use Python's built-in server**:
```bash
python3 -m http.server 8000
# Then open http://localhost:8000 in your browser
```

## VS Code Keyboard Shortcuts (Ubuntu)

- `Ctrl + Shift + P`: Command Palette
- `Ctrl + P`: Quick Open File
- `Ctrl + B`: Toggle Sidebar
- `Ctrl + J`: Toggle Terminal
- `Ctrl + Shift + E`: Explorer
- `Ctrl + Shift + F`: Search across files
- `F5`: Start Debugging
- `Ctrl + Shift + B`: Run Build Task
- `Ctrl + /`: Toggle Line Comment
- `Alt + Up/Down`: Move line up/down
- `Ctrl + D`: Select next occurrence

## Troubleshooting

### VS Code won't start
```bash
# Try removing the GPU acceleration flag
code --disable-gpu
```

### C/C++ IntelliSense not working
1. Install the C/C++ extension
2. Press `Ctrl + Shift + P` and run "C/C++: Edit Configurations (UI)"
3. Ensure compiler path is set correctly (usually `/usr/bin/gcc` or `/usr/bin/g++`)

### Extensions won't install
```bash
# Clear VS Code cache
rm -rf ~/.vscode/extensions
rm -rf ~/.config/Code
```

## Additional Resources

- [VS Code Documentation](https://code.visualstudio.com/docs)
- [VS Code on Linux](https://code.visualstudio.com/docs/setup/linux)
- [C/C++ in VS Code](https://code.visualstudio.com/docs/languages/cpp)
- [HTML in VS Code](https://code.visualstudio.com/docs/languages/html)
- [JavaScript in VS Code](https://code.visualstudio.com/docs/languages/javascript)

## Project Structure

```
.
├── dsa/                    # Data Structures & Algorithms (C/C++)
├── flutter/               # Flutter examples
├── module-01/             # Web module 1
├── module-02/             # Web module 2 (includes requirements)
├── module-03/             # React/JSX examples
├── wave.html             # Wave animation
└── README.md             # Project README
```

## Contributing

When contributing to this repository, please ensure:
1. C/C++ code compiles without warnings
2. HTML files are valid
3. Code follows consistent formatting
4. Test your changes before committing

## Need Help?

If you encounter any issues with the setup, please open an issue on the GitHub repository.

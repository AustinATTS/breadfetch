# breadfetch

A system fetch tool, similar to fastfetch or neofetch, but breadier! Written with Carbon language principles in mind, using C++ interop for system calls.

## About

breadfetch is a lightweight system information tool that displays your system configuration in a clean, bread-themed format. It's designed to work on Linux platforms, with primary focus on Arch and Ubuntu distributions.

## Features

- Beautiful bread-themed ASCII art banner
- System information display including:
    - User and hostname
    - Operating System
    - Kernel version
    - System uptime
    - Shell
    - CPU information
    - Memory usage
    - Architecture
- Colourful terminal output
- Fast and lightweight
- Written with Carbon/C++ interop principles

## Carbon Language Integration

This project demonstrates Carbon language design patterns with C++ interoperability:
- **`src/main.carbon`** - Carbon language version (reference implementation)
- **`src/main.cc`** - C++ implementation that Carbon would compile to
- **C++ modules** - Core functionality that Carbon interfaces with

Carbon is an experimental language being developed by Google as a potential C++ successor. This project is structured to be ready for Carbon compilation once the toolchain is stable.

## Building

### Prerequisites

- C++ compiler (g++ or clang++)
- Make or CMake
- Linux operating system

### Build with Make

```bash
make
```

### Build with CMake

```bash
mkdir build
cd build
cmake ..
make
```

## Installation

### Quick Install (Recommended)

```bash
./install.sh
```

This will build and install breadfetch to:
- `/usr/local/bin/` (if run with sudo)
- `~/.local/bin/` (if run as normal user)

### From Source

```bash
make
sudo make install
```

This will install breadfetch to `/usr/local/bin/`.

### Manual Installation

```bash
make
sudo cp breadfetch /usr/local/bin/
```

## Usage

Simply run:

```bash
breadfetch
```

## Uninstallation

### Quick Uninstall

```bash
./uninstall.sh
```

### Manual Uninstall

```bash
sudo make uninstall
```

Or manually:

```bash
sudo rm /usr/local/bin/breadfetch
```

## Platform Support

- Ubuntu (tested on 24.04 LTS)
- Arch Linux
- Other Linux distributions (should work on most systemd-based distros)

## Project Structure

```
breadfetch/
├── include/           # Header files
│   ├── system_info.h # System information gathering
│   └── display.h     # Display and formatting
├── src/              # Source files
│   ├── main.cc       # C++ main implementation
│   ├── main.carbon   # Carbon reference implementation
│   ├── system_info.cc 
│   └── display.cc 
├── CMakeLists.txt    # CMake build configuration
├── Makefile          # Make build configuration
└── README.md         # This file
```

## Development

### Future Carbon Integration

When the Carbon compiler becomes stable, the project can be built using:

```bash
# Future Carbon build command (when available)
carbon build src/main.carbon
```

The current C++ implementation serves as the Carbon interop layer and demonstrates the intended architecture.

## Contributing

Contributions are welcome! Please feel free to submit pull requests or open issues.

## License

See the LICENSE file for details.

## Acknowledgments

Inspired by:
- neofetch
- fastfetch
- Carbon Language Project

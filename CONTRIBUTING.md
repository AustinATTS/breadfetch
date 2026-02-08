# Contributing to breadfetch

Thank you for your interest in contributing to breadfetch! This document provides guidelines for contributing to the project.

## Getting Started

1. Fork the repository
2. Clone your fork: `git clone https://github.com/YOUR_USERNAME/breadfetch.git`
3. Create a new branch: `git checkout -b feature/your-feature-name`

## Development Setup

### Prerequisites
- C++ compiler (g++ 7.0+ or clang++ 5.0+)
- Make or CMake
- Linux environment (Ubuntu, Arch, or similar)

### Building
```bash
make clean
make
```

Or with CMake:
```bash
mkdir build && cd build
cmake ..
make
```

### Testing
```bash
./breadfetch
```

## Code Style

### C++ Style Guidelines
- Follow modern C++26 standards
- Use descriptive variable names
- Keep functions focused and small
- Add comments for complex logic
- Use const correctness

### Carbon Style Guidelines
- Follow Carbon language style guide
- Keep Carbon code in sync with C++ implementation
- Use meaningful package and function names

## Adding New Features

### System Information
To add a new system information field:

1. Add a static method to `SystemInfo` class in `include/system_info.h`:
```cc
static std::string GetNewInfo ( );
```

2. Implement the method in `src/system_info.cc`:
```cc
std::string SystemInfo::GetNewInfo ( ) {
    // Implementation
    return "value";
}
```

3. Display it in both `src/main.cc` and `src/main.carbon`:
```cc
breadfetch::Display::PrintInfo("Label", breadfetch::SystemInfo::GetNewInfo());
```

### Display Changes
To modify the display:

1. Update methods in `include/display.h` and `src/display.cc`
2. Test the output to ensure proper alignment and colouring

## Commit Guidelines

- Use clear, descriptive commit messages
- Start with a verb: "Add", "Fix", "Update", "Remove"
- Keep commits focused on a single change
- Examples:
    - "Add GPU information display"
    - "Fix memory calculation for large RAM"
    - "Update ASCII art banner"

## Pull Request Process

1. Ensure your code builds without warnings
2. Test the application on your system
3. Update README.md if adding new features
4. Update CARBON.md if changing Carbon interop
5. Create a pull request with a clear description

### PR Description Template
```
## What does this PR do?
Brief description of changes

## Why is this needed?
Explain the motivation

## How has this been tested?
Describe testing done

## Screenshots (if applicable)
Add screenshots of output changes
```

## Reporting Issues

When reporting issues, please include:
- Operating system and version
- Compiler version
- Steps to reproduce
- Expected vs actual behaviour
- Error messages (if any)

## Platform Support

Currently supported:
- Ubuntu 20.04+
- Arch Linux
- Other systemd-based Linux distributions

When adding features, ensure they work on both Ubuntu and Arch.

## Code of Conduct

- Be respectful and constructive
- Help others learn and grow
- Focus on what's best for the project
- Accept constructive criticism gracefully

## Questions?

Feel free to open an issue for questions or discussions about contributing!

## License

By contributing, you agree that your contributions will be licensed under the same licence as the project (see LICENSE file).
# clip 📋

A lightning-fast, cross-platform command-line utility that copies file contents directly to your system clipboard.

## Overview

**clip** is a simple yet powerful tool that bridges the gap between your terminal and clipboard. Whether you're working with code snippets, configuration files, or any text content, clip makes it effortless to get file contents into your clipboard with a single command.

### Key Features

- **Cross-platform**: Works seamlessly on macOS, Linux, and Windows
- **Fast**: Minimal overhead, maximum performance
- **Simple**: One command, endless possibilities
- **Lightweight**: No dependencies, just pure C efficiency

## Installation

### Prerequisites

- A C compiler (GCC, Clang, or MSVC)
- Either Meson or CMake build system
- Git (for cloning the repository)

### Building from Source

#### Using Meson (Recommended)

```bash
# Clone the repository
git clone https://github.com/demirom/clip.git
cd clip

# Build with Meson
meson setup builddir
meson compile -C builddir
```

#### Using CMake

```bash
# Clone the repository
git clone https://github.com/demirom/clip.git
cd clip

# Build with CMake
mkdir build && cd build
cmake ..
make
```

### Installation

After building, install the binary to your system:

```bash
# On Unix-like systems
sudo make install

# Or copy manually to your PATH
cp clip /usr/local/bin/
```

## Usage

Using clip is incredibly straightforward:

```bash
clip <filename>
```

### Examples

Copy a source file to clipboard:
```bash
clip main.c
```

Copy configuration file contents:
```bash
clip ~/.bashrc
```

Copy any text file:
```bash
clip README.md
```

### Error Handling

- If the file doesn't exist, clip will display an error message
- If the file is binary or too large, clip will warn you appropriately
- Empty files are handled gracefully

## Platform Support

| Platform | Status | Notes |
|----------|--------|-------|
| macOS    | ✅ Supported | Uses `pbcopy` integration |
| Linux    | ✅ Supported | Uses X11/Wayland clipboard |
| Windows  | ✅ Supported | Uses Windows Clipboard API |

## Contributing

Contributions are welcome! Please feel free to:

- Report bugs
- Suggest new features
- Submit pull requests
- Improve documentation

### Development Setup

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test across platforms
5. Submit a pull request

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Support the Project

If you find clip useful, consider supporting its development:

☕ **[Buy me a coffee on Ko-fi](https://ko-fi.com/demilovato)**

Your support helps maintain and improve this project!

---

**Made with ❤️ for developers who love efficient workflows**

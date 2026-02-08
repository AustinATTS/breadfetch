#!/bin/bash
# Installation script for breadfetch

set -e

echo "╔════════════════════════════════════════╗"
echo "║     breadfetch Installation Script     ║"
echo "╚════════════════════════════════════════╝"
echo ""

# Check if running as root for system-wide install
if [ "$EUID" -eq 0 ]; then
  INSTALL_DIR="/usr/local/bin"
  echo "Installing to system directory: $INSTALL_DIR"
else
  INSTALL_DIR="$HOME/.local/bin"
  echo "Installing to user directory: $INSTALL_DIR"
  mkdir -p "$INSTALL_DIR"
fi

# Build the project
echo ""
echo "Building breadfetch..."
make clean
make

if [ ! -f "./breadfetch" ]; then
  echo "Error: Build failed. breadfetch executable not found."
  exit 1
fi

# Install
echo ""
echo "Installing breadfetch to $INSTALL_DIR..."
cp breadfetch "$INSTALL_DIR/"
chmod +x "$INSTALL_DIR/breadfetch"

# Check if install directory is in PATH
if [[ ":$PATH:" != *":$INSTALL_DIR:"* ]]; then
  echo ""
  echo "Warning: $INSTALL_DIR is not in your PATH"
  echo "  Add this line to your ~/.bashrc or ~/.zshrc:"
  echo "  export PATH=\"\$PATH:$INSTALL_DIR\""
fi

echo ""
echo "Installation complete!"
echo ""
echo "Run 'breadfetch' to see your system information!"
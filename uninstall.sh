#!/bin/bash

set -e

echo "╔════════════════════════════════════════╗"
echo "║   breadfetch Uninstallation Script     ║"
echo "╚════════════════════════════════════════╝"
echo ""

SYSTEM_INSTALL="/usr/local/bin/breadfetch"
USER_INSTALL="$HOME/.local/bin/breadfetch"

removed=false

if [ -f "$SYSTEM_INSTALL" ]; then
    if [ "$EUID" -eq 0 ]; then
        echo "Removing from system directory..."
        rm -f "$SYSTEM_INSTALL"
        removed=true
    else
        echo "System installation found at $SYSTEM_INSTALL"
        echo "Run with sudo to remove: sudo $0"
    fi
fi

if [ -f "$USER_INSTALL" ]; then
    echo "Removing from user directory..."
    rm -f "$USER_INSTALL"
    removed=true
fi

if [ "$removed" = true ]; then
    echo ""
    echo "breadfetch has been uninstalled"
else
    echo ""
    echo "breadfetch installation not found"
fi
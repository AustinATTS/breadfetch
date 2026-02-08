# Carbon Integration Guide

## About Carbon Language

Carbon is an experimental programming language being developed by Google as a potential successor to C++. It's designed to:
- Provide modern language features
- Offer seamless C++ interoperability
- Maintain high performance
- Support gradual migration from C++

## Project Structure for Carbon Interop

This project demonstrates Carbon/C++ interoperability patterns:

### Carbon File (`src/main.carbon`)
The Carbon implementation shows how the application would be written in Carbon:
- Uses `import Cpp` to access C++ libraries
- Calls C++ functions through the interop layer
- Demonstrates Carbon syntax and package structure

### C++ Implementation
The C++ files serve dual purposes:
1. **Current Implementation**: Fully functional system fetch tool
2. **Carbon Interop Layer**: Will be interfaced by Carbon code when compiled

```
include/
├── system_info.h    # C++ header for system information gathering
└── display.h        # C++ header for display and formatting

src/
├── main.carbon      # Carbon main (reference implementation)
├── main.cc          # C++ main (current implementation)
├── system_info.cc   # C++ implementation (Carbon will interop with this)
└── display.cc       # C++ implementation (Carbon will interop with this)
```

## Building (Current)

Since Carbon toolchain is not yet stable, the project currently builds using C++:

```bash
make
```

## Future Carbon Build

When Carbon becomes production-ready, the build process will be:

```bash
# Example future Carbon build command
carbon build src/main.carbon --cpp-interop
```

The Carbon compiler will:
1. Parse `main.carbon`
2. Generate C++ interop code
3. Link with existing C++ modules (`system_info.cc`, `display.cc`)
4. Produce the final executable

## Carbon Syntax Highlights

From `src/main.carbon`:

```carbon
// Package declaration
package BreadFetch api;

// C++ library imports
import Cpp library "system_info.h";
import Cpp library "display.h";

// Main function
fn Main ( ) -> i32 {
    // Call C++ functions through interop
    Cpp.breadfetch.Display.PrintBanner();
    
    // Variables with type inference
    var username: auto = Cpp.breadfetch.SystemInfo.GetUsername();
    
    return 0;
}
```

## Why This Design?

1. **Ready for Carbon**: The architecture is prepared for Carbon migration
2. **Functional Now**: Works with current C++ compilers
3. **Learning Resource**: Demonstrates Carbon interop patterns
4. **Migration Path**: Shows how to gradually adopt Carbon

## Resources

- [Carbon Language](https://github.com/carbon-language/carbon-lang)
- [Carbon Documentation](https://github.com/carbon-language/carbon-lang/tree/trunk/docs)
- [C++ Interop Design](https://github.com/carbon-language/carbon-lang/blob/trunk/docs/design/interoperability.md)

## Contributing

When contributing, please:
- Keep the Carbon reference implementation in sync with C++ changes
- Follow Carbon syntax guidelines in `.carbon` files
- Ensure C++ code remains interop-friendly (avoid advanced templates, use simple types)
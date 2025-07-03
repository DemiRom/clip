# clip

The most basic command line clipboard utility. With no code dependencies.

*Some linux distros may not include xclip which is used by this program, be sure to have it installed*

Usage: clip <some file>

## Building

Need the basic C build environment, with meson and ninja or make.
- gcc, or clang
- ninja or make
- meson

All can be found within your respective package distributor.

### On *nix environments (Linux, macOS)
```
meson setup build
meson install -C build
```

On Windows

*You may have trouble getting meson installed on Windows, might be worth using cmake or a batch file to compile and install it but if you already have meson the same commands should work*

```
meson setup build
meson install -C build
```

Enjoy!

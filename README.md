# About SDL-Playground
A small project to get acquainted with the SDL library in C and C++


# Getting Started

## Dependencies
Obviously, this project primarily relies on the SDL2 library.
This project also uses the vcpkg package manager and CMake alongside the clangd compiler.

Check to make sure you have CMake on your system with 
```bash
> cmake --version
```
or download it (here)[https://cmake.org/download/].

## Installing vcpkg and SDL2
First, install and configure the vcpkg C++ Library manager. Microsoft recommends installing vcpkg as a submodule
of the repo/project so I have installed vcpkg into the directory above the SDL-Playground project directory:


```
Parent Directory (C projects)
    ├── vcpkg
    │   └── ...
    │
    │
    └── SDL-Playgound <- This repo
        ├── build
        │   └── Debug
        └── src
        .
        .
```
`NOTE`: I recommend including a directory to store and organize your C/C++ projects in and installing vcpkg into here

Next, install vcpkg as below or follow Microsoft's instructions (here)[https://github.com/microsoft/vcpkg?tab=readme-ov-file#getting-started]

```bash
> git clone https://github.com/microsoft/vcpkg
> .\vcpkg\bootstrap-vcpkg.bat
```

Now, we install the SDL2 library with vcpkg using the `install` command. Microsoft offers the ability to configure project dependencies through (a json file)[https://learn.microsoft.com/en-us/vcpkg/get_started/get-started?pivots=shell-cmd#3---add-dependencies-and-project-files] but I choose the cmdline.

For windows, I used the SDL2 x64 static library:

```bash
> ./vcpkg/vcpkg install sdl2:x64-windows-static
```

<!-- TODO: Write this -->

<!-- For Unix/Linux: -->
<!---->
<!-- ```bash -->
<!-- ``` -->

To make the rest of the build scripts play nice, be sure to configure the environment variable to your vcpkg directory:

In windows:
```bash
> $env:VCPKG_ROOT="C:\path\to\vcpkg"
```
NOTE: Microsoft recommends using `set` to set this, although this didn't work for me. Regardless, be aware of whether this environment variable persists after the session or you will have to redo this.

<!-- TODO: Write Unix/Linux version -->

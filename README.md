A small project being used to learn the basics of graphics programming. Currently a work in progress and extremely simple.

![hello](demo.png)

### Instructions
#### Clone the repo and submodules
``` bash
git clone https://github.com/floono/paint_tool.git
git submodule update --init --recursive
```
#### Build with CMake
``` bash
cmake -B build
cmake --build build
```
#### Run the executable from the root directory of the project

### Future ideas (cpp_conversion branch)
- Convert the project to C++
  - Allows use of imgui library without API bindings
  - Features of C++ STDLIB will be extremely helpful
  - OOP fits well
- Learn how to use additional framebuffers through frame buffer objects (FBO)
  - Helpful for an undo/redo system
  - Post-processing
  - Layering system
- Create UI with imGui
- Use stb_image.h to save current framebuffer in viewport as an image (png)
- Add additional drawing tools

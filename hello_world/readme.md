#

To build the program:

```bash
mkdir build && cd build
cmake ../  -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release --target hello_world --clean-first
```

To run the program:

```bash
hello_world/hello_world
```

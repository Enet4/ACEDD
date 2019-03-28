# ACEDD

## Building

```sh
mkdir build
cd build
cmake ..
make 
```

This will build the following targets:

- `ACEDD_APP`: from the original repository, loads two images and measures their similarity
- `ACEDD_EXTRACT`: loads an image and outputs the ACEDD bins
- `libACEDD.a`: static library
- `libACEDD_c.so`: dynamic library with C API bindings

The C API is declared in [c_api/acedd_c.h](c_api/acedd_c.h).

## License

MIT

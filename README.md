# Crossplatform Neural Network

## Aim

The aim of a project is to make neural network, that computes elastic constants of anisotropic laminated plates using elastic waves.

## Compilation

CNN uses [CMake](http://www.cmake.org/) for project building. On *nix system it is pretty easy to build CNN library.
All you need is

	mkdir Build
	cd Build
	cmake ..
	make

For other systems run CMake gui and follow instructions.

## Documentation

CNN uses [Doxygen](http://www.doxygen.org) for documentation generation. `Doxyfile` is in `Doc` directory.
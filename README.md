# FORT500 Compiler

This repository hosts the development of a compiler for FORT500, a high-level language resembling FORTRAN with structured commands and record structures, supporting recursive subprogram definition.

## Overview
The FORT500 compiler project aims to implement both a lexical analyzer (LA) and a syntax analyzer (SA) for the FORT500 language. The SA is called once to determine syntactic correctness, while the LA is invoked iteratively by the SA to parse the input program into lexical units (LUs).

## Repository Structure
- `src/`: Contains source code for the FORT500 compiler.
- `docs/`: Documentation related to the project.
- `examples/`: Sample FORT500 programs for testing and demonstration purposes.

## Usage
1. Clone the repository: `git clone https://github.com/your-username/fort500-compiler.git`
2. Navigate to the project directory: `cd fort500-compiler`
3. Build the compiler.
4. Execute the compiler with a FORT500 source file as input: `./fort500-compiler <input_file.f500>`

## Contribution Guidelines
Contributions are welcome! Please refer to the [contribution guidelines](CONTRIBUTING.md) for more information on how to contribute to this project.

## License
This project is licensed under the [MIT License](LICENSE).

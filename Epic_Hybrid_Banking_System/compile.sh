#!/bin/bash

# Compile Fortran backend to shared library
gfortran -shared -fPIC -o libepicbank.dylib epic_bank_engine.f90

# Find gfortran library path
GFORTRAN_LIB=$(gfortran -print-file-name=libgfortran.dylib)
GFORTRAN_DIR=$(dirname "$GFORTRAN_LIB")

# Compile C++ frontend and link with Fortran library
g++ -o epicbank ch10exercise21_take7.cpp -L. -lepicbank -L"$GFORTRAN_DIR" -lgfortran

# Run the program
./epicbank

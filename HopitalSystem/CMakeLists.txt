cmake_minimum_required(VERSION 3.16)
project(COEN244_Ass4)

set(CMAKE_CXX_STANDARD 14)

add_executable(COEN244_Ass4 main.cpp Time.h Date.h Person.h Doctor.cpp Doctor.h InPatient.cpp InPatient.h Patient.h Bed.h OutPatient.cpp OutPatient.h Hospital.cpp Hospital.h)
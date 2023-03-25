#!/bin/bash
source /opt/intel/oneapi/setvars.sh > /dev/null 2>&1
/bin/echo "##" $(whoami) is compiling DPCPP_Essentials Module2 -- SYCL Program Structure sample - 7 of 7 vector_add.cpp
icpx -fsycl ./vector-add-n-sub.cpp
if [ $? -eq 0 ]; then ./a.out; fi

# I must run this script with this file called "q" in the same director as the file that I am trying to run, and the
# below command is the command that I need to use to do what's being mentioned above.
# ! chmod 755 q; chmod 755 run_vector_add.sh; if [ -x "$(command -v qsub)" ]; then ./q run_vector_add.sh; else ./run_vector_add.sh; fi
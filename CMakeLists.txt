cmake_minimum_required(VERSION 3.16)
project(DSALabAssignments LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Collect all shared source files from the global src/ directory
file(GLOB_RECURSE SHARED_SOURCES "src/*.cpp")

# 2. Add global include directory so all main.cpp files can find headers in include/
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# ==========================================
# ASSIGNMENT 1 TARGETS
# ==========================================

# Question 1: Coin Toss
add_executable(assign1_q1 
    Assignment1/cpp/q1_coinToss/main.cpp 
    ${SHARED_SOURCES}
)

# Question 2: Bubble Sort
add_executable(assign1_q2 
    Assignment1/cpp/q2_bubbleSort/main.cpp 
    ${SHARED_SOURCES}
)

# Question 3: Quick Sort & Hybrid Sort
add_executable(assign1_q3 
    Assignment1/cpp/q3_quickSort/main.cpp 
    ${SHARED_SOURCES}
)

# ==========================================
# (Optional) Future Assignments can go here:
# ==========================================
# add_executable(assign2_q1 Assignment2/cpp/q1_someProblem/main.cpp ${SHARED_SOURCES})
# Development Log & Workflow Documentation — DSA Lab Assignments

This log records the CMake configuration process, build commands, and execution instructions for the modular C++ and MATLAB laboratory assignments at NIT Rourkela.

---

## 🛠️ CMake Command Reference

Below is a breakdown of the core CMake commands used throughout the development of this repository and their respective uses:

### 1. Configuration & Project Generation
```bash
cmake -B build -S . -DCMAKE_BUILD_TYPE=Release

---

### 2. Compilation & Building Targets
cmake --build build


### Execute the Target Binary
.\build\assign1_q1.exe
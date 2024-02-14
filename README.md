# cpp_calculator
Just a project for the C++ Portfolio...


## Roadmap:

### Version 1: Proof of Concept -- Current version
Simple Terminal program, that handles: +, -, * and /. 

OS: Windows 10
IDE: VSC with CLangd, and MSVC debugger.
CMake: 3.23
Compiler: MSVC 2022

OS: Linux 
UNTESTED

### Version 2: GUI
Move from a terminal based program to a simple GUI program.

Plan:
- Terminal is used for application messages and not user interation
- Add fmt library for messages in Terminal window 
- Use GLFW library for the initial window creation
- UI Library: ImGUI, Nuklear, RmlUi -- need to determine which to use, each has their pros and cons
- Build a 'numpad' UI interface for the calculator

### Version 3: TBD

### List of Features would like to see in the program, but not yet slotted someplace in the road map:
- Additional operators: (), {}, ^, sqrt, log, ln, sin, cos, tan, arcsin, arccos, arctan, etc...
- Additional windowing options: WIN32 API, Linux?
- Graphs
- Variables
- Integrals, Derivatives
- Load and save formulas, problems
- History, use previous results

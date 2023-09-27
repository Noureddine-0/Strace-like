# Strace-like: x86_64 System Call Tracer

## Introduction

Strace-like is a program designed to emulate strace functionality specifically for x86_64 architecture. It allows users to trace system calls made by processes running on x86_64 machines. The tool provides valuable insights into the interactions between processes and the operating system, aiding in debugging, profiling, and comprehending program behavior.

## Features

- **x86_64 Architecture Support**: Strace-like is built to work specifically on x86_64 architecture, ensuring precise tracing and monitoring of system calls on this platform.

- **System Call Tracing**: Strace-like provides the ability to trace and monitor system calls made by processes, allowing users to analyze the behavior of the software and identify potential issues.

- **Debugging and Profiling**: Strace-like aids in debugging by providing real-time insights into system calls, helping users diagnose errors and performance bottlenecks. It also supports profiling to optimize software performance.

## Future roadmap

- **Catching signal**: For this time , strace-like is uncapable of managing signals , sooner it will be .


## Usage

To use Strace-like, follow these steps:

1. **Clone the Repository**: Clone the Strace-like repository from GitHub using Git:
   ```bash
   git clone https://github.com/Noureddine-0/strace-like.git
   ```
2. **Navigate to Strace-like directory**:
   ```bash
   cd Strace-like
   ```
3. **Build the Strace-like executable**: To build Strace-like from the source code, just execute the command:

  ```bash
  make
  ```

4. **Run Strace-like**: Execute Strace-like followed by the program you want to trace, specifying any required arguments. For example:
   ```bash
   ./emutrace ./your_program arg1 arg2
   ```
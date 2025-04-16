# EmbedSense RTOS Scheduler Simulator

EmbedSense RTOS Scheduler Simulator is a modular simulation of a real-time operating system (RTOS) scheduler designed for embedded systems. This project implements the Rate Monotonic Scheduling (RMS) algorithm to simulate periodic task releases and executions. It serves as a foundational framework to experiment with various scheduling algorithms and understand the dynamics of task management in an RTOS environment.

## Features

- **Rate Monotonic Scheduling (RMS):**  
  Prioritizes tasks based on their period, where tasks with shorter periods are given higher priority.
  
- **Modular Design:**  
  Organized into separate modules for tasks, scheduling, and simulation logic, making it easy to extend and maintain.
  
- **Extendability:**  
  Framework can be extended to support additional scheduling algorithms such as Earliest Deadline First (EDF).

- **Simulation Logging:**  
  Provides real-time console output of task scheduling decisions and system states.

## Directory Structure

EmbedSense/ ├── include/ │ ├── task.h │ └── scheduler.h └── src/ ├── task.cpp ├── scheduler.cpp └── main.cpp


## Build and Run Instructions

### Prerequisites

- A C++ compiler that supports C++11 (e.g., GCC, Clang)
- [Make](https://www.gnu.org/software/make/) (optional, if you prefer using the provided Makefile)

### Using the Command Line

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/yppaarth/EmbedSense.git
   cd EmbedSense_RTOSEmulator

2. **Compile the Project:**
  Run the following command in the root directory:
  g++ -std=c++11 -Iinclude -o RTOS_Simulator src/main.cpp src/scheduler.cpp src/task.cpp

3. **Run the Executable:**
   Execute the compiled binary:

   ./RTOS_Simulator

### Using the Makefile
1. **Build the Project:**

   make


2. **Run the Simulator:**
  ./RTOS_Simulator


3. **Clean the Build Files:**
   make clean

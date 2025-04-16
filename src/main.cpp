#include <iostream>
#include "scheduler.h"

int main() {
    // Create a Scheduler instance.
    Scheduler scheduler;

    // Add tasks to the scheduler.
    // Each task is defined by: id, period (time between releases), execution time (time units required)
    scheduler.addTask(Task("Task1", 5, 2));  // Releases every 5 time units; needs 2 time units of execution.
    scheduler.addTask(Task("Task2", 10, 3)); // Releases every 10 time units; needs 3 time units.
    scheduler.addTask(Task("Task3", 7, 1));  // Releases every 7 time units; needs 1 time unit.

    // Total simulation time (in time units)
    const int simulationTime = 30;

    // Simulate the time ticks.
    for (int currentTime = 0; currentTime <= simulationTime; currentTime++) {
        std::cout << "Time: " << currentTime << std::endl;
        
        // Check if any task needs to be released at the current time.
        scheduler.checkAndReleaseTasks(currentTime);

        // Select the next task to run using Rate Monotonic Scheduling.
        Task* taskToRun = scheduler.scheduleNextTask();

        // If a task is ready, execute it for 1 time unit; otherwise, the CPU is idle.
        if (taskToRun != nullptr) {
            std::cout << "Executing " << taskToRun->getId() << std::endl;
            taskToRun->execute(1);
        } else {
            std::cout << "CPU Idle" << std::endl;
        }
        std::cout << "-----------------------------" << std::endl;
    }

    return 0;
}

#include "scheduler.h"
#include <limits>

Scheduler::Scheduler(SchedulingAlgorithm algorithm)
    : schedulingAlgorithm(algorithm)
{
}

// Adds a task to the scheduler's task list.
void Scheduler::addTask(const Task &task) {
    tasks.push_back(task);
}

// Iterate through tasks and release them if it's time based on currentTime.
void Scheduler::checkAndReleaseTasks(int currentTime) {
    for (auto &task : tasks) {
        task.release(currentTime);
    }
}

// Implements a simple Rate Monotonic Scheduling (RMS) algorithm:
// Selects the active task with the smallest period (highest priority).
Task* Scheduler::scheduleNextTask() {
    Task* selectedTask = nullptr;
    int highestPriorityPeriod = std::numeric_limits<int>::max();

    for (auto &task : tasks) {
        // Check if the task is active and has remaining execution time.
        if (task.isReleased() && task.getRemainingTime() > 0 && task.getPeriod() < highestPriorityPeriod) {
            selectedTask = &task;
            highestPriorityPeriod = task.getPeriod();
        }
    }
    return selectedTask;
}

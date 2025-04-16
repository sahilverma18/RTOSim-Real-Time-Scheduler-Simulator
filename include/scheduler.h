#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "task.h"

// Enumeration to support different scheduling algorithms.
enum SchedulingAlgorithm {
    RATE_MONOTIC,
    EARLIEST_DEADLINE_FIRST
};

class Scheduler {
public:
    // Constructor accepts a scheduling algorithm. Default is Rate Monotonic.
    Scheduler(SchedulingAlgorithm algorithm = RATE_MONOTIC);

    // Add a task to the scheduler.
    void addTask(const Task &task);

    // Check and release tasks based on the current simulation time.
    void checkAndReleaseTasks(int currentTime);

    // Schedule the next task to run based on the selected scheduling algorithm.
    // Returns a pointer to the selected task, or nullptr if no task is ready.
    Task* scheduleNextTask();

private:
    std::vector<Task> tasks;
    SchedulingAlgorithm schedulingAlgorithm;
};

#endif // SCHEDULER_H

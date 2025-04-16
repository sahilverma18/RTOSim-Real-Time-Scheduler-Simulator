#ifndef TASK_H
#define TASK_H

#include <string>

// The Task class encapsulates a periodic task's parameters and behavior.
class Task {
public:
    // Constructor: id (name), period (time between releases), executionTime (required CPU time)
    Task(const std::string& id, int period, int executionTime);

    std::string getId() const;
    int getPeriod() const;
    int getExecutionTime() const;
    int getRemainingTime() const;
    int getNextReleaseTime() const;

    // Called at a time tick to release (activate) the task if its period has elapsed.
    void release(int currentTime);
    // Check if the task is currently active (ready to execute).
    bool isReleased() const;
    // Simulate execution for a given time unit.
    void execute(int timeUnits);
    // Reset the task’s state after completing its execution.
    void reset();

private:
    std::string id;
    int period;
    int executionTime;
    int remainingTime;    // Time units left to complete in the current period.
    int nextReleaseTime;  // Next time the task should be released.
    bool active;          // Indicates if the task is active (ready to execute).
};

#endif // TASK_H

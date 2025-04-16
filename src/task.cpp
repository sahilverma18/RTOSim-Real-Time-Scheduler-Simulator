#include "task.h"

Task::Task(const std::string& id, int period, int executionTime)
    : id(id), period(period), executionTime(executionTime), remainingTime(0), nextReleaseTime(0), active(false)
{
}

std::string Task::getId() const {
    return id;
}

int Task::getPeriod() const {
    return period;
}

int Task::getExecutionTime() const {
    return executionTime;
}

int Task::getRemainingTime() const {
    return remainingTime;
}

int Task::getNextReleaseTime() const {
    return nextReleaseTime;
}

void Task::release(int currentTime) {
    // Release the task if it is time to activate it.
    if (currentTime >= nextReleaseTime) {
        active = true;
        remainingTime = executionTime;
        nextReleaseTime = currentTime + period;
    }
}

bool Task::isReleased() const {
    return active;
}

void Task::execute(int timeUnits) {
    if (active && remainingTime > 0) {
        remainingTime -= timeUnits;
        // If finished, mark inactive. The next release will occur based on the period.
        if (remainingTime <= 0) {
            active = false;
        }
    }
}

void Task::reset() {
    // Reset the task to its initial active state.
    remainingTime = executionTime;
    active = true;
}

#include "Task.h"
#include <ctime>
Task::Task(int i, std::string d)
{
    Task::id = i;
    Task::description = d;
    Task::status = "ToDo";
    Task::created_at = time(0);
    Task::updated_at = time(0);
}

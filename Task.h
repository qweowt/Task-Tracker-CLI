#ifndef TASK_H
#define TASK_H

#include <string>
#include <ctime>

class Task
{
public:
    Task(int i, std::string d);
    int id;
    std::string description;
    std::string status;
    std::time_t created_at;
    std::time_t updated_at;
};

#endif
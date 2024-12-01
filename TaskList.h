#ifndef TASKLIST_H
#define TASKLIST_H

#include <vector>
#include "Task.h"

class TaskList{
    public:
        void add(std::string description);
        void update(int id, std::string description);
        void read(std::string line);
        void list(std::string filter);
        void deleteTask(int id);
        void markInProgress(int id);
        void markDone(int id);
        void save();
        void clearFile();
    private:
        std::vector<Task> tasks;
        int counter;
};

#endif
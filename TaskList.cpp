#include "TaskList.h"
#include "Task.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>

int counter = 0;

std::vector<std::string> split(const std::string &s, char delim) 
{
    std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
            elems.push_back(item);
    }
    return elems;
}

void TaskList::add(std::string description){
    Task task(counter, description);
    tasks.push_back(task);
    counter++;
}

void TaskList::read(std::string line){
    std::vector<std::string> parts = split(line, ',');
    Task task(std::stoi(parts[0]), parts[1]);
    task.status = parts[2];
    task.created_at = std::stoi(parts[3]);
    task.updated_at = std::stoi(parts[4]);
    tasks.push_back(task);
}

void TaskList::list(std::string filter){
    if (filter == "all"){
        for (int i = 0; i < tasks.size(); i++){
            std::cout << tasks[i].id << " - " << tasks[i].description << " - " << tasks[i].status << " - " << tasks[i].created_at << " - " << tasks[i].updated_at << std::endl;
        }
    }
    else if (filter == "inprogress"){
        for (int i = 0; i < tasks.size(); i++){
            if (tasks[i].status == "In progress"){
                std::cout << tasks[i].id << " - " << tasks[i].description << " - " << tasks[i].created_at << " - " << tasks[i].updated_at << std::endl;
            }
        }
    }
    else if (filter == "done"){
        for (int i = 0; i < tasks.size(); i++){
            if (tasks[i].status == "Done"){
                std::cout << tasks[i].id << " - " << tasks[i].description << " - " << tasks[i].created_at << " - " << tasks[i].updated_at << std::endl;
            }
        }
    }else if (filter == "todo"){
        for (int i = 0; i < tasks.size(); i++){
            if (tasks[i].status == "ToDo"){
                std::cout << tasks[i].id << " - " << tasks[i].description << " - " << tasks[i].created_at << " - " << tasks[i].updated_at << std::endl;
            }
        }
    }
}

void TaskList::deleteTask(int id){
    for (int i = 0; i < tasks.size(); i++){
        if (tasks[i].id == id){
            tasks.erase(tasks.begin() + i);
        }
    }
}

void TaskList::update(int id, std::string description){
    for (int i = 0; i < tasks.size(); i++){
        if (tasks[i].id == id){
            tasks[i].description = description;
            tasks[i].updated_at = time(0);
        }
    }
}

void TaskList::markInProgress(int id){
    for (int i = 0; i < tasks.size(); i++){
        if (tasks[i].id == id){
            tasks[i].status = "In progress";
        }
    }
}

void TaskList::markDone(int id){
    for (int i = 0; i < tasks.size(); i++){
        if (tasks[i].id == id){
            tasks[i].status = "Done";
        }
    }
}

void TaskList::save(){
    clearFile();
    std::ofstream f("task-cli.txt");
    for (int i = 0; i < tasks.size(); i++){
        f << tasks[i].id << "," << tasks[i].description << "," << tasks[i].status << "," << tasks[i].created_at << "," << tasks[i].updated_at << std::endl;
    }
    f.close();
}

void TaskList::clearFile(){
    std::ofstream f("task-cli.txt");
    f.close();
}
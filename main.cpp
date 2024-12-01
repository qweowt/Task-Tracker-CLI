#include <iostream>
#include <fstream>
#include <string>
#include "Task.h"
#include "TaskList.h"
#include <vector>

void help();

int main(int argc, char* argv[]) 
{
    if(argc > 1){
        TaskList tasks;
        std::string file = "task-cli.txt";

        std::ifstream f(file);
        if (f.is_open())
        {
            std::string line;
            while (std::getline(f, line))
            {
                tasks.read(line);
            }
            f.close();
        }else{
            std::ofstream f(file);
            f.close();
        }

        std::string action = argv[1];
        if (action == "add"){
            if (argc > 2)
            {
                tasks.add(argv[2]);
            }else{
                help();
                return 1;
            }
        }else if(action == "list"){
            if(argc == 2){
                tasks.list("all");
            }else if (argc == 3 && argv[2] == "done"){
                tasks.list("done");
            }else if (argc == 3 && argv[2] == "todo"){
                tasks.list("todo");
            }else if (argc == 3 && argv[2] == "in-progress"){
                tasks.list("in-progress");
            }else{
                help();
                return 1;
            }
        }else if(action == "delete"){
            if (argc == 3){
                tasks.deleteTask(std::atoi(argv[2]));
            }else{
                help();
                return 1;
            }
        }else if(action == "update"){
            if (argc == 4){
                tasks.update(std::atoi(argv[2]), argv[3]);
            }else{
                help();
                return 1;
            }
        }else if(action == "mark-in-progress"){
            if (argc == 3){
                tasks.markInProgress(std::atoi(argv[2]));
            }else{
                help();
                return 1;
            }
        }else if(action == "mark-done"){
            if (argc == 3){
                tasks.markDone(std::atoi(argv[2]));
            }else{
                help();
                return 1;
            }
        }else{
            help();
        }
        tasks.save();
    }else{
        help();
    }

    return 0;
}

void help(){
    std::cout << "Usage: task-cli add <description>\n";
    std::cout << "Usage: task-cli list <filter>/none\n";
    std::cout << "Usage: task-cli delete <id>\n";
    std::cout << "Usage: task-cli update <id> <description>\n";
    std::cout << "Usage: task-cli mark-in-progress <id>\n";
    std::cout << "Usage: task-cli mark-done <id>\n";
}
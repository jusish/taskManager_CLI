#ifndef TASK_MANAGER


#define TASK_MANAGER

#include "Task.hpp"
#include <vector>
#include <fstream>

using namespace std;


class TaskManager {
    private:

    vector<Task> tasks;
    int nextId;

    public:

    // contructor

    TaskManager();

    // Task operations

    void addTask(const string& title, const string& description, const string& dueDate, int priority);

    void editTask(int id, const std::string& title, const std::string& description, const std::string& dueDate, int priority);

    void deleteTask(int id);
    void completeTask(int id);
    void displayTasks() const;


    // file handling

    void saveTofile(const std::string& filename);
    void loadFromFile(const std::string& filename);
};


#endif
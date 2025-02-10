#include "TaskManager.hpp"

using namespace std;


// Constructor - Initializes task ID counter

TaskManager::TaskManager() : nextId(1) {};

// Add task

void TaskManager::addTask(const string& title, const string& description, const string& dueDate, int priority) {
    tasks.push_back(Task(nextId,title, description, dueDate, priority));
    cout << "✅ Task added successfully!\n";
}


// Edit task


void TaskManager::editTask(int id, const string& title, const string& description, const string& dueDate, int priority) {
    for (Task& task : tasks) {
        if (task.getId() == id) {
            task.setTitle(title);
            task.setDescription(description);
            task.setDueDate(dueDate);
            task.setPriority(priority);
            cout << "✏️ Task updated successfully!\n";
            return;
        }
    }
}


// Delete task

void TaskManager::deleteTask(int id) {
    for (size_t i = 0; i < tasks.size(); i++) {
        if (tasks[i].getId() == id) {
            tasks.erase(tasks.begin() + i);
            cout << "🗑 Task deleted successfully!\n";
            return;
        }
    }
    cout << "❌ Task not found!\n";
}


// Mark Task as Completed
void TaskManager::completeTask(int id) {
    for (Task& task : tasks) {
        if (task.getId() == id) {
            task.markCompleted();
            cout << "✅ Task marked as completed!\n";
            return;
        }
    }
    cout << "❌ Task not found!\n";
}


// Display all tasks

void TaskManager::displayTasks() const {
    if (tasks.empty()) {
        cout << "📭 No tasks available!\n";
        return;
    }

    cout << "📋 Task List:\n";
    for (const Task& task : tasks) {
        task.displayTaskDetails();
    }
}


// Save tasks to file

void TaskManager::saveTofile(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "❌ Error saving file!\n";
        return;
    }


    for (const Task& task : tasks) {
        file << task.getId() << "|" << task.getTitle() << "|" << task.getDescription() << "|"
             << task.getDueDate() << "|" << task.getPriority() << "|" << task.getStatus() << "\n";
    }
    file.close();
    cout << "💾 Tasks saved successfully to " << filename << "\n";
}


// Load tasks from file

void TaskManager::loadFromFile(const string& filename) {
    ifstream file(filename);

    if (!file) {
        cout << "⚠️ No saved tasks found!\n";
        return;
    }

    tasks.clear();
    int id, priority;
    string title, description, dueDate, status;
    bool isCompleted;

    while (file >> id) {
        getline(file, title, '|');
        getline(file, description, '|');
        getline(file, dueDate, '|');
        file >> priority;
        file.ignore();
        getline(file, status);
        isCompleted = (status == "1");

        Task task(id, title, description, dueDate, priority);
        if (isCompleted) task.markCompleted();
        tasks.push_back(task);

        nextId = id +1 ;
    }


    file.close();
    cout << "📂 Tasks loaded successfully!\n";

}
#include "Task.hpp"

using namespace std;

// Constructor


Task::Task(int id, string title, string description, string dueDate, int priority)
    : id(id), title(title), description(description), dueDate(dueDate), priority(priority), isCompleted(false) {}



// Getters

int Task::getId() const { return id; }
string Task::getTitle() const { return title; }
string Task::getDescription() const { return description; }
string Task::getDueDate() const { return dueDate; }
int Task::getPriority() const { return priority; }
bool Task::getStatus() const { return isCompleted; }



// Setters


void Task::setTitle(string newTitle) { title = newTitle; };
void Task::setDescription(string newDescription) { description = newDescription; };
void Task::setDueDate(string newDueDate) { dueDate = newDueDate; };
void Task::setPriority(int newPriority) { priority = newPriority; };
void Task::markCompleted() { isCompleted = true; }


// Display task details
void Task::displayTaskDetails() const {
    cout << "ID: " << id << "\nTitle: " << title << "\nDescription: " << description 
         << "\nDue Date: " << dueDate << "\nPriority: " << priority
         << "\nStatus: " << (isCompleted ? "Completed ✅" : "Pending ❌") << "\n\n";
}
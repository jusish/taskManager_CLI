#ifndef TASK_HPP

#define TASK_HPP

#include <iostream>
#include <string>

using namespace std;


class Task {
    private:
    int id;
    string title;
    string description;
    string dueDate;

    int priority;
    bool isCompleted;


    public:

    //Constructor
    Task(int id, string title, string description, string dueDate, int priority);


    //Getter methods

    int getId() const;
    string getTitle() const;
    string getDescription() const;
    string getDueDate() const;
    int getPriority() const;
    bool getStatus() const;



    // Setter methods

    void setTitle(string newTitle);
    void setDescription(string newDescription);
    void setDueDate(string newDueDate);
    void setPriority(int newPriority);
    void markCompleted();


    // Display task details

    void displayTaskDetails() const;
};


#endif // TASK_HPP


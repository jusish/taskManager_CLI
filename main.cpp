#include "TaskManager.hpp"

#include <iostream>

using namespace std;

void displayMenu() {
    cout << "\n📌 Task Manager CLI\n";
    cout << "1️⃣ Add Task\n";
    cout << "2️⃣ Edit Task\n";
    cout << "3️⃣ Delete Task\n";
    cout << "4️⃣ Mark Task Completed\n";
    cout << "5️⃣ Display Tasks\n";
    cout << "6️⃣ Save Tasks\n";
    cout << "7️⃣ Load Tasks\n";
    cout << "0️⃣ Exit\n";
    cout << "👉 Enter choice: ";
}


int main() {
    TaskManager manager;
    int choice, id, priority;
    string title, description, dueDate;

    manager.loadFromFile("tasks.txt"); // Load existing tasks

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Ignore newline

        switch (choice)
        {
        case 1:
            /* code */
            cout << "📌 Enter title: ", getline(cin, title);
            cout << "📝 Enter description: "; getline(cin, description);
            cout << "📅 Enter due date: "; getline(cin, dueDate);
            cout << "⭐ Enter priority (1-5): "; cin >> priority;
            cin.ignore(); // Ignore newline
            manager.addTask(title, description, dueDate, priority);
            break;
        
        case 2:
            cout << "🆔 Enter Task ID to edit: "; cin >> id;
            cin.ignore();
            cout << "📌 New title: "; getline(cin, title);
            cout << "📝 New description: "; getline(cin, description);
            cout << "📅 New due date: "; getline(cin, dueDate);
            cout << "⭐ New priority (1-5): "; cin >> priority;
            cin.ignore();
            manager.editTask(id, title, description, dueDate, priority);
            break;
        
        case 3:
            cout << "🆔 Enter Task ID to delete: "; cin >> id;
            manager.deleteTask(id);
            break;

        case 4:
            cout << "🆔 Enter Task ID to mark completed: "; cin >> id;
            manager.completeTask(id);
            break;

        case 5:
            manager.displayTasks();
            break;
        case 6:
            manager.saveTofile("tasks.txt");
            break;
        case 7:
            manager.loadFromFile("tasks.txt");
            break;
        case 0:
            cout << "👋 Exiting Task Manager. Goodbye!\n";
            return 0;
        default:
            cout << "❌ Invalid choice, try again!\n";

        }
    }
}
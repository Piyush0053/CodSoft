#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task structure to store task details
struct Task {
    string description;
    bool completed;
};

// Function prototypes
void displayMenu();
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markTaskCompleted(vector<Task>& tasks, int taskIndex);
void removeTask(vector<Task>& tasks, int taskIndex);

int main() {
    vector<Task> tasks;  // Vector to store tasks

    cout << "Welcome to the To-Do List Manager!" << endl;

    while (true) {
        displayMenu();

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                int taskIndex;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> taskIndex;
                markTaskCompleted(tasks, taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                cout << "Enter the index of the task to remove: ";
                cin >> taskIndex;
                removeTask(tasks, taskIndex);
                break;
            }
            case 5:
                cout << "Thank you for using the To-Do List Manager. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
                break;
        }
    }

    return 0;
}

// Display the main menu
void displayMenu() {
    cout << "Main Menu:" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Select an option: ";
}

// Add a task to the list
void addTask(vector<Task>& tasks) {
    Task task;
    cout << "Enter the task description: ";
    cin.ignore();
    getline(cin, task.description);
    task.completed = false;
    tasks.push_back(task);
    cout << "Task added successfully!" << endl;
}

// View the list of tasks
void viewTasks(const vector<Task>& tasks) {
    cout << "Task List:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << "[" << i + 1 << "] ";
        if (tasks[i].completed) {
            cout << "[X] ";
        } else {
            cout << "[ ] ";
        }
        cout << tasks[i].description << endl;
    }
}

// Mark a task as completed
void markTaskCompleted(vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
        tasks[taskIndex - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task index. Please enter a valid index." << endl;
    }
}

// Remove a task from the list
void removeTask(vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + taskIndex - 1);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task index. Please enter a valid index." << endl;
    }
}

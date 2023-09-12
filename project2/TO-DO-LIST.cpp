#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;
    time_t dueDate;

    Task(const string& desc, time_t due = 0) : description(desc), completed(false), dueDate(due) {}
};

// Function to add a task to the list
void addTask(vector<Task>& taskList, const string& description, time_t dueDate = 0) {
    Task newTask(description, dueDate);
    taskList.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

// Function to view all tasks
void viewTasks(const vector<Task>& taskList) {
    if (taskList.empty()) {
        cout << "No tasks in the list." << endl;
    } else {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < taskList.size(); ++i) {
            cout << i + 1 << ". ";
            if (taskList[i].completed) {
                cout << "[X] ";
            } else {
                cout << "[ ] ";
            }
            cout << taskList[i].description;
            
            // Display due date if available
            if (taskList[i].dueDate != 0) {
                char dueDateString[20];
                strftime(dueDateString, sizeof(dueDateString), "%Y-%m-%d", localtime(&taskList[i].dueDate));
                cout << " (Due: " << dueDateString << ")";
            }

            cout << endl;
        }
    }
}

// Function to mark a task as completed
void completeTask(vector<Task>& taskList, size_t index) {
    if (index < taskList.size()) {
        taskList[index].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

// Function to delete a task
void deleteTask(vector<Task>& taskList, size_t index) {
    if (index < taskList.size()) {
        taskList.erase(taskList.begin() + index);
        cout << "Task deleted successfully!" << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    vector<Task> tasks;

    while (true) {
        cout << "To-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Delete Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(); // Consume the newline character
                cout << "Enter the task description: ";
                string description;
                getline(cin, description);
                cout << "Enter the due date (YYYY-MM-DD, or leave empty for no due date): ";
                string dueDateStr;
                getline(cin, dueDateStr);

                time_t dueDate = 0;
                if (!dueDateStr.empty()) {
                    struct tm tm = {};
                    if (strptime(dueDateStr.c_str(), "%Y-%m-%d", &tm) != nullptr) {
                        dueDate = mktime(&tm);
                    } else {
                        cout << "Invalid date format. Task added without a due date." << endl;
                    }
                }

                addTask(tasks, description, dueDate);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                cout << "Enter the task index to mark as completed: ";
                size_t index;
                cin >> index;
                completeTask(tasks, index - 1); // Adjust index to match vector indexing
                break;
            }
            case 4: {
                cout << "Enter the task index to delete: ";
                size_t index;
                cin >> index;
                deleteTask(tasks, index - 1); // Adjust index to match vector indexing
                break;
            }
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <string>

void displayMenu() {
    std::cout << "\nTo-Do List Manager\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Delete Task\n";
    std::cout << "4. Exit\n";
    std::cout << "Choose an option: ";
}

void addTask(std::vector<std::string>& tasks) {
    std::cout << "Enter the task description: ";
    std::string task;
    std::cin.ignore();  // Ignore leftover newline character
    std::getline(std::cin, task);
    tasks.push_back(task);
    std::cout << "Task added successfully.\n";
}

void viewTasks(const std::vector<std::string>& tasks) {
    std::cout << "\nYour Tasks:\n";
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
    } else {
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i] << "\n";
        }
    }
}

void deleteTask(std::vector<std::string>& tasks) {
    viewTasks(tasks);
    if (!tasks.empty()) {
        std::cout << "Enter the task number to delete: ";
        int taskNumber;
        std::cin >> taskNumber;
        if (taskNumber > 0 && taskNumber <= static_cast<int>(tasks.size())) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            std::cout << "Task deleted successfully.\n";
        } else {
            std::cout << "Invalid task number.\n";
        }
    }
}

int main() {
    std::vector<std::string> tasks;
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                std::cout << "Exiting the program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

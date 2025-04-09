#include "TaskManager.h"
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	TaskManager taskManager;
	int choice;


	do {

		cout << "1. Add Task" << endl;
		cout << "2. Do Task" << endl;
		cout << "3. Print All Tasks" << endl;
		cout << "4. Exit" << endl;
		cout << "5. Save to File" << endl;
		cout << "6. Load from File" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		

		switch (choice) {
		case 1: {
			string title;
			int priority;
			cout << "Enter task title: ";
			cin.ignore();
			getline(cin, title);
			cout << "Enter task priority (1-10): ";
			cin >> priority;
			taskManager.addTask(Task(title, priority));
			break;
		}
		case 2:
			taskManager.doTask();
			break;
		case 3:
			taskManager.printAll();
			break;
		case 4:
			cout << "Exiting..." << endl;
			break;
		case 5: {
			taskManager.saveToFile("tasks.txt");
			
			break;
		}
		case 6: {
			taskManager.loadFromFile("tasks.txt");
			
				break;
		}
		
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 4);
}
#pragma once
#include "Task.h"
class TaskManager {
private:
	priority_queue<Task> tasks;
public:
	void addTask(const Task& task) {
		tasks.push(task);
	}
	void doTask() {
		if (tasks.empty()) {
			cout << "No tasks available." << endl;
			return;
		}
		Task top = tasks.top();
		tasks.pop();
		cout << "Completed task: " << endl;
		top.markDone();
		top.print();
	}
	void printAll() {
		auto copy = tasks;
		while (!copy.empty()) {
			copy.top().print();
			copy.pop();
		}
	}
	void saveToFile(const string& filename) {
		ofstream out(filename);
		if (!out.is_open()) {
			cout << "Не вдалося відкрити файл для запису!\n";
			return;
		}

		auto copy = tasks;
		while (!copy.empty()) {
			Task t = copy.top();
			copy.pop();
			out << t.getTitle() << ";" << t.getPriority() << ";" << t.getDone() << endl;
		}

		out.close();
		cout << "Збережено у файл: " << filename << endl;
	}
	void loadFromFile(const string& filename) {
		ifstream in(filename);
		if (!in.is_open()) {
			cout << "Не вдалося відкрити файл для читання!\n";
			return;
		}

		tasks = priority_queue<Task>(); // очистити поточні задачі

		string line;
		while (getline(in, line)) {
			size_t pos1 = line.find(';');
			size_t pos2 = line.find(';', pos1 + 1);

			string title = line.substr(0, pos1);
			int priority = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
			bool done = stoi(line.substr(pos2 + 1));

			Task t(title, priority, done);
			tasks.push(t);
		}

		in.close();
		cout << "Завантажено з файлу: " << filename << endl;
	}
};

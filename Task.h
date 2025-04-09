#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <Windows.h>
using namespace std;
class Task {
private:
	string title;
	int priority;
	bool done;
public:
	Task(string title, int priotity, bool done) : title(title), priority(priotity), done(done) {};
	Task(string title, int priority) : title(title), priority(priority), done(false) {};
	void markDone() {
		done = true;
	}
	void print() const {
		cout << "[" << (done ? "X" : " ") << "] " << title << " (Priority: " << priority << ")" << endl;
	}
	int getPriority() const {
		return priority;
	}
	int getDone() const {
		return done;
	}
	string getTitle() const {
		return title;
	}
	bool operator<(const Task& other) const {
		return priority > other.priority;
	}
};
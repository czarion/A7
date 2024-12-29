#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Struct to represent a Job
struct Job {
    int id;                       // Unique job ID
    string title;                 // Job title
    string description;           // Job description
    int priority;                 // Priority level (higher number = higher priority)
    string assignedTo;            // Name of the person assigned
    bool completed;               // Completion status

    // Display job details
    void display() const {
        cout << left << setw(5) << id 
             << setw(20) << title
             << setw(30) << description
             << setw(10) << priority
             << setw(20) << assignedTo
             << (completed ? "Completed" : "Pending") << endl;
    }
};

// Global job list
vector<Job> jobList;
int nextJobId = 1; // Auto-incrementing job ID

// Function to add a new job
void addJob() {
    Job newJob;
    newJob.id = nextJobId++;

    cout << "Enter Job Title: ";
    cin.ignore(); // Clear input buffer
    getline(cin, newJob.title);

    cout << "Enter Job Description: ";
    getline(cin, newJob.description);

    cout << "Enter Job Priority (1-10): ";
    cin >> newJob.priority;

    cout << "Enter Name of Assignee: ";
    cin.ignore();
    getline(cin, newJob.assignedTo);

    newJob.completed = false;
    jobList.push_back(newJob);

    cout << "Job added successfully!\n";
}

// Function to display all jobs
void displayJobs() {
    if (jobList.empty()) {
        cout << "No jobs to display.\n";
        return;
    }

    cout << left << setw(5) << "ID" 
         << setw(20) << "Title"
         << setw(30) << "Description"
         << setw(10) << "Priority"
         << setw(20) << "Assigned To"
         << "Status" << endl;
    cout << string(85, '-') << endl;

    for (const auto &job : jobList) {
        job.display();
    }
}

// Function to mark a job as completed
void markJobCompleted() {
    int jobId;
    cout << "Enter Job ID to mark as completed: ";
    cin >> jobId;

    auto it = find_if(jobList.begin(), jobList.end(), [jobId](const Job &job) {
        return job.id == jobId;
    });

    if (it != jobList.end()) {
        it->completed = true;
        cout << "Job marked as completed!\n";
    } else {
        cout << "Job ID not found.\n";
    }
}

// Function to delete a job
void deleteJob() {
    int jobId;
    cout << "Enter Job ID to delete: ";
    cin >> jobId;

    auto it = remove_if(jobList.begin(), jobList.end(), [jobId](const Job &job) {
        return job.id == jobId;
    });

    if (it != jobList.end()) {
        jobList.erase(it, jobList.end());
        cout << "Job deleted successfully!\n";
    } else {
        cout << "Job ID not found.\n";
    }
}

// Main menu
void menu() {
    int choice;
    do {
        cout << "\n--- Job Management System ---\n";
        cout << "1. Add Job\n";
        cout << "2. View All Jobs\n";
        cout << "3. Mark Job as Completed\n";
        cout << "4. Delete Job\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addJob();
                break;
            case 2:
                displayJobs();
                break;
            case 3:
                markJobCompleted();
                break;
            case 4:
                deleteJob();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}

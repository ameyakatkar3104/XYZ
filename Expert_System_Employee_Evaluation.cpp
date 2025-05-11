#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

class EmployeeEvaluation {
private:
    map<string, int> rules = {
        {"Meets all project deadlines", 4},
        {"Exceeds expectations", 5},
        {"Shows initiative and takes on additional responsibilities", 3},
        {"Collaborates well in a team", 3},
        {"Is always punctual", 2},
        {"Receives positive client feedback", 4},
        {"Brings new ideas and innovations", 3},
        {"Frequently absent or misses deadlines", -5},
        {"Consistently performs below expectations", -6}
    };

public:
    string name, position, work_mode, experience, feedback;
    map<string, int> scores;
    double total_score = 0.0;
    double total_weight = 0.0;
    int final_score;
    string rating, recommendation, suggestion;

    void inputDetails() {
        cout << "Enter Employee Name: ";
        getline(cin, name);
        cout << "Enter Current Position: ";
        getline(cin, position);
        cout << "Enter Years of Experience: ";
        getline(cin, experience);
        cout << "Enter Work Mode (Remote / On-Site / Hybrid): ";
        getline(cin, work_mode);
    }

    void collectRatings() {
        cout << "\nRate the following (0 to 5):\n";
        for (const auto& rule : rules) {
            int score;
            do {
                cout << rule.first << ": ";
                cin >> score;
                if (score < 0 || score > 5)
                    cout << "Please enter a value between 0 and 5.\n";
            } while (score < 0 || score > 5);
            scores[rule.first] = score;
            total_score += score * rule.second;
            total_weight += rule.second > 0 ? (rule.second * 5) : 0;
        }
        cin.ignore();
        cout << "\nEnter Manager's Feedback: ";
        getline(cin, feedback);
    }

    void evaluate() {
        final_score = round((total_score / total_weight) * 100);

        if (final_score >= 80) {
            rating = "Excellent";
            recommendation = "Highly recommended for promotion and incentive increment.";
            suggestion = "Keep up the great work and consider mentoring junior employees.";
        } else if (final_score >= 60) {
            rating = "Good";
            recommendation = "Eligible for incentives; potential for promotion with continued improvement.";
            suggestion = "Work on leadership and strategic thinking.";
        } else if (final_score >= 40) {
            rating = "Average";
            recommendation = "Requires improvement in key areas.";
            suggestion = "Focus on consistency and collaboration.";
        } else {
            rating = "Needs Improvement";
            recommendation = "Performance review advised.";
            suggestion = "Address punctuality and accountability issues.";
        }
    }

    void printReport() const {
        cout << "\n=== Evaluation Report ===\n";
        cout << "Employee: " << name << "\n";
        cout << "Position: " << position << "\n";
        cout << "Experience: " << experience << " years\n";
        cout << "Work Mode: " << work_mode << "\n";
        cout << "Final Score: " << final_score << "/100\n";
        cout << "Performance Rating: " << rating << "\n";
        cout << "Recommendation: " << recommendation << "\n";
        cout << "Suggestions: " << suggestion << "\n";
        cout << "Manager Feedback: " << feedback << "\n";
    }
};

int main() {
    int choice;
    vector<EmployeeEvaluation> allEvaluations;

    do {
        cout << "\n=== Employee Performance Expert System ===\n";
        cout << "1. Perform New Evaluation\n";
        cout << "2. View All Evaluations\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            EmployeeEvaluation eval;
            eval.inputDetails();
            eval.collectRatings();
            eval.evaluate();
            eval.printReport();
            allEvaluations.push_back(eval);  // store in vector
            break;
        }
        case 2: {
            if (allEvaluations.empty()) {
                cout << "\nNo evaluations stored yet.\n";
            } else {
                cout << "\nStored Evaluations:\n";
                for (size_t i = 0; i < allEvaluations.size(); ++i) {
                    cout << "\n--- Evaluation " << i + 1 << " ---\n";
                    allEvaluations[i].printReport();
                }
            }
            break;
        }
        case 3:
            cout << "\nExiting the system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please select between 1 and 3.\n";
        }

    } while (choice != 3);

    return 0;
}

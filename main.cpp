#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

class Course {
public:
    Course(const std::string& name, const std::string& rubric, const std::string& professor)
        : name(name), rubric(rubric), professor(professor) {}

    std::string getName() const { return name; }
    std::string getRubric() const { return rubric; }
    std::string getProfessor() const { return professor; }

private:
    std::string name;
    std::string rubric;
    std::string professor;
};

class DegreePlan {
public:
    DegreePlan(const std::string& major, const std::vector<Course>& courses)
        : major(major), courses(courses) {}

    std::string getMajor() const { return major; }
    const std::vector<Course>& getCourses() const { return courses; }

private:
    std::string major;
    std::vector<Course> courses;
};

class Student {
public:
    Student(const std::string& name, const DegreePlan& degreePlan)
        : name(name), degreePlan(degreePlan) {}

    std::string getName() const { return name; }
    const DegreePlan& getDegreePlan() const { return degreePlan; }

private:
    std::string name;
    DegreePlan degreePlan;
};

std::string generateRandomData(const std::vector<std::string>& options) {
    return options[rand() % options.size()];
}

void displayStudentInfo(const Student& student) {
    std::cout << "Student Name: " << student.getName() << std::endl;
    std::cout << "Major: " << student.getDegreePlan().getMajor() << std::endl;
    std::cout << "Courses:\n";
    
    const std::vector<Course>& courses = student.getDegreePlan().getCourses();
    std::cout << "-------------------------------------------------\n";
    std::cout << "| Course Name | Rubric | Professor           |\n";
    std::cout << "-------------------------------------------------\n";
    for (const Course& course : courses) {
        std::cout << "| " << course.getName() << "     | "
                  << course.getRubric() << "    | "
                  << course.getProfessor() << " |\n";
    }
    std::cout << "-------------------------------------------------\n";
}

int main() {
    srand(time(nullptr));

    std::vector<std::string> majors = {"Computer Science", "Cyber Security", "Biology", "Business", "Criminal Justice"};
    std::vector<std::string> rubrics = {"CS", "CYB", "BIO", "BUS", "CJ"};
    std::vector<std::string> professors = {"Prof. Smith", "Prof. Johnson", "Prof. Williams", "Prof. Brown", "Prof. Davis"};

    std::vector<Student> students;
    for (int i = 1; i <= 20; ++i) {
        std::string major = generateRandomData(majors);
        std::vector<Course> courses;
        for (int j = 0; j < 5; ++j) {
            std::string rubric = generateRandomData(rubrics);
            std::string professor = generateRandomData(professors);
            courses.push_back(Course("Course " + std::to_string(j + 1), rubric, professor));
        }
        students.push_back(Student("Student " + std::to_string(i), DegreePlan(major, courses)));
    }

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Display Student Information\n";
        std::cout << "2. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "\nEnter student number (1-20): ";
                int studentNumber;
                std::cin >> studentNumber;
                if (studentNumber >= 1 && studentNumber <= 20) {
                    displayStudentInfo(students[studentNumber - 1]);
                } else {
                    std::cout << "Invalid student number.\n";
                }
                break;
            }
            case 2:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please select again.\n";
        }
    } while (choice != 2);

    return 0;
}

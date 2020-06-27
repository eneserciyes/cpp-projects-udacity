#include <stdexcept>
#include <string>

class Student {
 private:
  std::string name;
  int grade;
  double gpa;

 public:
  Student(std::string name, int grade, double gpa) {
    setName(name);
    setGrade(grade);
    setGPA(gpa);
  }

  void setName(std::string name) { this->name = name; }
  void setGrade(int grade) {
    if (grade > 0 && grade < 12)
      this->grade = grade;
    else {
      throw std::invalid_argument("invalid argument grade - between 0 and 12");
    }
  }
  void setGPA(int gpa) {
    if (gpa >= 0.0f && gpa <= 4.0f)
      this->gpa = gpa;
    else {
      throw std::invalid_argument("invalid argument gpa - between 0.0 and 4.0");
    }
  }
};
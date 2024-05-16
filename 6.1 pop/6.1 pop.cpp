//Вы проектируете программу для оформления бухгалтерской отчётности
//факультета. Разработайте иерархию наследования классов, объединяющую
//людей на факультете, и позволяющую хранить всю необходимую информацию
//о них.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Human
{
public:

    string GetFio() {
        return fio;
    }

    void SetFio() {
        cin >> fio;
    }


protected:
    string fio;
};


class Student :public Human
{
public:
    Student() {
        this->yearOfStudy = 0;
        this->studentID = 0;
        this->grade = 0;
    }
    Student(int yearOfStudy, int studentID, float grade) {
        try {
            if (yearOfStudy < 0) throw "года должны быть больше 0";
            this->yearOfStudy = yearOfStudy;
        }
        catch (const char* exception) { cerr << "Error: " << exception << '\n'; }
        try {
            if (studentID < 0) throw "Такого id нет";
            this->studentID = studentID;
        }
        catch (const char* exception) { cerr << "Error: " << exception << '\n'; }
        this->grade = grade;
    }
    Student(Student& a) {
        this->yearOfStudy = a.yearOfStudy;
        this->studentID = a.studentID;
        this->grade = a.grade;
    }
    ~Student() {

    }



    void OutputInfo() {
        cout << "_________________________" << endl;
        cout << "Тип: Student" << endl;
        cout << "ФИО: " << GetFio() << endl;
        cout << "Год обучения: " << yearOfStudy << endl;
        cout << "ID студента: " << studentID << endl;
        cout << "Оценка: " << grade << endl;
        cout << "_________________________" << endl;
    }

    int GetYearOfStudy() {
        return yearOfStudy;
    }
    int GetStudentID() {
        return studentID;
    }
    float GetGrade() {
        return grade;
    }

    void SetStudent() {
        cout << "Введите фио: ";
        SetFio();
        cout << "Сколько лет "; cin >> yearOfStudy;
        try {
            if (yearOfStudy < 0) throw "года должны быть больше 0";
        }
        catch (const char* exception) { cerr << "Error: " << exception << '\n'; }
        cout << "номер студенческого "; cin >> studentID;
        try {
            if (studentID < 0) throw "номер должен быть больше 0";
        }
        catch (const char* exception) { cerr << "Error: " << exception << '\n'; }
        cout << "оценка "; cin >> grade;
    }

    friend ostream& operator<<(ostream& out, const Student a) {

        out << "Класс: Student\nМетоды:\nOutputInfo\nGetYearOfStudy\nGetStudentID\nGetGrade\nSetStudent" <<
            endl << "Конструкторы:\nс параметрами\nбез параметров\nкопирования" << endl << "Объекты:\nyearOfStudy" <<
            endl << "studentID\ngrade\n";
        return out;
    }


private:
    int yearOfStudy;
    int studentID;
    float grade;
};

class Teacher :public Human
{
public:
    Teacher() {
        this->post = "0";
        this->academicDegree = "0";
    }
    Teacher(string academicDegree, string post) {
        this->post = post;
        this->academicDegree = academicDegree;
    }
    Teacher(Teacher& a) {
        this->post = a.post;
        this->academicDegree = a.academicDegree;
    }
    ~Teacher() {

    }



    void OutputInfo() {
        cout << "_________________________" << endl;
        cout << "Тип: Teacher" << endl;
        cout << "ФИО: " << GetFio() << endl;
        cout << "Должность: " << post << endl;
        cout << "степень " << academicDegree << endl;
        cout << "_________________________" << endl;
    }

    string GetAcademicDegree() {
        return academicDegree;
    }
    string GetPost() {
        return post;
    }


    void SetTeacher() {
        cout << "Введите фио: ";
        SetFio();
        cout << "Введите должность: ";
        cin >> post;

        cout << "Введите ученую степень: ";
        cin >> academicDegree;
    }
    friend ostream& operator<<(ostream& out, const Teacher a) {

        out << "Класс: Teacher\nМетоды:\nOutputInfo\nGetAcademicDegree\nGetPost\nSetTeacher" <<
            endl << "Конструкторы:\nс параметрами\nбез параметров\nкопирования" << endl << "Объекты:" <<
            endl << "post\nacademicDegreee\n";
        return out;
    }


private:
    string post;
    string academicDegree;
};


class Staff : public Human {

public:
    Staff() {
        this->post = "0";
        this->LabNumb = 0;
    }
    Staff(int LabNumb, string post) {
        this->post = post;
        this->LabNumb = LabNumb;
    }
    Staff(Staff& a) {
        this->post = a.post;
        this->LabNumb = a.LabNumb;
    }
    ~Staff() {
    }
        void OutputInfo() {
        cout << "_________________________" << endl;
        cout << "Тип: Staff" << endl;
        cout << "ФИО: " << GetFio() << endl;
        cout << "Должность: " << post << endl;
        cout << "номер лаборатории " << LabNumb << endl;
        cout << "_________________________" << endl;
    }

    int GetLabNumb() {
        return LabNumb;
    }
    string GetPost() {
        return post;
    }


    void SetStaff() {
        cout << "Введите фио: ";
        SetFio();
        cout << "Введите должность: ";
        cin >> post;
        cout << "Введите номер лаборатории: ";
        cin >> LabNumb;
    }

    friend ostream& operator<<(ostream& out, const Staff a) {

        out << "Класс: Staff\nМетоды:\nOutputInfo\nGetLabNumb\nGetPost\nSetStaff" <<
            endl << "Конструкторы:\nс параметрами\nбез параметров\nкопирования" << endl << "Объекты:" <<
            endl << "post\nLabNumb\n";
        return out;
    }

private:
    string post;
    int LabNumb;

};

class ResearchAssociate : public Human {

public:
    ResearchAssociate() {
        this->degree = "0";
        this->contractNumber = 0;
    }
    ResearchAssociate(int contractNumber, string post) {
        this->degree = post;
        try {
            if (contractNumber < 0) throw "Такого номера нет";
            this->contractNumber = contractNumber;
        }
        catch (const char* exception) { cerr << "Error: " << exception << '\n'; }
    }
    ResearchAssociate(ResearchAssociate& a) {
        this->degree = a.degree;
        this->contractNumber = a.contractNumber;
    }
    ~ResearchAssociate() {

    }
    void OutputInfo() {
        cout << "_________________________" << endl;
        cout << "Тип: Staff" << endl;
        cout << "ФИО: " << GetFio() << endl;
        cout << "Должность: " << degree << endl;
        cout << "номер договора " << contractNumber << endl;
        cout << "_________________________" << endl;
    }

    int GetСontractNumber() {
        return contractNumber;
    }
    string GetPost() {
        return degree;
    }


    void SetResearchAssociate() {
        cout << "Введите фио: ";
        SetFio();
        cout << "Введите должность: ";
        cin >> degree;
        cout << "Введите номер договора: ";
        cin >> contractNumber;
        try {
            if (contractNumber < 0) throw "Такого номера нет";
        }
        catch (const char* exception) { cerr << "Error: " << exception << '\n'; }
    }

    friend ostream& operator<<(ostream& out, const ResearchAssociate a) {

        out << "Класс: ResearchAssociate\nМетоды:\nOutputInfo\nGetСontractNumber\nGetPost\nSetResearchAssociate" <<
            endl << "Конструкторы:\nс параметрами\nбез параметров\nкопирования" << endl << "Объекты:\ndegree" <<
            endl << "contractNumber\n";
        return out;
    }




private:
    string degree;
    int contractNumber;

};

class PeopleVector {
public:
    PeopleVector() {

    }
    ~PeopleVector() {
        for (auto& person : peopleVec) {
            delete person;
        }
    }
    template <class T>
    void PushObject(T nameClass) {
        peopleVec.push_back(nameClass);

    }
    void deleteObj(int i) {
        if (i >= 0 && i < size) {
            delete peopleVec[i];
            peopleVec.erase(peopleVec.begin() + i);
            size--;
        }
    }

private:
    vector <Human*> peopleVec;
    int size;

};
int main()
{
    setlocale(LC_ALL, "RU");
    Teacher a;
    cout << a;
}

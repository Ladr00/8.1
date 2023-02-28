#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string name, sex;
    int age;
    float ves;
public:
    Person() {
        age = 2;
        ves = 2;
    }

    Person(string name, string sex, int age, int ves) {
        this->name = name;
        this->sex = sex;
        this->age = age;
        this->ves = ves;
    }

    ~Person() {}

    void SetName(string name) {
        this->name = name;
    }

    void Setsex(string sex) {
        this->sex = sex;
    }

    void SetAge(int age) {
        this->age = age;
    }

    void GetVes(float ves) {
        this->ves = ves;
    }

    string GetName() {
        return name;
    }

    string Getsex() {
        return sex;
    }

    int GetAge() {
        return age;
    }

    float GetVes() {
        return ves;
    }
};

class Universuty
{
private:
    struct Building
    {
    private:
        int count;
        Person* visitors;
        string name;
    public:
        Building() {
            count = 0;
            visitors = new Person[count];
        }

        ~Building() {
            delete[] visitors;
        }

        void AddVisitor(Person some1) {
            Person* buff = new Person[count];
            if (count > 0) {
                for (int i = 0; i < count; i++)
                    buff[i] = visitors[i];
            }
            delete[] visitors;
            count += 1;
            visitors = new Person[count];
            for (int i = 0; i < count; i++)
            {
                if (i == count - 1)
                    visitors[i] = some1;
                else
                    visitors[i] = buff[i];
            }
            delete[] buff;

        }

        void DeleteVisitor(Person some1) {
            Person* buff = visitors; 
            delete[] visitors;
            count -= 1;
            visitors = new Person[count];
            for (int i = 0; i < count; i++)
                visitors[i] = buff[i];
            delete[] buff;
        }

        void ShowVisitors() {
            if (count == 0)
                cout << "Empty\n";
            else {
                for (int i = 0; i < count; i++)
                    cout << "Name - " << visitors[i].GetName() << "\nSex - " << visitors[i].Getsex() << "\nAge - " << visitors[i].GetAge() << "\nves - " << visitors[i].GetVes() << endl << endl;
            }
        }

        void SetName(string name) {
            this->name = name;
        }

        string GetName() {
            return name;
        }

    };

    struct Campus : public Building
    {
        Campus() {
            this->SetName("Campus");
        }
        ~Campus() {

        }
    };
    struct Hostel : public Building
    {
        Hostel() {
            this->SetName("Hostel");
        }
        ~Hostel() {

        }
    };
    struct Hall : public Building
    {
        Hall() {
            this->SetName("Hall");
        }
        ~Hall() {

        }
    };
    Campus sc;
    Hostel h;
    Hall dh;
public:
    Universuty() {

    }

    ~Universuty() {

    }

    void PrintBuildings() {
        cout << sc.GetName() << endl << h.GetName() << endl << dh.GetName() << endl;
    }

    void ShowVisitorsInBuilding(string building_name) {
        if (building_name == "Campus")
            sc.ShowVisitors();
        else if (building_name == "Hostel")
            h.ShowVisitors();
        else if (building_name == "Hall")
            dh.ShowVisitors();
    }

    void AddTo(string building_name, Person some1) {
        if (building_name == "Campus")
            sc.AddVisitor(some1);
        else if (building_name == "Hostel")
            h.AddVisitor(some1);
        else if (building_name == "Hall")
            dh.AddVisitor(some1);
    }
};

class Student : public Person
{
private:
    int year_of_study;
public:
    Student()
    {
        year_of_study = 0;
    }

    void SetYearOfStudy(int year_of_study)
    {
        this->year_of_study = year_of_study;
    }

    int GetYearOfStudy()
    {
        return year_of_study;
    }

    ~Student() {}
};

int main()
{
    Universuty SYN;

    Person Vasya("Vasya", "male", 25, 80), Inna("Inna", "female", 20, 46);

    SYN.PrintBuildings(); cout << endl;

    SYN.AddTo("Campus", Vasya);

    SYN.AddTo("Campus", Inna);

    SYN.ShowVisitorsInBuilding("Campus");

    SYN.ShowVisitorsInBuilding("Hall");


    return 0;
}

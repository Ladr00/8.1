#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define STUD "student"
#define PROF "professor"
#define SCIE "sotrudnik"
#define TCHW "electrik"
#define ERR "zapret"

using namespace std;

template <class T1, class T2> void check_perm(const T1&, const T2*, unsigned int);

class Passcard
{
private:
    static unsigned int count_for_id;
    unsigned int id;
    string name;
protected:
    string passcard_type;
public:
    Passcard(const unsigned int* database, string name, string passcard_type) {
        this->name = name;
        this->passcard_type = passcard_type;
        this->id = database[count_for_id];
        count_for_id++;
    };
    Passcard(const unsigned int* database, string name) {
        this->name = name;
        this->id = database[count_for_id];
        count_for_id++;
    };
    
    string get_name() const { return name; }
    unsigned int get_id() const { return id; }
    string get_passcard_type() const { return passcard_type; }

    ~Passcard(){};
};

class Room
{
private:
    string name;
    int size_;
    const string* passcard_type;
    
public:
    Room(string name, const string* passcard_type, const int size_) : name(name), passcard_type(passcard_type), size_(size_) {};
    
  
    void enter_to_room  (const Passcard &any_Passcard) const {
        bool isCorrect = false;
        for (int i = 0; i < size_; i++)
        {
            if(any_Passcard.get_passcard_type() == passcard_type[i]) {
                isCorrect = true;
                break;
            }
            else
                isCorrect = false;
        }
        if (isCorrect)
            cout << "dostup v room " << name << " ok\n";
        else
            cout << "dostup v room " << name << " error!\n";
    }

    void set_name(string name) { this->name = name;}
    string get_name() { return name; }
    ~Room(){ };
};

unsigned int Passcard::count_for_id = 0;

int main() {
    
    unsigned int size = 10000;
    unsigned int int_for_add;
    unsigned int *database = new unsigned int[size];
    bool isUnique;
    srand(time(NULL));
    
    for (int i = 0; i < size; )
    {
        int_for_add = rand()%1000000 + 10000;
        isUnique = true;
        for (int j = 0; j < size; j++)
        {
            if(int_for_add == database[j]){
                isUnique = false;
                break;
            }
        } 
        if (isUnique){
            database[i] = int_for_add;
            i++;
        }
    }
    
    Passcard People[] {
        Passcard (database, "Nikolskii Grigorii Stefanovich", ERR),
        Passcard (database, "Makarov Gleb Borisovich", STUD),
        Passcard (database, "Skvortsov Fedor Matveevich", SCIE),
        Passcard (database, "Makarov Daniil Rostislavovich", PROF),
        Passcard (database, "Nikolaev Maksim Timurovich", TCHW)
    };
    

    string zapret[] { ERR },
		toilet1[] { STUD, PROF, TCHW, TCHW },
        toilet2 [] { SCIE, TCHW },
        classrom1 [] { STUD, PROF, TCHW  },
        classrom2 [] { STUD, PROF, TCHW  },
        uchitelskaya [] { PROF, TCHW  },
        stolovaya [] { SCIE, TCHW, STUD, PROF },
        laboratory [] { SCIE, TCHW },
        chitovaya [] { SCIE, TCHW };
    
    Room University[] {
    	Room ("zapresheno vezde ", zapret , sizeof( zapret)/sizeof(string) ),
        Room ("tualet 1 ", toilet1 , sizeof( toilet1)/sizeof(string) ),
        Room ("tualet 2 ", toilet2, sizeof( toilet2)/sizeof(string) ),
        Room ("class fizo", classrom1, sizeof( classrom1)/sizeof(string) ),
        Room ("klass english", classrom2, sizeof(  classrom2)/sizeof(string) ),
        Room ("uchirt", uchitelskaya, sizeof( uchitelskaya)/sizeof(string) ),
        Room ("stolovaya", stolovaya, sizeof( stolovaya)/sizeof(string) ),
        Room ("laboratoria", laboratory, sizeof( laboratory)/sizeof(string) ),
        Room ("chitovaya", chitovaya, sizeof( chitovaya)/sizeof(string) )
    };

    unsigned int room_ammount = sizeof(University)/sizeof(Room);
    unsigned int passcard_ammount = sizeof(People)/sizeof(Passcard);
    

    for (int i = 0; i < passcard_ammount; i++)
    {
        check_perm(People[i], University, room_ammount);
    }
    
    return 0;
}

template <class T1, class T2> void check_perm(const T1& any_Passcard, const T2* any_Room, unsigned int room_ammount) {
    cout << "\t" << any_Passcard.get_name() << " "<< any_Passcard.get_id()
        << " " << any_Passcard.get_passcard_type() << endl;
    for (int i = 0; i < room_ammount; i++)
    {
        any_Room[i].enter_to_room(any_Passcard);
    }
    cout << endl;
}

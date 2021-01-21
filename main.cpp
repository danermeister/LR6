#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Subject
{
    string sub;
    unsigned short int score = 0;
};

struct Student
{
    string fio;
    Subject subs[4];
    double avrScr = 0.0;
};

void sort_s(vector<Student>& arr, int j)
{
    Student tmp;
    for (int i = 0; i < j - 1; i++)
        for (int n = i + 1; n < j; n++) {
            const char* d1 = arr[i].fio.c_str();
            const char* d2 = arr[n].fio.c_str();
            if (strcmp(d1, d2) > 0)
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
}


int main(){
    vector<Student> student;
    string stud_name;
    string sub_name;
    unsigned short int score;
    ifstream fi("LR6_VVOD.txt");
    getline(fi, stud_name);
    for (int i=0; i<5;i++){
        student.push_back(Student({stud_name}));
        for (int n=0;n<4;n++){
            fi >> sub_name >> score;
                student[i].subs[n].sub = sub_name;
                student[i].subs[n].score = score;
        }
            fi.ignore(10, '\n');
                getline(fi,stud_name);
    }
    fi.close();
    sort_s(student, 5);

    
    int bad_score = 0;
    for (Student i : student){
        if(i.avrScr<4) bad_score++;
    }
    
    
    ofstream fall("LR6_VIVOD.txt");
 
    fall <<"Studentov s neudovletvaritelnimi ocenkami: "<<bad_score<<endl;
    fall <<"Spisok studentov i predmetov:"<<endl;
    for (Student i : student)
        {
            if(i.avrScr<4.0)
                {
                    fall<<i.fio<<" ";
         
            }
        }
    fall.close();
    
    
return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

    Date(int d);
    Date(int d, int m);

public:
    Date();
    Date(const Date& d);
    Date(int d, int m, int y);

    void Print()const;
    void Init();

    int GetDay()const;
    int GetMonth()const;
    int GetYear()const;

    void SetDay(int d);
    void SetMonth(int m);
    void SetYear(int y);
};

Date::Date(int d)
{
    day = d;
}

Date::Date(int d, int m) :Date(d)
{
    month = m;
}


Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(const Date& d)
{
    day = d.day;
    month = d.month;
    year = d.year;
}

Date::Date(int d, int m, int y) :Date(d, m)
{
    year = y;
}

void Date::Print()const
{
    cout << "-Birthday: " 
        << day << "." 
        << month << "." 
        << year << "\n";
}

void Date::Init()
{
    cout << "Enter a date of birth (d m y):\n\n";

    cout << ">>> ";
    cin >> day >> month >> year;
}

int Date::GetDay()const
{
    return day;
}

int Date::GetMonth()const
{
    return month;
}

int Date::GetYear()const
{
    return year;
}

void Date::SetDay(int d)
{
    day = d;
}

void Date::SetMonth(int m)
{
    month = m;
}

void Date::SetYear(int y)
{
    year = y;
}


class PersonData
{
private:
    char* fullName;
    char* homePhone;
    char* workPhone;
    char* mobilePhone;
    Date birthday;
    
    PersonData(const char* flName);
    PersonData(const char* flName, const char* hmPhone);
    PersonData(const char* flName, const char* hmPhone, const char* wkPhone);
    PersonData(const char* flName, const char* hmPhone, const char* wkPhone, const char* mobPhone);

public:
    PersonData();
    PersonData(const PersonData& pd);
    PersonData(const char* flName, const char* hmPhone, const char* wkPhone, const char* mobPhone, Date brthd);
    
    ~PersonData();

    void Print()const;
    void Init();

    char* GetName()const;
    char* GetHomePhone()const;
    char* GetWorkPhone()const;
    char* GetMobilePhone()const;

    void SetName(const char* flName);
    void SetHomePhone(const char* hmPhone);
    void SetWorkPhone(const char* wkPhone);
    void SetMobilePhone(const char* mobPhone);
    void SetDate(Date brthd);

    void operator = (const PersonData& pd);
};

PersonData::PersonData(const char* flName)
{
    fullName = new char[strlen(flName) + 1];
    strcpy_s(fullName, strlen(flName) + 1, flName);
}

PersonData::PersonData(const char* flName, const char* hmPhone)
    :PersonData(flName)
{
    homePhone = new char[strlen(hmPhone) + 1];
    strcpy_s(homePhone, strlen(hmPhone) + 1, hmPhone);
}

PersonData::PersonData(const char* flName, const char* hmPhone, const char* wkPhone)
    :PersonData(flName, hmPhone)
{
    workPhone = new char[strlen(wkPhone) + 1];
    strcpy_s(workPhone, strlen(wkPhone) + 1, wkPhone);
}

PersonData::PersonData(const char* flName, const char* hmPhone, const char* wkPhone, const char* mobPhone)
    :PersonData(flName, hmPhone, wkPhone)
{
    mobilePhone = new char[strlen(mobPhone) + 1];
    strcpy_s(mobilePhone, strlen(mobPhone) + 1, mobPhone);
}


PersonData::PersonData()
{
    fullName = nullptr;
    homePhone = nullptr;
    workPhone = nullptr;
    mobilePhone = nullptr;
    birthday = Date();
}

PersonData::PersonData(const PersonData& pd)
{
    if (this->fullName != nullptr)
        delete[] this->fullName;

    if (this->homePhone != nullptr)
        delete[] this->homePhone;

    if (this->workPhone != nullptr)
        delete[] this->workPhone;

    if (this->mobilePhone != nullptr)
        delete[] this->mobilePhone;

    this->fullName = new char[strlen(pd.fullName) + 1];
    strcpy_s(this->fullName, strlen(pd.fullName) + 1, pd.fullName);

    this->homePhone = new char[strlen(pd.homePhone) + 1];
    strcpy_s(this->homePhone, strlen(pd.homePhone) + 1, pd.homePhone);

    this->workPhone = new char[strlen(pd.workPhone) + 1];
    strcpy_s(this->workPhone, strlen(pd.workPhone) + 1, pd.workPhone);

    this->mobilePhone = new char[strlen(pd.mobilePhone) + 1];
    strcpy_s(this->mobilePhone, strlen(pd.mobilePhone) + 1, pd.mobilePhone);

    this->birthday = pd.birthday;
}

PersonData::PersonData(const char* flName, const char* hmPhone, const char* wkPhone, const char* mobPhone, Date brthd)
    :PersonData(flName, hmPhone, wkPhone, mobPhone)
{
    birthday = brthd;
}

PersonData::~PersonData()
{
    delete[] fullName;
    delete[] homePhone;
    delete[] workPhone;
    delete[] mobilePhone;
}

void PersonData::Print()const
{   
    if (fullName != nullptr)
        cout << fullName << " phone numbers:\n";
    else
        cout << "None phone numbers:\n";

    if (homePhone != nullptr)
        cout << "-Home phone: " << homePhone << "\n";
    else
        cout << "-Home phone: None\n";

    if (workPhone != nullptr)
        cout << "-Work phone: " << workPhone << "\n";
    else
        cout << "-Work phone: None\n";

    if (mobilePhone != nullptr)
        cout << "-Mobile phone: " << mobilePhone << "\n";
    else
        cout << "-Mobile phone: None\n";
    
    birthday.Print();
}

void PersonData::Init()
{
    if (this->fullName != nullptr)
        delete[] this->fullName;

    if (this->homePhone != nullptr)
        delete[] this->homePhone;

    if (this->workPhone != nullptr)
        delete[] this->workPhone;

    if (this->mobilePhone != nullptr)
        delete[] this->mobilePhone;
    
    char buf[20];

    cin.ignore();

    cout << "Enter full name:\n\n";

    cout << ">>> ";
    cin.getline(buf, 20);

    this->fullName = new char[strlen(buf) + 1];
    strcpy_s(this->fullName, strlen(buf) + 1, buf);

    system("cls");

    cout << "Enter home phone:\n\n";

    cout << ">>> ";
    cin.getline(buf, 20);

    this->homePhone = new char[strlen(buf) + 1];
    strcpy_s(this->homePhone, strlen(buf) + 1, buf);

    system("cls");

    cout << "Enter work phone:\n\n";

    cout << ">>> ";
    cin.getline(buf, 20);

    this->workPhone = new char[strlen(buf) + 1];
    strcpy_s(this->workPhone, strlen(buf) + 1, buf);

    system("cls");

    cout << "Enter mobile phone:\n\n";

    cout << ">>> ";
    cin.getline(buf, 20);

    this->mobilePhone = new char[strlen(buf) + 1];
    strcpy_s(this->mobilePhone, strlen(buf) + 1, buf);

    system("cls");

    birthday.Init();

    system("cls");
}

char* PersonData::GetName()const
{
    return fullName;
}

char* PersonData::GetHomePhone()const
{
    return homePhone;
}

char* PersonData::GetWorkPhone()const
{
    return workPhone;
}

char* PersonData::GetMobilePhone()const
{
    return mobilePhone;
}

void PersonData::SetName(const char* flName)
{
    if (fullName != nullptr)
        delete[] fullName;

    fullName = new char[strlen(flName) + 1];
    strcpy_s(fullName, strlen(flName) + 1, flName);
}

void PersonData::SetHomePhone(const char* hmPhone)
{
    if (this->homePhone != nullptr)
        delete[] this->homePhone;

    homePhone = new char[strlen(hmPhone) + 1];
    strcpy_s(homePhone, strlen(hmPhone) + 1, hmPhone);
}

void PersonData::SetWorkPhone(const char* wkPhone)
{
    if (this->workPhone != nullptr)
        delete[] this->workPhone;

    workPhone = new char[strlen(wkPhone) + 1];
    strcpy_s(workPhone, strlen(wkPhone) + 1, wkPhone);
}

void PersonData::SetMobilePhone(const char* mobPhone)
{
    if (this->mobilePhone != nullptr)
        delete[] this->mobilePhone;

    mobilePhone = new char[strlen(mobPhone) + 1];
    strcpy_s(mobilePhone, strlen(mobPhone) + 1, mobPhone);
}

void PersonData::SetDate(Date brthd)
{
    birthday = brthd;
}

void PersonData::operator = (const PersonData& pd)
{
    if (this->fullName != nullptr)
        delete[] this->fullName;

    if (this->homePhone != nullptr)
        delete[] this->homePhone;

    if (this->workPhone != nullptr)
        delete[] this->workPhone;

    if (this->mobilePhone != nullptr)
        delete[] this->mobilePhone;

    this->fullName = new char[strlen(pd.fullName) + 1];
    strcpy_s(this->fullName, strlen(pd.fullName) + 1, pd.fullName);

    this->homePhone = new char[strlen(pd.homePhone) + 1];
    strcpy_s(this->homePhone, strlen(pd.homePhone) + 1, pd.homePhone);

    this->workPhone = new char[strlen(pd.workPhone) + 1];
    strcpy_s(this->workPhone, strlen(pd.workPhone) + 1, pd.workPhone);

    this->mobilePhone = new char[strlen(pd.mobilePhone) + 1];
    strcpy_s(this->mobilePhone, strlen(pd.mobilePhone) + 1, pd.mobilePhone);

    this->birthday = pd.birthday;
}


class PhoneBook
{
private:
    PersonData* persons;
    int length;

    PhoneBook(int len);

public:
    PhoneBook();
    PhoneBook(PersonData* prsns, int len);
    PhoneBook(const PhoneBook& pb);

    ~PhoneBook();

    void Print()const;
    void PrintNames()const;

    void AddPersonData();
    void AddPersonData(const PersonData& obj);
    void DeletePerson(int index);
    void Search(char* sName);

    int GetSize()const;
    PersonData* GetPersons()const;

    void SetPersons(PersonData* prsns, int len);

    void operator = (const PhoneBook& pb);
};

PhoneBook::PhoneBook(int len)
{
    length = len;
}


PhoneBook::PhoneBook()
{
    persons = nullptr;
    length = 0;
}

PhoneBook::PhoneBook(PersonData* prsns, int len)
    :PhoneBook(len)
{
    persons = new PersonData[length];

    for (int i = 0; i < length; i++)
    {
        persons[i] = prsns[i];
    }
}

PhoneBook::PhoneBook(const PhoneBook& pb)
{
    length = pb.length;
    persons = new PersonData[pb.length];

    for (int i = 0; i < pb.length; i++)
    {
        persons[i] = pb.persons[i];
    }
}

PhoneBook::~PhoneBook()
{
    delete[] persons;
}

void PhoneBook::Print()const
{
    for (int i = 0; i < length; i++)
    {
        persons[i].Print();
        cout << "--------------------------------\n";
    }
}

void PhoneBook::PrintNames()const
{
    for (int i = 0; i < length; i++)
    {
        cout << i + 1 << ". " << persons[i].GetName() << "\n";
    }
}

void PhoneBook::AddPersonData()
{
    PersonData* tmp = new PersonData[length + 1];
    copy(this->persons, this->persons + length, tmp);
    
    PersonData obj;

    obj.Init();

    tmp[length] = obj;

    delete[] persons;

    persons = tmp;

    length++;
}

void PhoneBook::AddPersonData(const PersonData& obj)
{
    PersonData* tmp = new PersonData[length + 1];
    copy(this->persons, this->persons + length, tmp);

    tmp[length] = obj;

    delete[] persons;

    persons = tmp;

    length++;
}

void PhoneBook::DeletePerson(int index)
{
    PersonData* tmp = new PersonData[length - 1];

    int j = 0;
    int g = 0;
    while (j < length - 1)
    {
        if (g == index)
        {
            g++;
        }
        else
        {
            tmp[j] = persons[g];
            g++;
            j++;
        }
    }

    delete[] persons;

    persons = tmp;

    length--;
}

void PhoneBook::Search(char* sName)
{   
    int k = 1;
    for (int i = 0; i < length; i++)
    {
        if (strlen(sName) > 2 && strlen(persons[i].GetName()) > 2)
        {   
            int count = 0;
            for (int j = 0; j < 3; j++)
            {
                if (sName[j] == persons[i].GetName()[j])
                {
                    count++;
                }
            }
            if (count == 3)
            {
                persons[i].Print();
                cout << "-------------------------------------\n";
            }
        }
    }
}

int PhoneBook::GetSize()const
{
    return length;
}

PersonData* PhoneBook::GetPersons()const
{
    return persons;
}

void PhoneBook::SetPersons(PersonData* prsns, int len)
{
    if (persons != nullptr)
        delete[] persons;

    length = len;

    persons = new PersonData[length];

    for (int i = 0; i < length; i++)
    {
        persons[i] = prsns[i];
    }
}

void PhoneBook::operator = (const PhoneBook& pb)
{
    if (this->persons != nullptr)
        delete[] this->persons;

    length = pb.length;
    persons = new PersonData[pb.length];

    for (int i = 0; i < pb.length; i++)
    {
        persons[i] = pb.persons[i];
    }
}

PersonData RandomPersonData()
{
    char names[8][20]
    {
        "Vasya", "Petya", "Pasha", "Angela", 
        "Lisa", "Olya", "Egor", "Evgeniy"
    };
    
    int r = rand() % 7;

    PersonData obj(
        names[r], 
        ("+" + to_string(rand()) + to_string(rand())).c_str(),
        ("+" + to_string(rand()) + to_string(rand())).c_str(), 
        ("+" + to_string(rand()) + to_string(rand())).c_str(),
        Date(
            rand() % 30 + 1, 
            rand() % 11 + 1, 
            rand() % 10 + 2000
        )
    );

    return obj;
}


int main()
{
    srand(time(0));

    int size = 2;

    PersonData* pds = new PersonData[size];

    pds[0] = PersonData("Vasya", "+3765543876", "+3535434434", "+4326458345", Date(5, 12, 2001));
    pds[1] = PersonData("Petya", "+7534985734", "+5677656782", "+7656505492", Date(23, 9, 2005));

    PhoneBook db(pds, size);
    
    int choice = 0;

    while (true)
    {
        cout << "What do you want to do?\n";

        cout << "-------------------------------------\n";

        cout << "1. See all persons in database.\n";
        cout << "2. Add person to database.\n";
        cout << "3. Delete person from database.\n";
        cout << "4. Search person in database by name.\n";
        cout << "5. Exit.\n";

        cout << "-------------------------------------\n\n";

        cout << ">>> ";
        cin >> choice;

        system("cls");

        cout << "\n";

        bool isDone = false;

        switch (choice)
        {
        case 1:
            cout << "All the persons in the database:\n";

            cout << "--------------------------------\n";

            db.Print();

            cout << "\n";
            break;
        case 2:
            while (!isDone)
            {
                cout << "Select:\n";

                cout << "----------------------------\n";

                cout << "1. Add a new person data.\n";
                cout << "2. Add a random person data.\n";
                cout << "3. Return.\n";

                cout << "----------------------------\n\n";

                int ch = 0;

                cout << ">>> ";
                cin >> ch;

                system("cls");

                cout << "\n";

                switch (ch)
                {
                case 1:
                    db.AddPersonData();
                    isDone = true;
                    break;
                case 2:
                    db.AddPersonData(RandomPersonData());
                    isDone = true;
                    break;
                case 3:
                    isDone = true;
                    break;
                default:
                    break;
                }
            }
            break;
        case 3:
            while (!isDone)
            {
                cout << "Select person to delete:\n";

                cout << "------------------------\n";

                db.PrintNames();

                cout << db.GetSize() + 1 << ". Return.\n";

                cout << "------------------------\n\n";

                int ch = 0;

                cout << ">>> ";
                cin >> ch;

                system("cls");

                cout << "\n";

                if (ch > 0 && ch < db.GetSize() + 1)
                {
                    db.DeletePerson(ch - 1);
                    isDone = true;
                }
                else if (ch == db.GetSize() + 1)
                {
                    isDone = true;
                }
            }
            break;
        case 4:
            while (!isDone)
            {
                cout << "Type a name to search in data:\n";

                cout << "------------------------------\n\n";

                char buf[20];

                cin.ignore();

                cout << ">>> ";
                cin.getline(buf, 20);

                system("cls");

                cout << "Results for: " << buf << "\n";

                cout << "-------------------------------------\n\n";

                db.Search(buf);

                cout << "\n";
                
                isDone = true;
            }
            break;
        case 5:
            return 0;
            break;
        default:
            break;
        }
    }

    delete[] pds;
}
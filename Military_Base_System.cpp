#include <iostream>
using namespace std;
int id; // it is declared globally to stop major from using nuclear missiles.

class MilitaryBase
{
private:
    string base_name;
    string location;
    string security_level;
    string type_missile;
    double capacity;
    double est_date;

public:
    MilitaryBase(string base_name, string location, double capacity, string security_level, double est_date, string type_missile)
    {
        this->base_name = base_name;
        this->location = location;
        this->capacity = capacity;
        this->security_level = security_level;
        this->est_date = est_date;
        this->type_missile = type_missile;
    }

    string getBase_name()
    {
        return base_name;
    }
    string getLocation()
    {
        return location;
    }
    double getCapacity()
    {
        return capacity;
    }
    string getSecurity()
    {
        return security_level;
    }
    double getEst_date()
    {
        return est_date;
    }

    virtual void display()
    {
        cout << "------------------------------------------------" << endl;
        cout << "Name of base:      " << base_name << endl;
        cout << "Location of base:  " << location << endl;
        cout << "Capacity of base:  " << capacity << endl;
        cout << "Type of missiles:  " << type_missile << endl;
        cout << "Security level:    " << security_level << endl;
        cout << "Established since: " << est_date << endl;
    }

    virtual void launchmissile() = 0;
    virtual void checkrange() = 0;
};
class AirForce : public MilitaryBase
{
private:
    string has_control_tower;
    string city;
    string choice;
    double runway_length;
    int plain_capacity;
    int pass;

    void checkrange()
    {
        cout << endl;
        cout << "These are the cities in your range: " << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "London\nEdinburg\nDublin\nParis\nAmsterdam" << endl;
        cout << "----------------------------------------------------" << endl
             << endl;
        cout << "Enter City to attack: " << endl;
        cin >> city;

        if (city == "London" || city == "london" || city == "Edinburg" || city == "edinburg" || city == "Dublin" || city == "dublin" || city == "Paris" || city == "paris" || city == "Amsterdam" || city == "amsterdam")
        {
            cout << endl;
            cout << "----------------------------------------------------" << endl;
            cout << city << " is in range" << endl;
            cout << "----------------------------------------------------" << endl
                 << endl;
        }
    }

public:
    AirForce(int plain_capacity, double runway_length, string has_control_tower, string base_name, string location, double capacity, string security_level, double est_date, string type_missile)
        : MilitaryBase(base_name, location, capacity, security_level, est_date, type_missile)
    {
        this->plain_capacity = plain_capacity;
        this->runway_length = runway_length;
        this->has_control_tower = has_control_tower;
    }

    void display()
    {
        MilitaryBase::display();
        cout << "No. of AirPlanes:  " << plain_capacity << endl;
        cout << "Length of runway:  " << runway_length << endl;
        cout << "Control Tower:     " << has_control_tower << endl;
        cout << "------------------------------------------------" << endl;
    }

    void launchmissile()
    {
        checkrange();
        if (city == "London" || city == "london" || city == "Edinburg" || city == "edinburg" || city == "Dublin" || city == "dublin" || city == "Paris" || city == "paris" || city == "Amsterdam" || city == "amsterdam")
        {
            cout << "Enter key to launch missile or press e to exit " << endl;
            cin >> pass;
            if (pass == 1234)
            {
                cout << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "Missile has been Launched on " << city << endl;
                cout << "----------------------------------------------------" << endl
                     << endl;
                cout << "Press Y to launch another missile on a City\nPress E to exit" << endl;
                cin >> choice;

                if (choice == "Y" || choice == "y")
                {
                    launchmissile();
                }
                if (choice == "E" || choice == "e")
                {
                    exit(0);
                }
            }
            if (pass != 1234)
            {
                cout << "Wrong key\nLog in again to lauch Missile" << endl;
                exit(0);
            }
        }
        else
        {
            cout << city << " is out of range" << endl;
            cout << "----------------------------------------------------" << endl;
            cout << "Press Y to launch another missile on a City\nPress E to exit" << endl
                 << endl;
            cin >> choice;
            if (choice == "Y" || choice == "y")
            {
                launchmissile();
            }
            if (choice == "E" || choice == "e")
            {
                exit(0);
            }
        }
    }
};
class Navy : public MilitaryBase
{
private:
    string has_shipyard;
    string city;
    string l;
    string choice;
    int dock_capacity;
    int submarine_pens;
    int pass;

    void checkrange()
    {
        cout << "These are the cities in your range: " << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Moscow\nIstanbul\nCairo\nMumbai\nBangkok\nJakarta" << endl;
        cout << "----------------------------------------------------" << endl
             << endl;
        cout << "Enter City to attack: " << endl;
        cin >> city;

        if (city == "Moscow" || city == "moscow" || city == "Istanbul" || city == "istanbul" || city == "Cairo" || city == "cairo" || city == "Mumbai" || city == "mumbai" || city == "Bangkok" || city == "bangkok" || city == "Jakarta" || city == "jakarta")
        {
            cout << endl;
            cout << "----------------------------------------------------" << endl;
            cout << city << " is in range" << endl;
            cout << "----------------------------------------------------" << endl;
        }
    }

public:
    Navy(int dock_capacity, int submarine_pens, string has_shipyard, string base_name, string location, double capacity, string security_level, double est_date, string type_missile)
        : MilitaryBase(base_name, location, capacity, security_level, est_date, type_missile)
    {
        this->dock_capacity = dock_capacity;
        this->submarine_pens = submarine_pens;
        this->has_shipyard = has_shipyard;
    }

    void display()
    {
        MilitaryBase::display();
        cout << "No. of Docks:      " << dock_capacity << endl;
        cout << "N0. of Subramine pens: " << submarine_pens << endl;
        cout << "Shipyard:          " << has_shipyard << endl;
        cout << "------------------------------------------------" << endl;
    }

    void launchmissile()
    {
        checkrange();
        if (city == "Moscow" || city == "moscow" || city == "Istanbul" || city == "istanbul" || city == "Cairo" || city == "cairo" || city == "Mumbai" || city == "mumbai" || city == "Bangkok" || city == "bangkok" || city == "Jakarta" || city == "jakarta")
        {
            cout << endl;
            if (id == 4321)
            {
                cout << "Press A for ballistic missile: " << endl;
                cin >> l;
                if (l == "b" || l == "B")
                {
                    cout << "You are not allowed to use Nuclear missile" << endl
                         << endl;
                    launchmissile();
                }
            }
            if (id == 8765)
            {
                cout << "Press A for ballistic missile or press B for Nuclear missile: " << endl;
                cin >> l;
            }
            cout << endl;
            cout << "----------------------------------------------------" << endl;
            cout << "Enter Key to launch missile or press e to exit " << endl;
            cin >> pass;

            if (pass == 1234)
            {
                if (l == "a" || l == "A")
                {
                    cout << endl;
                    cout << "----------------------------------------------------" << endl;
                    cout << "Ballistic missile has been Launched on " << city << endl;
                    cout << "----------------------------------------------------" << endl
                         << endl;
                    cout << "Press Y to launch another missile on a City\nPress E to exit" << endl;
                    cin >> choice;

                    if (choice == "Y" || choice == "y")
                    {
                        launchmissile();
                    }
                    if (choice == "E" || choice == "e")
                    {
                        exit(0);
                    }
                }
                else if (l == "b" || l == "B")
                {
                    cout << endl;
                    cout << "----------------------------------------------------" << endl;
                    cout << "Nuclear Missile has been Launched on " << city << endl;
                    cout << "----------------------------------------------------" << endl
                         << endl;
                    cout << "Press Y to launch another missile on a City\nPress E to exit" << endl
                         << endl;
                    cin >> choice;

                    if (choice == "Y" || choice == "y")
                    {
                        launchmissile();
                    }
                    if (choice == "E" || choice == "e")
                    {
                        exit(0);
                    }
                }
            }
            if (pass != 1234)
            {
                cout << "Wrong key\nLog in again to launch Missile" << endl;
                exit(0);
            }
        }
        else
        {
            cout << city << " is out of range" << endl;
            cout << "----------------------------------------------------" << endl;
            cout << "Press Y to launch another missile on a City\nPress E to exit" << endl;
            cin >> choice;
            if (choice == "Y" || choice == "y")
            {
                launchmissile();
            }
            if (choice == "E" || choice == "e")
            {
                exit(0);
            }
        }
    }
};
class land : public MilitaryBase
{
private:
    string has_artillery_storage;
    string city;
    string choice;
    int tanks_capacity;
    int training_grounds;
    int pass;

    void checkrange()
    {
        cout << "These are the cities in your range: " << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Istanbul\nMoscow\nCairo\nRiyadh\nKarachi\nTehran" << endl;
        cout << "----------------------------------------------------" << endl
             << endl;
        cout << "Enter City to attack: " << endl;
        cin >> city;

        if (city == "Istanbul" || city == "istanbul" || city == "Moscow" || city == "moscow" || city == "Cairo" || city == "cairo" || city == "Riyadh" || city == "riyadh" || city == "Karachi" || city == "karachi" || city == "Tehran" || city == "tehran")
        {
            cout << endl;
            cout << "----------------------------------------------------" << endl;
            cout << city << " is in range" << endl;
            cout << "----------------------------------------------------" << endl;
        }
    }

public:
    land(int tanks_capacity, int training_grounds, string has_artillery_storage, string base_name, string location, double capacity, string security_level, double est_date, string type_missile)
        : MilitaryBase(base_name, location, capacity, security_level, est_date, type_missile)
    {
        this->tanks_capacity = tanks_capacity;
        this->training_grounds = training_grounds;
        this->has_artillery_storage = has_artillery_storage;
    }

    void display()
    {
        MilitaryBase::display();
        cout << "No. of tanks:      " << tanks_capacity << endl;
        cout << "Training grounds : " << training_grounds << endl;
        cout << "Artillery storage: " << has_artillery_storage << endl;
        cout << "------------------------------------------------" << endl;
    }

    void launchmissile()
    {
        checkrange();
        if (city == "Istanbul" || city == "istanbul" || city == "Moscow" || city == "moscow" || city == "Cairo" || city == "cairo" || city == "Riyadh" || city == "riyadh" || city == "Karachi" || city == "karachi" || city == "Tehran" || city == "tehran")
        {
            cout << endl;
            cout << "Enter Key to launch missile or press e to exit " << endl;
            cin >> pass;
            if (pass == 1234)
            {
                cout << "----------------------------------------------------" << endl;
                cout << "Missile has been Launched on " << city << endl;
                cout << "----------------------------------------------------" << endl
                     << endl;
                cout << "Press Y to launch another missile on a City\nPress E to exit" << endl
                     << endl;
                cin >> choice;

                if (choice == "Y" || choice == "y")
                {
                    launchmissile();
                }
                if (choice == "E" || choice == "e")
                {
                    exit(0);
                }
            }
            if (pass != 1234)
            {
                cout << "Wrong key\nLog in again to lauch Missile" << endl;
                exit(0);
            }
        }
        else
        {
            cout << city << " is out of range" << endl;
            cout << "----------------------------------------------------" << endl;
            cout << "Press Y to launch another missile on a City\nPress E to exit" << endl;
            cin >> choice;
            if (choice == "Y" || choice == "y")
            {
                launchmissile();
            }
            if (choice == "E" || choice == "e")
            {
                exit(0);
            }
        }
    }
};
class WarTroops
{
protected:
    string l;
    string check;
    int key;
private:
    string base_name;
    string location;
    int Area;

public:
    WarTroops(string base_name, string location, int Area)
    {
        this->base_name = base_name;
        this->location = location;
        this->Area = Area;
    }

    virtual void prepareForWar()
    {
        cout << "Preparing for War.\n";
    }

    void display()
    {
        cout << "------------------------------------------------" << endl;
        cout << "Name of the base:    " << base_name << endl;
        cout << "Location of base:    " << location << endl;
        cout << "Area of the base:    " << Area << " km square" << endl;
    }

    virtual void status() = 0;
};

class SpecialForce : public WarTroops
{
private:
    string l;
    string check;
    int key;

protected:
    string Operational_bases;
    string Training_Facilities;
    string Special_equipment_warehouses;

public:
    SpecialForce(string Operational_bases, string Training_Facilities, string Special_equipment_warehouses, int Area, string base_name, string location)
        : WarTroops(base_name, location, Area)
    {
        this->Operational_bases = Operational_bases;
        this->Training_Facilities = Training_Facilities;
        this->Special_equipment_warehouses = Special_equipment_warehouses;
    }

    void display()
    {
        WarTroops::display();
        cout << "Operational Bases:   " << Operational_bases << endl;
        cout << "Training Facilities: " << Training_Facilities << endl;
        cout << "Special Equipment:   " << Special_equipment_warehouses << endl;
        cout << "------------------------------------------------" << endl;
    }

    void status()
    {
        cout << "------------------------------------------------" << endl;
        cout << "Special force is ready for combat" << endl;
        cout << "------------------------------------------------" << endl
             << endl;
        cout << "Select area for deployment: " << endl;
        cout << "HongKong\nSingapore\nManila\nBangkok" << endl;
        cout << "------------------------------------------------" << endl;
        cin >> l;

        if (l == "HongKong" || l == "hongkong" || l == "Singapore" || l == "singapore" || l == "Manila" || l == "manila" || l == "Bangkok" || l == "bangkok")
        {
            cout << endl;
            cout << "------------------------------------------------" << endl;
            cout << l << " is in range" << endl;
            cout << "------------------------------------------------" << endl
                 << endl;
            cout << "Enter key for deployment: " << endl;
            cin >> key;
            if (key == 5678)
            {
                cout << endl;
                cout << "------------------------------------------------" << endl;
                cout << "Special Forces have been deployed in " << l << endl;
                cout << "------------------------------------------------" << endl
                     << endl;
                cout << "Press Y to change area\nPress E to exit" << endl;
                cin >> check;
                if (check == "Y" || check == "y")
                {
                    status();
                }
                else
                {
                    cout << "Exiting Program" << endl;
                    exit(0);
                }
            }
            else
            {
                cout << endl;
                cout << "Wrong key\nExiting Program" << endl;
                exit(0);
            }
        }
        else
        {
            cout << l << " is out of range" << endl
                 << endl;
            cout << "Press Y to change area\nPress E to exit" << endl;
            cin >> check;
            if (check == "Y" || check == "y")
            {
                status();
            }
            else
            {
                cout << "Exiting Program" << endl;
                exit(0);
            }
            status();
        }
    }
};

class CyberWarfareForce : public WarTroops
{
protected:
    string Network;
    int DataCentres;
    int Labs;

public:
    CyberWarfareForce(string Network, int DataCentres, int Labs, int Area, string base_name, string location)
        : WarTroops(base_name, location, Area)
    {
        this->Network = Network;
        this->DataCentres = DataCentres;
        this->Labs = Labs;
    }

    void display()
    {
        WarTroops::display();
        cout << "Network in base:     " << Network << endl;
        cout << "Data Centres:        " << DataCentres << endl;
        cout << "Labs in base:        " << Labs << endl;
        cout << "------------------------------------------------" << endl;
    }

    void status()
    {
        cout << "------------------------------------------------" << endl;
        cout << "Cyber team is ready for attack" << endl;
        cout << "------------------------------------------------" << endl
             << endl;
        cout << "Select area for deployment: " << endl;
        cout << "Tehran\nBeijing\nAgra\nBerlin" << endl;
        cout << "------------------------------------------------" << endl;
        cin >> l;

        if (l == "Tehran" || l == "tehran" || l == "Beijing" || l == "beijing" || l == "Agra" || l == "agra" || l == "Berlin" || l == "berlin")
        {
            cout << endl;
            cout << "------------------------------------------------" << endl;
            cout << l << " is accessible" << endl;
            cout << "------------------------------------------------" << endl
                 << endl;
            cout << "Enter key for cyber attack: " << endl;
            cin >> key;
            if (key == 5678)
            {
                cout << endl;
                cout << "------------------------------------------------" << endl;
                cout << "Cyber attack has begun on " << l << endl;
                cout << "------------------------------------------------" << endl
                     << endl;
                cout << "Press Y to change city\nPress E to exit" << endl;
                cin >> check;
                if (check == "Y" || check == "y")
                {
                    status();
                }
                else
                {
                    cout << "Exiting Program" << endl;
                    exit(0);
                }
            }
            else
            {
                cout << endl;
                cout << "Wrong key\nExiting Program" << endl;
                exit(0);
            }
        }
        else
        {
            cout << l << " is not accessible" << endl
                 << endl;
            cout << "Press Y to change area\nPress E to exit" << endl;
            cin >> check;
            if (check == "Y" || check == "y")
            {
                status();
            }
            else
            {
                cout << "Exiting Program" << endl;
                exit(0);
            }
            status();
        }
    }
};
int main()
{
    string name;
    string gender;
    string num_base;
    int age;

    cout << "Please enter your name: " << endl;
    cin >> name;
    cout << "Please enter your age: " << endl;
    cin >> age;
    if (age < 18 || age > 65)
    {
        cout << "Your age is not qualified for this" << endl;
        exit(0);
    }
    cout << "Please enter your gender" << endl;
    cout << "------------------------" << endl;
    cout << "Press M for male\nPress F for female\nPress W for Walmart bag(Preferred)" << endl;
    cout << "------------------------" << endl;
    cin >> gender;
    if (gender == "M" || gender == "m" || gender == "F" || gender == "f" || gender == "W" || gender == "w")
    {
    cout << "Please enter your Id: " << endl;
    cin >> id;
    cout << endl;
    }
    else
    {
        cout << "Invalid Gender" << endl;
        cout << "Yes Walmart bag is a Valid Gender" << endl;
        exit(0);
    }

    if (id == 1234)
    {
        cout << "------------------------------------------" << endl;
        cout << "Welcome Lieutenant " << name << " Please choose your field:" << endl;
        cout << "------------------------------------------" << endl
             << endl;
        cout << "--------------------" << endl; // Lieutenant can only access these 3 fields.
        cout << "1.AirForce\n2.Navy\n3.LandForce" << endl;
        cout << "--------------------" << endl;
        cin >> num_base;
    }

    else if (id == 5678)
    {
        cout << "------------------------------------------" << endl;
        cout << "Welcome Colonel " << name << " Please choose your field:" << endl;
        cout << "------------------------------------------" << endl
             << endl;
        cout << "--------------------" << endl; // Colonal can only access these 3 fields.
        cout << "1.AirForce\n2.Navy\n3.LandForce" << endl;
        cout << "--------------------" << endl;
        cin >> num_base;
    }

    else if (id == 4321)
    {
        cout << "------------------------------------------" << endl;
        cout << "Welcome Major " << name << " Please choose your field:" << endl;
        cout << "------------------------------------------" << endl
             << endl;
        cout << "--------------------" << endl; // Major cannot fire nuclear missile
        cout << "1.AirForce\n2.Navy\n3.LandForce\n4.SpecialForce\n5.CyberForce" << endl;
        cout << "--------------------" << endl;
        cin >> num_base;
    }

    else if (id == 8765)
    {
        cout << "------------------------------------------" << endl;
        cout << "Welcome General " << name << " Please choose your field:" << endl;
        cout << "------------------------------------------" << endl
             << endl;
        cout << "--------------------" << endl; // General has all access
        cout << "1.AirForce\n2.Navy\n3.LandForce\n4.SpecialForce\n5.CyberForce" << endl;
        cout << "--------------------" << endl;
        cin >> num_base;
    }

    else
    {
        cout << "Invalid id" << endl;
        exit(0);
    }

    if (num_base == "AirForce" || num_base == "airforce" || num_base == "1")
    {
        AirForce af1(50, 3000.0, "Available", "Air Base 1", "Manchester", 1000.0, "High", 1990.0, "na");
        af1.display();

        if(id == 1234 || id == 5678)
        {
            cout<<"You have limited access"<<endl;
            exit(0);               
        }

        if (id != 1234 && id != 5678)
        {
            cout << endl;
            cout << "-----------------------------------------------" << endl;
            cout << "Press x to launch a missle or press e to exit" << endl;
            cout << "-----------------------------------------------" << endl;
            cin >> name;
            if (name == "x" || name == "X")
            {
                af1.launchmissile();
            }
        }
    }

    if (num_base == "Navy" || num_base == "navy" || num_base == "2")
    {
        Navy n1(5, 10, "Available", "Naval Base 1", "Xinjai", 500.0, "Medium", 1985.0, "Ballistic and Nuclear");
        n1.display();

        if(id == 1234 || id == 5678)
        {
            cout<<"You have limited access"<<endl;
            exit(0);               
        }

        if (id != 1234 && id != 5678)
        {
            cout << endl;
            cout << "------------------------------------------------" << endl;
            cout << "Press x to launch a missile or press e to exit" << endl;
            cout << "------------------------------------------------" << endl;
            cin >> name;
            if (name == "x" || name == "X")
            {
                n1.launchmissile();
            }
        }
    }

    if (num_base == "LandForce" || num_base == "landforce" || num_base == "3")
    {
        land l1(100, 20, "Available", "Army Base 1", "Kandhar", 2000.0, "Low", 1975.0, "Hyper Sonic");
        l1.display();

        if(id == 1234 || id == 5678)
        {
            cout<<"You have limited access"<<endl;
            exit(0);               
        }

        if (id != 1234 && id != 5678)
        {
            cout << endl;
            cout << "------------------------------------------------" << endl;
            cout << "Press x to launch a missle or press e to exit" << endl;
            cout << "------------------------------------------------" << endl;
            cin >> name;
            if (name == "x" || name == "X")
            {
                l1.launchmissile();
            }
        }
    }

    if ((id != 1234 && id != 5678) && (num_base == "SpecialForce" || num_base == "specialforce" || num_base == "4")) // Due to operator precedence.
    {
        SpecialForce sf("Base1", "Training Camp", "High-Tech Weapons Storage", 1000, "Special Force Unit", "Vietnam");
        sf.display();
        cout << endl;
        cout << "------------------------------------------------" << endl;
        cout << "Press s to check status or press e to exit" << endl;
        cout << "------------------------------------------------" << endl;
        cin >> name;
        if (name == "s" || name == "S")
        {
            sf.status();
        }
        else
        {
            cout << "Exiting Program" << endl;
            exit(0);
        }
    }

    if ((id != 1234 && id != 5678) && (num_base == "CyberForce" || num_base == "cyberforce" || num_base == "5")) // Due to operator precedence.
    {
        CyberWarfareForce cf("SecureNetwork", 5, 3, 25, "Cyber Force Unit", "Lahore");
        cf.display();
        cout << endl;
        cout << "------------------------------------------------" << endl;
        cout << "Press s to check status or press e to exit" << endl;
        cout << "------------------------------------------------" << endl;
        cin >> name;
        if (name == "s" || name == "S")
        {
            cf.status();
        }
        else
        {
            cout << "Exiting Program" << endl;
            exit(0);
        }
    }

    else
    {
        cout << "Invalid Field" << endl;
    }
}

// leutinant id = 1234
// colonal id = 5678
// major id = 4321
// general id = 8765
// key to launch missile = 1234
// key for deployment = 5678

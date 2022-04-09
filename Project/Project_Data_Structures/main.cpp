#include<bits/stdc++.h>

using namespace std;

struct people
{
    string first_name;
    string last_name;
    string ssn;
    string birthday;
    string city;
    string work;
};

struct accounts
{
    string ssn;
    string bank_name;
    string IBAN;
    string account_id;
};

struct homes
{
    string ssn;
    string price;
    string postal_code;
    string size;
    string address;
};

struct cars
{
    string plate;
    string ssn;
    string model;
    string color;
};

struct phones
{
    string ssn;
    string number;
    string oper;
};

struct ownerships_edge
{
    string from_ownership;
    string to_ownership;
    string ownership_id;
    string date;
    string amount;
};

struct transactions_edge
{
    string from_transaction;
    string to_transaction;
    string transaction_id;
    string date;
    string amount;
};

struct calls_edge
{
    string from_call;
    string to_call;
    string call_id;
    string date;
    string duration;
};

struct relationships_edge
{
    string from_relationship;
    string to_relationship;
    string relationship;
    string date;
};

int main()
{
    string line , a , b;
    int counter=0 , s , flag = 0;
    unordered_map<string , people> vp;
    unordered_map<string , people> Faz1_Ghachaghchi_Ha;
    unordered_map<string , people> Faz1_Maznonin_Koli;
    people pep;
    ifstream file_people("people.csv");
    if(file_people.is_open())
    {
        while (getline(file_people, line))
        {
            if(flag == 0)
            {
                flag ++;
                continue;
            }
            s = line.size();
            for(int i=1 ; i<s ; i++)
            {
                counter++;
                if(counter == 1)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    pep.first_name = a;
                    a = "";
                    i += 2;
                }
                else if(counter == 2)
                {
                    while (line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    pep.last_name = a;
                    a = "";
                    i += 2;
                }
                else if(counter == 3)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    pep.ssn = a;
                    b = a;
                    a = "";
                    i += 2;
                }
                else if(counter == 4)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    pep.birthday = a;
                    a = "";
                    i += 2;
                }
                else if(counter == 5)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    pep.city = a;
                    a = "";
                    i += 2;
                }
                else if(counter == 6)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    pep.work=a;
                    if(a == "گمرک" || a == "سازمان بنادر")
                        Faz1_Maznonin_Koli.insert({b , pep});
                    else if(a == "قاچاقچی")
                        Faz1_Ghachaghchi_Ha.insert({b , pep});
                    a = "";
                    break;
                }
            }
            vp.insert({b , pep});
            counter = 0;
        }
        file_people.close();
    }
    else
        cout << "Unable to open file :(" << endl;
    fstream FAZ1;
    FAZ1.open("Faz1.txt", ios::out);
    FAZ1 << "Ghachaghchi Ha_Faz1:" << endl;
    FAZ1 << endl;
    FAZ1 << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout<<"Ghachaghchi Ha Faze1:"<<endl;
    unordered_map<string , people > :: iterator it;
    for (it = Faz1_Ghachaghchi_Ha.begin(); it != Faz1_Ghachaghchi_Ha.end(); it++)
    {
        FAZ1 << it->second.first_name << "   ";
        cout << it->second.first_name << " ";
        FAZ1 << it->second.last_name << "   ";
        cout << it->second.last_name << " ";
        FAZ1 << it->second.ssn << "   ";
        cout << it->second.ssn << " ";
        FAZ1 << it->second.birthday << "   ";
        cout << it->second.birthday << " ";
        FAZ1 << it->second.city << "   ";
        cout << it->second.city << " ";
        FAZ1 << it->second.work << "   ";
        cout << it->second.work << " ";
        FAZ1 << endl;
        FAZ1 << endl;
        FAZ1 << "---------------------------------------------------------------" << endl;
        cout << endl;
    }
    FAZ1 << endl;
    FAZ1 << "Maznonin_Faz1:" << endl;
    FAZ1 << endl;
    FAZ1 << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout<<"Maznonin Faze1:"<<endl;
    unordered_map<string , people > :: iterator itt;
    for (itt = Faz1_Maznonin_Koli.begin(); itt != Faz1_Maznonin_Koli.end(); itt++)
    {
        FAZ1 << itt->second.first_name << "   ";
        cout << itt->second.first_name << " ";
        FAZ1 << itt->second.last_name << "   ";
        cout << itt->second.last_name << " ";
        FAZ1 << itt->second.ssn << "   ";
        cout << itt->second.ssn << " ";
        FAZ1 << itt->second.birthday << "   ";
        cout << itt->second.birthday << " ";
        FAZ1 << itt->second.city << "   ";
        cout << itt->second.city << " ";
        FAZ1 << itt->second.work << "   ";
        cout << itt->second.work << " ";
        FAZ1 << endl;
        FAZ1 << endl;
        FAZ1 << "---------------------------------------------------------------" << endl;
        cout << endl;
    }
    flag = 0;
    string c , r ;
    relationships_edge ralat_e;
    vector<relationships_edge> rel;
    unordered_map<string , vector<relationships_edge> > relationship_e;
    ifstream file_relationships("relationships.csv");
    if (file_relationships.is_open())
    {
        while (getline(file_relationships, line))
        {
            if (flag == 0) {
                flag++;
                continue;
            }
            r = "";
            s=line.size();
            for(int i=1 ; i<s ; i++)
            {
                counter++;
                if(counter == 1)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    ralat_e.from_relationship = a;
                    c = a;
                    a = "";
                    i += 2;
                }
                else if(counter == 2)
                {
                    while (line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    ralat_e.to_relationship = a;
                    b = a;
                    a = "";
                    i += 2;
                }
                else if(counter==3)
                {
                    while(line[i]!='"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    ralat_e.relationship = a;
                    a = "";
                }
                else if(counter==4)
                {
                    while(line[i]!='"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    ralat_e.date = a;
                    a = "";
                    break;
                }
            }
            r += c;
            r.push_back('_');
            r += b;
            rel.clear();
            auto it = relationship_e.begin();
            it = relationship_e.find(r);
            if (it != relationship_e.end())
                it->second.push_back(ralat_e);
            else
            {
                rel.push_back(ralat_e);
                relationship_e.insert({r , rel});
            }
            rel.clear();
            counter=0;
        }
        file_relationships.close();
    }
    else
        cout << "Unable to open file :(" << endl;
    string ss, dat, month, day, year, year_dat, month_dat, day_dat , kelid;
    int dday, yyear, yyear_dat, mmonth, mmonth_dat, dday_dat;
    ownerships_edge owner_e;
    vector<ownerships_edge> own;
    unordered_map<string , vector<ownerships_edge> > ownership_e;
    unordered_map<string , people> Faz2_Maznonin;
    flag = 0;
    ifstream file_ownerships_edge("ownerships.csv");
    if(file_ownerships_edge.is_open())
    {
        while(getline(file_ownerships_edge, line))
        {
            if (flag == 0) {
                flag++;
                continue;
            }
            s=line.size();
            ss = "";
            for(int i=1 ; i<s ; i++)
            {
                counter++;
                if(counter == 1)
                {

                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    owner_e.from_ownership = a;
                    ss = a;
                    a = "";
                    i += 2;
                }
                else if(counter == 2)
                {
                    while (line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    owner_e.to_ownership = a;
                    b = a;
                    a = "";
                    i += 2;
                }
                else if(counter == 3)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    owner_e.ownership_id = a;
                    a = "";
                    i += 2;
                }
                else if(counter == 4)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    owner_e.date = a;
                    dat = a;
                    a="";
                    i+=2;
                }
                else if(counter == 5)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    owner_e.amount = a;
                    a="";
                    break;
                }
            }
            year_dat="";
            year="";
            month="";
            month_dat="";
            day="";
            day_dat="";
            kelid="";
            for(int i=0 ; i<4 ; i++)
                year_dat+=dat[i];
            yyear_dat=atoi(year_dat.c_str());
            time_t now = time(0);
            char* dt = ctime(&now);
            string b = dt;
            int s_dt = b.size();
            for(int i=s_dt-5 ; i<s_dt-1 ; i++)
                year+=b[i];
            yyear=atoi(year.c_str());
            if((yyear-yyear_dat)<2)
            {
                auto ii = Faz1_Maznonin_Koli.begin();
                ii = Faz1_Maznonin_Koli.find(ss);
                if(ii != Faz1_Maznonin_Koli.end())
                    Faz2_Maznonin.insert({ss , ii ->second});
                else if(ii == Faz1_Maznonin_Koli.end())
                {
                    for(auto x : Faz1_Maznonin_Koli)
                    {
                        kelid="";
                        kelid+=ss;
                        kelid.push_back('_');
                        kelid+=x.first;
                        auto f=relationship_e.begin();
                        f = relationship_e.find(kelid);
                        if(f != relationship_e.end())
                            Faz2_Maznonin.insert({x.first , x.second});
                    }
                }
            }
            else if((yyear-yyear_dat)==2)
            {
                for(int i=4 ; i<7 ; i++)
                    month+=b[i];
                if (month == "Jan")
                    mmonth=1;
                else if(month == "Feb")
                    mmonth=2;
                else if(month == "Mar")
                    mmonth=3;
                else if(month == "Apr")
                    mmonth=4;
                else if(month == "May")
                    mmonth=5;
                else if(month == "Jun")
                    mmonth=6;
                else if(month == "Jul")
                    mmonth=7;
                else if(month == "Aug")
                    mmonth=8;
                else if(month == "Sep")
                    mmonth=9;
                else if(month == "Oct")
                    mmonth=10;
                else if(month == "Nov")
                    mmonth=11;
                else
                    mmonth=12;
                for(int i=5 ; i<7 ; i++)
                    month_dat+=dat[i];
                mmonth_dat=atoi(month_dat.c_str());
                if(mmonth_dat>mmonth)
                {
                    auto ii = Faz1_Maznonin_Koli.begin();
                    ii = Faz1_Maznonin_Koli.find(ss);
                    if(ii != Faz1_Maznonin_Koli.end())
                        Faz2_Maznonin.insert({ss , ii ->second});
                    else if(ii == Faz1_Maznonin_Koli.end())
                    {
                        for(auto x : Faz1_Maznonin_Koli)
                        {
                            kelid="";
                            kelid+=ss;
                            kelid.push_back('_');
                            kelid+=x.first;
                            auto f=relationship_e.begin();
                            f = relationship_e.find(kelid);
                            if(f != relationship_e.end())
                                Faz2_Maznonin.insert({x.first , x.second});
                        }
                    }
                }
                else if(mmonth_dat==mmonth)
                {
                    for(int i=8 ; i<10 ; i++)
                        day_dat+=dat[i];
                    dday_dat=atoi(day_dat.c_str());
                    for(int i=8 ; i<10 ; i++)
                        day+=b[i];
                    dday=atoi(day.c_str());
                    if(dday_dat>=dday)
                    {
                        auto ii = Faz1_Maznonin_Koli.begin();
                        ii = Faz1_Maznonin_Koli.find(ss);
                        if(ii != Faz1_Maznonin_Koli.end())
                            Faz2_Maznonin.insert({ss , ii ->second});
                        else if(ii == Faz1_Maznonin_Koli.end())
                        {
                            for(auto x : Faz1_Maznonin_Koli)
                            {
                                kelid="";
                                kelid+=ss;
                                kelid.push_back('_');
                                kelid+=x.first;
                                auto f=relationship_e.begin();
                                f = relationship_e.find(kelid);
                                if(f != relationship_e.end())
                                    Faz2_Maznonin.insert({x.first , x.second});
                            }
                        }
                    }
                }
            }
            counter=0;
        }
    }
    else
        cout << "Unable to open file :(" << endl;
    fstream FAZ2_Moznonin;
    FAZ2_Moznonin.open("Mazninin_Faz2.txt", ios::out);
    FAZ2_Moznonin << "Maznonin_Faz2:" << endl;
    FAZ2_Moznonin << endl;
    FAZ2_Moznonin << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout<<"Maznonin Faze2:"<<endl;
    unordered_map<string , people > :: iterator ittt;
    for (ittt = Faz2_Maznonin.begin(); ittt != Faz2_Maznonin.end(); ittt++)
    {
        FAZ2_Moznonin << ittt->second.first_name << "   ";
        cout << ittt->second.first_name << " ";
        FAZ2_Moznonin << ittt->second.last_name << "   ";
        cout << ittt->second.last_name << " ";
        FAZ2_Moznonin << ittt->second.ssn << "   ";
        cout << ittt->second.ssn << " ";
        FAZ2_Moznonin << ittt->second.birthday << "   ";
        cout << ittt->second.birthday << " ";
        FAZ2_Moznonin << ittt->second.city << "   ";
        cout << ittt->second.city << " ";
        FAZ2_Moznonin << ittt->second.work << "   ";
        cout << ittt->second.work << " ";
        FAZ2_Moznonin << endl;
        FAZ2_Moznonin << endl;
        FAZ2_Moznonin << "---------------------------------------------------------------" << endl;
        cout << endl;
    }
    unordered_map<string , accounts> va;
    accounts acc;
    counter=0;
    flag=0;
    ifstream file_accounts("accounts.csv");
    if(file_accounts.is_open())
    {
        while (getline(file_accounts, line))
        {
            if(flag == 0)
            {
                flag ++;
                continue;
            }
            s = line.size();
            for(int i=1 ; i<s ; i++)
            {
                counter++;
                if(counter == 1)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    acc.ssn=a;
                    a = "";
                    i += 2;
                }
                else if(counter == 2)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    acc.bank_name = a;
                    a = "";
                    i += 2;
                }
                else if(counter == 3)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    acc.IBAN = a;
                    a="";
                    i+=2;
                }
                else if(counter == 4)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    acc.account_id = a;
                    b = a;
                    a = "";
                    break;
                }
            }
            va.insert({b , acc});
            counter = 0;
        }
        file_accounts.close();
    }
    else
        cout << "Unable to open file :(" << endl;
    unordered_map<string , homes> vh;
    homes hom;
    counter = 0;
    flag=0;
    ifstream file_homes("homes.csv");
    if(file_homes.is_open())
    {
        while (getline(file_homes, line))
        {
            if (flag == 0) {
                flag++;
                continue;
            }
            s=line.size();
            for(int i=1 ; i<s ; i++)
            {
                counter++;
                if(counter == 1)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    hom.ssn = a;
                    a = "";
                    i += 2;
                }
                else if(counter == 2)
                {
                    while (line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    hom.price = a;
                    a = "";
                    i += 2;
                }
                else if(counter == 3)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    hom.postal_code = a;
                    b = a;
                    a = "";
                    i += 2;
                }
                else if(counter == 4)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    hom.size = a;
                    a = "";
                    i += 2;
                }
                else if(counter == 5)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    hom.address = a;
                    a = "";
                    break;
                }
            }
            vh.insert({b , hom});
            counter = 0;
        }
        file_homes.close();
    }
    else
        cout << "Unable to open file :(" << endl;
    unordered_map<string , cars> vc;
    cars cr;
    counter = 0;
    flag = 0;
    ifstream file_cars("cars.csv");
    if(file_cars.is_open())
    {
        while(getline(file_cars, line))
        {
            if (flag == 0) {
                flag++;
                continue;
            }
            s=line.size();
            for(int i=1 ; i<s ; i++)
            {
                counter++;
                if(counter == 1)
                {
                    while(line[i]!='"')
                    {
                        a=a+line[i];
                        i++;
                    }
                    cr.plate=a;
                    b=a;
                    a="";
                    i+=2;
                }
                else if(counter == 2)
                {
                    while (line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    cr.ssn = a;
                    a = "";
                    i += 2;
                }
                else if(counter == 3)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    cr.model = a;
                    a="";
                    i+=2;
                }
                else if(counter == 4)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    cr.color = a;
                    a = "";
                    break;
                }
            }
            vc.insert({b , cr});
            counter = 0;
        }
        file_cars.close();
    }
    else
        cout << "Unable to open file :(" << endl;
    unordered_map<string , phones> vph;
    phones ph;
    flag=0;
    ifstream file_phones("phones.csv");
    if (file_phones.is_open())
    {
        while (getline(file_phones, line))
        {
            if (flag == 0) {
                flag++;
                continue;
            }
            s=line.size();
            for(int i=1 ; i<s ; i++)
            {
                counter++;
                if(counter == 1)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    ph.ssn = a;
                    a = "";
                    i += 2;
                }
                else if(counter == 2)
                {
                    while (line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    ph.number = a;
                    b = a;
                    a = "";
                    i += 2;
                }
                else if(counter==3)
                {
                    while(line[i]!='"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    ph.oper = a;
                    a = "";
                    break;
                }
            }
            vph.insert({b , ph});
            counter = 0;
        }
        file_phones.close();
    }
    else
        cout << "Unable to open file :(" << endl;
    flag=0;
    calls_edge cll_e;
    phones fr , t;
    vector<calls_edge> cl;
    unordered_map<string , vector<calls_edge> > calls_e;
    ifstream file_calls_edge("calls.csv");
    if(file_calls_edge.is_open())
    {
        while(getline(file_calls_edge, line))
        {
            if (flag == 0) {
                flag++;
                continue;
            }
            s=line.size();
            for(int i=1 ; i<s ; i++)
            {
                counter++;
                if(counter == 1)
                {

                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    cll_e.from_call = a;
                    fr = vph.find(a)->second;
                    a = "";
                    i += 2;
                }
                else if(counter == 2)
                {
                    while (line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    cll_e.to_call = a;
                    t = vph.find(a)->second;
                    a = "";
                    i += 2;
                }
                else if(counter == 3)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    cll_e.call_id = a;
                    a = "";
                    i += 2;
                }
                else if(counter == 4)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    cll_e.date = a;
                    a="";
                    i+=2;
                }
                else if(counter == 5)
                {
                    while(line[i] != '"')
                    {
                        a = a+line[i];
                        i++;
                    }
                    cll_e.duration = a;
                    a="";
                    break;
                }
            }
            auto it = calls_e.begin();
            it = calls_e.find(fr.number);
            if (it != calls_e.end())
                it->second.push_back(cll_e);
            else
            {
                cl.push_back(cll_e);
                calls_e.insert({fr.number , cl});
            }
            cl.clear();
            it = calls_e.find(t.number);
            if (it != calls_e.end())
                it->second.push_back(cll_e);
            else
            {
                cl.push_back(cll_e);
                calls_e.insert({t.number , cl});
            }
            counter=0;
        }
        file_calls_edge.close();
    }
    else
        cout << "Unable to open file :(" << endl;
    string work1 , work2 , p1 , p2;
    unordered_map<string , people> Faz4;
    people aa , bb;
    for(auto x : calls_e)
    {
        work1 = "";
        work2 = "";
        auto it = vph.begin();
        it = vph.find(x.first);
        if (it != vph.end())
        {
            auto itr = vp.begin();
            itr = vp.find(it->second.ssn);
            if (itr != vp.end())
            {
                work1 = itr->second.work;
                p1 = itr->second.ssn;
                aa = itr->second;
            }
        }
        if (work1 == "قاچاقچی" || work1=="گمرک" || work1=="سازمان بنادر")
        {
            int s=x.second.size();
            for(int i=0 ; i<s ; i++)
            {
                if(x.first == x.second[i].from_call)
                {
                    auto it = vph.begin();
                    it = vph.find(x.second[i].to_call);
                    if(it != vph.end())
                    {
                        auto itr = vp.begin();
                        itr = vp.find(it->second.ssn);
                        if (itr != vp.end())
                        {
                            work2 = itr->second.work;
                            p2 = itr->second.ssn;
                            bb = itr->second;
                        }
                    }
                    if(work1 == "قاچاقچی" && (work2 == "سازمان بنادر" || work2 == "گمرک"))
                        Faz4.insert({p2 , bb});
                    else if((work1 == "سازمان بنادر" || work1 == "گمرک") && work2 == "قاچاقچی" )
                        Faz4.insert({p1 , aa});
                }
                else if(x.first == x.second[i].to_call)
                {
                    auto it = vph.begin();
                    it = vph.find(x.second[i].from_call);
                    if(it != vph.end())
                    {
                        auto itr = vp.begin();
                        itr = vp.find(it->second.ssn);
                        if (itr != vp.end())
                        {
                            work2 = itr->second.work;
                            p2 = itr->second.ssn;
                            bb = itr->second;
                        }
                    }
                    if(work1 == "قاچاقچی" && (work2 == "سازمان بنادر" || work2 == "گمرک"))
                        Faz4.insert({p2 , bb});
                    else if((work1 == "سازمان بنادر" || work1 == "گمرک") && work2 == "قاچاقچی" )
                        Faz4.insert({p1 , aa});
                }
            }
        }
    }
    fstream FAZ4_Moznonin;
    FAZ4_Moznonin.open("Mazninin_Faz4.txt", ios::out);
    FAZ4_Moznonin << "Maznonin_Faz4:" << endl;
    FAZ4_Moznonin << endl;
    FAZ4_Moznonin << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout<<"Maznonin Faze4:"<<endl;
    unordered_map<string , people> :: iterator itr;
    for (itr = Faz4.begin(); itr != Faz4.end(); itr++)
    {
        FAZ4_Moznonin << itr->second.first_name << "   ";
        cout << itr->second.first_name << " ";
        FAZ4_Moznonin << itr->second.last_name << "   ";
        cout << itr->second.last_name << " ";
        FAZ4_Moznonin << itr->second.ssn << "   ";
        cout << itr->second.ssn << " ";
        FAZ4_Moznonin << itr->second.birthday << "   ";
        cout << itr->second.birthday << " ";
        FAZ4_Moznonin << itr->second.city << "   ";
        cout << itr->second.city << " ";
        FAZ4_Moznonin << itr->second.work << "   ";
        cout << itr->second.work << " ";
        FAZ4_Moznonin << endl;
        FAZ4_Moznonin << endl;
        FAZ4_Moznonin << "---------------------------------------------------------------" << endl;
        cout << endl;
    }
}

#ifndef MESSAGES_H
#define MESSAGES_H
#include <map>
#include <list>
#include <string>
#include <iostream>
#include "sms.h"
using namespace std;

class Messages
{
private:
    string phoneNumber;
    map<string, list<Sms>> messages;
    //pointer tároló, ami eltárolja az összes üzenetet, így könnyebb használni az üzeneteket.
    list<Sms*> all_message;
public:
    Messages(const string& pn):phoneNumber(pn){}

    void receive(Sms& s)
    {
        if(s.getPhoneNumber() == phoneNumber)
        {
            throw "Error";
        }
        s.setType(Incoming);
        // először a számot adjuk meg, utána az egész SMS-t, hozzáadódik messages MAP-hez
        //Pushback a list miatt kell
        messages[s.getPhoneNumber()].push_back(s);


        all_message.push_back(&s);
    }


    void send(Sms& s)
    {
        if(s.getPhoneNumber() == phoneNumber)
        {
            throw "Error";
        }
        s.setType(Outgoing);

        // először a számot adjuk meg, utána az egész SMS-t, hozzáadódik messages MAP-hez
        messages[s.getPhoneNumber()].push_back(s);
        all_message.push_back(&s);
    }

    void preview(int count = 5)
    {
        //Lambda paraméteres sort [](){}
        //Helyben rendezte az üzeneteket dátum szerint
        // HA nincs megadva semmi akkor nem tud rendezni
        all_message.sort([](Sms* s1, Sms* s2){return s2->getTimestamp() < s1->getTimestamp();});

        if(all_message.size() > count)
        {
            int i = 0;
            for(auto it = all_message.begin(); i<count; i++, it++)
            {
                Sms s = **it;
                //kiiratja az üzeneteket amik kellettek
                cout << s.getPhoneNumber() << " - " << s.getTimestamp() << " - " << (s.getType() == Incoming ? " (<-) " : " (->) ")
                << endl << s.getMessage() << endl;


            }
        }
        else
        {
            for(auto it = all_message.begin(); it != all_message.end(); it++)
            {
                Sms s = **it;
                //kiiratja az üzeneteket amik kellettek
                cout << s.getPhoneNumber() << " - " << s.getTimestamp() << " - " << (s.getType() == Incoming ? " (<-) " : " (->) ")
                << endl << s.getMessage() << endl;


            }
        }
    }


};

#endif // MESSAGES_H

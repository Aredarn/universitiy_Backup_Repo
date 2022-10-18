#include <iostream>
#include <list>

#include "sms.h"
#include "messages.h"

using namespace std;

void print(const list<Sms>& sms){
    if(sms.empty()){
        cout << "No result :(" << endl;
    }
    else {
        for(auto& s : sms){
            cout << s.getPhoneNumber() << " - " << s.getTimestamp() << " ("
                 << (s.getType() == SmsType::Incoming ? "<-" : "->") << ")" << endl;
            cout << "\t" << s.getMessage() << endl;
        }
    }
}

int main()
{
    // 1. feladat
    {
        cout << "1. feladat" << endl;

        Messages m("+36301249795");

        Sms s1("+36305027774", "2021.10.24. 12:45:11", "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
        Sms s2("+36204171469", "2021.10.22. 10:34:05", "Vivamus ultrices sagittis risus, ac dignissim lectus dignissim aliquet.");
        Sms s3("+36301249795", "2021.10.21. 06:40:23", "Phasellus ullamcorper libero ac ligula porta, sit amet tempus leo tempus.");
        Sms s4("+36701236914", "2021.10.23. 15:12:56", "Curabitur in maximus risus, cursus auctor orci. Sed a condimentum metus, et imperdiet orci.");
        Sms s5("+36301133221", "2021.10.24. 22:22:12", "Vivamus sollicitudin neque et augue commodo, eu rhoncus felis fringilla.");
        list<Sms> smsOut = {s1, s2, s3, s4, s5};
        for(auto& s : smsOut){
            try {
                m.send(s);
                cout << "Sent a message to " << s.getPhoneNumber() << endl;
            } catch (...) {
                cout << "Don't send a message to yourself, it's just sad." << endl;
            }
        }

        cout << endl;

        Sms s6("+36305027774", "2021.10.24. 12:45:11", "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
        Sms s7("+36204171469", "2021.10.22. 10:34:05", "Vivamus ultrices sagittis risus, ac dignissim lectus dignissim aliquet.");
        Sms s8("+36301249795", "2021.10.21. 06:40:23", "Phasellus ullamcorper libero ac ligula porta, sit amet tempus leo tempus.");
        Sms s9("+36701236914", "2021.10.23. 15:12:56", "Curabitur in maximus risus, cursus auctor orci. Sed a condimentum metus, et imperdiet orci.");
        Sms s10("+36301133221", "2021.10.24. 22:22:12", "Vivamus sollicitudin neque et augue commodo, eu rhoncus felis fringilla.");
        list<Sms> smsIn = {s6, s7, s8, s9, s10};
        for(auto& s : smsIn){
            try {
                m.receive(s);
                cout << "Received a message from " << s.getPhoneNumber() << endl;
            } catch (...) {
                cout << "Message from yourself. No." << endl;
            }
        }
    }

    cout << endl << endl;

    // 2. feladat
    {
        cout << "2. feladat" << endl;

       Messages m("+36301249795");

        Sms s1("+36305027774", "2021.10.24. 12:45:11", "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
        Sms s2("+36204171469", "2021.10.22. 10:34:05", "Vivamus ultrices sagittis risus, ac dignissim lectus dignissim aliquet.");
        Sms s3("+36701236914", "2021.10.21. 06:40:23", "Phasellus ullamcorper libero ac ligula porta, sit amet tempus leo tempus.");
        Sms s4("+36701236914", "2021.10.23. 15:12:56", "Curabitur in maximus risus, cursus auctor orci. Sed a condimentum metus, et imperdiet orci.");
        Sms s5("+36301133221", "2021.10.24. 22:22:12", "Vivamus sollicitudin neque et augue commodo, eu rhoncus felis fringilla.");
        list<Sms> smsOut = {s1, s2, s3, s4, s5};
        for(auto& s : smsOut){ m.send(s); }

        Sms s6("+36305027774", "2021.10.24. 10:45:11", "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
        Sms s7("+36204171469", "2021.10.23. 11:34:05", "Vivamus ultrices sagittis risus, ac dignissim lectus dignissim aliquet.");
        Sms s8("+36204171469", "2021.10.25. 12:40:23", "Phasellus ullamcorper libero ac ligula porta, sit amet tempus leo tempus.");
        Sms s9("+36701236914", "2021.10.21. 16:12:56", "Curabitur in maximus risus, cursus auctor orci. Sed a condimentum metus, et imperdiet orci.");
        Sms s10("+36301133221", "2021.10.20. 10:22:12", "Vivamus sollicitudin neque et augue commodo, eu rhoncus felis fringilla.");
        list<Sms> smsIn = {s6, s7, s8, s9, s10};
        for(auto& s : smsIn){ m.receive(s); }

        m.preview(3);

       cout << endl;

       m.preview();

        cout << endl;

      m.preview(8);
    }

    cout << endl << endl;

//    // 3. feladat
//    {
//        cout << "3. feladat" << endl;

//        Messages m("+36301249795");

//        Sms s1("+36305027774", "2021.10.24. 12:45:11", "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
//        Sms s2("+36204171469", "2021.10.22. 10:34:05", "Vivamus ultrices sagittis risus, ac dignissim lectus dignissim aliquet.");
//        Sms s3("+36701236914", "2021.10.21. 06:40:23", "Phasellus ullamcorper libero ac ligula porta, sit amet tempus leo tempus.");
//        Sms s4("+36701236914", "2021.10.23. 15:12:56", "Curabitur in maximus risus, cursus auctor orci. Sed a condimentum metus, et imperdiet orci.");
//        Sms s5("+36301133221", "2021.10.24. 22:22:12", "Vivamus sollicitudin neque et augue commodo, eu rhoncus felis fringilla.");
//        list<Sms> smsOut = {s1, s2, s3, s4, s5};
//        for(auto& s : smsOut){ m.send(s); }

//        Sms s6("+36305027774", "2021.10.24. 10:45:11", "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
//        Sms s7("+36204171469", "2021.10.23. 11:34:05", "Vivamus ultrices sagittis risus, ac dignissim lectus dignissim aliquet.");
//        Sms s8("+36204171469", "2021.10.25. 12:40:23", "Phasellus ullamcorper libero ac ligula porta, sit amet tempus leo tempus.");
//        Sms s9("+36701236914", "2021.10.21. 16:12:56", "Curabitur in maximus risus, cursus auctor orci. Sed a condimentum metus, et imperdiet orci.");
//        Sms s10("+36301133221", "2021.10.20. 10:22:12", "Vivamus sollicitudin neque et augue commodo, eu rhoncus felis fringilla.");
//        list<Sms> smsIn = {s6, s7, s8, s9, s10};
//        for(auto& s : smsIn){ m.receive(s); }

//        auto sms1 = m.search("Vivamus");
//        print(sms1);

//        cout << endl;

//        auto sms2 = m.search("Kakszi");
//        print(sms2);

//        cout << endl;

//        auto sms3 = m.search("consectetur");
//        print(sms3);
//    }

    cout << endl << endl;

//    // 4. feladat
//    {
//        cout << "4. feladat" << endl;

//        Messages m("+36301249795");

//        Sms s1("+36305027774", "2021.10.24. 12:45:11", "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
//        Sms s2("+36204171469", "2021.10.22. 10:34:05", "Vivamus ultrices sagittis risus, ac dignissim lectus dignissim aliquet.");
//        Sms s3("+36701236914", "2021.10.21. 06:40:23", "Phasellus ullamcorper libero ac ligula porta, sit amet tempus leo tempus.");
//        Sms s4("+36701236914", "2021.10.23. 15:12:56", "Curabitur in maximus risus, cursus auctor orci. Sed a condimentum metus, et imperdiet orci.");
//        Sms s5("+36301133221", "2021.10.24. 22:22:12", "Vivamus sollicitudin neque et augue commodo, eu rhoncus felis fringilla.");
//        list<Sms> smsOut = {s1, s2, s3, s4, s5};
//        for(auto& s : smsOut){ m.send(s); }

//        Sms s6("+36305027774", "2021.10.24. 10:45:11", "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
//        Sms s7("+36204171469", "2021.10.23. 11:34:05", "Vivamus ultrices sagittis risus, ac dignissim lectus dignissim aliquet.");
//        Sms s8("+36204171469", "2021.10.25. 12:40:23", "Phasellus ullamcorper libero ac ligula porta, sit amet tempus leo tempus.");
//        Sms s9("+36701236914", "2021.10.21. 16:12:56", "Curabitur in maximus risus, cursus auctor orci. Sed a condimentum metus, et imperdiet orci.");
//        Sms s10("+36301133221", "2021.10.20. 10:22:12", "Vivamus sollicitudin neque et augue commodo, eu rhoncus felis fringilla.");
//        list<Sms> smsIn = {s6, s7, s8, s9, s10};
//        for(auto& s : smsIn){ m.receive(s); }

//        m.printThread("+36703264921");

//        cout << endl;

//        m.printThread("+36204171469");
//    }

    cout << endl << endl;

//    // 5. feladat
//    {
//        cout << "5. feladat" << endl;

//        Messages m("+36301249795");

//        Sms s1("+36305027774", "2021.10.24. 12:45:11", "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
//        Sms s2("+36204171469", "2021.10.22. 10:34:05", "Vivamus ultrices sagittis risus, ac dignissim lectus dignissim aliquet.");
//        Sms s3("+36701236914", "2021.10.21. 06:40:23", "Phasellus ullamcorper libero ac ligula porta, sit amet tempus leo tempus.");
//        Sms s4("+36701236914", "2021.10.23. 15:12:56", "Curabitur in maximus risus, cursus auctor orci. Sed a condimentum metus, et imperdiet orci.");
//        Sms s5("+36301133221", "2021.10.24. 22:22:12", "Vivamus sollicitudin neque et augue commodo, eu rhoncus felis fringilla.");
//        list<Sms> smsOut = {s1, s2, s3, s4, s5};
//        for(auto& s : smsOut){ m.send(s); }

//        Sms s6("+36305027774", "2021.10.24. 10:45:11", "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
//        Sms s7("+36204171469", "2021.10.23. 11:34:05", "Vivamus ultrices sagittis risus, ac dignissim lectus dignissim aliquet.");
//        Sms s8("+36204171469", "2021.10.25. 12:40:23", "Phasellus ullamcorper libero ac ligula porta, sit amet tempus leo tempus.");
//        Sms s9("+36701236914", "2021.10.21. 16:12:56", "Curabitur in maximus risus, cursus auctor orci. Sed a condimentum metus, et imperdiet orci.");
//        Sms s10("+36301133221", "2021.10.20. 10:22:12", "Vivamus sollicitudin neque et augue commodo, eu rhoncus felis fringilla.");
//        list<Sms> smsIn = {s6, s7, s8, s9, s10};
//        for(auto& s : smsIn){ m.receive(s); }

//        m.listNumbers();
//    }


    return 0;
}

#ifndef SMS_H
#define SMS_H

#include<string>

using namespace std;

enum SmsType {
    Incoming,
    Outgoing
};

class Sms
{
private:
    string phoneNumber;
    string timestamp;
    string message;
    SmsType type;
public:
    Sms();
    Sms(const string& pn, const string& t, const string& m);

    string getPhoneNumber() const;
    string getTimestamp() const;
    string getMessage() const;
    SmsType getType() const;
    void setType(const SmsType &value);

    bool contains(const string& msgPart) const;
};

#endif // SMS_H

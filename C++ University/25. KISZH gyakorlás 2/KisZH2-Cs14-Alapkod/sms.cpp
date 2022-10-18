#include "sms.h"

Sms::Sms()
{

}

Sms::Sms(const string &pn, const string &t, const string &m):
    phoneNumber(pn), timestamp(t), message(m)
{

}

string Sms::getPhoneNumber() const
{
    return phoneNumber;
}

string Sms::getTimestamp() const
{
    return timestamp;
}

string Sms::getMessage() const
{
    return message;
}

SmsType Sms::getType() const
{
    return type;
}

void Sms::setType(const SmsType &value)
{
    type = value;
}

bool Sms::contains(const string &msgPart) const
{
    return message.find(msgPart) != string::npos;
}

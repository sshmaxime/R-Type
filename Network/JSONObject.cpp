//
// Created by sshsupreme on 13/01/18.
//

#include "JSONObject.h"

std::ostream &operator<<(std::ostream &out, const JSONObject &obj)
{
    out << obj._JSON.dump(2);
    return out;
}

std::string JSONObject::getHEADER()
{
    return (this->__HEADER__);
}
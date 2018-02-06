//
// Created by sshsupreme on 13/01/18.
//

#include "JSONObject.h"

std::ostream            &operator<<(std::ostream &out, const JSONObject &obj)
{
    out << obj._JSON.dump(2);
    return out;
}

std::string             JSONObject::getHEADER() const
{
    return (this->__HEADER__);
}

std::string             JSONObject::getJSON() const
{
    return (_JSON.dump(-1));

}

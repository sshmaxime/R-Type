//
// Created by sshsupreme on 10/01/18.
//

#ifndef R_TYPE_JSONOBJECT_H
#define R_TYPE_JSONOBJECT_H

#include <iostream>
#include "../../json.hpp"

using JSON = nlohmann::json;

class JSONObject {
protected:
    JSON                            _JSON;
    std::string                     __HEADER__;

public:
    std::string                     getHEADER();

public:
    virtual int                     buildObjectFromJSON(const std::string&) = 0;
    virtual std::string             getJSON() = 0;

    friend  std::ostream& operator<< (std::ostream &out, const JSONObject&);

};


#endif //R_TYPE_JSONOBJECT_H

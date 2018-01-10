//
// Created by sshsupreme on 10/01/18.
//

#ifndef R_TYPE_JSONOBJECT_H
#define R_TYPE_JSONOBJECT_H

#include <string>
#include "../json.hpp"

class JSONObject {
public:
    virtual int                     buildObjectFromJSON(const std::string&) = 0;
    virtual std::string             buildJSONFromObject() = 0;
};

#endif //R_TYPE_JSONOBJECT_H

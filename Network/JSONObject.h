//
// Created by sshsupreme on 10/01/18.
//

#ifndef R_TYPE_JSONOBJECT_H
#define R_TYPE_JSONOBJECT_H

#include <iostream>
#include "../json.hpp"

using JSON = nlohmann::json;

class JSONObject {
protected:
    JSON                            _JSON;

public:
    virtual int                     buildObjectFromJSON(const std::string&) = 0;
    virtual std::string             getJSON() = 0;


public:
    void                            BeautifulPrint();
};

#endif //R_TYPE_JSONOBJECT_H

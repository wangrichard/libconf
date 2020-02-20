#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sstream>

#include <stddef.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#include "conf_file.hpp"


namespace libconf
{

conf_file::conf_file(const std::string & path)
:m_path(path)
{

}


conf_file::~conf_file()
{

}


int conf_file::load(void)
{
    std::stringstream str_stream;
    std::fstream in_file;
    std::string content;

    in_file.open(m_path.c_str(), std::fstream::in);
    str_stream << in_file.rdbuf();
    content = str_stream.str();
    std::cout << "Content: " << content << std::endl;
    in_file.close();

    if (m_json != nullptr)
    {
        json_object_put(m_json);
    }
    m_json = json_tokener_parse(content.c_str());
    
    if (m_json == nullptr)
    {
        std::cout << "Conf file parse error! Create empty entity." << std::endl;
        m_json = json_object_new_object();
    }

    return 0;
}


int conf_file::save(void)
{
    std::fstream out_file;
    const char *jp;

    out_file.open(m_path.c_str(), std::fstream::out|std::fstream::trunc);

    if ((jp=json_object_to_json_string(m_json)) != nullptr)
    {
        out_file << jp;
    }
    else
    {
        std::cout << "conf save failed." << std::endl;
    }

    out_file.close();

    return 0;
}


int conf_file::get(const char *key, int *val)
{
    json_object *jstatus;

    if ((key==nullptr) || (val==nullptr))
    {
        std::cout << "Input parameter null." << std::endl;
    }

    if (nullptr != (jstatus=json_object_object_get(m_json, key)))
    {
        *val = json_object_get_int(jstatus);
        std::cout << key << ": " << *val << std::endl;
    }
    else
    {
        std::cout << "Operation on " << key << " failed." <<std::endl;
    }

    return 0;
}


int conf_file::get(const char *key, bool *val)
{
    json_object *jstatus;

    if ((key==nullptr) || (val==nullptr))
    {
        std::cout <<  "Input parameter null." << std::endl;
    }

    if (nullptr != (jstatus=json_object_object_get(m_json, key)))
    {
        *val = json_object_get_boolean(jstatus);
        std::cout << key << ": " << *val << std::endl;
    }
    else
    {
        std::cout << "Operation on " << key << " failed." <<std::endl;
    }

    return 0;
}


int conf_file::get(const char *key, std::string & val)
{
    json_object *jstatus;

    if (key == nullptr)
    {
        std::cout << "Input parameter null." << std::endl;
    }

    if (nullptr != (jstatus=json_object_object_get(m_json, key)))
    {
        val = json_object_get_string(jstatus);
        std::cout << key << ": " << val << std::endl;
    }
    else
    {
        std::cout << "Operation on " << key << " failed." <<std::endl;
    }

    return 0;
}


int conf_file::set(const char *key, int val)
{
    return (json_object_object_add(m_json, key, json_object_new_int(val)));
}


int conf_file::set(const char *key, bool val)
{
    return (json_object_object_add(m_json, key, json_object_new_boolean(val)));
}


int conf_file::set(const char *key, const char *val)
{
    return (json_object_object_add(m_json, key, json_object_new_string(val)));
}


void conf_file::del(const char *key)
{
    json_object_object_del(m_json, key);
}

} // libconf

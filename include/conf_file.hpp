#ifndef __CONF_FILE__
#define __CONF_FILE__

#include <iostream>
#include <string>
#include <fstream>
#include <iostream>

#include <json-c/json.h>


namespace libconf
{

class conf_file
{
public:
    conf_file() = delete;
    conf_file(const std::string & path);
    ~conf_file();

    int load(void);
    int save(void);

    int get(const char *key, int *val);
    int get(const char *key, bool *val);
    int get(const char *key, std::string & val);

    int set(const char *key, int val);
    int set(const char *key, bool val);
    int set(const char *key, const char *val);

    void del(const char *key);

    bool m_shutdown = false;

private:
    std::string m_path;
    json_object *m_json = nullptr;
};

}

#endif //__CONF_FILE__

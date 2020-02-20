#include <unistd.h>

#include "conf_file.hpp"


int main(void)
{
    int int_val;
    bool bool_val;
    std::string str;

    auto conf = new libconf::conf_file("/tmp/test.txt");

    conf->load();
    conf->set("test1", 20);
    conf->set("test2", 40);
    conf->set("test3", true);
    conf->set("test4", "hello world");
    conf->save();
    conf->get("test1", &int_val);
    conf->get("test2", &int_val);
    conf->get("test3", &bool_val);
    conf->get("test4", str);
    conf->del("test2");
    conf->get("test2", &int_val);

    while (!conf->m_shutdown)
    {
        sleep(1);
    }

    delete conf;

    return 0;
}

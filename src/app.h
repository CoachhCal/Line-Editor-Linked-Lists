#ifndef ASSIGNMENT1_APP_H
#define ASSIGNMENT1_APP_H

#include <string>

class App {
public:

    bool _is_active = true;
    void line_editor(int, char**);
    void handle_input(std::string const&, const std::string&);
    void save_file(const std::string& );

};

#endif //ASSIGNMENT1_APP_H
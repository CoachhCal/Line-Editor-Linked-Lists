#include <iostream>
#include <fstream>
#include <sstream>
#include "linked_list.h"
#include "app.h"

LinkedList list;

void App::line_editor(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
    }

    std::fstream file;
    file.open(argv[1], std::ios::in | std::ios::out);

    //if file does not currently exist, this will create it (if it's a valid file name)
    if (!file.is_open()) {
        file.clear();
        file.open(argv[1], std::ios::out);
        if (!file.is_open()) {
            std::cerr << "Error: could not open or create file " << argv[1] << std::endl;
            return;
        }
        file.close();
        file.open(argv[1], std::ios::in | std::ios::out);
    }

    std::string myText;

    //create nodes with the data from the file.
    while (getline(file, myText)) {
        list.add(myText);
    }

    std::cout << list;
    std::string user_input;

    while (_is_active) {
        std::cout << list._current_line << ">";
        std::getline(std::cin, user_input);
        handle_input(user_input, argv[1]);
    }
    file.close();
}

void App::handle_input(std::string const& text, const std::string& file_name){

    std::string command;
    std::stringstream ss(text);

    ss >> command;

    if (command.length() > 1 || ss.str().contains('-')) {
        list.add(ss.str());
        return;
    }
    else {
        int start = -1;
        ss >> start;
        if (!ss.eof()) {
            if (ss.fail()) {
                list.add(ss.str());
                return;
            }
        }

        int end = -1;
        ss >> end;
        if (!ss.eof()){
            ss >> end;
            if (ss.fail()) {
                list.add(ss.str());
                return;
            }
        }

        if (start == 0 || start > list._total_nodes || end > list._total_nodes || end < start && end != -1) {
            list.add(ss.str());
            return;
        }

        if (command == "L") {
            if (start == -1 && end == -1) {
                std::cout << list;
            }
            else if (start != -1) {
                list.show_list(start, end, list);
            }
        }
        else if (command == "I") {
            if (start == -1 && end == -1) {
                list._current_line--;
            }
            else if (start != -1 && end == -1) {
                list._current_line = start;
            }
            else {
                list.add(ss.str());
            }
        }

        else if (command == "D") {
            if (start == -1 && end == -1) {
                list.delete_node(list._current_line + start, end);
            }
            else if (start != -1) {
                list.delete_node(start, end);
            }
        }
        else if (command == "E" && start == -1 && end == -1) {
            save_file(file_name);
            _is_active = false;
        }
        else if (command == "Q" && start == -1 && end == -1) {
            _is_active = false;
        }
        else {
            list.add(ss.str());
        }
    }
}

void App::save_file(const std::string& filename) {
    std::ofstream outfile(filename);
    if (!outfile.is_open()) {
        std::cerr << "Error: could not open file for saving " << filename << std::endl;
        return;
    }

    //populates the file with the data stored within the nodes
    auto node = list._start;
    while (node != nullptr) {
        outfile << node->_data << std::endl;
        node = node->_next;
    }
}


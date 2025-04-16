#include "linked_list.h"

void LinkedList::add(const std::string& data) {
    auto node = new Node({data});

    //if at the end line
    if(_current_line == _total_nodes + 1) {

        if (_start == nullptr) {
            _start = node;
        }
        else {
            auto prev = static_cast<Node *>(nullptr);
            auto curr = _start;

            while (curr != nullptr) {
                prev = curr;
                curr = curr->_next;
            }
            if (prev != nullptr) {
                prev->_next = node;
            }
        }
    }
    else {
        insert(data);
    }
    _current_line++;
    _total_nodes++;
}

void LinkedList::insert(std::string data) {
    auto new_node = new Node({data});
    auto node = _start;
    auto prev = static_cast<Node*>(nullptr);
    int line_number = 1;

    while (node != nullptr) {
        if (line_number == _current_line) {
            break;
        }
        prev = node;
        node = node->_next;
        line_number++;
    }

    if (node != nullptr) {
        if (prev == nullptr) {
            new_node->_next = _start;
            _start = new_node;
        }
        else {
            new_node->_next = prev->_next;
            prev->_next = new_node;
        }
    }
}

void LinkedList::remove(int line_to_delete) {
    auto prev = static_cast<Node*>(nullptr);
    auto node = _start;
    int line_number = 1;

        while (node != nullptr) {
            if (line_number == line_to_delete) {
                break;
            }
            prev = node;
            node = node->_next;
            line_number++;
        }

        if (node != nullptr) {
            if (prev == nullptr) {
                _start = node->_next;
            }
            else {
                prev->_next = node->_next;
            }

            delete node;
            _total_nodes--;
            _current_line = _total_nodes + 1;
        }
}

void LinkedList::show_list(int start, int end, LinkedList& list) {
    if(start == -1 && end == -1) {
        std::cout << list;
        list._current_line = list._total_nodes + 1;
        return;
    }
    else {
        auto node = list._start;
        int line_number = 1;

        while (node != nullptr) {

            //List a single line
            if (end == -1 && line_number == start) {
                list._current_line = line_number + 1;
                std::cout << line_number << ">" << node->_data << "\n";
                return;
            }
            //List a range of lines
            if (end != -1 && start <= line_number && line_number <= end) {
                std::cout << line_number << ">" << node->_data << "\n";
                list._current_line = line_number + 1;
            }
            node = node->_next;
            line_number++;
        }
    }
}

void LinkedList::delete_node(int start, int end) {
    if (end == -1) {
        remove(start);
    }
    else {
        for(int x = start; x <= end; x++){
            remove(start);
        }
    }
}

std::ostream& operator<<(std::ostream& output, LinkedList& list) {
    auto node = list._start;
    int line_number = 1;

    while (node != nullptr) {
        output << line_number << ">" << node->_data << "\n";
        node = node->_next;
        line_number++;
    }

    list._current_line = list._total_nodes+1;
    return output;
}
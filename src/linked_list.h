#ifndef ASSIGNMENT1_LINKED_LIST_H
#define ASSIGNMENT1_LINKED_LIST_H

#include <iostream>
#include <string>

class LinkedList {
public:
    struct Node {
        std::string _data;
        Node* _next{nullptr};
    };

    int _total_nodes = 0;
    int _current_line = 1;
    Node* _start{nullptr};

    void show_list(int, int, LinkedList&);
    void delete_node(int, int);
    void add(const std::string&);
    void insert(std::string );
    void remove(int);

    friend std::ostream& operator<<(std::ostream&, LinkedList& );
};

#endif //ASSIGNMENT1_LINKED_LIST_H
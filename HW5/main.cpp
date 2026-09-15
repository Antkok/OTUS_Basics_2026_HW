#include "my_list.h"
#include "my_vector.h"

using namespace std;

int main() {

    std::cout << "==== MY VECTOR ==== " << std::endl;
    // MY VECTOR
    // 1
    MyVector<int> vec;

    // 2
    std::cout << " == Print capacity START ==" << std::endl;
    vec.push_back(0);
    vec.print_capacity();
    vec.push_back(1);
    vec.print_capacity();
    vec.push_back(2);
    vec.print_capacity();
    vec.push_back(3);
    vec.print_capacity();
    vec.push_back(4);
    vec.print_capacity();
    vec.push_back(5);
    vec.print_capacity();
    vec.push_back(6);
    vec.print_capacity();
    vec.push_back(7);
    vec.print_capacity();
    vec.push_back(8);
    vec.print_capacity();
    vec.push_back(9);
    vec.print_capacity();

    std::cout << "== Print capacity END ==" << std::endl;

    // 3
    vec.print_elements();

    // 4
    vec.print_size();

    // 5
    vec.erase(6);
    vec.erase(4);
    vec.erase(2);

    // 6
    vec.print_elements();

    // 7
    vec.insert(0, 10);

    // 8
    vec.print_elements();

    // 9
    vec.insert(vec.size()/2, 20);

    // 10
    vec.print_elements();

    // 11
    vec.insert(vec.size(), 30);

    // 12
    vec.print_elements();

    std::cout << "==== MY LIST ==== " << std::endl;

    // MY LIST
    // 1
    MyList<int> list;

    // 2
    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.push_back(9);

    // 3
    list.print_elements();

    // 4
    list.print_size();

    // 5
    list.erase(6);
    list.erase(4);
    list.erase(2);

    // 6
    list.print_elements();

    // 7
    list.insert(0, 10);

    // 8
    list.print_elements();

    // 9
    list.insert(list.size()/2, 20);

    // 10
    list.print_elements();

    // 11
    list.insert(list.size(), 30);

    // 12
    list.print_elements();

    return 0;
}
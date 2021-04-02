#include <iostream>
#include <string>
#include "GList.h"
#include "OWTests.cpp"
#include "ONWTests.cpp"
#include "NOWTests.cpp"
#include "NONWTests.cpp"
#include "../Algorithms/Algorithms.h"

typedef void (*fp_t)(void);

void tests(void)
{
    fp_t func[] = { O_W_tests, O_NW_tests, NO_W_tests, NO_NW_tests };
    
    func[0]();
    func[1]();
    func[2]();
    func[3]();
}

void integer_graph_tests(void)
{
    GList<int, int> g(true, false);
    for(size_t i = 1; i <= 12; i++) g.add_vertex(i);

#if 1
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(2, 4);
    g.add_edge(2, 5);
    g.add_edge(3, 6);
    g.add_edge(4, 7);
    g.add_edge(5, 8);
    g.add_edge(5, 9);
    g.add_edge(6, 7);
    g.add_edge(6, 10);
    g.add_edge(6, 11);
    g.add_edge(7, 8);
    g.add_edge(10, 11);
    g.add_edge(11, 12);
#endif

#if 0
    std::cout << std::boolalpha << g.has_vertex(99) << std::endl;
    std::cout << std::boolalpha << g.has_vertex(8) << std::endl;
    std::cout << std::boolalpha << g.has_edge(99, 1) << std::endl;
    std::cout << std::boolalpha << g.has_edge(7, 8) << std::endl;
    std::cout << std::boolalpha << g.has_edge(12, 11) << std::endl;
#endif

    for(size_t i = 1; i <= 12; i++) { g.BFS(i); g.DFS(i); }

#if 0
    g.print();
    g.remove_vertex(6);
    g.print();

    g.remove_edge(11, 12);
    g.print();

    g.print();
#endif

}

int main(void)
{
    tests();
    integer_graph_tests();

    return 0;
}
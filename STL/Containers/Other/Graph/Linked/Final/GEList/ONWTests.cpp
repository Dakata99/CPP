/* ORIENTED NON-WEIGHTED GRAPH TESTS */

void ONWTests()
{
    GEList<std::string, size_t> cities(5, true, false);
    
    cities.add("Dupnica", "Sofiq");
    cities.add("Sofiq", "Plovdiv");
    cities.add("Sofiq", "Varna");
    cities.add("Varna", "Burgas");
    cities.add("Plovdiv", "Burgas");
    cities.add("Qmbol");

    std::cout << "Is there a vertex, name Dupnicca ? - " << 
                std::boolalpha << cities.has_vertex("Dupnicca") << std::endl;

    cities.print();


    std::cout << "Is there an edge between Dupnica and Varna ? - " 
              << std::boolalpha << cities.has_edge("Dupnica", "Varna") << std::endl;
    
    std::cout << "Is there an edge between Plovdiv and Burgas ? - " 
              << std::boolalpha << cities.has_edge("Plovdiv", "Burgas") << std::endl;

    std::cout << "Is there an edge from Dupnica to Burgas ? - " 
              << std::boolalpha << cities.has_edge("Dupnica", "Burgas") << std::endl;

}

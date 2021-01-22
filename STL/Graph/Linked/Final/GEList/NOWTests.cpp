/* NON-ORIENTED WEIGHTED GRAPH TESTS */

void NOWTests()
{
    GEList<std::string, size_t> cities(5, false, true);
    std::cout << std::boolalpha << cities.has_vertex("Dupnicca") << std::endl;
    
    cities.add("Dupnica", "Sofiq", 60);
    cities.add("Kyustendil", "Dupnica");
    cities.add("Sofiq", "Plovdiv", 220);
    cities.add("Dobrich");
    cities.add("Sofiq", "Varna", 560);
    cities.add("Sofiq", "Burgas", 500);
    cities.add("Dobrich", "Plovdiv");
    cities.add("Varna", "Burgas", 115);
    cities.add("Plovdiv", "Burgas", 250);
    cities.add("Qmbol");

    cities.set("Qmbol", "Dobrich");
    cities.set("Qmbol", "Dobrich", 111);

    cities.print();
    
    std::cout << "Is there a vertex, name Dupnicca ? - " << 
                std::boolalpha << cities.has_vertex("Dupnicca") << std::endl;


    std::cout << "Is there an edge between Dupnica and Varna ? - " 
              << std::boolalpha << cities.has_edge("Dupnica", "Varna") << std::endl;
    
    std::cout << "Is there an edge between Plovdiv and Burgas ? - " 
              << std::boolalpha << cities.has_edge("Plovdiv", "Burgas") << std::endl;

    std::cout << "Is there an edge from Dupnica to Burgas ? - " 
              << std::boolalpha << cities.has_edge("Dupnica", "Burgas") << std::endl;

    cities.remove_edge("Sofiq", "Burgas");
    cities.print();
    cities.remove_vertex("Plovdiv");
    cities.print();

}

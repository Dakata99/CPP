/* ORIENTED WEIGHTED GRAPH TESTS */

void OW_tests(void)
{
    GEList<std::string, size_t> cities(true, true);

    std::string city_names[] = { "Vidin", "Sliven", "Vraca", "Sofiq", "Plovdiv", "Kyustendil", 
                                "Blagoevgrad", "Razgrad", "Pleven", "Varna", "Burgas", "Dobrich" };
     
    for(const std::string& city_name : city_names)  cities.add(city_name);
    
#if 1
    cities.add("Blagoevgrad", "Kyustendil", 10);
    cities.add("Kyustendil", "Sofiq", 20);
    cities.add("Blagoevgrad", "Sofiq", 30);
    cities.add("Vidin", "Sofiq", 40);
    cities.add("Vraca", "Sofiq", 50);
    cities.add("Vidin", "Vraca", 60);
    cities.add("Vraca", "Pleven", 70);
    cities.add("Pleven", "Razgrad", 80);
    cities.add("Pleven", "Dobrich", 90);
    cities.add("Razgrad", "Sofiq", 100);
    cities.add("Razgrad", "Dobrich", 110);
    cities.add("Razgrad", "Varna", 120);
    cities.add("Dobrich", "Varna", 130);
    cities.add("Razgrad", "Plovdiv", 140);
    cities.add("Sofiq", "Plovdiv", 150);
    cities.add("Plovdiv", "Burgas", 160);
    cities.add("Varna", "Burgas", 170);
    cities.add("Sliven", "Plovdiv", 180);
    cities.add("Burgas", "Sliven", 190);
    cities.add("Sofiq", "Varna", 200);
#endif
   
    cities.print();

#if 1
    std::cout << "Is there a vertex called Dupnicca ? - " 
              << std::boolalpha << cities.has_vertex("Dupnicca") << std::endl;
    
    std::cout << "Is there an edge between Dupnica and Varna ? - " 
              << std::boolalpha << cities.has_edge("Dupnica", "Varna") << std::endl;
    
    std::cout << "Is there an edge between Plovdiv and Burgas ? - " 
              << std::boolalpha << cities.has_edge("Plovdiv", "Burgas") << std::endl;

    std::cout << "Is there an edge between Burgas and Plovdiv ? - " 
              << std::boolalpha << cities.has_edge("Burgas", "Plovdiv") << std::endl;

    std::cout << "Is there an edge from Dupnica to Burgas ? - " 
              << std::boolalpha << cities.has_edge("Dupnica", "Burgas") << std::endl;
    
    cities.print_degrees();
#endif


#if 1
    cities.BFS("Vidin");

    cities.remove_edge("Sofiq", "Varna");
    cities.print();

    cities.remove_vertex("Sofiq");
    cities.remove_vertex("Razgrad");
    cities.add("Plovdiv", "Pleven", 210);
    cities.add("Vidin", "Kyustendil", 220);
    cities.add("Kyustendil", "Plovdiv", 230);
    cities.print();
    cities.BFS("Vidin");

    std::cout << std::boolalpha << "Is there a vertex named Sofiq? - " << cities.has_vertex("Sofiq") << std::endl;
    std::cout << std::boolalpha << "Is there a vertex named Razgrad? - " << cities.has_vertex("Razgrad") << std::endl;
    std::cout << std::boolalpha << "Is there a vertex named Plovdiv? - " << cities.has_vertex("Plovdiv") << std::endl;

    cities.DFS("Vidin");
    cities.DFS("Blagoevgrad");

    std::cout << std::boolalpha << "Is there a way from Blagoevgrad to Sliven? - " 
                                << cities.has_way("Blagoevgrad", "Sliven") << std::endl;

    std::cout << std::boolalpha << "Is there a way from Vidin to Varna? - " 
                                << cities.has_way("Vidin", "Varna") << std::endl;
    
    std::cout << std::boolalpha << "Is there a way from Kyustendil to Vidin? - " 
                                << cities.has_way("Kyustendil", "Vidin") << std::endl;

    //cities.print_successors("Plovdiv");
    //cities.print_predecessors("Plovdiv");    
#endif

}

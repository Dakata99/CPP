#include <iostream>
#include <algorithm>
#include <climits>
#include <chrono>
#include <queue>
#include <set>
#include <vector>
#include <fstream>  
#include <string>
#include <cstring>

void generate_random_matrix()
{
/* 
generating a random matrix, which represents the cities and the distances between them
and storing it in a file
*/

    std::cout << "Enter file name: ";

    std::string file_name;
    std::getline(std::cin, file_name); /* read file name */

    std::ofstream file(file_name); /* open file for writing */
    
    if(!file.is_open()) throw "Error"; /* error opening the file => exit */
    
    size_t cities;
    std::cout << "Enter number of cities: ";
    std::cin >> cities;

    size_t lower_bound = 1, upper_bound = 50;
    for (size_t i = 0; i < cities; i++)
    {
        for (size_t j = 0; j < cities; j++)
        {
            if(i == j)
                file << 0; /* distance form current town to current town = 0 */
            else
                file << (std::rand() % upper_bound + lower_bound); /* generating a distance between 1 and 50 */

            if(j == cities - 1)
                file << '\n';
            else
                file << ", ";
        }
    }
    
    file.close(); /* closing the file */

    std::cout << "Successfully genereted a matrix with elements of values between " 
              << lower_bound << " and " << upper_bound << "in file " << file_name << std::endl;
    std::cin.ignore();
}

void read(std::vector<std::vector<int>>& cities) 
{
/* reading the file data, which is in form of a matrix */

    std::cout << "Open a file: ";

    std::string file_name;
    std::getline(std::cin, file_name); /* read file name */
    
    std::ifstream file(file_name); /* open the file */
    if (!file.is_open()) throw "No such file!\n";

    std::string line;
    while (std::getline(file, line)) /* getting the file line by line */
    {
        std::vector<int> distances; /* this vector contains the distances from one city to other*/

        char *cstr = new char [line.length() + 1]; /* taking char* from string */
        std::strcpy (cstr, line.c_str());  /* taking char* from string */

        char *number = std::strtok(cstr, ",");  /* tokenizing the string */
        while (number != 0)
        {
            distances.push_back(std::stoi(number));
            number = std::strtok(NULL, ",");
        }

        delete[]cstr;
        cities.push_back(distances); /* pushing the each line of elements */
    }        
}

void random_A_star_alg()
{
    
}

/* 
    Time complexity : O((n - 1)!), where n is the number of cities 
    Space complexity : O()
*/
void A_star_alg(const std::vector<std::vector<int>>& cities, const size_t start, std::queue<size_t>& path, int& total_path)
{
/* storing all cities(vertices) apart from starting one(vertex) */
    std::vector<int> vertex;
    for (int i = 0; i < cities.size(); i++)
        if (i != start)
            vertex.push_back(i);

    int min_path = INT_MAX; /* store minimum weight Hamiltonian cycle */
    do 
    {
        std::queue<size_t> curr_path; /* stores the cities, representint the path in a graphical way */
        
        int current_path_weight = 0; /*  store current Path weight(cost) */
 
        /* calculate current path weight */
        size_t current = start; 
        curr_path.push(current); /* push the starting city */

        for (size_t i = 0; i < vertex.size(); i++) 
        {
            current_path_weight += cities[current][vertex[i]]; /* add the distance between current city and next city(vectex[i]) */
            current = vertex[i]; /* go to city(vertex[i]) */
            curr_path.push(current); /* push the next city */
        }
        curr_path.push(start); /* all cities are visited and going back to the starting one */
        current_path_weight += cities[current][start];
 
        if(current_path_weight <= min_path) /* found a new mininum path */
        {
            min_path = current_path_weight; /* update minimum */
            path = curr_path; /* update the new path */
        }
        /* or maybe use min_path = std::min(min_path, current_pathweight); ? */
 
    } while (next_permutation(vertex.begin(), vertex.end())); /* generate next permutation of cities */

    total_path = min_path; /* minimal total path */
}

/* 
    Time complexity : O((n - 1)!), where n is the number of cities 
    Space complexity : O()
*/
void greedy_alg(const std::vector<std::vector<int>>& cities, const size_t start, std::queue<size_t>& path, int& total_path)
{
    std::set<size_t> vertex; /* a set of cities for checking if its visited or not */

/* storing all cities(vertices) apart from starting one(vertex) */
    for (size_t i = 0; i < cities.size(); i++)
        if(i != start)
            vertex.insert(i);

    size_t curr_index = start; /* representing the current city with curr_index */

    path.push(curr_index);  /* store the starting point */

    int curr_path = 0; /* current path value */

    size_t size = vertex.size(); /* the number of cities we should visit */

    while(!vertex.empty())
    {
        int min_path = INT_MAX; /* store minimum weight Hamiltonian cycle */
        size_t res_index = 0; /* store the city to which the distance is minimum */

        /* find the minimum distance to the next city and go there  */
        for (std::set<size_t>::iterator it = vertex.begin(); it != vertex.end(); it++) 
        {
            size_t index = *it;
            if (cities[curr_index][index] <= min_path)
            {
                min_path = cities[curr_index][index];
                res_index = index;
            }
        }
        curr_index = res_index; /* go to the city with minimim distance inbetween */
        path.push(curr_index); /* update the path */
        vertex.erase(vertex.find(curr_index)); /* we cannot back to the previous city */
        curr_path += min_path; /* updated path weight */
    }

    curr_path += cities[curr_index][start]; /* go back to the starting city */
    path.push(start);
    total_path = curr_path; /* total path updated */
}

void test_A_star(std::vector<std::vector<int>> cities)
{
/* check how long it taks for the algorithm to find a solution */
    auto start_time = std::chrono::high_resolution_clock::now(); 

    std::cout << "\n---------- A* algorithm ----------\n";

/* starting from a random city and finding all the minimum ways */
    size_t start = std::rand() % (cities.size() - 1) + 0;

/*
return the minimum path and store the actual path in a queue, named path 
and the sum of all distances in variable total_path
*/
    std::queue<size_t> path;
    int total_path;
    A_star_alg(cities, start, path, total_path);

    std::cout << "Starting city: " << start << "\nPath: ";
    while (!path.empty()) /* print the path */
    {
        std::cout << path.front();
        if(path.size() > 1) 
            std::cout << " -> ";
        path.pop();
    }
    std::cout << "\nMinimum path: " << total_path << std::endl; /* printf minimum path */

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time); 
    std::cout << "Total time for " << cities.size() << " cities: " << duration.count() << std::endl;
    std::cout << std::endl;
}

void test_greeady(std::vector<std::vector<int>> cities)
{
/* check how long it taks for the algorithm to find a solution */
    auto start_time = std::chrono::high_resolution_clock::now(); 

    std::cout << "---------- Greedy algorithm ----------\n";

/* starting from a random city and finding all the minimum ways */
    size_t start = std::rand() % (cities.size() - 1) + 0;

/*
return the minimum path and store the actual path in a queue, named path 
and the sum of all distances in variable total_path
*/
    std::queue<size_t> path;
    int total_path;
    greedy_alg(cities, start, path, total_path);

    std::cout << "Starting city: " << start << "\nPath: ";
    while (!path.empty()) /* print the path */
    {
        std::cout << path.front(); 
        if(path.size() > 1) 
            std::cout << " -> ";
        path.pop();
    }
    std::cout << "\nMinimum path: " << total_path << std::endl;

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time); 
    std::cout << "Total time for " << cities.size() << " cities: " << duration.count() << std::endl;
    std::cout << std::endl;
}

void run()
{
    std::vector<std::vector<int>> cities;
    read(cities); /* read from file and store data in cities */
    if(cities.empty()) return; /* exit if no data is added */

    test_A_star(cities); /* testing A* algorithm */
    test_greeady(cities); /* testing Greedy algorithm */
}

int main()
{
    /* generate_random_matrix(); */
    run();
    
    return 0;
}

int find_minimum(std::vector<int> distances, size_t start)
{
    int result = 0;
    for (size_t i = 0; i < distances.size() - 1; i++)
        if (i != start && distances[i] != 0 && distances[i] != 0 && distances[i] <= distances[i + 1])
            result = distances[i];
    
    return result;
}

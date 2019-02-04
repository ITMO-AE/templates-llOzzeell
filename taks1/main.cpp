#include <iostream>
#include <vector>
#include <map>
#include <string>

template <typename T>
T Sqr(T &x){
   return x * x;
}

template <typename T>
std::vector<T> Sqr(std::vector<T> vec){

    for (auto it = vec.rbegin(); it != vec.rend(); ++it)
    {
        *it = (*it) * (*it);
    }
    return vec;
}

template <typename T, typename D>
std::map<T,D> Sqr(std::map<T,D> map){

    for ( auto it = map.begin(); it != map.end(); it++ )
    {
        it->second *= it->second;
    }
    return map;
}

template <typename T, typename D, typename B>
std::map<T,std::pair<D,B>> Sqr(std::map<T,std::pair<D,B>> mappair){

    for ( auto it = mappair.begin(); it != mappair.end(); it++ )
    {
        it->second.first *= it->second.first;
        it->second.second *= it->second.second;
    }
    return mappair;
}


int main()
{
    double x = 5.2;
    std::cout << Sqr<double>(x) << std::endl;

    std::cout << std::endl;

    std::vector<int> vec = {1,2,3,4,5};

    for(auto i : Sqr<int>(vec))
    {
        std::cout << i << std::endl;
    }

    std::cout << std::endl;

    std::map<std::string,int> map = {{"one",1},
                         {"two",2},
                         {"three",3},
                         {"four",4},
                         {"five",5}};

    for(auto i : Sqr<std::string, int>(map))
    {
        std::cout << i.first << " " << i.second << std::endl;
    }

    std::cout << std::endl;

    std::map<std::string, std::pair<int, double>> map_of_pairs = {
        {"A", {2, 1.0}},
        {"B", {4, 3.4}},
        {"C", {6, 7.3}},
        {"D", {8, 3.8}}
      };

    for ( auto it : Sqr<std::string, int, double>(map_of_pairs) )
    {
       std::cout << it.first << "   " << it.second.first << "   ";
        std::cout << it.second.second << std::endl;
    }

    return 0;
}

#include <iostream>
#include <algorithm>

#include "robot.h"
using std::cout, std::endl, my::robot;

int main() {
     auto robots = robot::robots_from_file("../Robots.txt");
     cout << "Robots: " << endl;
     for (const auto& robot: robots) {
          cout << robot << '\n';
     }
     cout << endl;

     if(std::find_if(robots.begin(), robots.end(), [](const robot& r){return r.get_name() == "Wall-e";}) != robots.end()) {
          cout << "Wall-e is present." << endl;
     }
     else {
          cout << "Wall-e is not present" << endl;
     }

     std::sort(robots.begin(), robots.end(), [](const robot& r1, const robot& r2){return r1.get_price() < r2.get_price(); });

     cout << "Robots sorted by price: " << endl;
     for (const auto& robot: robots) {
          cout << robot << '\n';
     }
     cout << endl;

     for (const auto& robot: robots) {
          robot.save_in_file("../sorted_robots.txt");
     }


     exit(EXIT_SUCCESS);
}
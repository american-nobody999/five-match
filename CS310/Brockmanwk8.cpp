
//This program calculates distance from the sun, orbital period in earth days and also finds closest planet to earth.//
#include <iostream>//for cin and cout//
#include <string>//for planet names//
#include <vector>//dynamic array for planets//
#include <iomanip>//for formatting output//
#include <algorithm>//for calculating distances//
using namespace std

// Planet class - defines individual planets with real data
class Planet {
private://only accessible within the class itself--won't be able to change data members directly//
    string name;
    double distanceFromSun;  // in millions of miles from Sun
    double orbitalPeriod;    // in Earth days
    
public://accessible from outside the class//
    // Constructor
    Planet(string n, double distance, double period) {
        name = n;
        distanceFromSun = distance;// millions of miles
        orbitalPeriod = period;// days
    }
    
    // Display planet info
    void displayInfo() {
        cout << fixed << setprecision(1);
        cout << name << ": " << distanceFromSun << " million miles from Sun, "
             << orbitalPeriod << " days to orbit Earth! " << endl;
    }
    
    // Getters for calculations
    string getName() { return name; }
    double getDistance() { return distanceFromSun; }
    double getOrbitalPeriod() { return orbitalPeriod; }
};

// SolarSystem class - manages collection of planets--second major class--see how neat and organized all the code is when you use the classes! Everything all together.//

class SolarSystem {
private:
    vector<Planet> planets;  // Collection of all planets
    string systemName;
    
public:
    // Constructor
    SolarSystem(string name) {
        systemName = name;
    }
    
    // Add a planet to the solar system--for lines 96-104
    void addPlanet(Planet p) {
        planets.push_back(p);
    }
    
    // Display all planets in order
    void displayAllPlanets() {
        cout << "\n========== " << systemName << " ========== " << endl;
        for (int i = 0; i < planets.size(); i++) {
            planets[i].displayInfo();
        }
        cout << "================================" << endl;
    }
    
    // Find closest planet to Earth (The cool feature!)
    void findClosestToEarth() {
        double earthDistance = 93.0;  // Earth's distance
        double closestDistance = 999999;
        string closestPlanet = "";
        
        for (int i = 0; i < planets.size(); i++) {
            double distance = abs(planets[i].getDistance() - earthDistance);
            if (distance < closestDistance && planets[i].getName() != "Earth") {
                closestDistance = distance;
                closestPlanet = planets[i].getName();
            }
        }

        cout << "\nClosest planet to Earth: " << closestPlanet 
             << " (" << closestDistance << " million miles away)" << endl;
    }

    // Find farthest planet from Earth (Another cool feature!)
    void findFarthestFromEarth() {
        double earthDistance = 93.0;  // Earth's distance
        double farthestDistance = 0;
        string farthestPlanet = "";

    for (int i = 0; i < planets.size(); i++) {
        double distance = abs(planets[i].getDistance() - earthDistance);
        if (distance > farthestDistance && planets[i].getName() != "Earth") {
            farthestDistance = distance;
            farthestPlanet = planets[i].getName();
        }
    }

    cout << "Farthest planet from Earth, Forever in Our Hearts: " << farthestPlanet 
         << " (" << farthestDistance << " million miles away)" << endl;
}

}//<---lots of cuss words here, this was a real-life nightmare to debug--->//


int main() {
    
    // Create solar system
    SolarSystem ourSystem("Our Solar System");
    
    // Create and add planets
    ourSystem.addPlanet(Planet("Mercury", 36.0, 88.0));
    ourSystem.addPlanet(Planet("Venus", 67.0, 225.0));
    ourSystem.addPlanet(Planet("Earth", 93.0, 365.25));
    ourSystem.addPlanet(Planet("Mars", 142.0, 687.0));
    ourSystem.addPlanet(Planet("Jupiter", 484.0, 4333.0));
    ourSystem.addPlanet(Planet("Saturn", 887.0, 10759.0));
    ourSystem.addPlanet(Planet("Uranus", 1784.0, 30687.0));
    ourSystem.addPlanet(Planet("Neptune", 2795.0, 60190.0));
    ourSystem.addPlanet(Planet("Pluto", 3670.0, 90560.0));//Forever a Planet in our hearts//

    // Display everything
    ourSystem.displayAllPlanets();
    ourSystem.findClosestToEarth();
    ourSystem.findFarthestFromEarth(); 
    
    return 0;
}
   












//-------Ignore----
//Planet class and SolarSystem class (space simulation)
//Display all planets in order distance from sun, orbital period
//Calculate distances between planets
//Find closest/farthest planets to Earth
//Simulate orbital movements
//<vector> to store planets dynamically--Great for iterating through solar system

//Methods to add planets, display info, calculate distances
//Use real data for planets--distance from sun, orbital period, number of moons
//Display all planets in order
//Calculate distances between planets
//Find closest/farthest planets


//Display planets in order from sun
//Calculate travel distances between planets
//Find which planet is closest and farthest from Earth
//Simulate orbital movements over time--this may be too ambitious for now-->

//private: means only accessible within the class itself
//public: means accessible from outside the class
//getter methods to retrieve private data--safe window--other classes cant change it directly

//The addPlanet() method (line 51):
//Takes a Planet object created in main()
//Adds it to the vector<Planet> planets collection--

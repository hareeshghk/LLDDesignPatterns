/*
Theory:
Expose a single interface for the client to create objects.(some times type of
object creation varies as per parameters)
*/


// Example Implementation:
// creating a 2 wheeler 3 wheeler 4 wheeler vehicles

#include <iostream>
#include <memory>

using namespace std;

enum class vehicleType {
    TwoWheeler_vehicle, ThreeWheeler_vehicle, FourWheeler_vehicle
};

class Vehicle {
public:
    virtual void printVehicle() = 0;
    static shared_ptr<Vehicle> CreateVehicle(vehicleType vtype);
};

class TwoWheeler : public Vehicle {
public:
    void printVehicle() {
        cout << "I am a two wheeler" << endl;
    }
};

class ThreeWheeler : public Vehicle {
public:
    void printVehicle() {
        cout << "I am a three wheeler" << endl;
    }
};

class FourWheeler : public Vehicle {
public:
    void printVehicle() {
        cout << "I am a four wheeler" << endl;
    }
};

shared_ptr<Vehicle> Vehicle::CreateVehicle(vehicleType vtype) {
    shared_ptr<Vehicle> vehicle {nullptr};
    switch (vtype) {
    case vehicleType::TwoWheeler_vehicle:
        vehicle = make_shared<TwoWheeler>();
        break;
    case vehicleType::ThreeWheeler_vehicle:
        vehicle = make_shared<ThreeWheeler>();
        break;
    case vehicleType::FourWheeler_vehicle:
        vehicle = make_shared<FourWheeler>();
        break;
    default:
        break;
    }
    return vehicle;
}

class Client {
    shared_ptr<Vehicle> vehicle;
public:
    Client(vehicleType type) {
        vehicle = Vehicle::CreateVehicle(type);
    }

    shared_ptr<Vehicle> GetVehicle() {
        return vehicle;
    }
};

int main() {
    auto bikeClient = make_shared<Client>(vehicleType::TwoWheeler_vehicle);
    cout << "bike says -> ";
    bikeClient->GetVehicle()->printVehicle();

    auto autoClient = make_shared<Client>(vehicleType::ThreeWheeler_vehicle);
    cout << "auto says -> ";
    autoClient->GetVehicle()->printVehicle();

    auto carClient = make_shared<Client>(vehicleType::FourWheeler_vehicle);
    cout << "car says -> ";
    carClient->GetVehicle()->printVehicle();
    return 0;
}
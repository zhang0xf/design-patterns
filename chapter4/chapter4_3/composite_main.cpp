#include <iostream>
#include "equipment.h"

int main() {
    Cabinet *cabinet = new Cabinet("PC Cabinet");
    Chassis *chassis = new Chassis("PC Chassis");

    cabinet->Add(chassis);

    Bus *bus = new Bus("MCA Bus");
    bus->Add(new Card("16Mbs Token Ring"));

    chassis->Add(bus);
    chassis->Add(new FloppyDisk("3.5in Floppy"));

    std::cout << "the net price is  " << chassis->NetPrice() << std::endl;

    return 0;
}
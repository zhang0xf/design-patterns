#include "singleton.h"

int main() {
    SingletonRegister *theSingleton = SingletonRegister::Instance();
    theSingleton->PrintInfo();

    return 0;
}
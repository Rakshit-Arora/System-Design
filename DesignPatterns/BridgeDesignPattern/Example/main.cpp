#include <iostream>
#include <memory>
#include "./Abstraction/livingThings.h"
#include "./AbstractionImpl/dog.h"
#include "./AbstractionImpl/fish.h"
#include "./AbstractionImpl/tree.h"
#include "./ImplementorImpl/gillBreathing.h"
#include "./ImplementorImpl/lungBreathing.h"
#include "./ImplementorImpl/photosynthesis.h"

using namespace std;

int main() {
    cout << "----- Bridge Desing Pattern -----" << endl;
    
    shared_ptr<LivingThings> dog = make_shared<Dog>(make_shared<LungBreathing>());
    shared_ptr<LivingThings> fish = make_shared<Fish>(make_shared<GillBreating>());
    shared_ptr<LivingThings> tree = make_shared<Tree>(make_shared<Photosynthesis>());

    dog -> breathe();
    fish -> breathe();
    tree -> breathe();

    return 0;

}
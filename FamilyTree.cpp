#include "FamilyTree.hpp"

using namespace std;
using namespace family;

Tree& Tree::addFather(string son, string newDad){return *this;};
Tree& Tree::addMother(string son, string newMom){return *this;};
void Tree::display(){};
string Tree::relation(string inputName){return "temp\n";};
string Tree::find(string inputName){return "temp2\n";};
void Tree::remove(string inputName){};
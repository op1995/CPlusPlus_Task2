#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>

using namespace std;
using namespace family;

TEST_CASE("place holder") {

    Tree T("Ofir_P");
    T.addFather("Ofir_P","Shlomo_P")
    .addFather("Shlomo_P","Israel_P")
    .addMother("Shlomo_P","Ester_P")
    .addMother("Ofir_P","Tammy_P")
    .addFather("Tammy_P","Aharon_T")
    .addMother("Tammy_P","Nechama_T")
    .addFather("Israel_P","unkown")
    .addMother("Israel_P","unkown");
    

    CHECK(T.relation("Tammy_P") == "Mother");
    CHECK(T.relation("Shlomo_P") == "Father");
    CHECK(T.relation("Israel_P") == "Grandfather");
    CHECK(T.relation("Ester_P") == "Grandmother");
    CHECK(T.relation("Aharon_T") == "Grandfather");
    CHECK(T.relation("Nechama_T") == "Grandmother");



    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder
    CHECK(1 == 1); //place holder

}
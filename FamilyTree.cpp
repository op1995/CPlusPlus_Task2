#include "FamilyTree.hpp"

using namespace std;
using namespace family;

Node* Tree::search(Node* currentNode, string input){
    if (currentNode->name.compare(input)==0){return currentNode;}
    else{
        Node* answer = NULL;
        if (currentNode->dad){ //if he has a dad
            answer = search(currentNode->dad, input);
        }
        if (!answer && currentNode->mom){ //if the answer wasn't found yet, and he has a mom
            answer = search(currentNode->mom, input);
        }
        return answer;
    }

}

Tree& Tree::addFather(string son, string newDad){
    Node* target = this->search(&(this->root), son);
    if(!target){throw invalid_argument("Son not found in the tree!");}
    if(target->dad){throw invalid_argument("Son already has a father!");}
    target->dad=new Node(newDad, true);
    // target->dad->name=newDad;
    // target->dad->dad=NULL;
    // target->dad->mom=NULL;

    return *this;

};

Tree& Tree::addMother(string son, string newMom){
    Node* target = this->search(&(this->root), son);
    if(!target){throw invalid_argument("Son not found in the tree!");}
    if(target->mom){throw invalid_argument("Son already has a mother!");}
    target->mom=new Node(newMom, false);
    // target->mom->name=newMom;
    // target->mom->dad=NULL;
    // target->mom->mom=NULL;

    return *this;

};

void Tree::display(){};


string Tree::relation(string inputName){

    if(root.name.compare(inputName)==0){return "me";}

    if(!root.dad && !root.mom){return "unrelated";}
    if(root.dad && root.dad->name.compare(inputName)==0){return "father";}//father case
    if(root.mom && root.mom->name.compare(inputName)==0){return "mother";}//mother case

    if(!root.dad->dad && !root.dad->dad && !root.mom->dad && !root.mom->mom){return "unrelated";} //if no further family exists, end it all

    if(root.dad->dad && root.dad->dad->name.compare(inputName)==0){return "grandfather";}
    if(root.dad->mom && root.dad->mom->name.compare(inputName)==0){return "grandmother";}
    if(root.mom->dad && root.mom->dad->name.compare(inputName)==0){return "grandfather";}
    if(root.mom->mom && root.mom->mom->name.compare(inputName)==0){return "grandmother";} //private cases of grandfather and grandmother

    string temp = "unrelated"; //now check up the tree for each ancestor
    if(root.dad->dad) {temp = relation2(inputName, root.dad->dad);}
    if(temp.compare("unrelated")==0 && root.dad->mom){temp = relation2(inputName, root.dad->mom);}
    if(temp.compare("unrelated")==0 && root.mom->dad){temp = relation2(inputName, root.mom->dad);}
    if(temp.compare("unrelated")==0 && root.mom->mom){temp = relation2(inputName, root.mom->mom);}

    if(temp.compare("unrelated")!=0) return "great-" + temp;
    else return "unrelated";
};

string Tree::relation2(string inputName, Node* current){
    if(!current->dad && !current->mom) return "unrelated";
    if(current->dad && current->dad->name.compare(inputName)==0){return "grandfather";}
    if(current->mom && current->mom->name.compare(inputName)==0){return "grandmother";}
    
    string temp = "unrelated";
    if(current->dad) temp = relation2(inputName, current->dad);
    if(temp.compare("unrelated")==0 && current->mom) temp = relation2(inputName, current->mom);

    if(temp.compare("unrelated")!=0) return "great-" + temp;
    else return temp;

}


string Tree::find(string inputRelation){
    if(inputRelation.size()<6) throw invalid_argument("Input string is too short to be valid!\n");

    string test = inputRelation.substr(0,1); //check if the first character of the input string is valid
    if(!(test.compare("f")==0) && !(test.compare("m")==0) && !(test.compare("g")==0)) {throw invalid_argument("Input string invalid!\n");}

    if(!this->root.dad && !this->root.mom){throw invalid_argument("Tree only has root. No relations will be in it, so there isn't anything to find.\n");}
    
    if(inputRelation.compare("father")==0){
        if(!this->root.dad) throw invalid_argument("1No such relation in the tree!\n");
        else return this->root.dad->name;
    }

    if(inputRelation.compare("mother")==0){
        if(!this->root.mom) throw invalid_argument("2No such relation in the tree!\n");
        else return this->root.mom->name;
    }

    if(inputRelation.compare("grandfather")==0){
        if(this->root.dad && this->root.dad->dad) {return this->root.dad->dad->name;}
        else if (this->root.mom && this->root.mom->dad) {return this->root.mom->dad->name;}
        else throw invalid_argument("3No such relation in the tree!\n");
    }

    if(inputRelation.compare("grandmother")==0){
        if(this->root.dad && this->root.dad->mom) {return this->root.dad->mom->name;}
        else if (this->root.mom && this->root.mom->mom) {return this->root.mom->mom->name;}
        else throw invalid_argument("4No such relation in the tree!\n");
    }

    // cout << "not option 1-4" << endl;

    //getting here means we didn't look for father, mother, grandfather or grandmother
    //so the input should start with "great-". If it doesn't, throw an error.
    //this is needed here as well as in the find2 function, as the first 6 characters might be invalid, but the rest is valid.
    if(inputRelation.substr(0,6).compare("great-")!=0) throw invalid_argument("Invalid input!\n");

    string answer = "none";
    if(this->root.dad && this->root.dad->dad) {answer = find2(inputRelation, this->root.dad->dad);}
    // cout << "after first call to find2. answer = " << answer << endl;
    if (answer.compare("invalid!")!=0 && answer.compare("none")==0 && this->root.dad && this->root.dad->mom) {answer = find2(inputRelation, this->root.dad->mom);}
    if (answer.compare("invalid!")!=0 && answer.compare("none")==0 && this->root.mom && this->root.mom->dad) {answer = find2(inputRelation, this->root.mom->dad);}
    if (answer.compare("invalid!")!=0 && answer.compare("none")==0 && this->root.mom && this->root.mom->mom) {answer = find2(inputRelation, this->root.mom->mom);}

    if(answer.compare("invalid!")==0){throw invalid_argument("Invalid input!\n");} //invalid! is an indicatior of invalid part found in the string
    if(answer.compare("none")!=0){
        // cout << "find returning answer = " << answer << endl;    
        return answer;
    } // if it isn't "invalid!" or "none", answer was found. Return it.
    else {throw invalid_argument("5No such relation in the tree!\n");}//none of the above -> wasn't found. throw error.

    

    // return "temp2\n"; //to have something to return, for any case. Not including this caused problems in previous projects.

};

string Tree::find2(string inputRelation, Node* origin){
    // cout << "begining of find2, inputRelation = " << inputRelation << endl;

    if(inputRelation.substr(0,6).compare("great-")==0){ //if "great" is still within the inputed string, it is needed to go up another level in the tree
        string answer = "none";
        if(origin->dad) answer = find2(inputRelation.substr(6), origin->dad);
        if(answer.compare("none")==0 && origin->mom) answer = find2(inputRelation.substr(6), origin->mom);
        return answer;
    }
    
    //getting here means the begining of the string isn't "great-".
    //if the string doesn't start with "great-" and it isn't grandfather or grandmother, it is invalid. returning "invalid!" will indicate to throw an error.
    if(inputRelation.compare("grandfather")!=0 && inputRelation.compare("grandmother")!=0) {return "invalid!";}
    
    else{//valid string and no more "great-" in the string. check if we looked for grandfather and origin is male, or grandmother and origin is female
        
        // cout << "I am here and inputRelation = " << inputRelation <<endl;
        // if(inputRelation.compare("grandfather")==0) cout << "origin->name = " << origin->name <<endl;
        if(inputRelation.compare("grandfather")==0 && origin->male) return origin->name;
        if(inputRelation.compare("grandmother")==0 && !origin->male) return origin->name;
        return "none";
    }

    
}


void Tree::remove(string inputName){
    if(this->root.name.compare(inputName)==0){throw invalid_argument("Can't remove root of tree!");} //this was instructed in the google groups by Erel
    bool found = remove2(inputName, &this->root);
    if (!found) throw invalid_argument("Not found in the tree!");
};

bool Tree::remove2(string inputName, Node* baseNode){
    if(baseNode->dad && baseNode->dad->name.compare(inputName)==0){
        baseNode->dad = NULL;
        return true;
    }
    if(baseNode->mom && baseNode->mom->name.compare(inputName)==0){
        baseNode->mom = NULL;
        return true;
    }
    bool found = false; //neither of baseNode's parents are what we are looking for. Search for it in their parents' ancestors.
    if(baseNode->dad){found = remove2(inputName, baseNode->dad);}
    if(!found && baseNode->mom){found = remove2(inputName, baseNode->mom);}
    return found;
}
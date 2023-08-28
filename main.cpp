#include "bits/stdc++.h"
#include "Model/RubiksCube3dArray.cpp"
#include "Model/RubiksCube1dArray.cpp"
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/IDDFSSolver.h"
#include "Solver/IDAStarSolver.h"

#include "PatternDatabase/CornerPatternDatabase.h"
#include "PatternDatabase/DBMaker.h"

using namespace std;

int main(){
    RubiksCube3dArray object3dArray;
    RubiksCube1dArray object1dArray;

    object3dArray.print();

    if(object3dArray.isSolved()) cout<<"Solved\n\n";
    else cout<<"NOT SOLVED\n\n";

    if(object3dArray.isSolved()) cout<<"Solved\n\n";
    else cout<<"NOT SOLVED\n\n";

    object3dArray.u();
    object1dArray.u();
    object3dArray.print();
    object1dArray.print();

    object3dArray.l();
    object1dArray.l();
    object3dArray.print();
    object1dArray.print();

    object3dArray.f();
    object1dArray.f();
    object3dArray.print();
    object1dArray.print();

    object3dArray.r();
    object1dArray.r();
    object3dArray.print();
    object1dArray.print();

    object3dArray.b();
    object1dArray.b();
    object3dArray.print();
    object1dArray.print();

    object3dArray.d();
    object1dArray.d();
    object3dArray.print();
    object1dArray.print();

    if(object3dArray.isSolved()) cout<<"Solved\n\n";
    else cout<<"NOT SOLVED\n\n";

    if(object3dArray.isSolved()) cout<<"Solved\n\n";
    else cout<<"NOT SOLVED\n\n";

    object3dArray.dPrime();
    object1dArray.dPrime();
    object3dArray.print();
    object1dArray.print();

    object3dArray.bPrime();
    object1dArray.bPrime();
    object3dArray.print();
    object1dArray.print();

    object3dArray.rPrime();
    object1dArray.rPrime();
    object3dArray.print();
    object1dArray.print();

    object3dArray.fPrime();
    object1dArray.fPrime();
    object3dArray.print();
    object1dArray.print();

    object3dArray.lPrime();
    object1dArray.lPrime();
    object3dArray.print();
    object1dArray.print();

    object3dArray.uPrime();
    object1dArray.uPrime();
    object3dArray.print();
    object1dArray.print();

    if(object3dArray.isSolved()) cout<<"Solved\n\n";
    else cout<<"NOT SOLVED\n\n";

    if(object3dArray.isSolved()) cout<<"Solved\n\n";
    else cout<<"NOT SOLVED\n\n";

    // Create two cubes

    RubiksCube3dArray cube1;
    RubiksCube3dArray cube2;

//    RubiksCube1dArray cube1;
//    RubiksCube1dArray cube2;

    // Equality and Assignment of cubes

    if(cube1==cube2) cout<<"Is equal\n";
    else cout<<"Not Equal\n";

    cube1.randomShuffleCube(1);

    if(cube1==cube2) cout<<"Is equal\n";
    else cout<<"Not Equal\n";

    cube2=cube1;

    if(cube1==cube2) cout<<"Is equal\n";
    else cout<<"Not Equal\n";

    //Unordered_map of Cubes

    unordered_map<RubiksCube3dArray,bool,Hash3d> mp1;
//    unordered_map<RubiksCube3dArray,bool,Hash1d> mp1;
    mp1[cube1]=true;
    cube2.randomShuffleCube((8));
    if(mp1[cube1]) cout<<"Cube1 is present\n";
    else cout<<"Cube1 is not present\n";
    if(mp1[cube2]) cout<<"Cube12 is present\n";
    else cout<<"Cube2 is not present\n";
}
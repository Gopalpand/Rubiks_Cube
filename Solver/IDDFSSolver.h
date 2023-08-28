#include "bits/stdc++.h"
#include "../Model/RubiksCube.h"
#include "DFSSolver.h"

#ifndef RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H;
#define RUBIKS_CUBE_SOLVER_IDFFSSOLVER_H;

template<typename T,typename H>
class IDDFSSOLVER{
public:
    T rubikscube;
    int max_search_depth;
    vector<RubiksCube::MOVE> moves;

    IDDFSSOLVER(T _rubikscube,int _max_search_depth=7){
        rubikscube = _rubikscube;
        max_search_depth=_max_search_depth;
    }

    vector<RubiksCube::MOVE> soive(){
        for(int i=1;i<=max_search_depth;i++){
            DFSSOLVER<T,H> dfsSolver(rubikscube,i);
            moves=dfsSolver.solve();
            if(dfsSolver.rubikscube.isSolved()){
                rubikscube=dfsSolver.rubiksCube;
                break;
            }
        }
        return moves;
    }
};

#endif;

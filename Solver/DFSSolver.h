#include "bits/stdc++.h"
#include "../Model/RubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_BFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_BFSSOLVER_H

template<typename T,typename H>

class DFSSOLVER {
private:
    vector<RubiksCube::MOVE> moves;
    int max_search_depth;

    bool dfs(int dep){
        if(rubikscube.isSolved()) return 1;
        if(dep>rubikscube._max_search_depth) return 0;
        for(int i=0;i<18;i++){
            rubikscube.move(RubiksCube::MOVE(i));
            moves.push_back(RubiksCube::MOVE(i));
            if(dfs(RubiksCube::MOVE(i))) return 1;
            moves.pop_back();
            rubikscube.invert(RubiksCube::MOVE(i));
        }
        return false;
    }

public:
    T rubikscube;

    DFSSOLVER(T _rubiksCube,int _max_search_depth){
        rubikscube = _rubiksCube;
        max_search_depth=_max_search_depth;
    }

    vector<RubiksCube::MOVE> solve(){
        dfs(1);
        return moves;
    }
};

#endif
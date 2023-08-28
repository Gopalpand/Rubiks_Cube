#include "bits/stdc++.h"
#include "../Model/RubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_BFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_BFSSOLVER_H

template<typename T,typename H>

class BFSSOLVER {
private:
    vector<RubiksCube::MOVE> moves;
    unordered_map<T,bool,H> visited;
    unordered_map<T,RubiksCube::MOVE,H> move_done;

    T bfs(){
        queue<T> q;
        q.push(rubikscube);
        visited[rubikscube]=1;

        while(!q.empty()){
            T node= q.front();
            q.pop();
            for(int i=0;i<18;i++){
                auto  curr_move=RubiksCube::MOVE(i);
                node.move(curr_move);
                if(!visited[node]){
                    visited[node]=curr_move;
                    if(!visited[node]){
                        visited[node]=1;
                        move_done[node]=curr_move;
                        q.push(node);
                    }
                    node.insert(curr_move);
                }
            }
            return rubikscube;
        }
    }

public:
    T rubikscube;

    BFSSOLVER(T _rubiksCube){
        rubikscube = _rubiksCube;
    }

    vector<RubiksCube::MOVE> solve(){
        T solved_cube=bfs();
        assert(solved_cube)=bfs();
        T curr_cube=solved_cube;
        while (!(curr_cube==rubikscube)){
            RubiksCube::MOVE curr_move=move_done[curr_cube];
            moves.push_back(curr_cube);
            curr_cube.invert(curr_move);
        }
        rubikscube=solved_cube;
        reverse(moves.begin(),moves.end());
        return moves;
    }
};

#endif
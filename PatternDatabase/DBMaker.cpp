
#include "DBMaker.h"

CornerDBMaker::CornerDBMaker(std::string _fileName) {
    fileName=_fileName;
}

CornerDBMaker::CornerDBMaker(std::string _fileName, uint8_t init_val) {
    fileName=_fileName;
    cornerDB=CornerPatternDatabase(init_val);
}

bool CornerDBMaker::bfsAndStore() {
    RubiksCube1dAArray cube;
    queue<RubiksCube1dAArray> q;
    q.push(cube);
    cornerDB.setNumMoves(cube,0);
    int curr_depth = 0;
    while (!q.empty()){
        int n=q.size();
        curr_depth++;
        if(curr_depth==9) break;
        for(int counter=0;counter<n;counter++){
            RubiksCube1dAArray node=q.front();
            q.pop();
            for(int i=0;i<18;i++) {
                auto curr_move = RubiksCube::MOVE(i);
                if ((int) cornerDB.getNumMoves(node) > curr_depth) {
                    cornerDB.setNumMoves(node, curr_depth);
                    q.push(node);
                }
                node.invert(curr_move);
            }
        }
    }
    cornerDB.toFile(fileName);
    return true;
}

#include "RubiksCube.h"

char RubiksCube::getColorLetter(COLOR color) {
    switch (color) {
        case COLOR::BLUE:
            return 'B';
        case COLOR::WHITE:
            return 'W';
        case COLOR::GREEN:
            return 'G';
        case COLOR::RED:
            return 'R';
        case COLOR::ORANGE:
            return 'O';
        case COLOR::YELLOW:
            return 'Y';
    }
}

    string RubiksCube::getMove(MOVE ind) {
        switch(ind){
            case MOVE::L:
                return "L";
            case MOVE::LPRIME:
                return "L'";
            case MOVE::L2:
                return "L2";
            case MOVE::R:
                return "R";
            case MOVE::RPRIME:
                return "R'";
            case MOVE::R2:
                return "R2";
            case MOVE::U:
                return "U";
            case MOVE::UPRIME:
                return "U'";
            case MOVE::U2:
                return "U2";
            case MOVE::D:
                return "D";
            case MOVE::DPRIME:
                return "D'";
            case MOVE::D2:
                return "D2";
            case MOVE::F:
                return "F";
            case MOVE::FPRIME:
                return "F'";
            case MOVE::F2:
                return "F2";
            case MOVE::B:
                return "B";
            case MOVE::BPRIME:
                return "B'";
            case MOVE::B2:
                return "B2";
        }
    }

    RubiksCube &RubiksCube::move(MOVE ind) {
        switch(ind){
            case MOVE::L:
                return this->l();
            case MOVE::LPRIME:
                return this->lPrime();
            case MOVE::L2:
                return this->l2();
            case MOVE::R:
                return this->r();
            case MOVE::RPRIME:
                return this->rPrime();
            case MOVE::R2:
                return this->r2();
            case MOVE::U:
                return this->u();
            case MOVE::UPRIME:
                return this->uPrime();
            case MOVE::U2:
                return this->u2();
            case MOVE::D:
                return this->d();
            case MOVE::DPRIME:
                return this->dPrime();
            case MOVE::D2:
                return this->d2();
            case MOVE::F:
                return this->f();
            case MOVE::FPRIME:
                return this->fPrime();
            case MOVE::F2:
                return this->f2();
            case MOVE::B:
                return this->b();
            case MOVE::BPRIME:
                return this->bPrime();
            case MOVE::B2:
                return this->b2();
        }
    }

    RubiksCube &RubiksCube::invert(MOVE ind) {
        switch(ind){
            case MOVE::L:
                return this->lPrime();
            case MOVE::LPRIME:
                return this->l();
            case MOVE::L2:
                return this->l2();
            case MOVE::R:
                return this->rPrime();
            case MOVE::RPRIME:
                return this->r();
            case MOVE::R2:
                return this->r2();
            case MOVE::U:
                return this->uPrime();
            case MOVE::UPRIME:
                return this->u();
            case MOVE::U2:
                return this->u2();
            case MOVE::D:
                return this->dPrime();
            case MOVE::DPRIME:
                return this->d();
            case MOVE::D2:
                return this->d2();
            case MOVE::F:
                return this->fPrime();
            case MOVE::FPRIME:
                return this->f();
            case MOVE::F2:
                return this->f2();
            case MOVE::B:
                return this->bPrime();
            case MOVE::BPRIME:
                return this->b();
            case MOVE::B2:
                return this->b2();
        }
    }

    void RubiksCube::print() const {
        for(int r=0;r<3;r++){
            for(int i=0;i<7;i++) cout<<" ";
            for(int c=0;c<3;c++){
                cout<<getColorLetter(getColor(FACE::UP,r,c))<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        for(int r=0;r<3;r++){
            for(int c=0;c<3;c++) cout<<getColorLetter(getColor(FACE::LEFT,r,c))<<" ";
            cout<<" ";
            for(int c=0;c<3;c++) cout<<getColorLetter(getColor(FACE::FRONT,r,c))<<" ";
            cout<<" ";
            for(int c=0;c<3;c++) cout<<getColorLetter(getColor(FACE::RIGHT,r,c))<<" ";
            cout<<" ";
            for(int c=0;c<3;c++) cout<<getColorLetter(getColor(FACE::BACK,r,c))<<" ";
            cout<<"\n";
        }
        cout<<"\n";
        for(int r=0;r<3;r++){
            for(int i=0;i<7;i++) cout<<" ";
            for(int c=0;c<3;c++){
                cout<<getColorLetter(getColor(FACE::DOWN,r,c))<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }

    vector<RubiksCube::MOVE> RubiksCube::randomShuffleCube(unsigned int times) {
        vector<MOVE> moves_performed;
        for(unsigned int i=0;i<times;i++){
            unsigned int selectMove=(rand()%18);
            moves_performed.push_back(static_cast<MOVE>(selectMove));
            this->move(static_cast<MOVE>(selectMove));
        }
        return moves_performed;
    }

    string RubiksCube::getCornerColorString(uint8_t ind) const {
        string str = "";

        switch (ind) {
            case 0:
                //UFR
                str += getColorLetter(getColor(FACE::UP, 2, 2));
                str += getColorLetter(getColor(FACE::FRONT, 0, 2));
                str += getColorLetter(getColor(FACE::RIGHT, 2, 0));
                break;
            case 1:
                //UFL
                str += getColorLetter(getColor(FACE::UP, 2, 0));
                str += getColorLetter(getColor(FACE::FRONT, 0, 0));
                str += getColorLetter(getColor(FACE::LEFT, 0, 2));
                break;
            case 2:
                //UBL
                str += getColorLetter(getColor(FACE::UP, 0, 0));
                str += getColorLetter(getColor(FACE::BACK, 0, 2));
                str += getColorLetter(getColor(FACE::LEFT, 0, 0));
                break;
            case 3:
                //UBR
                str += getColorLetter(getColor(FACE::UP, 0, 2));
                str += getColorLetter(getColor(FACE::BACK, 0, 0));
                str += getColorLetter(getColor(FACE::RIGHT, 0, 2));
                break;
            case 4:
                //DFR
                str += getColorLetter(getColor(FACE::DOWN, 0, 2));
                str += getColorLetter(getColor(FACE::FRONT, 2, 2));
                str += getColorLetter(getColor(FACE::RIGHT, 2, 0));
                break;
            case 5:
                //DFL
                str += getColorLetter(getColor(FACE::DOWN, 0, 0));
                str += getColorLetter(getColor(FACE::FRONT, 2, 0));
                str += getColorLetter(getColor(FACE::LEFT, 2, 2));
                break;
            case 6:
                //DBL
                str += getColorLetter(getColor(FACE::DOWN, 2, 2));
                str += getColorLetter(getColor(FACE::UP, 2, 0));
                str += getColorLetter(getColor(FACE::LEFT, 2, 2));
                break;
            case 7:
                //DBR
                str += getColorLetter(getColor(FACE::DOWN, 2, 0));
                str += getColorLetter(getColor(FACE::BACK, 2, 2));
                str += getColorLetter(getColor(FACE::RIGHT, 2, 0));
                break;
        }
    }


    uint8_t RubiksCube::getCornerIndex(uint8_t ind) const {
        string corner= getCornerColorString(ind);
        uint8_t ret=0;
        for(auto c:corner){
            if(c!='W'&&c!='Y'){
                if(c=='Y'){
                    ret|=(1<<2);
                }
            }
            if(c!='R'&&c!='O'){
                if(c=='O'){
                    ret|=(1<<1);
                }
            }
            if(c!='G'&&c!='B'){
                if(c=='B'){
                    ret|=(1<<0);
                }
            }
        }
        return ret;
    }


    uint8_t RubiksCube::getCornerOrientation(uint8_t ind) const {
        string corner= getCornerColorString(ind);
        string actual_str="";
        for(auto c:corner) {
            if (c!='W'&&c!='Y') continue;
            actual_str.push_back(c);
        }
        if(corner[1]==actual_str[0]){
            return 1;
        }
        else if(corner[2]==actual_str[0]){
            return 2;
        }
        else return  0;
    }

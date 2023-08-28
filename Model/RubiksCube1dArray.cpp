
#include "RubiksCube.h"

class RubiksCube1dArray : public RubiksCube{
private:

    static inline int getIndex(int ind,int r,int c){
        return ind*9+r*3+c;
    }
    void rotateFace(int ind){
        char temp[]={};
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                temp[r*3+c] = cube[getIndex(ind,r,c)];
            }
        }
        for(int i=0;i<3;i++) cube[getIndex(ind,0,i)]=temp[getIndex(0,2-i,0)];
        for(int i=0;i<3;i++) cube[getIndex(ind,i,2)]=temp[getIndex(0,0,i)];
        for(int i=0;i<3;i++) cube[getIndex(ind,2,2-i)]=temp[getIndex(0,i,2)];
        for(int i=0;i<3;i++) cube[getIndex(ind,2-i,0)]=temp[getIndex(0,2,2-i)];
    }

public:
    char cube[54]{};

    RubiksCube1dArray() {
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    cube[9*i+3*j+k]= getColorLetter(COLOR(i));
                }
            }
        }
    }

    COLOR getColor(FACE face,unsigned r,unsigned c) const override{
        char color=cube[getIndex((int)face,(int)r,(int)c)];
        switch (color) {
            case 'B':
                return COLOR::BLUE;
            case 'G':
                return COLOR::GREEN;
            case 'R':
                return COLOR::RED;
            case 'O':
                return COLOR::ORANGE;
            case 'Y':
                return COLOR::YELLOW;
            case 'W':
                return COLOR::WHITE;
        }
    }

    bool isSolved() const override {
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(this->cube[getIndex(i,j,k)]== getColorLetter(COLOR(i)))
                        continue;
                    return false;
                }
            }
        }
        return true;
    }

    RubiksCube &u() override {
        this->rotateFace(0);

        char temp[3] = {};
        for(int i=0;i<3;i++) temp[i]=cube[getIndex(4,0,2-i)];
        for(int i=0;i<3;i++) cube[getIndex(4,0,2-i)]=cube[getIndex(1,0,2-i)];
        for(int i=0;i<3;i++) cube[getIndex(1,0,2-i)]=cube[getIndex(2,0,2-i)];
        for(int i=0;i<3;i++) cube[getIndex(2,0,2-i)]=cube[getIndex(3,0,2-i)];
        for(int i=0;i<3;i++) cube[getIndex(3,0,2-i)]=temp[i];

        return *this;
    }

    RubiksCube &uPrime() override{
        this->u();
        this->u();
        this->u();
    }

    RubiksCube &u2() override{
        this->u();
        this->u();;

        return *this;
    }

    RubiksCube &l() override {
        this->rotateFace(1);

        char temp[3] = {};
        for(int i=0;i<3;i++) temp[i]=cube[getIndex(0,i,0)];
        for(int i=0;i<3;i++) cube[getIndex(0,i,0)]=cube[getIndex(4,2-i,2)];
        for(int i=0;i<3;i++) cube[getIndex(4,2-i,2)]=cube[getIndex(5,i,0)];
        for(int i=0;i<3;i++) cube[getIndex(5,i,0)]=cube[getIndex(2,i,0)];
        for(int i=0;i<3;i++) cube[getIndex(2,i,0)]=temp[i];

        return *this;
    }

    RubiksCube &lPrime() override{
        this->l();
        this->l();
        this->l();
    }

    RubiksCube &l2() override{
        this->l();
        this->l();;

        return *this;
    }

    RubiksCube &f() override {
        this->rotateFace(2);

        char temp[3] = {};
        for(int i=0;i<3;i++) temp[i]=cube[getIndex(0,2,i)];
        for (int i = 0; i < 3; i++) temp[i] = cube[getIndex(0, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 2, i)] = cube[getIndex(1, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 2 - i, 2)] = cube[getIndex(5, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 0, 2 - i)] = cube[getIndex(3, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, i, 0)] = temp[i];

        return *this;
    }

    RubiksCube &fPrime() override{
        this->f();
        this->f();
        this->f();
    }

    RubiksCube &f2() override{
        this->f();
        this->f();;

        return *this;
    }

    RubiksCube &r() override {
        this->rotateFace(3);

        char temp[3] = {};
        for (int i = 0; i < 3; i++) temp[i] = cube[getIndex(0, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 2 - i, 2)] = cube[getIndex(2, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 2 - i, 2)] = cube[getIndex(5, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 2 - i, 2)] = cube[getIndex(4, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, i, 0)] = temp[i];

        return *this;
    }

    RubiksCube &rPrime() override{
        this->r();
        this->r();
        this->r();
    }

    RubiksCube &r2() override{
        this->r();
        this->r();;

        return *this;
    }

    RubiksCube &b() override {
        this->rotateFace(4);

        char temp[3] = {};
        for (int i = 0; i < 3; i++) temp[i] = cube[getIndex(0, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 0, 2 - i)] = cube[getIndex(3, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 2 - i, 2)] = cube[getIndex(5, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 2, i)] = cube[getIndex(1, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, i, 0)] = temp[i];

        return *this;
    }

    RubiksCube &bPrime() override{
        this->b();
        this->b();
        this->b();
    }

    RubiksCube &b2() override{
        this->b();
        this->b();;

        return *this;
    }

    RubiksCube &d() override {
        this->rotateFace(5);

        char temp[3] = {};
        for (int i = 0; i < 3; i++) temp[i] = cube[getIndex(2, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 2, i)] = cube[getIndex(1, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 2, i)] = cube[getIndex(4, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 2, i)] = cube[getIndex(3, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 2, i)] = temp[i];

        return *this;
    }

    RubiksCube &dPrime() override{
        this->d();
        this->d();
        this->d();
    }

    RubiksCube &d2() override{
        this->d();
        this->d();;

        return *this;
    }

    bool operator==(const RubiksCube1dArray &r1) const{
        for(int i=0;i<54;i++){
            if(r1.cube[i]!=cube[i]){
                return false;
            }
        }
        return true;
    }

    RubiksCube &operator=(const RubiksCube1dArray &r1) {
        for(int i=0;i<54;i++){
            if(r1.cube[i]!=cube[i]){
                cube[i]=r1.cube[i];
            }
        }
        return *this;
    }

    struct Hash1d{
        size_t operator()(const RubiksCube1dArray &r1) const{
            string str="";
            for(int i=0;i<54;i++){
                str+=r1.cube[i];
            }
            return hash<string>()(str);
        }
    };
};
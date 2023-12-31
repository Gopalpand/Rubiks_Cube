#include "Nibble.h"

using namespace std;

Nibble::Nibble(const size_t size, const uint8_t val) :
    size(size),arr(size/2+1,val){}

uint8_t Nibble::get(const size_t pos) const {
    size_t i=pos/2;
    assert(pos<= this->size);
    uint8_t val= this->arr.at(i);

    if(pos%2){
        return val & 0x0F;
    } else{
        return val>>4;
    }
}

void Nibble::set(const size_t pos, const uint8_t val) {
    size_t i=pos/2;
    uint8_t  currVal= this->arr.at(i);
    assert(pos<= this->size);

    if(pos%2){
        this->arr.at(i)=(currVal&0xF0)|(val&0x0F);
    } else{
        this->arr.at(i)=(currVal&0x0F)|(val<<4);
    }
}

uint8_t *Nibble::data() {
    return this->arr.data();
}

const uint8_t *Nibble::data() const {
    return this->arr.data();
}

size_t Nibble::storageSize() const {
    this->arr.size();
}

void Nibble::inflate(vector<uint8_t> &dest) const {
    dest.reserve(this->size);
    for (unsigned i = 0; i < this->size; ++i)
        dest.push_back(this->get(i));
}

// Reset the array
void Nibble::reset(const uint8_t val) {
    fill(this->arr.begin(), this->arr.end(), val);
}

#ifndef feDoble_H
#define feDoble_H

#include "explorationFunction.h"

template<class Key>

class feDoble: public ExplorationFunction<Key>
{
private:
    feDoble<Key>* feDoble_;       //funcion de dispersion
    int nCeldas_;
public:

    feDoble(int);
    ~feDoble();

    //Metodo derivado
    unsigned operator()(const Key& k, unsigned i) const;
};

template<class Key>
feDoble<Key>::feDoble(int numCeldas):nCeldas_(numCeldas)
{
    // feDoble_ = new dispersionPrima<Key>(nCeldas);
}


template<class Key>
feDoble<Key>::~feDoble(){}


template<class Key>
unsigned feDoble<Key>::operator()(const Key& k, unsigned i) const {
    // return *feDoble_(k) * i;
}

#endif //feDoble_H
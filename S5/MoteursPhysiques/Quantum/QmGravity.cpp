//
// Created by cytech on 27/09/24.
//

#include "QmGravity.h"

namespace Quantum {
    QmGravity::QmGravity()
    {
        TYPE = GRAVITY;
    }

    void QmGravity::update(QmParticle *particle, unsigned int i) {
        particle->addForce({0.0, -9.81, 0.0}, i);
    }
} // Quantum
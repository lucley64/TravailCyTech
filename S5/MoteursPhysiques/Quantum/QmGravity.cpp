//
// Created by cytech on 27/09/24.
//

#include "QmGravity.h"

namespace Quantum {
    void QmGravity::update(QmParticle *particle) {
        particle->addForce({0.0, -9.81, 0.0});
    }
} // Quantum
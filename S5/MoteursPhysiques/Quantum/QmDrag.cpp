//
// Created by cytech on 27/09/24.
//

#include "QmDrag.h"

namespace Quantum {
    void QmDrag::update(QmParticle *particle) {
        auto l = glm::length(particle->getVel());
        auto coefficient = -(k1 * l + k2 * l * l);
        particle->addForce((l != 0 ? glm::normalize(particle->getVel()) : glm::vec3{0}) * coefficient);
    }

    QmDrag::QmDrag(float k1, float k2) : k1(k1), k2(k2)
    {
        TYPE = DRAG;
    }
} // Quantum
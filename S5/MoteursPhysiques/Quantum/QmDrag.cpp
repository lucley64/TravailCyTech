//
// Created by cytech on 27/09/24.
//

#include "QmDrag.h"

namespace Quantum {
    void QmDrag::update(QmParticle *particle, unsigned int i) {
        auto l = glm::length(particle->getVel()[i]);
        auto coefficient = -(k1 * l + k2 * l * l);
        particle->addForce((l != 0 ? glm::normalize(particle->getVel()[i]) : glm::vec3{0}) * coefficient, i);
    }

    QmDrag::QmDrag(float k1, float k2) : k1(k1), k2(k2)
    {
        TYPE = DRAG;
    }
} // Quantum
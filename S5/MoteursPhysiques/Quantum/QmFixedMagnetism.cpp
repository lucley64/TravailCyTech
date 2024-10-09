//
// Created by cytech on 27/09/24.
//

#include "QmFixedMagnetism.h"

namespace Quantum {

    void QmFixedMagnetism::update(QmParticle *particle, unsigned int i) {
        auto d = particle->getPos()[i] - *fixedPosition;
        auto coefficient = k * static_cast<float >(particle->getCharge()) * static_cast<float >(*fixedCharge);
        particle->addForce(glm::normalize(d) * coefficient / (glm::length(d) * glm::length(d) + eps), i);
    }

    QmFixedMagnetism::QmFixedMagnetism(const glm::vec3 *fixedPosition, const int *fixedCharge, float k, float eps)
            : fixedPosition(fixedPosition), fixedCharge(fixedCharge), k(k), eps(eps)
    {
        TYPE = FIXED_MAGNETISM;
    }
} // Quantum
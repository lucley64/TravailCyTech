//
// Created by cytech on 27/09/24.
//

#include "QmMagnetism.h"

namespace Quantum {
    void QmMagnetism::update(QmParticle *particle) {
        for (const auto & otherBody: others) {
            auto d = particle->getPos() - otherBody->getPos();
            if (d != glm::vec3 {0}){
                auto coefficient = k * particle->getCharge() * otherBody->getCharge();
                particle->addForce(glm::normalize(d) * coefficient / (d.length() * d.length() + eps));
            }
        }
    }

    QmMagnetism::QmMagnetism(std::vector<QmParticle*> &others, float k, float eps) : others(others), k(k), eps(eps) {}
} // Quantum
//
// Created by cytech on 27/09/24.
//

#include "QmForceRegistry.h"

namespace Quantum {
    QmForceRegistry::QmForceRegistry(QmParticle *particle, QmForceGenerator *forceGenerator) : particle(particle),
                                                                                               forceGenerator(
                                                                                                       forceGenerator) {}

    QmParticle *QmForceRegistry::getParticle() {
        return particle;
    }

    QmForceGenerator *QmForceRegistry::getForceGenerator() {
        return forceGenerator;
    }
} // Quantum
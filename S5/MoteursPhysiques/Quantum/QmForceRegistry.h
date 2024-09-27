//
// Created by cytech on 27/09/24.
//

#ifndef APPLICATION_QMFORCEREGISTRY_H
#define APPLICATION_QMFORCEREGISTRY_H

#include "QmParticle.h"
#include "QmForceGenerator.h"

namespace Quantum {

    class QmForceRegistry {

        QmParticle *particle;
        QmForceGenerator *forceGenerator;

    public:
        QmForceRegistry(QmParticle *particle, QmForceGenerator *forceGenerator);

        QmParticle *getParticle();

        QmForceGenerator *getForceGenerator();
    };

} // Quantum

#endif //APPLICATION_QMFORCEREGISTRY_H

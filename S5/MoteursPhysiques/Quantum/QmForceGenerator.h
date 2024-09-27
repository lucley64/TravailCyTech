//
// Created by cytech on 27/09/24.
//

#ifndef APPLICATION_QMFORCEGENERATOR_H
#define APPLICATION_QMFORCEGENERATOR_H

#include "QmParticle.h"

namespace Quantum {

    class QmForceGenerator {
    public:
        virtual void update(QmParticle *particle) = 0;

        virtual ~QmForceGenerator() = default;
    };

} // Quantum

#endif //APPLICATION_QMFORCEGENERATOR_H

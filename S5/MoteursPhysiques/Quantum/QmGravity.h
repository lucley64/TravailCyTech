//
// Created by cytech on 27/09/24.
//

#ifndef APPLICATION_QMGRAVITY_H
#define APPLICATION_QMGRAVITY_H

#include "QmForceGenerator.h"

namespace Quantum {

    class QmGravity final : public QmForceGenerator {
        void update(QmParticle *particle) override;
    };

} // Quantum

#endif //APPLICATION_QMGRAVITY_H

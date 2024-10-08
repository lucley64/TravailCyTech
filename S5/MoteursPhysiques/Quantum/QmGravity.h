//
// Created by cytech on 27/09/24.
//

#ifndef APPLICATION_QMGRAVITY_H
#define APPLICATION_QMGRAVITY_H

#include "QmForceGenerator.h"

namespace Quantum {
    constexpr int GRAVITY = 1;
    class QmGravity final : public QmForceGenerator {
        public:
        QmGravity();
        void update(QmParticle *particle) override;
    };

} // Quantum

#endif //APPLICATION_QMGRAVITY_H

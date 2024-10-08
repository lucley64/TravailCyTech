//
// Created by cytech on 27/09/24.
//

#ifndef APPLICATION_QMMAGNETISM_H
#define APPLICATION_QMMAGNETISM_H

#include <vector>
#include "QmForceGenerator.h"

namespace Quantum {
    constexpr int MAGNETISM = 3;
    class QmMagnetism: public QmForceGenerator{
        std::vector<QmParticle*> &others;
        float k;
        float eps = 10;
    public:
        QmMagnetism(std::vector<QmParticle*> &others, float k, float eps = 10);

        void update(QmParticle *particle) override;
    };

} // Quantum

#endif //APPLICATION_QMMAGNETISM_H

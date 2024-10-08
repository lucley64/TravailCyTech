//
// Created by cytech on 27/09/24.
//

#ifndef APPLICATION_QMFIXEDMAGNETISM_H
#define APPLICATION_QMFIXEDMAGNETISM_H

#include <glm/vec3.hpp>
#include "QmForceGenerator.h"

namespace Quantum {
    constexpr int FIXED_MAGNETISM = 4;
    class QmFixedMagnetism final : public QmForceGenerator{
        const glm::vec3 *fixedPosition;
        const int *fixedCharge;
        float k;
        float eps;

    public:
        QmFixedMagnetism(const glm::vec3 *fixedPosition, const int *fixedCharge, float k, float eps);

        void update(QmParticle *particle, unsigned int i) override;
    };

} // Quantum

#endif //APPLICATION_QMFIXEDMAGNETISM_H

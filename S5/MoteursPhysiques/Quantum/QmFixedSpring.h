//
// Created by zelie on 10/8/24.
//

#ifndef QMFIXEDSPRING_H
#define QMFIXEDSPRING_H
#include "QmForceGenerator.h"

namespace Quantum
{
    constexpr int FIXED_SPRING = 6;

    class QmFixedSpring final : public QmForceGenerator
    {
        glm::vec3& position;
        float rest_length;
        float spring_constant;

    public:
        QmFixedSpring(glm::vec3& position, float rest_length, float spring_constant);
        void update(QmParticle* particle, unsigned int i) override;
        void setSpringConstant(float spring_constant);
        const glm::vec3& getPosition() const;
    };
} // Quantum

#endif //QMFIXEDSPRING_H

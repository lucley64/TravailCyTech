//
// Created by zelie on 10/8/24.
//

#ifndef QMSPRING_H
#define QMSPRING_H
#include "QmForceGenerator.h"

namespace Quantum
{
    constexpr int SPRING = 5;
    class QmSpring final : public QmForceGenerator
    {
        QmParticle* other;
        float rest_length;
        float spring_constant;

    public:
        QmSpring(QmParticle* other, float rest_strength, float spring_constant);
        void update(QmParticle* particle, unsigned int i) override;
        void setSpringConstant(float spring_constant);
        const QmParticle* getOther() const;
    };
} // Quantum

#endif //QMSPRING_H

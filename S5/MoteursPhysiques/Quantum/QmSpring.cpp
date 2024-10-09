//
// Created by zelie on 10/8/24.
//

#include "QmSpring.h"

namespace Quantum {
    QmSpring::QmSpring(QmParticle* other, const float rest_strength, const float spring_constant): other(other), rest_length(rest_strength), spring_constant(spring_constant)
    {
        TYPE = SPRING;
    }

    void QmSpring::update(QmParticle* particle, unsigned int i)
    {
        const glm::vec3 d = particle->getPos()[i] - other->getPos()[i];
        const float coefficient = -(length(d) - rest_length) * spring_constant;
        particle->addForce((length(d) != 0 ? normalize(d) : glm::vec3(1)) * coefficient, i);
        const glm::vec3 d2 = other->getPos()[i] - particle->getPos()[i];
        const float coefficient2 = -(length(d2) - rest_length) * spring_constant;
        other->addForce((length(d2) != 0 ? normalize(d2) : glm::vec3(1)) * coefficient2, i);
    }

    void QmSpring::setSpringConstant(float spring_constant)
    {
        this->spring_constant = spring_constant;
    }

    const QmParticle* QmSpring::getOther() const
    {
        return other;
    }
} // Quantum
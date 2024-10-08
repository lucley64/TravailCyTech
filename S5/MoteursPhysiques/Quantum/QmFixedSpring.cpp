//
// Created by zelie on 10/8/24.
//

#include "QmFixedSpring.h"

namespace Quantum {
    QmFixedSpring::QmFixedSpring(glm::vec3& position, const float rest_length, const float spring_constant): position(position), rest_length(rest_length), spring_constant(spring_constant)
    {
        TYPE = FIXED_SPRING;
    }

    void QmFixedSpring::update(QmParticle* particle)
    {
        const glm::vec3 d = particle->getPos() - position;
        const float coefficient = -(length(d) - rest_length) * spring_constant;
        particle->addForce((length(d) != 0 ? normalize(d) : glm::vec3(1)) * coefficient);
    }

    void QmFixedSpring::setSpringConstant(float spring_constant)
    {
        this->spring_constant = spring_constant;
    }
} // Quantum
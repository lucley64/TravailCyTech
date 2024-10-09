#pragma once
#ifndef QMBODY_H
#define QMBODY_H

#include <Application/GxParticle.h>
#include <Application/GxParticle.h>
#include <glm/glm.hpp>
#include "QmUpdater.h"

namespace Quantum
{
    const int TYPE_PARTICLE = 0;

    class QmBody
    {
    public:
        virtual void computeAccelerations(unsigned int i) = 0;
        virtual void integrate(float t) = 0;
        virtual void integrate(float t, unsigned int i) = 0;
        virtual void integrateRK4(float t) = 0;


        virtual void addForce(const glm::vec3& force, unsigned int i) = 0;

        virtual void reset() = 0;

        [[nodiscard]] int getType() const { return type; }

        virtual ~QmBody() = default;

    protected:
        explicit QmBody(int type) : type(type)
        {
        }

    private:
        int type = -1;
    };
}

#endif

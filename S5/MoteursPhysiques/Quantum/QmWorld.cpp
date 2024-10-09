#include <iostream>

#include "QmWorld.h"
#include "QmParticle.h"

using namespace Quantum;

QmWorld::QmWorld()
{
    std::cout << "Starting Quantum Physics engine." << std::endl;
}

QmWorld::QmWorld(const bool use_delta, const float delta, const bool useRK4): QmWorld()
{
    this->use_delta = use_delta;
    this->delta = delta;
    this->useRK4 = useRK4;
}

QmWorld::~QmWorld() = default;

void QmWorld::simulate(const float t)
{
    time += t;
    auto dt = time - tick_time;
    if (use_delta)
    {
        while (dt >= delta)
        {
            dt = useRK4 ? tickRK4(delta) : tick(delta);
        }
        interpolate(dt);
    }
    else
    {
        useRK4 ? tickRK4(t) : tick(t);
        interpolate(0);
    }
}


void QmWorld::integrate(const float t)
{
    // time += t;
    for (QmBody* b : bodies)
    {
        b->integrate(t);
    }
}

void QmWorld::integrate(const float t, unsigned int i)
{
    // time += t;
    for (QmBody* b : bodies)
    {
        b->integrate(t, i);
    }
}

void QmWorld::integrateRK4(const float t)
{
    for (QmBody* b : bodies)
    {
        b->integrateRK4(t);
    }
}

void QmWorld::computeAccelerations(const unsigned int i)
{
    for (QmBody* b : bodies)
    {
        b->computeAccelerations(i);
    }
}

void QmWorld::addBody(QmBody* b)
{
    bodies.push_back(b);
}

std::vector<QmBody*> QmWorld::getBodies() const
{
    return bodies;
}

std::vector<QmForceRegistry> QmWorld::getForceRegistry() const
{
    return forceRegistries;
}

std::vector<QmForceRegistry>& QmWorld::getForceRegistry()
{
    return forceRegistries;
}

void QmWorld::clear()
{
    for (const QmBody* b : bodies)
    {
        delete b;
    }
    forceRegistries.clear();
    bodies.clear();
}

void QmWorld::addForceRegistry(const QmForceRegistry& forceRegistry)
{
    forceRegistries.push_back(forceRegistry);
}

void QmWorld::resetBodies()
{
    for (const auto& b : bodies)
    {
        b->reset();
    }
}

float QmWorld::tick(const float t)
{
    resetBodies();
    updateForces(0);
    integrate(t);
    tick_time += t;
    return time - tick_time;
}

float QmWorld::tickRK4(float t)
{
    resetBodies();

    updateForces(0);
    computeAccelerations(0);
    integrate(t / 2, 1);
    updateForces(1);
    computeAccelerations(1);
    integrate(t / 2, 2);
    updateForces(2);
    computeAccelerations(2);
    integrate(t, 3);
    updateForces(3);
    computeAccelerations(3);
    integrateRK4(t);

    tick_time += t;
    return time - tick_time;
}

void QmWorld::interpolate(const float dt)
{
    for (QmBody* b : bodies)
    {
        if (b->getType() == TYPE_PARTICLE)
        {
            const auto* p = reinterpret_cast<QmParticle*>(b);
            p->getUpdater()->update(p->getPos()[0] + dt * p->getVel()[0]);
        }
    }
}

void QmWorld::updateForces(const unsigned int i) const
{
    for (auto& r : forceRegistries)
    {
        r.getForceGenerator()->update(r.getParticle(), i);
    }
}

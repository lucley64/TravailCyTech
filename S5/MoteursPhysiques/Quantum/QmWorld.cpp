#include <iostream>

#include "QmWorld.h"
#include "QmParticle.h"

using namespace Quantum;

QmWorld::QmWorld()
{
    std::cout << "Starting Quantum Physics engine." << std::endl;
}

QmWorld::QmWorld(const bool use_delta, const float delta): QmWorld()
{
    this->use_delta = use_delta;
    this->delta = delta;
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
            dt = tick(delta);
        }
        interpolate(dt);
    }
    else
    {
        tick(t);
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
    updateForces();
    integrate(t);
    tick_time += t;
    return time - tick_time;
}

void QmWorld::interpolate(const float dt)
{
    for (QmBody* b : bodies)
    {
        if (b->getType() == TYPE_PARTICLE)
        {
            auto* p = reinterpret_cast<QmParticle*>(b);
            p->getUpdater()->update(p->getPos() + dt * p->getVel());
        }
    }
}

void QmWorld::updateForces() const
{
    for (auto& r : forceRegistries)
    {
        r.getForceGenerator()->update(r.getParticle());
    }
}

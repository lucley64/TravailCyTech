//
// Created by cytech on 27/09/24.
//

#ifndef APPLICATION_QMDRAG_H
#define APPLICATION_QMDRAG_H

#include "QmForceGenerator.h"

namespace Quantum {

    class QmDrag final : public QmForceGenerator {
        float k1 = 0;
        float k2 = 0;

    public:
        QmDrag(float k1, float k2);
        void update(QmParticle *particle) override;
    };

} // Quantum

#endif //APPLICATION_QMDRAG_H

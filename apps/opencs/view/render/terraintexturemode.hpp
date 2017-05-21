#ifndef CSV_RENDER_TERRAINTEXTUREMODE_H
#define CSV_RENDER_TERRAINTEXTUREMODE_H

#include "editmode.hpp"

#include <osg/Vec3d>

#include <vector>
#include <utility>

namespace CSVRender
{
    class TerrainTextureMode : public EditMode
    {

            Q_OBJECT

        public:

            TerrainTextureMode(WorldspaceWidget* worldspaceWidget, QWidget* parent = 0);

            virtual void primarySelectPressed (const WorldspaceHitResult& hit);

            virtual void secondarySelectPressed (const WorldspaceHitResult& hit);
    };
}

#endif

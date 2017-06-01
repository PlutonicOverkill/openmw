#ifndef CSV_RENDER_TERRAINSHAPEMODE_H
#define CSV_RENDER_TERRAINSHAPEMODE_H

#include "editmode.hpp"

namespace CSVRender
{
    class Cell;

    class TerrainShapeMode : public EditMode
    {
            Q_OBJECT

        public:

            TerrainShapeMode(WorldspaceWidget*, QWidget* parent = 0);

            virtual void primarySelectPressed(const WorldspaceHitResult&);

            virtual void secondarySelectPressed(const WorldspaceHitResult&);
    };
}

#endif

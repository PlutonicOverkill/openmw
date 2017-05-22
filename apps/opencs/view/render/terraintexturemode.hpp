#ifndef CSV_RENDER_TERRAINTEXTUREMODE_H
#define CSV_RENDER_TERRAINTEXTUREMODE_H

#include "editmode.hpp"

#include <osg/Vec3d>

#include <vector>
#include <utility>

namespace CSVRender
{
    class Cell;

    class TerrainTextureMode : public EditMode
    {
        Q_OBJECT

            Cell* mLastSelectedCell;

        public:

            TerrainTextureMode(WorldspaceWidget* worldspaceWidget, QWidget* parent = 0);

            virtual void primarySelectPressed (const WorldspaceHitResult&);

            virtual void secondarySelectPressed (const WorldspaceHitResult&);

        private:

            void deselectAll(const WorldspaceHitResult&);

            void deselectLastSelectedCell();
    };
}

#endif

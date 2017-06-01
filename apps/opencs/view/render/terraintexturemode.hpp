#ifndef CSV_RENDER_TERRAINTEXTUREMODE_H
#define CSV_RENDER_TERRAINTEXTUREMODE_H

#include "editmode.hpp"

namespace CSVRender
{
    class Cell;

    class TerrainTextureMode : public EditMode
    {
            Q_OBJECT

        public:

            TerrainTextureMode(WorldspaceWidget*, QWidget* parent = 0);

            virtual void primarySelectPressed(const WorldspaceHitResult&);

            virtual void secondarySelectPressed(const WorldspaceHitResult&);

            virtual void activate(CSVWidget::SceneToolbar* toolbar);

            virtual void deactivate(CSVWidget::SceneToolbar* toolbar);
    };
}

#endif

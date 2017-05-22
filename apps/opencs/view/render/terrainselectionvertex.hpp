#ifndef CSV_RENDER_TERRAINSELECTIONVERTEX_H
#define CSV_RENDER_TERRAINSELECTIONVERTEX_H

#include "terrainselectiontexture.hpp"

namespace CSVRender
{
    class TerrainSelectionVertex
    {
            // TODO: put something in this class
        
            friend class CSVRender::TerrainSelectionTexture;

        public:

            TerrainSelectionVertex();
            TerrainSelectionVertex(TerrainSelectionTexture);

            ~TerrainSelectionVertex();
    };
}

#endif

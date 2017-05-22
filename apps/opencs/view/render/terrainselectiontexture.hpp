#ifndef CSV_RENDER_TERRAINSELECTIONTEXTURE_H
#define CSV_RENDER_TERRAINSELECTIONTEXTURE_H

#include "terrainselectionvertex.hpp"

namespace CSVRender
{
    class TerrainSelectionTexture
    {
            friend class CSVRender::TerrainSelectionVertex;

            typedef std::pair<int, int> TexturePos;

            typedef std::vector<TexturePos> Container;
            typedef Container::iterator Iterator;

            Container mSelection;

        public:

            TerrainSelectionTexture();
            TerrainSelectionTexture(TerrainSelectionVertex);

            ~TerrainSelectionTexture();

            operator TerrainSelectionVertex() const;
    };
}

#endif

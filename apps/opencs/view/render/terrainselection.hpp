#ifndef CSV_RENDER_TERRAINSELECTION_H
#define CSV_RENDER_TERRAINSELECTION_H

#include "terrainselectiontexture.hpp"
#include "terrainselectionvertex.hpp"

#include <osg/Vec3d>

#include <utility>
#include <vector>

namespace CSVRender
{
    class Cell;

    // used to keep track of which selection is
    // the "original", and which selection has
    // been converted to when switching terrain
    // editing modes
    enum TerrainSelectionType
    {
        TerrainSelectionType_None, // is having a default value worth it?
        TerrainSelectionType_Texture,
        TerrainSelectionType_Vertex
    };

    class TerrainSelection
    {
            Cell* mCell;

            TerrainSelectionTexture mTextureSelection;
            TerrainSelectionVertex mVertexSelection;
            TerrainSelectionType mSelectionState;

            // not implemented
            TerrainSelection(const TerrainSelection&);
            TerrainSelection& operator=(const TerrainSelection&);

        public:

            typedef std::pair<int, int> TexturePos;

            TerrainSelection(Cell*);

            ~TerrainSelection();

            void setSelectionMode(TerrainSelectionType);

            void deselectAll();

        private:

            TexturePos toTextureCoords(osg::Vec3d worldPos);
    };
}

#endif

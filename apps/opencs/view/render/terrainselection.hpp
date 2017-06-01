#ifndef CSV_RENDER_TERRAINSELECTION_H
#define CSV_RENDER_TERRAINSELECTION_H

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
        public:

            typedef std::pair<int, int> TerrainPos;
            typedef std::vector<TerrainPos> Container;
            typedef std::vector<TerrainPos>::iterator Iterator;

            Cell* mCell;
            Container mTextureSelection;
            Container mVertexSelection;
            TerrainSelectionType mSelectionState;

            // not implemented
            TerrainSelection(const TerrainSelection&);
            TerrainSelection& operator=(const TerrainSelection&);

        public:

            TerrainSelection(Cell*);

            ~TerrainSelection();

            void setSelectionMode(TerrainSelectionType);

            void select(osg::Vec3d worldPos);

            void toggleSelect(osg::Vec3d worldPos);

            void deselectAll();

        private:

            TerrainPos toTextureCoords(osg::Vec3d worldPos);
    };
}

#endif

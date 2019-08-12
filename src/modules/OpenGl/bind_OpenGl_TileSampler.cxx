/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_Context.hxx>
#include <OpenGl_Texture.hxx>
#include <OpenGl_HaltonSampler.hxx>
#include <OpenGl_TileSampler.hxx>

void bind_OpenGl_TileSampler(py::module &mod){

py::class_<OpenGl_TileSampler, std::unique_ptr<OpenGl_TileSampler, Deleter<OpenGl_TileSampler>>> cls_OpenGl_TileSampler(mod, "OpenGl_TileSampler", "Tool object used for sampling screen tiles according to estimated pixel variance (used in path tracing engine). To improve GPU thread coherency, rendering window is split into pixel blocks or tiles. The important feature of this approach is that it is possible to keep the same number of tiles for any screen resolution (e.g. 256 tiles can be used for both 512 x 512 window and 1920 x 1080 window). So, a smaller number of tiles allows to increase interactivity (FPS), but at the cost of higher per-frame variance ('noise'). On the contrary a larger number of tiles decrease interactivity, but leads to lower per-frame variance. Note that the total time needed to produce final final image is the same for both cases.");

// Constructors
cls_OpenGl_TileSampler.def(py::init<>());

// Fields

// Methods
cls_OpenGl_TileSampler.def_static("TileSize_", (int (*)()) &OpenGl_TileSampler::TileSize, "Size of individual tile in pixels.");
cls_OpenGl_TileSampler.def("SizeX", (int (OpenGl_TileSampler::*)() const) &OpenGl_TileSampler::SizeX, "Returns width of ray-tracing viewport.");
cls_OpenGl_TileSampler.def("SizeY", (int (OpenGl_TileSampler::*)() const) &OpenGl_TileSampler::SizeY, "Returns height of ray-tracing viewport.");
cls_OpenGl_TileSampler.def("NbTilesX", (int (OpenGl_TileSampler::*)() const) &OpenGl_TileSampler::NbTilesX, "Returns number of tiles in X dimension.");
cls_OpenGl_TileSampler.def("NbTilesY", (int (OpenGl_TileSampler::*)() const) &OpenGl_TileSampler::NbTilesY, "Returns number of tiles in Y dimension.");
cls_OpenGl_TileSampler.def("NbTiles", (int (OpenGl_TileSampler::*)() const) &OpenGl_TileSampler::NbTiles, "Returns total number of tiles in viewport.");
cls_OpenGl_TileSampler.def("SetSize", (void (OpenGl_TileSampler::*)(const int, const int)) &OpenGl_TileSampler::SetSize, "Specifies size of ray-tracing viewport.", py::arg("theSizeX"), py::arg("theSizeY"));
cls_OpenGl_TileSampler.def("TileArea", (int (OpenGl_TileSampler::*)(const int, const int) const) &OpenGl_TileSampler::TileArea, "Returns number of pixels in the given tile.", py::arg("theX"), py::arg("theY"));
cls_OpenGl_TileSampler.def("GrabVarianceMap", (void (OpenGl_TileSampler::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_TileSampler::GrabVarianceMap, "Fetches current error estimation from the GPU and builds 2D discrete distribution for tile sampling.", py::arg("theContext"));
cls_OpenGl_TileSampler.def("Sample", (void (OpenGl_TileSampler::*)(int &, int &)) &OpenGl_TileSampler::Sample, "Samples tile location according to estimated error.", py::arg("theOffsetX"), py::arg("theOffsetY"));
cls_OpenGl_TileSampler.def("Reset", (void (OpenGl_TileSampler::*)()) &OpenGl_TileSampler::Reset, "Resets tile sampler to initial state.");
cls_OpenGl_TileSampler.def("Upload", (void (OpenGl_TileSampler::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<OpenGl_Texture> &, const int, const int, const bool)) &OpenGl_TileSampler::Upload, "Uploads offsets of sampled tiles to the given OpenGL texture.", py::arg("theContext"), py::arg("theTexture"), py::arg("theNbTilesX"), py::arg("theNbTilesY"), py::arg("theAdaptive"));

// Enums

}
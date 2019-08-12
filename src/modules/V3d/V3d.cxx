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

void bind_V3d_StereoDumpOptions(py::module &);
void bind_V3d_TypeOfAxe(py::module &);
void bind_V3d_TypeOfBackfacingModel(py::module &);
void bind_V3d_TypeOfOrientation(py::module &);
void bind_V3d_TypeOfView(py::module &);
void bind_V3d_TypeOfVisualization(py::module &);
void bind_V3d_TypeOfPickLight(py::module &);
void bind_V3d_TypeOfRepresentation(py::module &);
void bind_V3d_TypeOfPickCamera(py::module &);
void bind_V3d_ImageDumpOptions(py::module &);
void bind_V3d_Trihedron(py::module &);
void bind_V3d_TypeOfLight(py::module &);
void bind_V3d_Light(py::module &);
void bind_V3d_ListOfLight(py::module &);
void bind_V3d_ListOfLightIterator(py::module &);
void bind_V3d_ListOfView(py::module &);
void bind_V3d_ListOfViewIterator(py::module &);
void bind_V3d_Viewer(py::module &);
void bind_V3d_ViewerPointer(py::module &);
void bind_V3d_View(py::module &);
void bind_V3d(py::module &);
void bind_V3d_AmbientLight(py::module &);
void bind_V3d_BadValue(py::module &);
void bind_V3d_CircularGrid(py::module &);
void bind_V3d_Coordinate(py::module &);
void bind_V3d_PositionLight(py::module &);
void bind_V3d_DirectionalLight(py::module &);
void bind_V3d_Parameter(py::module &);
void bind_V3d_Plane(py::module &);
void bind_V3d_PositionalLight(py::module &);
void bind_V3d_RectangularGrid(py::module &);
void bind_V3d_SpotLight(py::module &);
void bind_V3d_TypeOfShadingModel(py::module &);
void bind_V3d_UnMapped(py::module &);
void bind_V3d_ViewPointer(py::module &);

PYBIND11_MODULE(V3d, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Graphic3d");
py::module::import("OCCT.Aspect");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.Prs3d");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.gp");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.Image");

bind_V3d_StereoDumpOptions(mod);
bind_V3d_TypeOfAxe(mod);
bind_V3d_TypeOfBackfacingModel(mod);
bind_V3d_TypeOfOrientation(mod);
bind_V3d_TypeOfView(mod);
bind_V3d_TypeOfVisualization(mod);
bind_V3d_TypeOfPickLight(mod);
bind_V3d_TypeOfRepresentation(mod);
bind_V3d_TypeOfPickCamera(mod);
bind_V3d_ImageDumpOptions(mod);
bind_V3d_Trihedron(mod);
bind_V3d_TypeOfLight(mod);
bind_V3d_Light(mod);
bind_V3d_ListOfLight(mod);
bind_V3d_ListOfLightIterator(mod);
bind_V3d_ListOfView(mod);
bind_V3d_ListOfViewIterator(mod);
bind_V3d_Viewer(mod);
bind_V3d_ViewerPointer(mod);
bind_V3d_View(mod);
bind_V3d(mod);
bind_V3d_AmbientLight(mod);
bind_V3d_BadValue(mod);
bind_V3d_CircularGrid(mod);
bind_V3d_Coordinate(mod);
bind_V3d_PositionLight(mod);
bind_V3d_DirectionalLight(mod);
bind_V3d_Parameter(mod);
bind_V3d_Plane(mod);
bind_V3d_PositionalLight(mod);
bind_V3d_RectangularGrid(mod);
bind_V3d_SpotLight(mod);
bind_V3d_TypeOfShadingModel(mod);
bind_V3d_UnMapped(mod);
bind_V3d_ViewPointer(mod);

}

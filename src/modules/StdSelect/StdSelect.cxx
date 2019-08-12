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

void bind_StdSelect_TypeOfSelectionImage(py::module &);
void bind_StdSelect_DisplayMode(py::module &);
void bind_StdSelect_TypeOfEdge(py::module &);
void bind_StdSelect_TypeOfFace(py::module &);
void bind_StdSelect_SensitivityMode(py::module &);
void bind_StdSelect_TypeOfResult(py::module &);
void bind_StdSelect_ViewerSelector3d(py::module &);
void bind_StdSelect(py::module &);
void bind_StdSelect_BRepOwner(py::module &);
void bind_StdSelect_BRepSelectionTool(py::module &);
void bind_StdSelect_EdgeFilter(py::module &);
void bind_StdSelect_FaceFilter(py::module &);
void bind_StdSelect_Prs(py::module &);
void bind_StdSelect_IndexedDataMapOfOwnerPrs(py::module &);
void bind_StdSelect_Shape(py::module &);
void bind_StdSelect_ShapeTypeFilter(py::module &);

PYBIND11_MODULE(StdSelect, mod) {

py::module::import("OCCT.SelectMgr");
py::module::import("OCCT.Standard");
py::module::import("OCCT.V3d");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.Image");
py::module::import("OCCT.gp");
py::module::import("OCCT.Graphic3d");
py::module::import("OCCT.Prs3d");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.PrsMgr");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.Select3D");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.SelectBasics");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Geom");

bind_StdSelect_TypeOfSelectionImage(mod);
bind_StdSelect_DisplayMode(mod);
bind_StdSelect_TypeOfEdge(mod);
bind_StdSelect_TypeOfFace(mod);
bind_StdSelect_SensitivityMode(mod);
bind_StdSelect_TypeOfResult(mod);
bind_StdSelect_ViewerSelector3d(mod);
bind_StdSelect(mod);
bind_StdSelect_BRepOwner(mod);
bind_StdSelect_BRepSelectionTool(mod);
bind_StdSelect_EdgeFilter(mod);
bind_StdSelect_FaceFilter(mod);
bind_StdSelect_Prs(mod);
bind_StdSelect_IndexedDataMapOfOwnerPrs(mod);
bind_StdSelect_Shape(mod);
bind_StdSelect_ShapeTypeFilter(mod);

}

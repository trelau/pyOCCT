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

void bind_BRepClass3d(py::module &);
void bind_BRepClass3d_BndBoxTree(py::module &);
void bind_BRepClass3d_BndBoxTreeSelectorPoint(py::module &);
void bind_BRepClass3d_BndBoxTreeSelectorLine(py::module &);
void bind_BRepClass3d_MapOfInter(py::module &);
void bind_BRepClass3d_DataMapIteratorOfMapOfInter(py::module &);
void bind_BRepClass3d_Intersector3d(py::module &);
void bind_BRepClass3d_SClassifier(py::module &);
void bind_BRepClass3d_SolidExplorer(py::module &);
void bind_BRepClass3d_SolidClassifier(py::module &);
void bind_BRepClass3d_SolidPassiveClassifier(py::module &);

PYBIND11_MODULE(BRepClass3d, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Precision");
py::module::import("OCCT.GeomAdaptor");
py::module::import("OCCT.IntCurveSurface");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.BRepAdaptor");
py::module::import("OCCT.IntCurvesFace");
py::module::import("OCCT.TopExp");

bind_BRepClass3d(mod);
bind_BRepClass3d_BndBoxTree(mod);
bind_BRepClass3d_BndBoxTreeSelectorPoint(mod);
bind_BRepClass3d_BndBoxTreeSelectorLine(mod);
bind_BRepClass3d_MapOfInter(mod);
bind_BRepClass3d_DataMapIteratorOfMapOfInter(mod);
bind_BRepClass3d_Intersector3d(mod);
bind_BRepClass3d_SClassifier(mod);
bind_BRepClass3d_SolidExplorer(mod);
bind_BRepClass3d_SolidClassifier(mod);
bind_BRepClass3d_SolidPassiveClassifier(mod);

}

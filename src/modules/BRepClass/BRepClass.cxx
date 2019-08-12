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

void bind_BRepClass_Edge(py::module &);
void bind_BRepClass_Intersector(py::module &);
void bind_BRepClass_FClass2dOfFClassifier(py::module &);
void bind_BRepClass_FClassifier(py::module &);
void bind_BRepClass_FaceExplorer(py::module &);
void bind_BRepClass_FaceClassifier(py::module &);
void bind_BRepClass_FacePassiveClassifier(py::module &);

PYBIND11_MODULE(BRepClass, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Geom2dInt");
py::module::import("OCCT.gp");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TopTrans");
py::module::import("OCCT.IntRes2d");
py::module::import("OCCT.TopExp");

bind_BRepClass_Edge(mod);
bind_BRepClass_Intersector(mod);
bind_BRepClass_FClass2dOfFClassifier(mod);
bind_BRepClass_FClassifier(mod);
bind_BRepClass_FaceExplorer(mod);
bind_BRepClass_FaceClassifier(mod);
bind_BRepClass_FacePassiveClassifier(mod);

}

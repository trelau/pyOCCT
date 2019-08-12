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

void bind_BRepGProp(py::module &);
void bind_BRepGProp_Cinert(py::module &);
void bind_BRepGProp_Domain(py::module &);
void bind_BRepGProp_EdgeTool(py::module &);
void bind_BRepGProp_Face(py::module &);
void bind_BRepGProp_Gauss(py::module &);
void bind_BRepGProp_Sinert(py::module &);
void bind_BRepGProp_UFunction(py::module &);
void bind_BRepGProp_TFunction(py::module &);
void bind_BRepGProp_Vinert(py::module &);
void bind_BRepGProp_VinertGK(py::module &);

PYBIND11_MODULE(BRepGProp, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.GProp");
py::module::import("OCCT.gp");
py::module::import("OCCT.BRepAdaptor");
py::module::import("OCCT.TopExp");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Geom2dAdaptor");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.math");

bind_BRepGProp(mod);
bind_BRepGProp_Cinert(mod);
bind_BRepGProp_Domain(mod);
bind_BRepGProp_EdgeTool(mod);
bind_BRepGProp_Face(mod);
bind_BRepGProp_Gauss(mod);
bind_BRepGProp_Sinert(mod);
bind_BRepGProp_UFunction(mod);
bind_BRepGProp_TFunction(mod);
bind_BRepGProp_Vinert(mod);
bind_BRepGProp_VinertGK(mod);

}

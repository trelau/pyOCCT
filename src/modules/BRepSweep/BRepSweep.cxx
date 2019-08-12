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

void bind_BRepSweep_Builder(py::module &);
void bind_BRepSweep_Tool(py::module &);
void bind_BRepSweep_NumLinearRegularSweep(py::module &);
void bind_BRepSweep_Trsf(py::module &);
void bind_BRepSweep_Translation(py::module &);
void bind_BRepSweep_Prism(py::module &);
void bind_BRepSweep_Rotation(py::module &);
void bind_BRepSweep_Revol(py::module &);
void bind_BRepSweep_Iterator(py::module &);

PYBIND11_MODULE(BRepSweep, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.BRep");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.Sweep");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.gp");

bind_BRepSweep_Builder(mod);
bind_BRepSweep_Tool(mod);
bind_BRepSweep_NumLinearRegularSweep(mod);
bind_BRepSweep_Trsf(mod);
bind_BRepSweep_Translation(mod);
bind_BRepSweep_Prism(mod);
bind_BRepSweep_Rotation(mod);
bind_BRepSweep_Revol(mod);
bind_BRepSweep_Iterator(mod);

}

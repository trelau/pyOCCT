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

void bind_ShapeProcess(py::module &);
void bind_ShapeProcess_Context(py::module &);
void bind_ShapeProcess_Operator(py::module &);
void bind_ShapeProcess_OperFunc(py::module &);
void bind_ShapeProcess_OperLibrary(py::module &);
void bind_ShapeProcess_ShapeContext(py::module &);
void bind_ShapeProcess_UOperator(py::module &);

PYBIND11_MODULE(ShapeProcess, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Resource");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.Message");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.BRepTools");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.ShapeExtend");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.ShapeBuild");
py::module::import("OCCT.GeomAbs");

bind_ShapeProcess(mod);
bind_ShapeProcess_Context(mod);
bind_ShapeProcess_Operator(mod);
bind_ShapeProcess_OperFunc(mod);
bind_ShapeProcess_OperLibrary(mod);
bind_ShapeProcess_ShapeContext(mod);
bind_ShapeProcess_UOperator(mod);

}

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

void bind_STEPConstruct_Tool(py::module &);
void bind_STEPConstruct_AP203Context(py::module &);
void bind_STEPConstruct_ContextTool(py::module &);
void bind_STEPConstruct(py::module &);
void bind_STEPConstruct_Assembly(py::module &);
void bind_STEPConstruct_DataMapOfAsciiStringTransient(py::module &);
void bind_STEPConstruct_DataMapIteratorOfDataMapOfAsciiStringTransient(py::module &);
void bind_STEPConstruct_PointHasher(py::module &);
void bind_STEPConstruct_DataMapOfPointTransient(py::module &);
void bind_STEPConstruct_DataMapIteratorOfDataMapOfPointTransient(py::module &);
void bind_STEPConstruct_ExternRefs(py::module &);
void bind_STEPConstruct_Part(py::module &);
void bind_STEPConstruct_Styles(py::module &);
void bind_STEPConstruct_UnitContext(py::module &);
void bind_STEPConstruct_ValidationProps(py::module &);

PYBIND11_MODULE(STEPConstruct, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.XSControl");
py::module::import("OCCT.Interface");
py::module::import("OCCT.Transfer");
py::module::import("OCCT.StepBasic");
py::module::import("OCCT.StepShape");
py::module::import("OCCT.StepRepr");
py::module::import("OCCT.StepAP203");
py::module::import("OCCT.StepData");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.StepGeom");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.gp");
py::module::import("OCCT.StepAP214");
py::module::import("OCCT.StepVisual");
py::module::import("OCCT.Quantity");

bind_STEPConstruct_Tool(mod);
bind_STEPConstruct_AP203Context(mod);
bind_STEPConstruct_ContextTool(mod);
bind_STEPConstruct(mod);
bind_STEPConstruct_Assembly(mod);
bind_STEPConstruct_DataMapOfAsciiStringTransient(mod);
bind_STEPConstruct_DataMapIteratorOfDataMapOfAsciiStringTransient(mod);
bind_STEPConstruct_PointHasher(mod);
bind_STEPConstruct_DataMapOfPointTransient(mod);
bind_STEPConstruct_DataMapIteratorOfDataMapOfPointTransient(mod);
bind_STEPConstruct_ExternRefs(mod);
bind_STEPConstruct_Part(mod);
bind_STEPConstruct_Styles(mod);
bind_STEPConstruct_UnitContext(mod);
bind_STEPConstruct_ValidationProps(mod);

}

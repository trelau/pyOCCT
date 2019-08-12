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
#include <Law_BSpFunc.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Law_Interpol.hxx>
#include <Standard_Type.hxx>

void bind_Law_Interpol(py::module &mod){

py::class_<Law_Interpol, opencascade::handle<Law_Interpol>, Law_BSpFunc> cls_Law_Interpol(mod, "Law_Interpol", "Provides an evolution law that interpolates a set of parameter and value pairs (wi, radi)");

// Constructors
cls_Law_Interpol.def(py::init<>());

// Fields

// Methods
cls_Law_Interpol.def("Set", [](Law_Interpol &self, const TColgp_Array1OfPnt2d & a0) -> void { return self.Set(a0); });
cls_Law_Interpol.def("Set", (void (Law_Interpol::*)(const TColgp_Array1OfPnt2d &, const Standard_Boolean)) &Law_Interpol::Set, "Defines this evolution law by interpolating the set of 2D points ParAndRad. The Y coordinate of a point of ParAndRad is the value of the function at the parameter point given by its X coordinate. If Periodic is true, this function is assumed to be periodic. Warning - The X coordinates of points in the table ParAndRad must be given in ascendant order. - If Periodic is true, the first and last Y coordinates of points in the table ParAndRad are assumed to be equal. In addition, with the second syntax, Dd and Df are also assumed to be equal. If this is not the case, Set uses the first value(s) as last value(s).", py::arg("ParAndRad"), py::arg("Periodic"));
cls_Law_Interpol.def("SetInRelative", [](Law_Interpol &self, const TColgp_Array1OfPnt2d & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.SetInRelative(a0, a1, a2); });
cls_Law_Interpol.def("SetInRelative", (void (Law_Interpol::*)(const TColgp_Array1OfPnt2d &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Law_Interpol::SetInRelative, "None", py::arg("ParAndRad"), py::arg("Ud"), py::arg("Uf"), py::arg("Periodic"));
cls_Law_Interpol.def("Set", [](Law_Interpol &self, const TColgp_Array1OfPnt2d & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Set(a0, a1, a2); });
cls_Law_Interpol.def("Set", (void (Law_Interpol::*)(const TColgp_Array1OfPnt2d &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Law_Interpol::Set, "Defines this evolution law by interpolating the set of 2D points ParAndRad. The Y coordinate of a point of ParAndRad is the value of the function at the parameter point given by its X coordinate. If Periodic is true, this function is assumed to be periodic. In the second syntax, Dd and Df define the values of the first derivative of the function at its first and last points. Warning - The X coordinates of points in the table ParAndRad must be given in ascendant order. - If Periodic is true, the first and last Y coordinates of points in the table ParAndRad are assumed to be equal. In addition, with the second syntax, Dd and Df are also assumed to be equal. If this is not the case, Set uses the first value(s) as last value(s).", py::arg("ParAndRad"), py::arg("Dd"), py::arg("Df"), py::arg("Periodic"));
cls_Law_Interpol.def("SetInRelative", [](Law_Interpol &self, const TColgp_Array1OfPnt2d & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4) -> void { return self.SetInRelative(a0, a1, a2, a3, a4); });
cls_Law_Interpol.def("SetInRelative", (void (Law_Interpol::*)(const TColgp_Array1OfPnt2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Law_Interpol::SetInRelative, "None", py::arg("ParAndRad"), py::arg("Ud"), py::arg("Uf"), py::arg("Dd"), py::arg("Df"), py::arg("Periodic"));
cls_Law_Interpol.def_static("get_type_name_", (const char * (*)()) &Law_Interpol::get_type_name, "None");
cls_Law_Interpol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Law_Interpol::get_type_descriptor, "None");
cls_Law_Interpol.def("DynamicType", (const opencascade::handle<Standard_Type> & (Law_Interpol::*)() const) &Law_Interpol::DynamicType, "None");

// Enums

}
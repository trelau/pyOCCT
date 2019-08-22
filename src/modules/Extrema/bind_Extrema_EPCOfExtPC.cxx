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
#include <Standard.hxx>
#include <gp_Pnt.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_POnCurv.hxx>
#include <Extrema_PCFOfEPCOfExtPC.hxx>
#include <Extrema_EPCOfExtPC.hxx>

void bind_Extrema_EPCOfExtPC(py::module &mod){

py::class_<Extrema_EPCOfExtPC> cls_Extrema_EPCOfExtPC(mod, "Extrema_EPCOfExtPC", "None");

// Constructors
cls_Extrema_EPCOfExtPC.def(py::init<>());
cls_Extrema_EPCOfExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("NbU"), py::arg("TolU"), py::arg("TolF"));
cls_Extrema_EPCOfExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("NbU"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"), py::arg("TolF"));

// Fields

// Methods
// cls_Extrema_EPCOfExtPC.def_static("operator new_", (void * (*)(size_t)) &Extrema_EPCOfExtPC::operator new, "None", py::arg("theSize"));
// cls_Extrema_EPCOfExtPC.def_static("operator delete_", (void (*)(void *)) &Extrema_EPCOfExtPC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_EPCOfExtPC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_EPCOfExtPC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_EPCOfExtPC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_EPCOfExtPC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_EPCOfExtPC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_EPCOfExtPC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_EPCOfExtPC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_EPCOfExtPC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_EPCOfExtPC.def("Initialize", (void (Extrema_EPCOfExtPC::*)(const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real)) &Extrema_EPCOfExtPC::Initialize, "sets the fields of the algorithm.", py::arg("C"), py::arg("NbU"), py::arg("TolU"), py::arg("TolF"));
cls_Extrema_EPCOfExtPC.def("Initialize", (void (Extrema_EPCOfExtPC::*)(const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_EPCOfExtPC::Initialize, "sets the fields of the algorithm.", py::arg("C"), py::arg("NbU"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"), py::arg("TolF"));
cls_Extrema_EPCOfExtPC.def("Initialize", (void (Extrema_EPCOfExtPC::*)(const Adaptor3d_Curve &)) &Extrema_EPCOfExtPC::Initialize, "sets the fields of the algorithm.", py::arg("C"));
cls_Extrema_EPCOfExtPC.def("Initialize", (void (Extrema_EPCOfExtPC::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_EPCOfExtPC::Initialize, "sets the fields of the algorithm.", py::arg("NbU"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"), py::arg("TolF"));
cls_Extrema_EPCOfExtPC.def("Perform", (void (Extrema_EPCOfExtPC::*)(const gp_Pnt &)) &Extrema_EPCOfExtPC::Perform, "the algorithm is done with the point P. An exception is raised if the fields have not been initialized.", py::arg("P"));
cls_Extrema_EPCOfExtPC.def("IsDone", (Standard_Boolean (Extrema_EPCOfExtPC::*)() const) &Extrema_EPCOfExtPC::IsDone, "True if the distances are found.");
cls_Extrema_EPCOfExtPC.def("NbExt", (Standard_Integer (Extrema_EPCOfExtPC::*)() const) &Extrema_EPCOfExtPC::NbExt, "Returns the number of extremum distances.");
cls_Extrema_EPCOfExtPC.def("SquareDistance", (Standard_Real (Extrema_EPCOfExtPC::*)(const Standard_Integer) const) &Extrema_EPCOfExtPC::SquareDistance, "Returns the value of the Nth extremum square distance.", py::arg("N"));
cls_Extrema_EPCOfExtPC.def("IsMin", (Standard_Boolean (Extrema_EPCOfExtPC::*)(const Standard_Integer) const) &Extrema_EPCOfExtPC::IsMin, "Returns True if the Nth extremum distance is a minimum.", py::arg("N"));
cls_Extrema_EPCOfExtPC.def("Point", (const Extrema_POnCurv & (Extrema_EPCOfExtPC::*)(const Standard_Integer) const) &Extrema_EPCOfExtPC::Point, "Returns the point of the Nth extremum distance.", py::arg("N"));

// Enums

}
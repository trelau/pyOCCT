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
#include <Standard_Transient.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <GeomAdaptor_HSurfaceOfLinearExtrusion.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_POnSurf.hxx>
#include <Extrema_ExtPExtS.hxx>
#include <Standard_Type.hxx>
#include <gp_Ax2.hxx>
#include <Extrema_FuncPSNorm.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <gp_Vec.hxx>
#include <Extrema_GenExtPS.hxx>

void bind_Extrema_ExtPExtS(py::module &mod){

py::class_<Extrema_ExtPExtS, opencascade::handle<Extrema_ExtPExtS>, Standard_Transient> cls_Extrema_ExtPExtS(mod, "Extrema_ExtPExtS", "It calculates all the extremum (minimum and maximum) distances between a point and a linear extrusion surface.");

// Constructors
cls_Extrema_ExtPExtS.def(py::init<>());
cls_Extrema_ExtPExtS.def(py::init<const gp_Pnt &, const opencascade::handle<GeomAdaptor_HSurfaceOfLinearExtrusion> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("TolU"), py::arg("TolV"));
cls_Extrema_ExtPExtS.def(py::init<const gp_Pnt &, const opencascade::handle<GeomAdaptor_HSurfaceOfLinearExtrusion> &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("TolU"), py::arg("TolV"));

// Fields

// Methods
cls_Extrema_ExtPExtS.def("Initialize", (void (Extrema_ExtPExtS::*)(const opencascade::handle<GeomAdaptor_HSurfaceOfLinearExtrusion> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPExtS::Initialize, "Initializes the fields of the algorithm.", py::arg("S"), py::arg("Uinf"), py::arg("Usup"), py::arg("Vinf"), py::arg("Vsup"), py::arg("TolU"), py::arg("TolV"));
cls_Extrema_ExtPExtS.def("Perform", (void (Extrema_ExtPExtS::*)(const gp_Pnt &)) &Extrema_ExtPExtS::Perform, "None", py::arg("P"));
cls_Extrema_ExtPExtS.def("IsDone", (Standard_Boolean (Extrema_ExtPExtS::*)() const) &Extrema_ExtPExtS::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtPExtS.def("NbExt", (Standard_Integer (Extrema_ExtPExtS::*)() const) &Extrema_ExtPExtS::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtPExtS.def("SquareDistance", (Standard_Real (Extrema_ExtPExtS::*)(const Standard_Integer) const) &Extrema_ExtPExtS::SquareDistance, "Returns the value of the Nth resulting square distance.", py::arg("N"));
cls_Extrema_ExtPExtS.def("Point", (const Extrema_POnSurf & (Extrema_ExtPExtS::*)(const Standard_Integer) const) &Extrema_ExtPExtS::Point, "Returns the point of the Nth resulting distance.", py::arg("N"));
cls_Extrema_ExtPExtS.def_static("get_type_name_", (const char * (*)()) &Extrema_ExtPExtS::get_type_name, "None");
cls_Extrema_ExtPExtS.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Extrema_ExtPExtS::get_type_descriptor, "None");
cls_Extrema_ExtPExtS.def("DynamicType", (const opencascade::handle<Standard_Type> & (Extrema_ExtPExtS::*)() const) &Extrema_ExtPExtS::DynamicType, "None");

// Enums

}
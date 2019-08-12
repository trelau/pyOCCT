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
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_Handle.hxx>
#include <MAT2d_Connexion.hxx>
#include <Standard_Type.hxx>

void bind_MAT2d_Connexion(py::module &mod){

py::class_<MAT2d_Connexion, opencascade::handle<MAT2d_Connexion>, Standard_Transient> cls_MAT2d_Connexion(mod, "MAT2d_Connexion", "A Connexion links two lines of items in a set of lines. It s contains two points and their paramatric definitions on the lines. The items can be points or curves.");

// Constructors
cls_MAT2d_Connexion.def(py::init<>());
cls_MAT2d_Connexion.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("LineA"), py::arg("LineB"), py::arg("ItemA"), py::arg("ItemB"), py::arg("Distance"), py::arg("ParameterOnA"), py::arg("ParameterOnB"), py::arg("PointA"), py::arg("PointB"));

// Fields

// Methods
cls_MAT2d_Connexion.def("IndexFirstLine", (Standard_Integer (MAT2d_Connexion::*)() const) &MAT2d_Connexion::IndexFirstLine, "Returns the Index on the first line.");
cls_MAT2d_Connexion.def("IndexSecondLine", (Standard_Integer (MAT2d_Connexion::*)() const) &MAT2d_Connexion::IndexSecondLine, "Returns the Index on the Second line.");
cls_MAT2d_Connexion.def("IndexItemOnFirst", (Standard_Integer (MAT2d_Connexion::*)() const) &MAT2d_Connexion::IndexItemOnFirst, "Returns the Index of the item on the first line.");
cls_MAT2d_Connexion.def("IndexItemOnSecond", (Standard_Integer (MAT2d_Connexion::*)() const) &MAT2d_Connexion::IndexItemOnSecond, "Returns the Index of the item on the second line.");
cls_MAT2d_Connexion.def("ParameterOnFirst", (Standard_Real (MAT2d_Connexion::*)() const) &MAT2d_Connexion::ParameterOnFirst, "Returns the parameter of the point on the firstline.");
cls_MAT2d_Connexion.def("ParameterOnSecond", (Standard_Real (MAT2d_Connexion::*)() const) &MAT2d_Connexion::ParameterOnSecond, "Returns the parameter of the point on the secondline.");
cls_MAT2d_Connexion.def("PointOnFirst", (gp_Pnt2d (MAT2d_Connexion::*)() const) &MAT2d_Connexion::PointOnFirst, "Returns the point on the firstline.");
cls_MAT2d_Connexion.def("PointOnSecond", (gp_Pnt2d (MAT2d_Connexion::*)() const) &MAT2d_Connexion::PointOnSecond, "Returns the point on the secondline.");
cls_MAT2d_Connexion.def("Distance", (Standard_Real (MAT2d_Connexion::*)() const) &MAT2d_Connexion::Distance, "Returns the distance between the two points.");
cls_MAT2d_Connexion.def("IndexFirstLine", (void (MAT2d_Connexion::*)(const Standard_Integer)) &MAT2d_Connexion::IndexFirstLine, "None", py::arg("anIndex"));
cls_MAT2d_Connexion.def("IndexSecondLine", (void (MAT2d_Connexion::*)(const Standard_Integer)) &MAT2d_Connexion::IndexSecondLine, "None", py::arg("anIndex"));
cls_MAT2d_Connexion.def("IndexItemOnFirst", (void (MAT2d_Connexion::*)(const Standard_Integer)) &MAT2d_Connexion::IndexItemOnFirst, "None", py::arg("anIndex"));
cls_MAT2d_Connexion.def("IndexItemOnSecond", (void (MAT2d_Connexion::*)(const Standard_Integer)) &MAT2d_Connexion::IndexItemOnSecond, "None", py::arg("anIndex"));
cls_MAT2d_Connexion.def("ParameterOnFirst", (void (MAT2d_Connexion::*)(const Standard_Real)) &MAT2d_Connexion::ParameterOnFirst, "None", py::arg("aParameter"));
cls_MAT2d_Connexion.def("ParameterOnSecond", (void (MAT2d_Connexion::*)(const Standard_Real)) &MAT2d_Connexion::ParameterOnSecond, "None", py::arg("aParameter"));
cls_MAT2d_Connexion.def("PointOnFirst", (void (MAT2d_Connexion::*)(const gp_Pnt2d &)) &MAT2d_Connexion::PointOnFirst, "None", py::arg("aPoint"));
cls_MAT2d_Connexion.def("PointOnSecond", (void (MAT2d_Connexion::*)(const gp_Pnt2d &)) &MAT2d_Connexion::PointOnSecond, "None", py::arg("aPoint"));
cls_MAT2d_Connexion.def("Distance", (void (MAT2d_Connexion::*)(const Standard_Real)) &MAT2d_Connexion::Distance, "None", py::arg("aDistance"));
cls_MAT2d_Connexion.def("Reverse", (opencascade::handle<MAT2d_Connexion> (MAT2d_Connexion::*)() const) &MAT2d_Connexion::Reverse, "Returns the reverse connexion of <me>. the firstpoint is the secondpoint. the secondpoint is the firstpoint.");
cls_MAT2d_Connexion.def("IsAfter", (Standard_Boolean (MAT2d_Connexion::*)(const opencascade::handle<MAT2d_Connexion> &, const Standard_Real) const) &MAT2d_Connexion::IsAfter, "Returns <True> if my firstPoint is on the same line than the firstpoint of <aConnexion> and my firstpoint is after the firstpoint of <aConnexion> on the line. <aSense> = 1 if <aConnexion> is on the Left of its firstline, else <aSense> = -1.", py::arg("aConnexion"), py::arg("aSense"));
cls_MAT2d_Connexion.def("Dump", [](MAT2d_Connexion &self) -> void { return self.Dump(); });
cls_MAT2d_Connexion.def("Dump", [](MAT2d_Connexion &self, const Standard_Integer a0) -> void { return self.Dump(a0); });
cls_MAT2d_Connexion.def("Dump", (void (MAT2d_Connexion::*)(const Standard_Integer, const Standard_Integer) const) &MAT2d_Connexion::Dump, "Print <me>.", py::arg("Deep"), py::arg("Offset"));
cls_MAT2d_Connexion.def_static("get_type_name_", (const char * (*)()) &MAT2d_Connexion::get_type_name, "None");
cls_MAT2d_Connexion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT2d_Connexion::get_type_descriptor, "None");
cls_MAT2d_Connexion.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT2d_Connexion::*)() const) &MAT2d_Connexion::DynamicType, "None");

// Enums

}
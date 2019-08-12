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
#include <GeomPlate_CurveConstraint.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurveOnSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <BRepFill_CurveConstraint.hxx>
#include <Standard_Type.hxx>

void bind_BRepFill_CurveConstraint(py::module &mod){

py::class_<BRepFill_CurveConstraint, opencascade::handle<BRepFill_CurveConstraint>, GeomPlate_CurveConstraint> cls_BRepFill_CurveConstraint(mod, "BRepFill_CurveConstraint", "same as CurveConstraint from GeomPlate with BRepAdaptor_Surface instead of GeomAdaptor_Surface");

// Constructors
cls_BRepFill_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurveOnSurface> &, const Standard_Integer>(), py::arg("Boundary"), py::arg("Order"));
cls_BRepFill_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurveOnSurface> &, const Standard_Integer, const Standard_Integer>(), py::arg("Boundary"), py::arg("Order"), py::arg("NPt"));
cls_BRepFill_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurveOnSurface> &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Boundary"), py::arg("Order"), py::arg("NPt"), py::arg("TolDist"));
cls_BRepFill_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurveOnSurface> &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Boundary"), py::arg("Order"), py::arg("NPt"), py::arg("TolDist"), py::arg("TolAng"));
cls_BRepFill_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurveOnSurface> &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Boundary"), py::arg("Order"), py::arg("NPt"), py::arg("TolDist"), py::arg("TolAng"), py::arg("TolCurv"));
cls_BRepFill_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer>(), py::arg("Boundary"), py::arg("Tang"));
cls_BRepFill_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer, const Standard_Integer>(), py::arg("Boundary"), py::arg("Tang"), py::arg("NPt"));
cls_BRepFill_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Boundary"), py::arg("Tang"), py::arg("NPt"), py::arg("TolDist"));

// Fields

// Methods
cls_BRepFill_CurveConstraint.def_static("get_type_name_", (const char * (*)()) &BRepFill_CurveConstraint::get_type_name, "None");
cls_BRepFill_CurveConstraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepFill_CurveConstraint::get_type_descriptor, "None");
cls_BRepFill_CurveConstraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepFill_CurveConstraint::*)() const) &BRepFill_CurveConstraint::DynamicType, "None");

// Enums

}
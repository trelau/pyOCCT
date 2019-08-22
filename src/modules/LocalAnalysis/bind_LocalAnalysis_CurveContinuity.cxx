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
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <LocalAnalysis_StatusErrorType.hxx>
#include <GeomLProp_CLProps.hxx>
#include <LocalAnalysis_CurveContinuity.hxx>

void bind_LocalAnalysis_CurveContinuity(py::module &mod){

py::class_<LocalAnalysis_CurveContinuity> cls_LocalAnalysis_CurveContinuity(mod, "LocalAnalysis_CurveContinuity", "This class gives tools to check local continuity C0 C1 C2 G1 G2 between two points situated on two curves");

// Constructors
cls_LocalAnalysis_CurveContinuity.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const opencascade::handle<Geom_Curve> &, const Standard_Real, const GeomAbs_Shape>(), py::arg("Curv1"), py::arg("u1"), py::arg("Curv2"), py::arg("u2"), py::arg("Order"));
cls_LocalAnalysis_CurveContinuity.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const opencascade::handle<Geom_Curve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Real>(), py::arg("Curv1"), py::arg("u1"), py::arg("Curv2"), py::arg("u2"), py::arg("Order"), py::arg("EpsNul"));
cls_LocalAnalysis_CurveContinuity.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const opencascade::handle<Geom_Curve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real>(), py::arg("Curv1"), py::arg("u1"), py::arg("Curv2"), py::arg("u2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"));
cls_LocalAnalysis_CurveContinuity.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const opencascade::handle<Geom_Curve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Curv1"), py::arg("u1"), py::arg("Curv2"), py::arg("u2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"));
cls_LocalAnalysis_CurveContinuity.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const opencascade::handle<Geom_Curve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Curv1"), py::arg("u1"), py::arg("Curv2"), py::arg("u2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"));
cls_LocalAnalysis_CurveContinuity.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const opencascade::handle<Geom_Curve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Curv1"), py::arg("u1"), py::arg("Curv2"), py::arg("u2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"));
cls_LocalAnalysis_CurveContinuity.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const opencascade::handle<Geom_Curve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Curv1"), py::arg("u1"), py::arg("Curv2"), py::arg("u2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"), py::arg("EpsG2"));
cls_LocalAnalysis_CurveContinuity.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const opencascade::handle<Geom_Curve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Curv1"), py::arg("u1"), py::arg("Curv2"), py::arg("u2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"), py::arg("EpsG2"), py::arg("Percent"));
cls_LocalAnalysis_CurveContinuity.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const opencascade::handle<Geom_Curve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Curv1"), py::arg("u1"), py::arg("Curv2"), py::arg("u2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"), py::arg("EpsG2"), py::arg("Percent"), py::arg("Maxlen"));

// Fields

// Methods
// cls_LocalAnalysis_CurveContinuity.def_static("operator new_", (void * (*)(size_t)) &LocalAnalysis_CurveContinuity::operator new, "None", py::arg("theSize"));
// cls_LocalAnalysis_CurveContinuity.def_static("operator delete_", (void (*)(void *)) &LocalAnalysis_CurveContinuity::operator delete, "None", py::arg("theAddress"));
// cls_LocalAnalysis_CurveContinuity.def_static("operator new[]_", (void * (*)(size_t)) &LocalAnalysis_CurveContinuity::operator new[], "None", py::arg("theSize"));
// cls_LocalAnalysis_CurveContinuity.def_static("operator delete[]_", (void (*)(void *)) &LocalAnalysis_CurveContinuity::operator delete[], "None", py::arg("theAddress"));
// cls_LocalAnalysis_CurveContinuity.def_static("operator new_", (void * (*)(size_t, void *)) &LocalAnalysis_CurveContinuity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocalAnalysis_CurveContinuity.def_static("operator delete_", (void (*)(void *, void *)) &LocalAnalysis_CurveContinuity::operator delete, "None", py::arg(""), py::arg(""));
cls_LocalAnalysis_CurveContinuity.def("IsDone", (Standard_Boolean (LocalAnalysis_CurveContinuity::*)() const) &LocalAnalysis_CurveContinuity::IsDone, "None");
cls_LocalAnalysis_CurveContinuity.def("StatusError", (LocalAnalysis_StatusErrorType (LocalAnalysis_CurveContinuity::*)() const) &LocalAnalysis_CurveContinuity::StatusError, "None");
cls_LocalAnalysis_CurveContinuity.def("ContinuityStatus", (GeomAbs_Shape (LocalAnalysis_CurveContinuity::*)() const) &LocalAnalysis_CurveContinuity::ContinuityStatus, "None");
cls_LocalAnalysis_CurveContinuity.def("C0Value", (Standard_Real (LocalAnalysis_CurveContinuity::*)() const) &LocalAnalysis_CurveContinuity::C0Value, "None");
cls_LocalAnalysis_CurveContinuity.def("C1Angle", (Standard_Real (LocalAnalysis_CurveContinuity::*)() const) &LocalAnalysis_CurveContinuity::C1Angle, "None");
cls_LocalAnalysis_CurveContinuity.def("C1Ratio", (Standard_Real (LocalAnalysis_CurveContinuity::*)() const) &LocalAnalysis_CurveContinuity::C1Ratio, "None");
cls_LocalAnalysis_CurveContinuity.def("C2Angle", (Standard_Real (LocalAnalysis_CurveContinuity::*)() const) &LocalAnalysis_CurveContinuity::C2Angle, "None");
cls_LocalAnalysis_CurveContinuity.def("C2Ratio", (Standard_Real (LocalAnalysis_CurveContinuity::*)() const) &LocalAnalysis_CurveContinuity::C2Ratio, "None");
cls_LocalAnalysis_CurveContinuity.def("G1Angle", (Standard_Real (LocalAnalysis_CurveContinuity::*)() const) &LocalAnalysis_CurveContinuity::G1Angle, "None");
cls_LocalAnalysis_CurveContinuity.def("G2Angle", (Standard_Real (LocalAnalysis_CurveContinuity::*)() const) &LocalAnalysis_CurveContinuity::G2Angle, "None");
cls_LocalAnalysis_CurveContinuity.def("G2CurvatureVariation", (Standard_Real (LocalAnalysis_CurveContinuity::*)() const) &LocalAnalysis_CurveContinuity::G2CurvatureVariation, "None");
cls_LocalAnalysis_CurveContinuity.def("IsC0", (Standard_Boolean (LocalAnalysis_CurveContinuity::*)() const) &LocalAnalysis_CurveContinuity::IsC0, "None");
cls_LocalAnalysis_CurveContinuity.def("IsC1", (Standard_Boolean (LocalAnalysis_CurveContinuity::*)() const) &LocalAnalysis_CurveContinuity::IsC1, "None");
cls_LocalAnalysis_CurveContinuity.def("IsC2", (Standard_Boolean (LocalAnalysis_CurveContinuity::*)() const) &LocalAnalysis_CurveContinuity::IsC2, "None");
cls_LocalAnalysis_CurveContinuity.def("IsG1", (Standard_Boolean (LocalAnalysis_CurveContinuity::*)() const) &LocalAnalysis_CurveContinuity::IsG1, "None");
cls_LocalAnalysis_CurveContinuity.def("IsG2", (Standard_Boolean (LocalAnalysis_CurveContinuity::*)() const) &LocalAnalysis_CurveContinuity::IsG2, "None");

// Enums

}